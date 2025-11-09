#include "overlaystatus.h"
#include "mainwindow.h"
#include "nav/cloth.h"
#include <QLabel>
#include "Functions.h"

OverlayStatus::OverlayStatus(QWidget * ptr)
{
    root = ptr;
    m_styleSheet = "text-decoration: none; color: black; width: 50px; height: 50px; background: #fff; border-radius: 12px; border: 1px solid #aaa;";
}

void OverlayStatus::setParentWidget(QWidget *ptr)
{
    m_parent = ptr;
    m_layout = new QVBoxLayout(m_parent);
    m_layout->setAlignment(Qt::AlignTop);
    m_layout->setSpacing(5);
}

QLabel *OverlayStatus::genStatusWidget(QString imgLink, QString desc)
{
    QLabel* lbl = new QLabel;
    lbl->setScaledContents(true);
    lbl->setFixedSize(55,55);
    lbl->setPixmap(imgLink);
    lbl->setToolTip(desc);
    lbl->setStyleSheet(m_styleSheet);
    lbl->setAlignment(Qt::AlignCenter);
    return lbl;
}

void OverlayStatus::genOverlay()
{
    ClearLayout(m_layout);
    grabStatusVector();
    for (int i = statusNotif::ind_makeup; i < statusNotif::ind_bell; ++i)
    {
        statusNotif val = static_cast<statusNotif>(i);
        if(!m_statuses[val].isEmpty())
        {
            m_layout->addWidget(genStatusWidget(":/img/icons/statuses/" + m_statusesImg[val] + ".png", m_statuses[val]));
        }
    }
}

void OverlayStatus::grabStatusVector()
{
    m_statuses.clear();
    m_statusesImg.clear();
// 1. потек макияж/насыщенность макияжа
    grabInd_makeup();
//	!-- Натёртость вагины и/или ануса
    grabInd_Rub();
//	!-- Болит влагалище и/или анус из-за секса + натёртость
    grabInd_Pain();
//соски
    grabInd_Pin();
//жопа
    grabIndAss();
//ноги
    grabInd_depilation();

    grabInd_Sweat();
//Вывод иконок по типу одежды
    grabInd_dress();
//ind_wday
    grabInd_Wday();
//ind_pregnancy
    grabInd_pregnancy();
//ind_mouthsmell
    grabInd_MouthSmell();
//ind_cum & ind_sperma
    grabInd_Cum();
//11 Частичная или полная обнажёнка
//   Состояние вагинынальных выделений с трусами и без
    grabInd_dampness();
//ind_toy
    grabInd_Toy();
//ind_remedy
    grabInd_Remedy();
//ind_books
    grabInd_Books();
//ind_drunk
    grabInd_Drunk();
//ind_frost
    grabInd_Frost();
//ind_addict
    grabInd_Addict();
//ind_basket_full
    grabInd_Basket_Full();
//ind_debt
    grabInd_Debt();
//ind_work
    //...
//ind_info
    //...
//ind_vagina_estrus
    grabInd_Vagina_Estrus();
//ind_vagina_issues
    grabInd_Vagina_Issues();
//ind_rose
    //...
//ind_PillsAndCondoms
    grabInd_PillsAndCondoms();
//ind_hangover
    granInd_hangover();
//ind_closed_door
    //...
//ind_tryst_house
    //...
//ind_christmas
    grabInd_Christmas();
//ind_no_alcohol
    //...
//ind_bad_sex
    //...
//ind_gel_rubbing
    //...
//ind_bell
    //...
}

void OverlayStatus::grabInd_makeup()
{
    m_statusesImg[ind_makeup] = "makeup" + intQStr(getVBody(makeup));
    m_statuses[ind_makeup] = "<p style='color: #000000'>" + ((MainWindow*)root)->m_player->getMakeupDesc() + "</p>";
}

void OverlayStatus::grabInd_Pain()
{
    QString tmpV[] {
        " ",
        "У вас немного болит влагалище.",
        "У вас болит влагалище и вы с трудом можете свести ноги вместе.",
        "У вас сильно болит влагалище, вы даже с трудом ходите, при этом стараясь пошире расставлять ноги."
    };
    QString tmpA[] {
        "У вас немного болит и чешется анус.",
        "У вас болит анус.",
        "У вас сильно болит и кровоточит анус."
    };
    m_statuses[ind_pain] = "";
    int vgape = getVSex(stat_vgape);
    int agape = getVSex(stat_agape);
    if (vgape > 0)
    {
        m_statuses[ind_pain] += tmpV[vgape - 1] + "<br>";
    }
    if(agape > 0)
    {
        m_statuses[ind_pain] += tmpA[agape - 1];
    }
    m_statusesImg[ind_pain] = "pain";
}

