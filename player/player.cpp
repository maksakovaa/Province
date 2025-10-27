#include "player.h"
#include "../Functions.h"
#include <QPixmap>
#include "cloth.h"
#include <iostream>

Player::Player(): m_wardrobe()
{
    initDefaultArrays();
    connect(this, &Player::sigUpdClothSize, &m_wardrobe, &Wardrobe::slotUpdSize);
    f_name = "Света";
    l_name = "Лебедева";
}

Player::Player(CharacterType history, Settings* ptr): m_wardrobe(), m_settings(ptr)
{
    initDefaultArrays();
    connect(this, &Player::sigUpdClothSize, &m_wardrobe, &Wardrobe::slotUpdSize);

    f_name = "Света";
    l_name = "Лебедева";
    

    m_birthDate.tm_mday= 5;
    m_birthDate.tm_mon = 8 - 1;
    m_birthDate.tm_year = 1998 - 1900;

    m_body[Body::eyeColor] = 1;
    m_body[Body::eyeSize] = 2;
    m_body[Body::hairColor] = 1;
    m_body[Body::lip] = 0;
    m_body[Body::height] = getRandInt(165,172);
    m_body[Body::weight] = getRandInt(45,80);
    m_body[Body::pubisHair] = 3;
    m_body[Body::makeup] = 1;
    m_body[Body::vidage] = getRandInt(15,19);
    m_body[Body::hairStatus] = 1;
    m_body[Body::legHair] = 5;

    m_status[Status::energy] = 15;
    m_status[Status::water] = 15;
    m_status[Status::son] = 24;

    m_status[Status::health] = 100;
    m_status[Status::mood] = 100;
    m_status[Status::money] = 1500;
    m_status[Status::vidageday] = 300;

    m_skills[Skills::strenght] = 10;
    m_skills[Skills::speed] = 10;
    m_skills[Skills::agility] = 10;
    m_skills[Skills::endurance] = 10;
    m_skills[Skills::intellect] = 10;
    m_skills[Skills::react] = 10;
    m_skills[Skills::schoolProgress] = 75;

    if(history == CharacterType::nerd)
    {
        m_body[Body::eyeSize] = 2;
        m_body[Body::weight] = getRandInt(60,80);
        m_body[Body::eyeSize] = 0;
        m_body[Body::skinTan] = 0;
        m_body[Body::skin] = 0;
        m_body[Body::legHair] = 10;
        m_body[Body::glass] = 1;
        m_skills[Skills::strenght] = 1;
        m_skills[Skills::endurance] = 5;
        m_skills[Skills::agility] = 1;
        m_skills[Skills::domination] = 0;
        m_skills[Skills::schoolProgress] = 50;
        m_status[Status::nerdism] = 100;
    }
    else if(history == CharacterType::schoolgirl)
    {
        m_body[Body::weight] = getRandInt(45,50);
        m_body[Body::skinTan] = 0;
        m_body[Body::skin] = 1;
        m_body[Body::legHair] = 3;
        m_body[Body::glass] = 1;
        m_skills[Skills::strenght] = 1;
        m_skills[Skills::endurance] = 5;
        m_skills[Skills::agility] = 1;
        m_skills[Skills::intellect] = 70;
        m_skills[Skills::domination] = -20;
        m_skills[Skills::schoolProgress] = 100;
        m_status[Status::nerdism] = 100;
    }
    else if (history == CharacterType::dancer)
    {
        m_body[Body::lip] = 1;
        m_body[Body::skinTan] = 30;
        m_body[Body::skin] = 2;
        m_body[Body::legHair] = -5;
        m_skills[Skills::intellect] = 30;
        m_skills[Skills::agility] = 60;
        m_skills[Skills::strenght] = 20;
        m_skills[Skills::endurance] = 20;
        m_skills[Skills::schoolProgress] = 40;
        m_skills[Skills::vokal] = 80;
        m_skills[Skills::dance] = 90;
        m_skills[Skills::domination] = getRandInt(-10, 10);
    }
    else if (history == CharacterType::sportgirl)
    {
        m_body[Body::height] = getRandInt(173,180);
        m_body[Body::skinTan] = 30;
        m_body[Body::skin] = 1;
        m_body[Body::legHair] = 0;
        m_body[Body::weight] = getRandInt(45,60);
        m_skills[Skills::strenght] = 50;
        m_skills[Skills::endurance] = 50;
        m_skills[Skills::speed] = 25;
        m_skills[Skills::agility] = 25;
        m_skills[Skills::volleyball] = 70;
        m_skills[Skills::runner] = 40;
        m_skills[Skills::domination] = getRandInt(10,30);
        m_skills[Skills::schoolProgress] = 30; 
    }
    else if (history == CharacterType::playgirl)
    {
        m_body[Body::skinTan] = 30;
        m_body[Body::skin] = 2;
        m_body[Body::legHair] = -5;
        m_body[Body::colorfulLenses] = 30;
        m_skills[Skills::agility] = 20;
        m_skills[Skills::endurance] = 20;
        m_skills[Skills::domination] = getRandInt(30,60);
        m_skills[Skills::schoolProgress] = 30;
    }
    else if (history == CharacterType::frivolous)
    {
        m_body[Body::hairStatus] = 1;
        m_body[Body::hairCurly] = 14;
        m_body[Body::lip] = 2;
        m_body[Body::skinTan] = 30;
        m_body[Body::legHair] = 0;
        m_body[Body::eyeLashes] = 2;
        m_body[Body::eyeBrows] = 10;
        m_body[Body::eyeColor] = 3;
        m_body[Body::skin] = 4;
        m_body[Body::weight] = getRandInt(51,55);
        m_body[Body::height] = getRandInt(169,175);
        m_skills[Skills::intellect] = 15;
        m_skills[Skills::agility] = 30;
        m_skills[Skills::schoolProgress] = 28;
        m_skills[Skills::dance] = 50;
        m_skills[Skills::domination] = getRandInt(-5,5);
    }
    zz_body();
    emit sigUpdClothSize(m_body[hips]);
    initWardrobeClothes();
    calcVneshBonus();
    calcShamelessFlag();
}

