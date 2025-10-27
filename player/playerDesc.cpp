#include "player.h"
#include "../Functions.h"

QString Player::getNameDesc()
{
    return "Вас зовут <b>" + getName() + "</b>";
}

QString Player::getBirthDayDesc()
{
    return "Дата рождения: " + getBirthDate();
}

QString Player::getAgesDesc()
{
    QString vidage = intQStr(m_body[Body::vidage]);
    if(isCheatsOn())
    {
        makeLink(vidage, "vidage");
    }
    return "Вам " + intQStr(getAge()) + " " + letgoda(getAge()) +
           ", на вид вам можно дать не больше " + vidage +
           " " + letgoda2(m_body[Body::vidage]);
}

QString Player::getHeightDesc()
{
    QString heightStr = intQStr(m_body[Body::height]);
    QString weightStr = intQStr(m_body[Body::weight]);

    if (isCheatsOn()) {
        makeLink(heightStr, "height");
        makeLink(weightStr, "weight");
    }

    return "Рост " + heightStr + " см, вес " + weightStr;
}

QString Player::getBreastsDesc()
{
    return intQStr(m_body[Body::breasts]) + " - " + intQStr(m_body[waist]) + " - "
           + intQStr(m_body[hips]) + ", размер груди: " + intQStr(m_body[breastsSize]);
}

QString Player::getLipsDesc()
{
    if(m_body[Body::lip] > 4) { m_body[Body::lip] = 4; }
    if(m_body[Body::lip] < 0) { m_body[Body::lip] = 0; }
    QString piercingAstr;
    if(m_body[Body::piercingA] != 0) { piercingAstr = "Иногда при разговоре у вас во рту заметен пирсинг языка."; }
    QString piercingBstr;
    if(m_body[Body::piercingB] != 0) { piercingBstr = "Нижняя губа проколота и в неё вдето кольцо."; }

    QString almstat;
    if (m_body[Body::lipbalmstat] > 0)
    {
        switch (m_body[Body::lip]) {
        case 0:
            almstat = "блестящие от бальзама";
            break;
        case 1:
            almstat = "блестящие от бальзама";
            break;
        case 2:
            almstat = "блестящие и сочные от бальзама";
            break;
        case 3:
            almstat = "сочные";
            break;
        case 4:
            almstat = "лоснящиеся";
            break;
        default:
            break;
        }
    }
    else { almstat = ""; }

    QString result;

    switch(m_body[Body::lip])
    {
    case 0:
        result += "У вас тонкие " + almstat + " губы. " + piercingBstr + piercingAstr;
        break;
    case 1:
        result += "У вас нормальные " + almstat + " губы. " + piercingBstr + piercingAstr;
        break;
    case 2:
        result += "У вас пухленькие " + almstat + " губы. " + piercingBstr + piercingAstr;
        break;
    case 3:
        result += "У вас крупные, " + almstat + " пухлые губы. " + piercingBstr + piercingAstr;
        break;
    case 4:
        result += "У вас толстые и огромные " + almstat + " губы. " + piercingBstr + piercingAstr;
        break;
    default:
        break;
    }
    if (isCheatsOn())
    {
        makeLink(result, "lips");
    }
    return result;
}

QString Player::getThroatDesc()
{
    QString res;
    if (m_body[Body::throat] == 0)
    {
        res += "У вас целомудренный ротик.";
    }
    else if (m_body[Body::throat] > 0 && m_body[Body::throat] <= 5)
    {
        res += "У вас неопытный ротик.";
    }
    else if (m_body[Body::throat] > 5 && m_body[Body::throat] <= 10)
    {
        res += "У вас рабочий ротик и чувствительное горло.";
    }
    else if (m_body[Body::throat] > 10 && m_body[Body::throat] <= 15)
    {
        res += "У вас опытный рот и слегка растянутое горло.";
    }
    else if (m_body[Body::throat] > 15 && m_body[Body::throat] <= 25)
    {
        res += "У вас вместительный рот и тренированное горло.";
    }
    else if (m_body[Body::throat] > 25 && m_body[Body::throat] <= 35)
    {
        res += "У вас глубокое горло привыкщее к минету.";
    }
    else
    {
        res += "У вас рот и горло опытной проститутки.";
    }
    if (isCheatsOn())
    {
        makeLink(res, "throat");
    }

    return res;
}