void OverlayStatus::grabInd_Rub()
{
    m_statusesImg[ind_rub] = "broken_heart";
    QString vag[]{
        "Слегка натертая киска вызывает почти неуловимую боль во время секса",
        "Ваша киска натерта, боль довольно сильная и секс не доставляет удовольствия",
        "Вы сильно натерли свою вагину, во время секса вы ощущаете сильную боль",
        "Вы уже так натерли пизду, что больно не только при сексе, но и во время ходьбы",
        "У вас между ног словно раскаленный шест, который делает любое движение болезненным"
    };
    QString anal[] {
        "У вас лёгкая натертость ануса, но это терпимо",
        "Из-за натертости ануса секс доставляет боль",
        "Вы натерли попу так, что даже присесть не можете без боли",
        "Ваше очко серьёзно натерто и невыносимо болит",
        "Ваше очко натерто в кровь, а боль такая, что хочется умереть."
    };
    int _tmpv = ((MainWindow*)root)->m_ccsex.calc_rubb("vagina");
    int _tmpa = ((MainWindow*)root)->m_ccsex.calc_rubb("anus");
    if(_tmpv != 0 || _tmpa != 0)
    {
        m_statuses[ind_rub] = "Вы пострадали из-за любви к сексу<br>";
    }
    if(_tmpv != 0)
    {
        m_statuses[ind_rub] += vag[_tmpv];
    }
    if(_tmpv != 0 && _tmpa != 0)
    {
        m_statuses[ind_rub] += "<br>";
    }
    if(_tmpa != 0)
    {
        m_statuses[ind_rub] += anal[_tmpa];
    }
}

void OverlayStatus::grabInd_Pin()
{
    m_statuses[ind_pin] = "";
    m_statusesImg[ind_pin] = "pin";
    int nip = getVSex(nippain);
    int pub = getVSex(painpub);
    int pirc = getVSex(pirs_pain_ton);
    if(nip > 0)
    {
        if(nip < 5) { m_statuses[ind_pin] += "У вас немного болят соски.<br>"; }
        else {m_statuses[ind_pin] += "У вас сильно болят соски.<br>";}
    }
    if(pub > 0)
    {
        if(pub < 5) { m_statuses[ind_pin] += "У вас немного болит влагалище.<br>"; }
        else { m_statuses[ind_pin] += "У вас сильно болит влагалище.<br>"; }
    }
    if(pirc > 0)
    {
        if(pirc > 2) { m_statuses[ind_pin] += "У вас болит язык, он сильно опух и едва ворочается во рту."; }
        if(pirc == 1) { m_statuses[ind_pin] += "У вас ноет язык и он немного припухший"; }
        if(pirc == 2) { m_statuses[ind_pin] += "У вас сильно ноет язык и он заметно припухший.";}
    }
}

void OverlayStatus::grabIndAss()
{
    if(getVSex(spanked) > 0)
    {
        m_statusesImg[ind_ass] = "ass";
        if(getVSex(spanked)/25 == 0)
        {
            m_statuses[ind_ass] = "Ваши ягодицы немного покраснели от шлепков и грубых прикосновений и побаливают.";
        }
        else if(getVSex(spanked)/25 <= 2)
        {
            m_statuses[ind_ass] = "Ваши ягодицы горят огнём, на них отчётливо видны полосы.";
        }
        else
        {
            m_statuses[ind_ass] = "Ваша бедная задница нещадно болит, на ней видны ярко красные рубцы от ударов, местами переходящие в синяки.";
        }
    }
}

void OverlayStatus::grabInd_depilation()
{
    if(getVBody(Body::legHair) > 0)
    {
        m_statusesImg[ind_depilation] = "depilation";
        m_statuses[ind_depilation] = ((MainWindow*)root)->m_player->getLegsDesc();
    }
}