QString Player::getName()
{
    return f_name + " " + l_name;
}

int Player::getSkillValue(Skills skill_name)
{
    return m_skills[skill_name];
}

int Player::getVBody(Body param)
{
    return m_body[param];
}

int Player::getStatisticsValue(SC stat)
{
    return m_statistic[stat];
}

int Player::getVStatus(Status stat)
{
    return m_status[stat];
}

int Player::getVConst(Const param)
{
    return m_const[param];
}

QString Player::getBirthDate()
{
    QString result;
    QString nul = intQStr(0);
    if(m_birthDate.tm_mday < 10)
    {
        result += nul;
    }
    result += intQStr(m_birthDate.tm_mday) + ".";
    if(m_birthDate.tm_mon + 1 < 10)
    {
        result += nul;
    }
    result += intQStr(m_birthDate.tm_mon + 1) + "." + intQStr(m_birthDate.tm_year + 1900);
    return result;
}


int Player::getAge()
{
    int diff;
    emit sigCalcAge(diff, m_birthDate);
    return diff;
}

bool Player::updVSkill(Skills skill_name, int value)
{
    if (m_skills[skill_name] += value)
    {
        checkSkillParams();
        return true;
    }
    else
        return false;
}

bool Player::updVBody(Body param, int value)
{
    if(m_body[param] += value)
    {
        checkBodyParams();
        calcVneshBonus();
        return true;
    }
    else
        return false;
}

bool Player::updVStatus(Status stat, int value)
{
    if(m_status[stat] += value)
    {
        checkStatusParams();
        return true;
    }
    else
        return false;
}

void Player::setVStatus(Status stat, int value)
{
    m_status[stat] = value;
    checkStatusParams();
}

void Player::setVBody(Body param, int value)
{
    m_body[param] = value;
    checkBodyParams();
}

void Player::setVSexVar(SexVar param, int value)
{
    m_sex[param] = value;
}

void Player::updVBuzzer(budilnik type, int value)
{
    m_budilnik[type] += value;
    if(m_budilnik[timerH] > 23) m_budilnik[timerH] = 0;
    if(m_budilnik[timerM] > 59) m_budilnik[timerM] = 0;
    if(m_budilnik[budilnikOn] > 1) m_budilnik[budilnikOn] = 0;
}

void Player::updVSexVar(SexVar param, int value)
{
    m_sex[param] += value;
}

void Player::updVStatistic(SC param, int value)
{
    m_statistic[param] += value;
}

int Player::getVBuzzer(budilnik param)
{
    return m_budilnik[param];
}

int Player::getVSexVar(SexVar param)
{
    return m_sex[param];
}

int Player::getCurClothGroup()
{
    if(m_clothSLots[ClothType::Main] != nullptr)
    {
        ClothMain* ptr = (ClothMain*)m_clothSLots[ClothType::Main];
        return ptr->getClothGroup();
    }
    else
    {
        return 0;
    }
}