QString Player::getVaginaDesc()
{
    int val = m_body[Body::vagina];
    QString res;
    if (val == 0)
    {
        res += "У вас девственная плева.";
    }
    else if (val > 0 && val <= 5)
    {
        res += "У вас очень узенькая киска.";
    }
    else if (val > 5 && val <= 10)
    {
        res += "У вас тесная, похожая на щель вагина.";
    }
    else if (val > 10 && val <= 15)
    {
        res += "У вас тугая, но эластичная киска.";
    }
    else if (val > 15 && val <= 25)
    {
        res += "У вас разработанная вагина.";
    }
    else if (val > 25 && val <= 35)
    {
        res += "У вас хорошо разработанная вагина.";
    }
    else
    {
        res += "У вас рабочая, как у проститутки, вагина.";
    }
    if (isCheatsOn())
    {
        makeLink(res, "vagina");
    }
    return res;
}

QString Player::getAnusDesc()
{
    QString res;
    if (m_body[Body::anus] == 0)
    {
        res += "У вас девственный анус";
    }
    else if (m_body[Body::anus] > 0 && m_body[Body::anus] <= 5)
    {
        res += "У вас анус выглядит как крохотная щёлочка.";
    }
    else if (m_body[Body::anus] > 5 && m_body[Body::anus] <= 10)
    {
        res += "У вас анус имеет форму звёздочки";
    }
    else if (m_body[Body::anus] > 10 && m_body[Body::anus] <= 15)
    {
        res += "У вас анус выглядит как щель";
    }
    else if (m_body[Body::anus] > 15 && m_body[Body::anus] <= 25)
    {
        res += "У вас анус выглядит как дупло";
    }
    else if (m_body[Body::anus] > 25 && m_body[Body::anus] <= 35)
    {
        res += "У вас очко не закрывается, выглядит как дупло.";
    }
    else
    {
        res += "У вас рабочая, как у проститутки, раздолбанная и красная дырень.";
    }
    if (isCheatsOn())
    {
        makeLink(res, "anus");
    }
    return res;
}

QString Player::getBodyDesc()
{
    int x = m_skills[Skills::strenght] + m_skills[Skills::endurance];
    QString result;
    switch (m_body[Body::bodyGroup])
    {
    case 0:
    {
        if (x >= 50)
        {
            result = "Вы очень тонкая девушка, с маленькой мягкой попой и у вас еле заметны мышцы.";
        }
        else
        {
            result = "Вы очень тонкая девушка, с маленькой мягкой попой и у вас еле заметны мышцы.";
        }
    }
    break;
    case 1:
    {
        if (x < 50)
        {
            result = "Вы стройная девушка.";
        }
        else if (x > 50 && x < 100)
        {
            result = "Вы стройная девушка с отчётливо заметными мышцами.";
        }
        else
        {
            result = "Вы спортивная девушка с поджарой мускулистой фигурой.";
        }
    }
    break;
    case 2:
    {
        if (x >= 50)
        {
            result = "Вы формастая девушка, весьма пухленькая.";
        }
        else
        {
            result = "Вы формастая девушка.";
        }
    }
    break;
    case 3:
    {
        if (x >= 50)
        {
            result = "Вы жирноватая девушка, ваши мышцы заплыли жиром.";
        }
        else
        {
            result = "Вы жирноватая девушка, ваши мышцы заплыли жиром.";
        }
    }
    break;
    case 4:
    {
        if (x >= 50)
        {
            result = "Вы жирная девушка, ваши мышцы давно заплыли жиром.";
        }
        else
        {
            result = "Вы жирная девушка.";
        }
    }
    break;
    }
    return result;
}