void OverlayStatus::grabInd_Sweat()
{
    int val = getVStatus(Status::sweat);
    if(val > 0)
    {
        if(val == 1)
        {
            m_statuses[ind_sweat] = "Вы вспотели.";
        }
        else if(val == 2)
        {
            m_statuses[ind_sweat] = "От вас немного пахнет.";
        }
        else if(val == 3)
        {
            m_statuses[ind_sweat] = "От вас разит потом.";
        }
        else
        {
            m_statuses[ind_sweat] = "От вас разит как от бомжихи.";
        }
        m_statusesImg[ind_sweat] = "sweat" + intQStr(val);
    }
}

void OverlayStatus::grabInd_Wday()
{
    if (((MainWindow*)root)->m_reproductSys.isMesec() && !((MainWindow*)root)->m_reproductSys.isPregnancy())
    {
        if (getVStatus(isprok) == 0)
        {
            m_statuses[ind_wday] = "У вас течёт кровь между ног, срочно нужна прокладка.";
            m_statusesImg[ind_wday] = "wday0";
        }
        else
        {
            m_statuses[ind_wday] = "У вас месячные, но прокладка вас защищает.";
            m_statusesImg[ind_wday] = "wday1";
        }
    }    
}

void OverlayStatus::grabInd_pregnancy()
{
    int preg = ((MainWindow*)root)->m_reproductSys.getPregValue();
    if (preg != 0 && getVStatus(pregnancyKnow) == 1 && preg < 280)
    {
        m_statuses[ind_pregnancy] = "Вы беременны " + intQStr(preg) + " дней, до родов осталось " + intQStr(280 - preg) + " дней.";
        m_statusesImg[ind_pregnancy] = "pregnancy";
    }
    else if (preg == 280)
    {
        m_statuses[ind_pregnancy] = "У ВАС НАЧАЛИСЬ СХВАТКИ. ВАМ СРОЧНО НАДО В РОДДОМ!";
        m_statusesImg[ind_pregnancy] = "pregnancy";
    }
    
    
}

void OverlayStatus::grabInd_MouthSmell()
{
    if (getVStatus(cumLips) > 0)
    {
        m_statuses[ind_mouthsmell] = "Из вашего рта пахнет спермой.";
        m_statusesImg[ind_mouthsmell] = "mouthsmell";
    }
    
}

void OverlayStatus::grabInd_Cum()
{
    m_statuses[ind_cum] = "";
    m_statuses[ind_sperma] = "";
    m_statusesImg[ind_cum] = "cum";
    m_statusesImg[ind_sperma] = "sperma";
    if (getVStatus(cumFace) > 0)
    {
        m_statuses[ind_cum] += "Ваше лицо и волосы измазаны в сперме.<br>";
    }
    if (getVStatus(cumFrot) > 0)
    {
        m_statuses[ind_cum] += "У вас на одежде пятно спермы.<br>";
    }
    if (getVStatus(cumBelly) > 0)
    {
        m_statuses[ind_cum] += "Ваш живот перемазан в сперме.<br>";
    }
    if (getVStatus(cumAss) > 0)
    {
        m_statuses[ind_cum] += "Ваша попа перемазана в сперме.<br>";
    }
    if (getVStatus(cumAnus) > 0)
    {
        m_statuses[ind_cum] += "Из вашей попки медленно вытекает сперма.<br>";
    }
    if (getVStatus(cumPussy) > 0)
    {
        m_statuses[ind_sperma] = "Из вашей киски медленно вытекает сперма.<br>";
    }
}

void OverlayStatus::grabInd_Toy()
{
    m_statuses[ind_toy] = "";
    m_statusesImg[ind_toy] = "toy";
    if (getVSex(analplugIN) > 0)
    {
        m_statuses[ind_toy] += "У вас в попу вставлена анальная пробка.<br>";
    }
    if (getVSex(vibratorIN) > 0)
    {
        m_statuses[ind_toy] += "У вас во влагалище работает вибратор.";
    }
}