void Player::redress(Cloth *newCloth)
{
    if (newCloth != nullptr)
    {
        if(newCloth->getClothType() == ClothType::Main)
        {
            ClothGroup newClothGroup = ((ClothMain*)newCloth)->getClothGroup();
            if (m_clothSLots[ClothType::Main] != nullptr)
            {
                m_wardrobe.addCloth(m_clothSLots[ClothType::Main]);
            }
            m_clothSLots[ClothType::Main] = newCloth;
            if (newClothGroup <= swimsuit)
            {
                if(m_clothSLots[ClothType::Panties] != nullptr)
                {
                    m_wardrobe.addCloth(m_clothSLots[ClothType::Panties]);
                }
                m_clothSLots[ClothType::Panties] = nullptr;
                if(m_clothSLots[ClothType::Stockings] != nullptr)
                {
                    m_wardrobe.addCloth(m_clothSLots[ClothType::Stockings]);
                }
                m_clothSLots[ClothType::Stockings] = nullptr;
            }
            if (newClothGroup == ClothGroup::jeans || newClothGroup == ClothGroup::sportsSuit)
            {
                if(m_clothSLots[ClothType::Stockings] != nullptr)
                {
                    m_wardrobe.addCloth(m_clothSLots[ClothType::Stockings]);
                }
                m_clothSLots[ClothType::Stockings] = nullptr;
            }
        }
        if(newCloth->getClothType() == ClothType::Panties)
        {
            if(m_clothSLots[ClothType::Panties] == nullptr)
            {
                m_clothSLots[ClothType::Panties] = newCloth;
            }
        }
        if(newCloth->getClothType() == ClothType::Stockings)
        {
            if(m_clothSLots[ClothType::Stockings] == nullptr)
            {
                m_clothSLots[ClothType::Stockings] = newCloth;
            }
        }
    }
    else
    {
        for (int i = 0; i < ClothType::Stockings; ++i)
        {
            if(m_clothSLots[static_cast<ClothType>(i)] != nullptr)
            {
                m_wardrobe.addCloth(m_clothSLots[static_cast<ClothType>(i)]);
            }
            m_clothSLots[static_cast<ClothType>(i)] = nullptr;
        }
    }
}

Cloth *Player::getCloth(ClothType type)
{
    return m_clothSLots[type];
}

void Player::setSettingsPtr(Settings *ptr)
{
    m_settings = ptr;
}

void Player::initDefaultArrays()
{
    for (int i = 0; i <= Skills::truancy; ++i)
    {
        m_skills[static_cast<Skills>(i)] = 0;
    }
    for (int i = 0; i <= Body::glass; ++i)
    {
        m_body[static_cast<Body>(i)] = 0;
    }
    for (int i = 0; i <= Status::vnesh; ++i)
    {
        m_status[static_cast<Status>(i)] = 0;
    }
    for (int i = 0; i <= SC::sexWithFuta; ++i)
    {
        m_statistic[static_cast<SC>(i)] = 0;
    }
    m_const[dec_anti_rubbing] = 10;
    m_const[max_dry_v_rubbing] = 8;
    m_const[max_dry_a_rubbing] = 8;
    m_const[max_vaginal_grease] = 450;
    m_const[max_sweat_grease] = 300;
    m_const[many_vaginal_grease] = 270;
    m_const[out_vaginal_grease] = 35;
    m_const[shameStage1] = 27;
    m_const[shameStage2] = 81;
    m_const[shameStage3] = 243;
    m_const[dv_breast] = 64;
    m_const[dv_hips] = 63;

    m_budilnik[budilnikOn] = 0;
    m_budilnik[timerH] = 0;
    m_budilnik[timerM] = 0;
}

void Player::calcShamelessFlag()
{


    int shameless_main = m_statistic[SC::raped] / 3 + m_statistic[SC::raped] / 3
                         + m_statistic[SC::voyeurism] / 3 + m_statistic[SC::cumOnClothes] / 3
                         + m_statistic[SC::vaginalSex] + m_statistic[SC::blowJob]
                         + m_statistic[SC::handJob] + m_statistic[SC::getKuni]
                         + m_statistic[SC::piss] + m_statistic[SC::lesbianSex]
                         + m_skills[Skills::danceStrip] + m_statistic[SC::stripDanceSum] * 3 + m_statistic[SC::nudeModelFoto]
                         + m_statistic[SC::exhibi] * 3 + m_statistic[SC::analSex] * 3 + m_statistic[SC::spankAss] * 3
                         + m_statistic[SC::swallow] * 3 + m_statistic[SC::facialCum] * 3
                         + m_body[Body::throat] * 3 + m_statistic[SC::gangBang] * 6
                         + m_statistic[SC::sluttyLove] * 6 + m_statistic[SC::pornoFilmModel] * 6;

    int shameless_flag;
    if (shameless_main < m_const[shameStage1]) { shameless_flag = 0; }
    else if (shameless_main >= m_const[shameStage1] && shameless_main < m_const[shameStage2])
    {
        shameless_flag = 1;
    }
    else if(shameless_main >= m_const[shameStage2] && shameless_main < m_const[shameStage3])
    {
        shameless_flag = 2;
    }
    else if(shameless_main >= m_const[shameStage3])
    {
        shameless_flag = 3;
    }
    m_status[Status::shamelessFlag] = shameless_flag;
}