QString Player::getBodyTypeFigureDesc()
{
    int ideal_body_breasts = m_body[waist] * 100 / m_body[breasts];
    int ideal_body_hips = m_body[waist] * 100 / m_body[hips];
    int fashion_model_body = std::abs(m_body[breasts] - ideal_body_breasts) + std::abs(m_body[hips] - ideal_body_hips);

    QString body_type_figure;
    if(fashion_model_body > 7)
    {
        body_type_figure = "ужасная и нескладная";
    }
    else if (fashion_model_body == 7)
    {
        body_type_figure = "нескладная";
    }
    else if (fashion_model_body == 6)
    {
        body_type_figure = "ничего, но нужно лучше";
    }
    else if (fashion_model_body == 5)
    {
        body_type_figure = "красивая, но можно лучше";
    }
    else if (fashion_model_body == 4)
    {
        body_type_figure = "красивая, но можно лучше";
    }
    else if (fashion_model_body == 3)
    {
        body_type_figure = "красивая и модельная.";
    }
    else if (fashion_model_body == 2)
    {
        body_type_figure = "идеальная и красивая.";
    }
    else if (fashion_model_body < 2)
    {
        body_type_figure = "идеальная и красивая.";
    }
    return "Ваша фигура " + body_type_figure;
}

QString Player::getHairDesc()
{
    if(m_body[Body::hairLength] == 3)
    {
        m_body[Body::hairStatus] = 1;
        m_body[Body::hairCurly] = 0;
    }
    if(!m_settings->isHapri())
    {
        m_body[Body::hairStatus] = 1;
    }

    QString hairStatus;
    if (m_body[Body::hairStatus] == 0) { hairStatus = "спутавшиеся "; }
    else { hairStatus = "аккуратно уложенные "; }

    QString hairColor;
    switch (m_body[Body::hairColor]) {
    case 0:
        hairColor = "чёрные";
        break;
    case 1:
        hairColor = "русые";
        break;
    case 2:
        hairColor = "рыжие";
        break;
    case 3:
        hairColor = "светлые";
        break;
    default:
        hairColor = "чёрные";
        break;
    }

    QString hairCurly;
    if (m_body[Body::hairCurly] == 0)
    {
        hairCurly = "прямые";
    }
    else
    {
        hairCurly = "кудрявые";
    }

    QString hairLength;
    switch (m_body[Body::hairLength]) {
    case 0:
        hairLength = "длинные";
        break;
    case 1:
        hairLength = "средней длинны";
        break;
    case 2:
        hairLength = "короткие";
        break;
    case 3:
        hairLength = "очень короткие";
        break;
    default:
        hairLength = "ошибка hairLength";
        break;
    }

    QString hairDesc = "У Вас ";
    if (m_body[Body::hairLength] < 3)
    {
        hairDesc += hairStatus + " ";
    }

    if (isCheatsOn()) { makeLink(hairLength, "hairLength"); }

    hairDesc += hairLength + " ";

    if (m_body[Body::hairLength] < 2)
    {
        if (isCheatsOn()) { makeLink(hairCurly, "hairCurly"); }
        hairDesc += hairCurly + " ";
    }
    if (isCheatsOn()) { makeLink(hairColor, "hairColor"); }
    hairDesc += hairColor + " волосы.";

    return hairDesc;
}

QString Player::getPubisDesc()
{
    int g = m_body[Body::piercingG];
    int gl = m_body[Body::piercingGL];
    int lobok = m_body[Body::pubisHair];

    QString piercingGstr;
    if(g == 1 && gl == 0)
    {
        piercingGstr = " На половых губах висят колечки.";
    }
    else if (g == 0 && gl == 1)
    {
        piercingGstr = " В клитор вставлена штанга.";
    }
    else if (g == 1 && gl == 1)
    {
        piercingGstr = " У вас проколот клитор и в половые губы вставлены колечки.";
    }
    else { piercingGstr = ""; }

    QString tmp;
    if(lobok <= 0) { tmp = "У вас гладкий, выбритый лобок."; }
    else if (lobok > 0 && lobok <= 2) { tmp = "У вас небольшая щетина на лобке."; }
    else { tmp = "У вас волосатый лобок."; }

    if (isCheatsOn()) { makeLink(tmp, "pubisHair"); }
    return tmp + piercingGstr;
}