void OverlayStatus::grabInd_Remedy()
{
    m_statuses[ind_remedy] = "";
    int sickStatus = getVSick(sick);
    int crazyStatus = getVSick(crazy);
    if (sickStatus > 0)
    {
        m_statusesImg[ind_remedy] = "remedy";
        if (sickStatus == 1)
        {
            m_statuses[ind_remedy] += "Вам что-то нехорошо, першит в горле и немного течёт из носа.<br>";
        }
        else if (sickStatus > 1 && sickStatus < 24)
        {
            m_statuses[ind_remedy] += "Вас знобит. У вас течёт из носа и саднит горло, вы покашливаете и чихаете - похоже, вы простыли.<br>";
        }
        else if (sickStatus >= 24 && sickStatus < 48)
        {
            m_statuses[ind_remedy] += "У вас поднялась температура. Вы постоянно кашляете и чихаете - похоже, вы простудились.<br>";
        }
        else if (sickStatus >= 48 && sickStatus < 72)
        {
            m_statuses[ind_remedy] += "У вас сильный жар. Может быть, это грипп.<br>";
        }
        else if (sickStatus > 72)
        {
            m_statuses[ind_remedy] += "Вы мечетесь в жару. Вы тяжело с надрывом кашляете - похоже, вы серьезно больны. Может быть, это ангина.<br>";
        }
    }

    if (crazyStatus > 0)
    {
        m_statusesImg[ind_remedy] = "remedy";
        if (crazyStatus >= 4 && crazyStatus < 7)
        {
            m_statuses[ind_remedy] += "Вы подавлены. Надо что-то в жизни менять.";
        }
        else if (crazyStatus >= 7 && crazyStatus <= 10)
        {
            m_statuses[ind_remedy] += "У вас депрессия. До добра это не доведёт, надо к врачу.";
        }
        else if (crazyStatus > 10)
        {
            m_statuses[ind_remedy] += "Ваша депрессия затянулась, еще немного - и суицид неизбежен!";
        }
    }
    
    
}

void OverlayStatus::grabInd_Books()
{
    if (getVStatus(nerdism) > 0)
    {
        int j = getVStatus(nerdism) / 20 + 1;
        if (j < 2) j = 2;
        if (j > 5) j = 5;
        
        if (j == 2)
        {
            m_statuses[ind_books] = "Вы жутко хотите хоть что-нибудь почитать!!!";
        }
        else if (j == 3)
        {
            m_statuses[ind_books] = "Вам очень хочется что-нибудь почитать.";
        }
        else if (j == 4)
        {
            m_statuses[ind_books] = "Вам немного скучно и хочется опять погрузится в книги.";
        }
        else if (j == 5)
        {
            m_statuses[ind_books] = "Вы погружены в свои фантазии после прочтения книги.";
        }               
        m_statusesImg[ind_books] = "books" + intQStr(j -2);
    }
    
}

void OverlayStatus::grabInd_Drunk()
{
    int alkoVal = getVAddict(alko);
    if (alkoVal > 0)
    {
        if (alkoVal < 3)
        {
            m_statuses[ind_drunk] = "Вы немного выпивши." + intQStr(alkoVal);
        }
        else if (alkoVal <= 3 && alkoVal < 6)
        {
            m_statuses[ind_drunk] = "Вы пьяны." + intQStr(alkoVal);
        }
        else
        {
            m_statuses[ind_drunk] = "Вы в стельку пьяны." + intQStr(alkoVal);
        }
        
        m_statusesImg[ind_drunk] = "drunk";
    }
    
}

void OverlayStatus::grabInd_Frost()
{
    int frostVal = getVStatus(frost);
    if (frostVal > 0)
    {
        if (frostVal <= 5)
        {
            m_statuses[ind_frost] = "Вам немного холодно.";
        }
        else if (frostVal > 5 && frostVal <= 10)
        {
            m_statuses[ind_frost] = "Вы замёрзли.";
        }
        else
        {
            m_statuses[ind_frost] = "Вы очень замёрзли.";
        }
        m_statusesImg[ind_frost] = "frost";
    }
    
}

void OverlayStatus::grabInd_Addict()
{
    int drug_eff = getVAddict(drugEffect);
    int drug_st = getVAddict(drugStatus);

    if (drug_st > 0)
    {
        if (drug_st > 75)
        {
            if (drug_eff == 0)
            {
                m_statuses[ind_addict] = "Вы под кайфом и чувствуете себя окрыленно.<br>";
            }
            else
            {
                m_statuses[ind_addict] = "Вы под кайфом, но ощущения не очень.<br>";
            }
            
        }
        else if ((drug_st > 50 && drug_st <= 75) || (drug_st > 0 && drug_st <= 25))
        {
            m_statuses[ind_addict] = "Вы чувствуете себя нехорошо после приема наркотиков.<br>";
        }
        else if (drug_st > 25 && drug_st <= 50)
        {
            m_statuses[ind_addict] = "У вас очень плохое самочуствие после приема наркотиков.<br>";
        }
        m_statusesImg[ind_addict] = "addict";
    }
    else
    {
        m_statuses[ind_addict] = "";
    }
}