void Player::checkBodyParams()
{
    if (m_body[Body::vidage] == 24)
    {
        m_body[Body::vidage] = 16;
    }
    if (m_body[Body::weight] > 100)
    {
        m_body[Body::weight] = 40;
    }
    if (m_body[Body::height] > 180)
    {
        m_body[Body::height] = 160;
    }
    if (m_body[Body::lip] > 4)
    {
        m_body[Body::lip] = 0;
    }
    if (m_body[Body::skin] > 4)
    {
        m_body[Body::skin] = 0;
    }
    if (m_body[Body::makeup] >= 5)
    {
        m_body[Body::makeup] = 1;
    }
    if (m_body[Body::anus] == 1 && m_statistic[SC::analSex] < 1)
    {
        m_statistic[SC::analSex] = 1;
    }
    else if (m_body[Body::anus] == 6 && m_statistic[SC::analSex] < 6)
    {
        m_statistic[SC::analSex] = 6;
    }
    else if (m_body[Body::anus] == 11 && m_statistic[SC::analSex] < 6)
    {
        m_statistic[SC::analSex] = 6;
    }
    else if (m_body[Body::anus] == 16 && m_statistic[SC::analSex] < 51)
    {
        m_statistic[SC::analSex] = 51;
    }
    else if (m_body[Body::anus] == 26 && m_statistic[SC::analSex] < 201)
    {
        m_statistic[SC::analSex] = 201;
    }
    else if (m_body[Body::anus] == 36 && m_statistic[SC::analSex] < 201)
    {
        m_statistic[SC::analSex] = 201;
    }
    else if (m_body[Body::anus] == 0 && m_statistic[SC::analSex] != 0)
    {
        m_statistic[SC::analSex] = 0;
    }

    if (m_body[Body::vagina] == 1 && m_statistic[SC::vaginalSex] < 1)
    {
        m_statistic[SC::vaginalSex] = 1;
    }
    else if (m_body[Body::vagina] == 6 && m_statistic[SC::vaginalSex] < 6)
    {
        m_statistic[SC::vaginalSex] = 6;
    }
    else if (m_body[Body::vagina] == 11 && m_statistic[SC::vaginalSex] < 6)
    {
        m_statistic[SC::vaginalSex] = 6;
    }
    else if (m_body[Body::vagina] == 16 && m_statistic[SC::vaginalSex] < 51)
    {
        m_statistic[SC::vaginalSex] = 51;
    }
    else if (m_body[Body::vagina] == 26 && m_statistic[SC::vaginalSex] < 201)
    {
        m_statistic[SC::vaginalSex] = 201;
    }
    else if (m_body[Body::vagina] == 36 && m_statistic[SC::vaginalSex] < 201)
    {
        m_statistic[SC::vaginalSex] = 201;
    }
    else if (m_body[Body::vagina] == 0 && m_statistic[SC::vaginalSex] != 0)
    {
        m_statistic[SC::vaginalSex] = 0;
    }
    
    if (m_body[Body::hairCurly] > 10)
    {
        m_body[Body::hairCurly] = 0;
    }
    
    if (m_body[Body::hairColor] >= 4)
    {
        m_body[Body::hairColor] = 0;
    }
    
    if (m_body[Body::hairLength] >= 4)
    {
        m_body[Body::hairLength] = 0;
    }
    
    if (m_body[Body::eyeColor] > 3)
    {
        m_body[Body::eyeColor] = 0;
    }

    if (m_body[Body::eyeSize] > 3)
    {
        m_body[Body::eyeSize] = 0;
    }
    
    if (m_body[Body::eyeLashes] > 2)
    {
        m_body[Body::eyeLashes] = 0;
    }

    if (m_body[Body::eyeBrows] >= 20)
    {
        m_body[Body::eyeBrows] = -1;
    }
    
    if (m_body[Body::glass] > 3)
    {
        m_body[Body::glass] = 1;
    }
    updBody();
}

void Player::checkStatusParams()
{
    if (m_sex[dry_v_rubbing] < 0)
    {
        m_sex[dry_v_rubbing] = 0;
    }
    if (m_sex[level_v_rubbing] < 0)
    {
        m_sex[level_v_rubbing] = 0;
    }

    if (m_status[Status::pregnancyKnow] > 1)
    {
        m_status[Status::pregnancyKnow] = 1;
    }
    if (m_status[Status::isprok] > 1)
    {
        m_status[Status::isprok] = 1;
    }
    if (m_status[Status::sweat] > 4)
    {
        m_status[Status::sweat] = 4;
    }
    if (m_status[Status::mesec] < 0)
    {
        m_status[Status::mesec] = 0;
    }
}

void Player::checkSkillParams()
{
    for (int i = 0; i <= Skills::truancy; ++i)
    {
        Skills skill = static_cast<Skills>(i);
        if(skill == Skills::jab || skill == Skills::punch || skill == Skills::kik || skill == Skills::kikDef || skill == Skills::boxing)
        {
            if(m_skills[skill] > 120)
            {
                m_skills[skill] = 0;
            }
        }
        else if (skill == Skills::domination)
        {
            if(m_skills[skill] > 100)
            {
                m_skills[skill] = -100;
            }
        }
        else if (skill == Skills::posSkill)
        {
            if(m_skills[skill] > 1000)
            {
                m_skills[skill] = 0;
            }
        }
        else if (skill == Skills::runner)
        {
            if(m_skills[skill] > 2000)
            {
                m_skills[skill] = 0;
            }
        }
        else if (skill == truancy)
        {
            if (m_skills[skill] > 30)
            {
                m_skills[skill] = 0;
            }
        }
        else {
            if (m_skills[skill] > 100)
            {
                m_skills[skill] = 0;
            }
        }

    }
    m_skills[Skills::boxing] = m_skills[Skills::jab]/4 + m_skills[Skills::punch]/4 + m_skills[Skills::kik]/4 + m_skills[Skills::kikDef]/4;
}