QString Player::getSkinDesc()
{
    QString piercingCstr, piercingDstr, piercingEstr;
    if(m_body[Body::piercingC] != 0) { piercingCstr = "В ушах болтаются серёжки."; }
    if(m_body[Body::piercingD] != 0) { piercingDstr = "В ваш нос вставлено кольцо."; }
    if(m_body[Body::piercingE] != 0) { piercingEstr = "Ваша бровь проколота и туда вставлена штанга."; }

    if(m_body[Body::skin] > 4) { m_body[Body::skin] = 4; }
    if(m_body[Body::skin] < 0) { m_body[Body::skin] = 0; }

    int Bodykin = m_body[Body::skin];
    int tanVal = m_body[Body::skinTan];

    QString tan;
    if(tanVal == 0) { tan = "бледная"; }
    else if (tanVal > 0 && tanVal <= 30) { tan = "слегка загорелая"; }
    else if (tanVal > 30 && tanVal <= 100) { tan = "загорелая"; }
    else if (tanVal > 100) { tan = "смуглая от загара"; }

    QString skinTemp;
    switch (m_body[Body::skin]) {
    case 0:
        skinTemp = "кожа неровная и покрыта прыщами и чёрными точками";
        break;
    case 1:
        skinTemp = "кожа неровная и кое-где заметны прыщики";
        break;
    case 2:
        skinTemp = "кожа неровная, но прыщей не видно";
        break;
    case 3:
        skinTemp = "гладкая и ухоженная кожа";
        break;
    case 4:
        skinTemp = "гладкая как стекло и шелковистая даже на вид кожа";
        break;
    default:
        break;
    }

    QString result;
    if(Bodykin < 3) { result = "Ваша "; }
    else { result = "У вас "; }

    if (isCheatsOn()) {
        makeLink(tan, "skinTan");
        makeLink(skinTemp, "skin");
    }
    return result + " " + skinTemp + piercingCstr + piercingDstr + piercingEstr;
}

QString Player::getEyeDesc()
{
    if(m_body[Body::eyeSize] > 3) { m_body[Body::eyeSize] = 3; }

    QString eyeSizeStr, eyeColorStr, eyeLashesStr, eyeBrowsStr, glassStr, eyeLens;

    switch (m_body[Body::eyeSize]) {
    case 0:
        eyeSizeStr = "маленькие";
        break;
    case 1:
        eyeSizeStr = "выразительные";
        break;
    case 2:
        eyeSizeStr = "большие";
        break;
    case 3:
        eyeSizeStr = "огромные";
        break;
    default:
        break;
    }

    switch (m_body[Body::eyeColor]) {
    case 0:
        eyeColorStr = "карие ";
        break;
    case 1:
        eyeColorStr = "серые ";
        break;
    case 2:
        eyeColorStr = "зеленые ";
        break;
    case 3:
        eyeColorStr = "голубые ";
        break;
    default:
        break;
    }

    if(m_body[Body::eyeLashes] > 2) { m_body[Body::eyeLashes] = 2; }
    switch (m_body[Body::eyeLashes]) {
    case 0:
        eyeLashesStr = "с короткими ресницами";
        break;
    case 1:
        eyeLashesStr = "с нормальной длинны ресницами";
        break;
    case 2:
        eyeLashesStr = "с длинными ресницами";
        break;
    default:
        break;
    }

    if(m_body[Body::eyeBrows] < 0)
    {
        eyeBrowsStr = "перманентный татуаж бровей.";
    }
    else if(m_body[Body::eyeBrows] >= 0 && m_body[Body::eyeBrows] < 10)
    {
        eyeBrowsStr= "немного неаккуратные брови.";
    }
    else { eyeBrowsStr = "ухоженные брови."; }

    if(m_body[Body::glass] > 0)
    {
        glassStr = " Вы носите ";
        switch (m_body[Body::glass]) {
        case 0:
            glassStr += "";
            break;
        case 1:
            glassStr += "дурацкие гадские очки в дешёвой оправе";
            break;
        case 2:
            glassStr += "неплохие очки";
            break;
        case 3:
            glassStr += "дорогие модные очки";
            break;
        default:
            break;
        }
        if (isCheatsOn()) { makeLink(glassStr, "glass"); }
    }

    if (isCheatsOn())
    {
        makeLink(eyeSizeStr, "eyeSize");
        makeLink(eyeColorStr, "eyeColor");
        makeLink(eyeLashesStr, "eyeLashes");
        makeLink(eyeBrowsStr, "eyeBrows");
    }


    if(m_body[Body::colorfulLenses] > 0)
    {
        if(m_body[Body::glass] > 0)
        {
            eyeLens = "и ";
        }
        else
        {
            eyeLens += "Вы носите ";
        }
        eyeLens += "стильные цветные контактные линзы без диоптрий.";
    }

    return "У вас " + eyeSizeStr + " " + eyeColorStr + " глаза, " + eyeLashesStr + "и " + eyeBrowsStr + glassStr + eyeLens;
}