void OverlayStatus::grabInd_Basket_Full()
{
    int bilberryVal = getVStatus(bilberry);
    int boletusVal = getVStatus(boletus);
    if (bilberryVal + boletusVal >= 10)
    {
        m_statusesImg[ind_basket_full] = "basket_full";
        m_statuses[ind_basket_full] = "У вас полная корзина, больше в неё ничего не влазит. В ней <b>" + intQStr(boletusVal) + "</b> кг грибов и <b>" + intQStr(bilberryVal) + "</b> кг ягод.";
    }
    else
    {
        m_statusesImg[ind_basket_full] = "basket";
        if (boletusVal > 0 && bilberryVal == 0)
        {
            "У вас в корзинке <b>" + intQStr(boletusVal) + "</b> кг грибов.";
        }
        if (boletusVal == 0 && bilberryVal > 0)
        {
            "У вас в корзинке <b>" + intQStr(bilberryVal) + "</b> кг ягод.";
        }
        if (boletusVal > 0 && bilberryVal > 0)
        {
            "У вас в корзинке <b>" + intQStr(boletusVal) + "</b> кг грибов и <b>" + intQStr(bilberryVal) + "</b> кг ягод.";
        }
    }
    
}

void OverlayStatus::grabInd_Debt()
{
    int debt = getVStatus(house_debt);
    if (debt > 0)
    {
        m_statuses[ind_debt] = "У вас задолженность за квартиру " + intQStr(debt) + " рублей.";
        m_statusesImg[ind_debt] = "debt";
    }
    
}

void OverlayStatus::grabInd_Vagina_Estrus()
{
    if (((MainWindow*)root)->m_reproductSys.isEstrus())
    {
        m_statuses[ind_vagina_estrus] = "У вас <b><i>''''течка''''</i></b> - киска приятно ноет, но можно и залететь.";
        m_statusesImg[ind_vagina_estrus] = "vagina_estrus";
    }
}

void OverlayStatus::grabInd_Vagina_Issues()
{
    QString _qstr = "";
    QString _tmpstrvenera = "<font size=4><b>У вас венерическое заболевание!</b><font>";
    int gerpesVal = getVSick(Gerpes);
    int sifVal = getVSick(Sifilis);
    int tripVal = getVSick(Triper);
    int kandidVal = getVSick(Kandidoz);

    if (gerpesVal >= 3)
    {
        _qstr += "<br><font color = red>На ваших губах язвочки. Все признаки генитального герпеса.</font>";
    }
    if (gerpesVal >= 5 && gerpesVal < 10)
    {
        _qstr += "<br><font color = red>Ваша киска покраснела и сильно зудит. Это генитальный герпес.</font>";
    }
    if (gerpesVal >= 10)
    {
        _qstr += "<br><font color = red>На вашей киске появились язвочки. Это генитальный герпес.</font>";
    }
    if (gerpesVal >= 20)
    {
        _qstr += "<br><font color = red>Вашу жопу покрывают язвочки генитального герпеса.</font>";
    }
    if (sifVal >= 21 && sifVal < 50)
    {
        _qstr += "<b><font color = red>У вас вскочила большая, твердая болячка на губе.</font>";
    }
    if (sifVal >= 50)
    {
        _qstr += "<br><font color = red>Сифилитическая сыпь покрывает все ваше тело.</font>";
    }
    if (tripVal > 2)
    {
        _qstr += "<br><font color = red>Из влагалища выходят белые выделения и сильная резь при мочеиспускании. Так же из влагалища сильно и противно пахнет.</font>";
    }
    if (kandidVal > 30)
    {
        _qstr += "<br><font color = red>У вас молочница.</font>";
    }
    if (!_qstr.isEmpty())
    {
        m_statuses[ind_vagina_issues] = _tmpstrvenera + _qstr;
        m_statusesImg[ind_vagina_issues] = "vagina_issues";
    }
    
}