bool Player::isCheatsOn()
{
    return m_settings->isCheats();
}

bool Player::isPanties()
{
    return m_clothSLots[ClothType::Panties] != nullptr;
}

bool Player::isAutoTampon()
{
    return m_settings->isAutoTampon();
}

void Player::updBody()
{
    zz_body();
    calcVneshBonus();
    emit sigUpdClothSize(m_body[hips]);
}

void Player::initWardrobeClothes()
{
    ClothMain* first = new ClothMain(3, ClothType::Main, ClothGroup::sundress, "Сарафан");
    ClothMain* second = new ClothMain(4, ClothType::Main, ClothGroup::schoolUniform, "Школьная форма");
    ClothMain* third = new ClothMain(getRandInt(10,29), ClothType::Main, ClothGroup::sportsSuit, "Спортивный костюм");
    ClothMain* four = new ClothMain(getRandInt(30,49), ClothType::Main, ClothGroup::jeans, "Джинсы");
    ClothPanties* pants = new ClothPanties(ClothType::Panties);
    m_wardrobe.addCloth(first);
    m_wardrobe.addCloth(second);
    m_wardrobe.addCloth(third);
    m_wardrobe.addCloth(four);
    m_wardrobe.addCloth((ClothMain*)pants);
    wearClothes(first);
    wearClothes(pants);
}

void Player::wearClothes(Cloth* thing)
{
    m_clothSLots[thing->getClothType()] = m_wardrobe.wearCloth((ClothMain*)thing);
}

void Player::checkPanties()
{
    Cloth* pantiePtr = m_clothSLots[ClothType::Panties];
    if(pantiePtr != nullptr)
    {
        pantiePtr->decreaseCondition(1);
        if (m_status[isprok] == 0 && m_status[mesec] > 0)
        {
            pantiePtr->decreaseCondition(7);
        }
        if (m_status[isprok] > 0 && m_status[mesec] > 0)
        {
            pantiePtr->decreaseCondition(2);
        }
        if(m_status[cumPussy] > 0)
        {
            pantiePtr->decreaseCondition(5);
        }
        if(m_status[cumAnus] > 0)
        {
            pantiePtr->decreaseCondition(4);
        }
        pantiePtr->decreaseCondition(m_status[panties_grease]);
        if(pantiePtr->getCondition() < 0)
        {
            m_clothSLots[ClothType::Panties] = nullptr;
            delete pantiePtr;
        }
    }
}

int Player::calcHairCurlyBonus()
{
    if (m_body[Body::hairCurly] != 0)
    {
        return 3;
    }
    else 
    {
        return 0;
    }
}

int Player::calcLipBonus()
{
    if (m_body[Body::lip] == 4)
    {
        return -1;
    }
    else
    {
        return m_body[Body::lip];
    }
}