QString Player::getMakeupDesc()
{
    QString result;
    switch (m_body[Body::makeup]) {
    case 0:
        result = "<font color = red>У вас потёк макияж</font>";
        break;
    case 1:
        result = "У вас нет макияжа";
        break;
    case 2:
        result = "У вас легкий макияж";
        break;
    case 3:
        result = "У вас нормальный макияж";
        break;
    case 4:
        result = "У вас яркий, вызывающий макияж";
        break;
    default:
        break;
    }
    if (isCheatsOn())
    {
        makeLink(result, "makeup");
    }
    return result;
}

QString Player::getLegsDesc()
{
    QString result;
    int val = m_body[Body::legHair];

    if(val <= 0) { result += "У вас гладкие ноги."; }
    else if(val > 0 && val <= 2) { result += "У вас не видимая глазу, но шершавая на ощупь щетина на ногах."; }
    else if(val > 3 && val <= 5) { result += "У вас отчётливо видимые тонкие волосики на ногах."; }
    else { result += "У вас длинные выделяющиеся волосы на ногах."; }

    if (isCheatsOn())
    {
        makeLink(result, "legHair");
    }

    return result;
}

QString Player::getShamelessDesc()
{
    QString desc;
    switch (m_status[Status::shamelessFlag]) {
    case 0:
        desc = "Вы совершенно не развратны. Любое эротическое событие заставляет вас краснеть.";
        break;
    case 1:
        desc = "Вы совершенно не развратны. Любое эротическое событие заставляет вас краснеть.";
        break;
    case 2:
        desc = "Вы потряли всякий стыд.";
        break;
    case 3:
        desc = "Вы максимально развратны и готовы учавствовать в любых извращениях.";
        break;
    default:
        break;
    }
    return desc;
}

QString Player::getVneshDesc()
{
    QString str;
    if (m_status[vnesh] == -10) { str = "У вас заметны признаки венерического заболевания. Поэтому парни разбегаются в ужасе."; }
    if (m_status[vnesh] >= 0 && m_status[vnesh] < 20) { str = "У вас страшная внешность. Парни от вас шарахаются."; }
    if (m_status[vnesh] >= 20 && m_status[vnesh] < 40) { str = "У вас серенькая внешность. Парни практически вас не замечают."; }
    if (m_status[vnesh] >= 40 && m_status[vnesh] < 60) { str = "У вас симпатичная внешность. Парни частенько обращают на вас внимание."; }
    if (m_status[vnesh] >= 60 && m_status[vnesh] < 80) { str = "У вас сногсшибательная внешность. Парни постоянно оборачиваются видя вас."; }
    if (m_status[vnesh] >= 80) { str = "У вас сногсшибательная внешность. Парни постоянно оборачиваются видя вас."; }
    return str;
}