void OverlayStatus::grabInd_PillsAndCondoms()
{
    m_statuses[ind_PillsAndCondoms] = "";
    m_statusesImg[ind_PillsAndCondoms] = "pills";

    if (((MainWindow*)root)->m_bag->getQuantityof(iCondoms) > 0)
    {
        m_statusesImg[ind_PillsAndCondoms] = "condoms";
        m_statuses[ind_PillsAndCondoms] += "<font color = red><b>Презервативы</b></font> - " + intQStr(((MainWindow*)root)->m_bag->getQuantityof(iCondoms)) + " штук.<br>";
    }
    if (((MainWindow*)root)->m_bag->getQuantityof(iAntiPregPills) > 0)
    {
        m_statuses[ind_PillsAndCondoms] += "<b>Вы используете пр.зачаточные средства:</b><br><font color = red><b>Пр.зачаточные таблетки</b></font> - " + intQStr(((MainWindow*)root)->m_bag->getQuantityof(iAntiPregPills)) + " штук.<br>";
    }
}

void OverlayStatus::granInd_hangover()
{
    if(getVAddict(alko) < 3 && getVAddict(hangoverDay) != 0 && getVStatus(daystart) >= getVAddict(hangoverDay))
    {
        m_statuses[ind_hangover] = "У вас похмелье.<br>Болит голова и паршивое настроение.<br>Хочется опохмелится, но это развите алкоголизма!(" + intQStr(getVAddict(alkoholism)) + ")";
        m_statusesImg[ind_hangover] = "hangover";
    }
    else if(getVAddict(alko) < 3 && getVAddict(hangoverDay) > 0)
    {
        m_statuses[ind_hangover] = "У вас похмелье.<br>Болит голова и паршивое настроение.<br>Хочется опохмелится, но это развите алкоголизма!(" + intQStr(getVAddict(alkoholism)) + ")";
        m_statusesImg[ind_hangover] = "hangover";
    }
}

void OverlayStatus::grabInd_Christmas()
{

}

int OverlayStatus::getVStatus(Status param)
{
    return ((MainWindow*)root)->m_player->getVStatus(param);
}

int OverlayStatus::getVSick(Sickness param)
{
    return ((MainWindow*)root)->m_player->getVSick(param);
}

int OverlayStatus::getVAddict(Addiction param)
{
    return ((MainWindow*)root)->m_player->getVAddict(param);
}

int OverlayStatus::getVSex(SexVar param)
{
    return ((MainWindow*)root)->m_player->getVSexVar(param);
}

int OverlayStatus::getVBody(Body param)
{
    return ((MainWindow*)root)->m_player->getVBody(param);
}

void OverlayStatus::grabInd_dress()
{
    switch (((MainWindow*)root)->m_player->getCurClothGroup()) {
    case ClothGroup::nude:
        m_statuses[ind_dress] = "";
        break;
    case ClothGroup::towel:
        m_statuses[ind_dress] = "";
        break;
    case ClothGroup::swimsuit:
        m_statusesImg[ind_dress] = "dress_swimsuit";
        m_statuses[ind_dress] = "На вас одето<br><font size=3><font color = red><b><i>Купальник</i></b></font>'";
        break;
    case ClothGroup::sundress:
        m_statusesImg[ind_dress] = "dress_sarafan";
        m_statuses[ind_dress] = "На вас одето<br><font size=3><font color = red><b><i>Сарафан</i></b></font>'";
        break;
    case ClothGroup::schoolUniform:
        m_statusesImg[ind_dress] = "dress_scoll";
        m_statuses[ind_dress] = "На вас одето<br><font size=3><font color = red><b><i>Школьная форма</i></b></font>'";
        break;
    case ClothGroup::waitressUniform:
        m_statusesImg[ind_dress] = "dress_waitresses";
        m_statuses[ind_dress] = "На вас одето<br><font size=3><font color = red><b><i>Форма официантки</i></b></font>'";
        break;
    case ClothGroup::sportsSuit:
        m_statusesImg[ind_dress] = "dress_sports";
        m_statuses[ind_dress] = "На вас одето<br><font size=3><font color = red><b><i>Спортивный костюм</i></b></font>'";
        break;
    case ClothGroup::jeans:
        m_statusesImg[ind_dress] = "dress_jeans";
        m_statuses[ind_dress] = "На вас одето<br><font size=3><font color = red><b><i>Джинсы</i></b></font>'";
        break;
    case ClothGroup::skirt:
        m_statusesImg[ind_dress] = "dress_skirt";
        m_statuses[ind_dress] = "На вас одето<br><font size=3><font color = red><b><i>Наряд с юбкой</i></b></font>'";
        break;
    case ClothGroup::casualDress:
        m_statusesImg[ind_dress] = "dress_daily";
        m_statuses[ind_dress] = "На вас одето<br><font size=3><font color = red><b><i>Повседневное платье</i></b></font>'";
        break;
    case ClothGroup::eveningDress:
        m_statusesImg[ind_dress] = "dress_evening";
        m_statuses[ind_dress] = "На вас одето<br><font size=3><font color = red><b><i>Вечернее платье</i></b></font>'";
        break;
    case ClothGroup::officeSuit:
        m_statusesImg[ind_dress] = "dress_office";
        m_statuses[ind_dress] = "На вас одето<br><font size=3><font color = red><b><i>Офисный костюм</i></b></font>'";
        break;
    case ClothGroup::revealingOutfit:
        m_statusesImg[ind_dress] = "dress_slut";
        m_statuses[ind_dress] = "На вас одето<br><font size=3><font color = red><b><i>Откровенный наряд</i></b></font>'";
        break;
    case ClothGroup::blouseWithShorts:
        m_statusesImg[ind_dress] = "dress_briefs";
        m_statuses[ind_dress] = "На вас одето<br><font size=3><font color = red><b><i>Блузка с шортами</i></b></font>'";
        break;
    default:
        break;
    }
    if(getVStatus(Status::dirtyClothes) == 1)
    {
        m_statusesImg[ind_dress] = "dirty";
        if(getVStatus(Status::sweat) > 3)
            m_statuses[ind_dress] = "Вы с ног до головы перемазаны в грязи.";
        else
            m_statuses[ind_dress] = "У вас грязная одежда.";
    }
}