int Player::calcLipAlmstatBonus()
{
    if (m_body[lipbalmstat] > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int Player::calcLenseBonus()
{
    if (m_body[colorfulLenses] > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Player::calcSkinTanBonus()
{
    int res;
    if (m_body[skinTan] == 0)
    {
        res = 0;
    }
    else if (m_body[skinTan] > 0 && m_body[skinTan] <= 30)
    {
        res = 1;
    }
    else if (m_body[skinTan] > 30 && m_body[skinTan] <= 100)
    {
        res = 5;
    }
    else if (m_body[skinTan] > 100)
    {
        res = 10;
    }
    return res;
}

int Player::calcEyeSizeBonus()
{
    if (m_body[eyeSize] > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int Player::calcEyeBrowBonus()
{
    int eyeBrowk = 0;
    if (m_body[eyeBrows] < 0)
    {
        eyeBrowk = 1;
    }
    if (m_body[eyeBrows] >= 10)
    {
        eyeBrowk = 2;
    }
    return eyeBrowk;
}

int Player::calcBodyBonus()
{
    int bodykoef;
    if (m_settings->getBodyType() == 0)
    {
        bodykoef = 15 - m_body[bodyGroup] * 5;
    }
    else if (m_settings->getBodyType() == 2)
    {
        bodykoef = m_body[bodyGroup] * 5 - 5;
    }
    else
    {
        if (m_body[bodyGroup] == 0)
        {
            bodykoef = 10;
        }
        else
        {
            bodykoef = 20 - m_body[bodyGroup] * 5;
        }
    }
    
    if (m_body[bodyGroup] <= 2)
    {
        bodykoef += (m_skills[strenght] + m_skills[endurance]) / 40;
    }
    return bodykoef;
}

int Player::calcPubisBonus()
{
    int lobkoef;
    if (m_clothSLots[ClothType::Main] == nullptr)
    {
        if (m_body[pubisHair] <= 0)
        {
            lobkoef = 20;
        }
        else if (m_body[pubisHair] > 0 && m_body[pubisHair] <= 2)
        {
            lobkoef = 0;
        }
        else
        {
            lobkoef = -20;
        }

        if (m_settings->getPubicHair())
        {
            lobkoef = -1 * lobkoef;
        }
    }
    else
    {
        lobkoef = 0;
    }
    return lobkoef;
}

int Player::calcClothesBonus()
{
    ClothMain* ptr = (ClothMain*)m_clothSLots[ClothType::Main];
    int odevnesh;
    if (ptr == nullptr)
    {
        odevnesh = 0;
    }
    else if (ptr->getClothGroup() == ClothGroup::towel)
    {
        odevnesh = 3;
    }
    else if (ptr->getClothGroup() == ClothGroup::swimsuit)
    {
        odevnesh = 7;
    }
    else
    {
        odevnesh = ptr->getClothBonus();
    }
    return odevnesh;
}

int Player::calcVidageBonus()
{
    int vidagebonus;
    if(m_body[vidage] < 21) { vidagebonus = 0; }
    else if(m_body[vidage] < 26) { vidagebonus = 5; }
    else if (m_body[vidage] < 31) { vidagebonus = 10; }
    else if(m_body[vidage] < 41) { vidagebonus = 20; }
    else {vidagebonus = 40; }
    return vidagebonus;
}

int Player::calcGlassBonus()
{
    int glassvnesh = 0;
    if (m_body[Body::glass] == 1)
    {
        glassvnesh = -3;
    }
    if (m_body[Body::glass] == 3)
    {
        glassvnesh = 1;
    }
    return glassvnesh;
}

int Player::calcLegBonus()
{
    int legkoef;
    if (m_body[Body::legHair] <= 0) { legkoef = 0; }
    if (m_body[Body::legHair] > 0 && m_body[Body::legHair] <= 2) { legkoef = 3;}
    if (m_body[Body::legHair] > 2 && m_body[Body::legHair] <= 5) { legkoef = 10; } 
    if (m_body[Body::legHair] > 5) { legkoef = 20; }

    ClothMain* ptr = (ClothMain*)m_clothSLots[ClothType::Main];
    if (ptr != nullptr)
    {
        if (ptr->getClothGroup() == ClothGroup::sportsSuit || ptr->getClothGroup() == ClothGroup::jeans)
        {
            legkoef = 0;
        }
    }
    return legkoef;
}

int Player::calcZZTits()
{
    int quot, zz_tits, tmp = m_body[breasts] - m_body[silicone];
    if (m_body[silicone] == 0)
    {
        quot = 0;
    }
    else if (tmp < m_body[silicone])
    {
        quot = 1;
    }
    else if (tmp == m_body[silicone])
    {
        quot = 2;
    }
    else if (tmp > m_body[silicone])
    {
        quot = 3;
    }
    
    if (m_settings->getBody_tits() == 0)
    {
        zz_tits = 20 - m_body[breastsSize] * 3;
    }
    else if (m_settings->getBody_tits() == 1)
    {
        if (m_body[breastsSize] < 3)
        {
            zz_tits = 20 + 3 * quot - (3 - m_body[breastsSize]) * 6;
        }
        else if (m_body[breastsSize] > 3)
        {
            zz_tits = 20 + 3 * quot - (m_body[breastsSize] - 3) * 6;
        }
        else
        {
            zz_tits = 20 + 3 * quot;
        }       
    }
    else
    {
        zz_tits = m_body[breastsSize] * 3 + 2 + 3 * quot;
    }    
    return zz_tits;
}

void Player::calcVneshBonus()
{
    m_status[vnesh] = 0;
    m_status[vnesh] += calcHairCurlyBonus();
    m_status[vnesh] += calcZZTits();
    m_status[vnesh] += calcLipBonus();
    m_status[vnesh] += calcLenseBonus();
    m_status[vnesh] += calcSkinTanBonus();
    m_status[vnesh] += m_body[Body::skin];
    m_status[vnesh] += m_body[Body::makeup] * 2;
    m_status[vnesh] += m_body[Body::eyeLashes];
    m_status[vnesh] += calcEyeSizeBonus();
    m_status[vnesh] += calcBodyBonus();
    m_status[vnesh] += calcPubisBonus();
    m_status[vnesh] += calcClothesBonus();
    m_status[vnesh] += calcLipAlmstatBonus();
    m_status[vnesh] += calcEyeBrowBonus();
    m_status[vnesh] += calcGlassBonus();
    if (m_settings->isHapri() && m_body[hairStatus] != 0)
    {
        m_status[vnesh] += 2;
    }

    m_status[vnesh] -= calcVidageBonus() + calcLegBonus();

    int ideal_body_breast = m_body[waist] * 100 / m_body[breasts];
    int ideal_body_hips	= m_body[waist] * 100 / m_body[hips];
    m_status[vnesh] -= abs(m_const[dv_breast] - ideal_body_breast) + abs(m_const[dv_hips] - ideal_body_hips);
    if (m_status[vnesh] < 0)
    {
        m_status[vnesh] = 0;
    }
    if (m_status[Status::sifilis] >= 21 || m_status[Status::gerpes] >= 3 || m_status[Status::tripper] > 2)
    {
        m_status[vnesh] = -10;
    }
}

void Player::skinDecrement(int value)
{
    if(value <= 0)
    {
        m_body[skinVan] -= 1;
    }
    else
    {
        m_body[skinVan] -= value;
    }
    if(m_body[skinVan] < 0 && m_body[skin] > 0)
    {
        m_body[skinVan] = 19;
        m_body[skin] -= 1;
    }
    if(m_body[skinVan] < 0 && m_body[skin] == 0)
    {
        m_body[skinVan] = 0;
        m_body[skin] = 0;
    }
    if(m_body[skin] < 0)
    {
        m_body[skin] = 0;
    }
}

void Player::skinIncrement(int value)
{
    if(value <= 0)
    {
        m_body[skinVan] += 1;
    }
    else
    {
        m_body[skinVan] += value;
    }
    if(m_body[skinVan] >= 20)
    {
        m_body[skinVan] = 0;
        m_body[skin] += 1;
    }
    if(m_body[skin] > 4)
    {
        m_body[skin] = 4;
    }
}

QString Player::getPlayerFace()
{
    QString path;
    if(m_settings->isHapri())
    {
        if(m_body[Body::makeup] == 0)
        {
            path += ":/img/body/face_alt/2/" + intQStr(m_body[Body::hairColor]);
            if(m_body[Body::hairCurly] > 0) { path += intQStr(1) ; }
            else { path += intQStr(0); }
            path += ".jpg";
        }
        else
        {
            path += ":/img/body/face_alt/" + intQStr(m_body[Body::hairStatus]) + "/" + intQStr(m_body[Body::hairColor]);
            if(m_body[Body::glass] > 2) { path += intQStr(2); }
            else { path += intQStr(m_body[Body::glass]); }
            path += intQStr(m_body[Body::hairLength]);
            if(m_body[Body::hairStatus] != 0)
            {
                if(m_body[Body::hairCurly] > 0) { path += intQStr(1); }
                else { path += intQStr(0); }
            }
            path += intQStr(m_body[Body::makeup]) + ".jpg";
        }
    }
    else
    {
        path += ":/img/body/face/" + intQStr(m_body[Body::hairColor]) + intQStr(m_body[Body::glass]);
        if(m_body[Body::hairLength] <= 1) { path += intQStr(0); }
        else { path += intQStr(0); }
        if(m_body[Body::hairCurly] > 0) { path += intQStr(1); }
        else { path += intQStr(0); }
        path += ".jpg";
    }
    return makeImg(path);
}

QString Player::getCurClothName()
{
    return m_clothSLots[ClothType::Main]->getName();
}

QPixmap Player::getPlayerIcon()
{
    QString path = ":/img/icons/player/" + intQStr(m_body[Body::hairColor]);

    if(m_body[Body::hairLength] >= 2) { path += intQStr(2); }
    else { path += intQStr(m_body[Body::hairLength]); }

    if(m_body[Body::glass] > 0) { path += intQStr(1); }
    else { path += intQStr(0); }

    path += ".png";
    return QPixmap(path);
}

QString Player::getPlayerBody()
{
    QString path;
    int koef = m_skills[Skills::strenght] + m_skills[Skills::endurance];
    if (m_body[Body::bodyGroup] == 0)
    {
        if (koef >= 50)
        {
            path = ":/img/body/body_fit/0.jpg";
        }
        else {
            path = ":/img/body/body_normal/3.jpg";

        }
    }
    else if (m_body[Body::bodyGroup] == 1)
    {
        if (koef < 50)
        {
            path = ":/img/body/body_normal/5.jpg";
        }
        else if (koef >= 50 && koef < 100)
        {
            path = ":/img/body/body_fit/3.jpg";
        }
        else
        {
            path = ":/img/body/body_fit/4.jpg";
        }
    }
    else if (m_body[Body::bodyGroup] == 2)
    {
        if (koef >= 50)
        {
            path = ":/img/body/body_fit/5.jpg";
        }
        else {
            path = ":/img/body/body_normal/9.jpg";
        }
    }
    else if (m_body[Body::bodyGroup] == 3)
    {
        if (koef >= 50)
        {
            path = ":/img/body/body_fit/6.jpg";
        }
        else {
            path = ":/img/body/body_normal/11.jpg";
        }
    }
    else if (m_body[Body::bodyGroup] == 4)
    {
        if (koef >= 50)
        {
            path = ":/img/body/body_fit/7.jpg";
        }
        else {
            path = ":/img/body/body_normal/12.jpg";
        }
    }
    return makeImg(path);
}

QString Player::getPlayerVagina()
{
    int vag = m_body[Body::vagina];
    int tmp_pussy;
    if (vag == 0) { tmp_pussy = 0; }
    else if (vag > 0 && vag <= 15) { tmp_pussy = (vag-1)/5+1; }
    else { tmp_pussy = (vag - 16)/10 + 4; }
    QString path = ":/img/body/vagina/" + intQStr(tmp_pussy) + ".jpg";
    return makeImg(path);
}

QString Player::getPlayerAnus()
{
    int cloth1;

    int analPlugIn = 0;
    int anus = m_body[Body::anus];
    QString tmp_anus;
    if(analPlugIn == 0)
    {
        if (anus == 0)
        {
            tmp_anus = intQStr(0);
        }
        else if (anus > 0 && anus <= 15)
        {
            tmp_anus = intQStr((anus - 1)/5 + 1);
        }
        else
        {
            tmp_anus = intQStr((anus - 16)/10 + 4);
        }
    }
    else
    {
        if(cloth1 == 1)
        {
            tmp_anus = "analplug";
        }
        else
        {
            if(m_body[Body::piercingG] == 0)
            {
                if(m_body[Body::piercingGL] == 0)
                {
                    tmp_anus = "analplugnotanga";
                }
                else
                {
                    tmp_anus = "analplugpirsclit";
                }
            }
            else
            {
                if(m_body[Body::piercingGL] == 0)
                {
                    tmp_anus = "analplugpirsring";
                }
                else
                {
                    tmp_anus = "analplugpirscligub";
                }
            }
        }
    }
    QString path = ":/img/body/anus/" + tmp_anus + ".jpg";
    return makeImg(path);
}

QString Player::getPlayerPubis()
{
    QString path;
    int lobok = m_body[Body::pubisHair];
    if(lobok <= 0)
    {
        path = ":/img/body/pubis/shaved.jpg";
    }
    else if (lobok > 0 && lobok <= 2)
    {
        path = ":/img/body/pubis/trim.jpg";
    }
    else
    {
        path = ":/img/body/pubis/hairy.jpg";
    }
    return makeImg(path);
}

QString Player::getPlayerClothes()
{
    QString path;
    if(m_clothSLots[ClothType::Main] == nullptr)
    {
        path = ":/img/clothing/0/0.jpg";
    }
    else
    {
        ClothMain* ptr = (ClothMain*)m_clothSLots[ClothType::Main];
        path = ptr->getClothImage();
    }
    return makeImg(path);
}

QString Player::getPlayerBreasts()
{
    QString path = ":/img/body/breasts/" + intQStr(m_body[breastsSize]) + ".jpg";
    return makeImg(path);
}

void Player::zz_body()
{
    if (m_body[height] > 180) { m_body[height] = 180; }
    if (m_body[height] < 160) { m_body[height] = 160; }

    m_body[base_weight] = (m_body[Body::weight]*10000) / (m_body[Body::height] * m_body[Body::height]);

    if (m_body[weight] <= 30) { m_body[weight] = 30; }

    if (m_body[base_weight] < 19)
    {
        m_body[Body::bodyGroup] = 0;
    }
    else if (m_body[base_weight] >= 19 && m_body[base_weight] < 25)
    {
        m_body[Body::bodyGroup] = 1;
    }
    else if (m_body[base_weight] >= 25 && m_body[base_weight] < 30)
    {
        m_body[Body::bodyGroup] = 2;
    }
    else if (m_body[base_weight] >= 30 && m_body[base_weight] < 40)
    {
        m_body[Body::bodyGroup] = 3;
    }
    else
    {
        m_body[Body::bodyGroup] = 4;
    }

    m_body[underBreast] = m_body[Body::height] / 3 + m_body[base_weight];

    m_body[fat] = (m_skills[Skills::strenght] + m_skills[Skills::endurance]) / 2;

    m_body[muscles_body] = (m_body[Body::weight] * m_body[fat]) / 100;

    m_body[breasts] = m_body[underBreast] + m_body[base_weight] / 2 + (m_body[weight] - m_body[muscles_body]) / 7 + m_body[silicone] - m_body[operation];

    m_body[hips] = m_body[underBreast] + m_body[base_weight] + (m_body[weight] - m_body[muscles_body]) / 7 - (m_body[base_weight] * m_body[muscles_body]) / 100;

    m_body[waist] = m_body[hips] / 3 + m_body[Body::weight] / 2 + (m_body[hips] % 3) + (m_body[weight] % 2);

    int razmer_tits = m_body[breasts] - m_body[underBreast];
    if(razmer_tits > 0 && razmer_tits < 10) { m_body[breastsSize] = 0; }
    else if(razmer_tits >= 10 && razmer_tits < 15) { m_body[breastsSize] = 1; }
    else if(razmer_tits >=15 && razmer_tits < 20) { m_body[breastsSize] = 2; }
    else if (razmer_tits >= 20 && razmer_tits < 25) { m_body[breastsSize] = 3; }
    else if (razmer_tits >= 25 && razmer_tits < 30) { m_body[breastsSize] = 4; }
    else if(razmer_tits >= 30 && razmer_tits < 35) { m_body[breastsSize] = 5; }
    else { m_body[breastsSize] = 6; }
    if (m_body[breastsSize] < 0) { m_body[breastsSize] = 0; }
    if (m_body[breastsSize] > 6) { m_body[breastsSize] = 6; }
}