void OverlayStatus::grabInd_dampness()
{
    int tmp_dampness = ((MainWindow*)root)->m_ccsex.getVaginaDampness();

    QString vagDamp[] {
        "<b>У вас между ног сухо, как в пустыне</b>",
        "<b>У вас сухо между ног</b>",
        "<b>У вас влажно между ног</b>",
        "<b>У вас между ног немного мокро</b>",
        "<b>У вас между ног очень мокро</b>",
        "<b>У вас водопад между ног</b>"
    };
    QString pantDamp[] {
        "<b>У вас сухие трусики</b>",
        "<b>У вас чуть влажные трусики</b>",
        "<b>У вас сырые трусики</b>",
        "<b>У вас промокли трусики</b>",
        "<b>У вас мокрые трусики</b>",
        "<b>У вас грязнее трусики и смазка протекает сквозь ткань</b>"
    };

    m_statusesImg[ind_dampness] = "wet_pant" + intQStr(tmp_dampness);
    m_statuses[ind_dampness] = pantDamp[tmp_dampness];

    ClothGroup current = static_cast<ClothGroup>(((MainWindow*)root)->m_player->getCurClothGroup());
    if (current == ClothGroup::nude)
    {
        if(!((MainWindow*)root)->m_player->isPanties())
        {
            m_statusesImg[ind_nude] = "all_nude";
            m_statuses[ind_nude] = "Вы абсолютно обнажены.";
            m_statusesImg[ind_dampness] = "wet_vagin" + intQStr(tmp_dampness);
            m_statuses[ind_dampness] = vagDamp[tmp_dampness];
        }
        else
        {
            m_statuses[ind_nude] = "Вы только в трусиках и грудь раскачиваются при ходьбе.";
        }
    }
    else if(current == ClothGroup::towel)
    {
        m_statusesImg[ind_nude] = "towel";
        m_statuses[ind_nude] = "Ваше голое тело прикрывает полотенце.";
        m_statusesImg[ind_dampness] ="wet_vagin" + intQStr(tmp_dampness);
        m_statuses[ind_dampness] = vagDamp[tmp_dampness];
    }
    else if(current > ClothGroup::swimsuit)
    {
        if(!((MainWindow*)root)->m_player->isPanties())
        {
            if((current == ClothGroup::sundress || current == ClothGroup::schoolUniform || current >= ClothGroup::skirt) && getVStatus(Status::shamelessFlag) == 0)
            {
                m_statusesImg[ind_dampness] = "wet_vagin" + intQStr(tmp_dampness);
                m_statuses[ind_dampness] = "Вам стыдно, вы без трусиков.<br>" + vagDamp[tmp_dampness];
            }
            else
            {
                m_statusesImg[ind_dampness] = "wet_vagin" + intQStr(tmp_dampness);
                m_statuses[ind_dampness] = "Вы не надели трусики.<br>" + vagDamp[tmp_dampness];
            }
        }
    }
}

