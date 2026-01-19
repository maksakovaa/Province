#include "Functions.h"
#include <random>
#include <QVBoxLayout>
#include <QLabel>

int getRandInt(int min, int max)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dist(min,max);
    return dist(rng);
}

int getItemArr(int arr[], int arr_size, int id)
{
    int result {0};
    if(id < 0)
    {
        result = arr[getRandInt(0,arr_size - 1)];
    }
    else
    {
        if ((arr_size) > id)
        {
            result = arr[id];
        }
    }
    return result;
}

QString letgoda(int age)
{   
    QString result;
    int lastNum = age % 10;

    if(age == 11 || age == 12 || age == 13 || age == 14)
    {
        result = "лет";
    }
    else if(lastNum == 2 || lastNum == 3 || lastNum == 4 || lastNum % 10 == 1 && age != 11 && age != 12 && age !=13 && age !=14)
    {
        result = "года";
    }
    else if(lastNum == 5 || lastNum == 6 || lastNum == 7 || lastNum == 8 || lastNum == 9 || lastNum == 0)
    {
        result = "лет";
    }
    return result;
}

QString letgoda2(int age)
{
    if(age % 10 == 1) { return "года";}
    else { return "лет"; }
}

QString intQStr(int value)
{
    return QString::number(value);
}

void makeLink(QString& txt, const QString& link)
{
    txt = "<a style='text-decoration:none' href = '" + link + "'>" + txt + "</a>";
}

QString styleForBar(int value, int maxv, int type)
{
    int maxValue, val;

    if(maxv == 0) { maxValue = 1; }
    else { maxValue = maxv; }

    val = std::abs(value * 100 / maxValue);

    if (val < 1) { val = 1; }
    if (val > 100) { val = 100; }

    QString res;
    if(val < 30)
    {
        if (type == 1)
        {
            res = "#348017";
        }
        else
        {
            res = "#C11B17";
        }
    }
    if(val >= 30 && val < 70 && type == 0)
    {
        res = "#3BB9FF";
    }
    if(val >= 30 && val < 50 && type == 1)
    {
        res = "#FFA62F";
    }
    if(val >= 50 && val < 70 && type == 1)
    {
        res = "#E56717";
    }
    if (val >= 70)
    {
        if(type == 1)
        {
            res = "#C11B17";
        }
        else
        {
            res = "#348017";
        }
    }
    if(type == 2)
    {
        if(val < 20) { res = "#C11B17"; }
        if(val >= 20 && val < 40) { res = "#E56717"; }
        if(val >= 40 && val < 60) { res = "#FFA62F"; }
        if(val >= 60 && val < 80) { res = "#3BB9FF"; }
        if(val >= 80) { res = "#348017"; }
    }

    QString style = "QProgressBar { background-color: #C0C6CA; border: 0px; padding: 0px; height: 16px; text-align: right; margin-right: 25px;}"
                    "QProgressBar::chunk { background: " + res + "; width:5px; height: 16px;}";

    return style;
}

int getSexuality()
{
    return getRandInt(0, 2);
}

int genDick(int arg)
{
    if(arg != 0) { return arg; }
    int _tmp = getRandInt(1,100);
    int _tmpDick;
    if(_tmp >= 99)
    {
        _tmpDick = getRandInt(28,31);
    }
    else if (_tmp >= 95)
    {
        _tmpDick = getRandInt(24,27);
    }
    else if (_tmp >= 75)
    {
        _tmpDick = getRandInt(22,23);
    }
    else if (_tmp >= 65)
    {
        _tmpDick = getRandInt(18,21);
    }
    else if (_tmp >= 25)
    {
        _tmpDick = getRandInt(16,17);
    }
    else
    {
        _tmpDick = getRandInt(12,15);
    }
    return _tmpDick;
}

QString makeImg(QString path)
{
    return "<img style='max-width: 500px; max-height: 1000px' src='"+path+"'></img>";
}

QString makeImage(QString path, bool isDay, int month)
{
    if (path.isEmpty())
    {
        return "";
    }
    QString img, ext = path.split(".")[1];
    if (ext.isEmpty())
    {
        ext = "jpg";
    }
    else
    {
        img = path.split(".")[0];
    }

    if (month == 1 || month == 2 || month == 12)
    {
        img.append("_winter");
    }
    if (!isDay)
    {
        img.append("_night");
    }
   img.append("." + ext);
   return img;
}

QString makeExtImage(QString path, bool isDay, int month)
{
    if (path.isEmpty())
    {
        return "";
    }
    QString img, ext = path.split(".")[1];
    if (ext.isEmpty())
    {
        ext = "jpg";
    }
    else
    {
        img = path.split(".")[0];
    }
    if (month  >= 3 && month <= 5)
    {
        img.append("_spring");
    }
    else if(month >=6 && month <= 8)
    {
        img.append("_summer");
    }
    else if(month >= 9 && month <= 11)
    {
        img.append("_autumn");
    }
    else
    {
        img.append("_winter");
    }
    if (!isDay)
    {
        img.append("_night");
    }
    img.append("." + ext);    
    return img;
}

void ClearLayout(QLayout *layout)
{
    while (layout->count() > 0)
    {
        QLayoutItem* item = layout->takeAt(0);
        if(item->widget())
        {
            delete item->widget();
        }
        delete item;
    }
}

int valChecker(int val, int min, int max)
{
    int result;
    if (val <= min)
        result = min;
    else if (val >= max)
        result = max;
    else
        result = val;  
    return result;
}

int upSportSkill(int val)
{
    int result{0};
    if(val >= 90)
    {
        if(getRandInt(1,6) ==1)
            result = 1;
        else result = 0;
    }
    else if(val >= 75)
    {
        if(getRandInt(1,5) == 1)
            result = 1;
        else result = 0;
    }
    else if(val >= 60)
    {
        if(getRandInt(1,4) == 1)
            result = 1;
        else result = 0;
    }
    else if(val >= 45)
    {
        if(getRandInt(1,3) == 1)
            result = 1;
        else result = 0;
    }
    else if(val >= 30)
    {
        if(getRandInt(1,2) == 1)
            result = 1;
        else result = 0;
    }
    else result = 1;
    return result;
}

QString getLocIdStr(LocId id)
{
    //common
    if(id == lbathroom)
        return "bathroom";
    else if(id == lbeach)
        return "beach";
    else if(id == licerink)
        return "icerink";
    else if(id == lcinema)
        return "cinema";
    else if(id == lgamehall)
        return "gamehall";
    else if(id == lmetro)
        return "metro";
    else if(id == lbandahome)
        return "bandahome";
    else if(id == lbandasklad)
        return "bandasklad";
    else if(id == ltailor)
        return "tailor";
    else if(id == ltaxi)
        return "taxi";
    else if(id == lzoo)
        return "zoo";
    else if(id == lpark)
        return "park";
    else if(id == lshop)
        return "shop";

    //gadukino
    else if(id == lbackwater)
        return "backwater";
    else if(id == lgadbana)
        return "gadbana";
    else if(id == lgadbeach)
        return "gadbeach";
    else if(id == lgaddvor)
        return "gaddvor";
    else if(id == lgadfield)
        return "gadfield";
    else if(id == lgadforest)
        return "gadforest";
    else if(id == lgadforestswamp)
        return "gadforestswamp";
    else if(id == lgadgarden)
        return "gadgarden";
    else if(id == lgadhouse)
        return "gadhouse";
    else if(id == lgadmarket)
        return "gadmarket";
    else if(id == lgadriver)
        return "gadriver";
    else if(id == lgadroad)
        return "gadroad";
    else if(id == lgadsarai)
        return "gadsarai";
    else if(id == lgadukino)
        return "gadukino";
    else if(id == lmeadow)
        return "meadow";
    else if(id == lmirahome)
        return "mirahome";
    else if(id == lswamp)
        return "swamp";
    else if(id == lswamphouse)
        return "swamphouse";
    else if(id == lswampspring)
        return "swampspring";
    else if(id == lswampyard)
        return "swampyard";

    //road dacha
    else if(id == ldachi)
        return "dachi";
    else if(id == lroad)
        return "road";

    //pavlovo
    else if(id == lmeyhome)
        return "meyhome";
    else if(id == lbedrpar)
        return "bedrpar";
    else if(id == lbedrpar2)
        return "bedrpar2";
    else if(id == lkorrpar)
        return "korrpar";
    else if(id == lkuhrpar)
        return "kuhrpar";
    else if(id == lsitrpar)
        return "sitrpar";
    else if(id == lbarbershop)
        return "barbershop";
    else if(id == lcafeparco)
        return "cafeparco";
    else if(id == lcarwash)
        return "carwash";
    else if(id == ldancegev)
        return "dancegev";
    else if(id == lgargazel)
        return "gargazel";
    else if(id == lgdk)
        return "gdk";
    else if(id == lgdkbibl)
        return "gdkbibl";
    else if(id == lgdkin)
        return "gdkin";
    else if(id == lgdkintoilet)
        return "gdkintoilet";
    else if(id == lgdkkru)
        return "gdkkru";
    else if(id == lgdksport)
        return "gdksport";
    else if(id == lghomeyard)
        return "ghomeyard";
    else if(id == lgkafe)
        return "gkafe";
    else if(id == lglake)
        return "glake";
    else if(id == lglakenude)
        return "glakenude";
    else if(id == lglakenudeforest)
        return "glakenudeforest";
    else if(id == lgorodok)
        return "gorodok";
    else if(id == lgpoli)
        return "gpoli";
    else if(id == lgrinok)
        return "grinok";
    else if(id == lgschool)
        return "gschool";
    else if(id == lgschooltoilet)
        return "gschooltoilet";
    else if(id == lgshveyfab)
        return "gshveyfab";
    else if(id == lhotel)
        return "hotel";
    else if(id == ligorhome)
        return "igorhome";
    else if(id == ljuliamilhome)
        return "juliamilhome";
    else if(id == lkotovdom)
        return "kotovdom";
    else if(id == llariskahome)
        return "lariskahome";
    else if(id == lmishahome)
        return "mishahome";
    else if(id == lnatbelhome)
        return "natbelhome";
    else if(id == lpodezd)
        return "podezd";
    else if(id == lshulgaroom)
        return "shulgaroom";
    else if(id == lshulgahome)
        return "shulgahome";
    else if(id == lvokzalg)
        return "vokzalg";
    else if(id == lvokzalgin)
        return "vokzalgin";
    else if(id == lvolley)
        return "volley";
    else if(id == lalbinaev)
        return "albinaev";
    else if(id == ldimagohome2)
        return "dimagohome2";

    //city
    else if(id == lcasino)
        return "casino";
    else if(id == lcasino2)
        return "casino2";

    //city north
    else if(id == lautosalonf)
        return "autosalonf";
    else if(id == lautoservicef)
        return "autoservicef";
    else if(id == lautotraidf)
        return "autotraidf";
    else if(id == lbuklinik)
        return "buklinik";
    else if(id == ldk)
        return "dk";
    else if(id == lkazinosvid)
        return "kazinosvid";
    else if(id == llakecafe)
        return "lakecafe";
    else if(id == llaketoilet)
        return "laketoilet";
    else if(id == llogist)
        return "logist";
    else if(id == lnorth)
        return "north";
    else if(id == lpirsingsalon)
        return "pirsingsalon";
    else if(id == lskk)
        return "skk";
    else if(id == lskkelevator)
        return "skkelevator";
    else if(id == lskkgym)
        return "skkgym";
    else if(id == lskkblockzona)
        return "skkblockzona";
    else if(id == lskkgymcabtrener)
        return "skkgymcabtrener";
    else if(id == lskkgymcardiozona)
        return "skkgymcardiozona";
    else if(id == lskkgymfreezona)
        return "skkgymfreezona";
    else if(id == lskkgymgirl)
        return "skkgymgirl";
    else if(id == lskkgymkor)
        return "skkgymkor";
    else if(id == lskkgymleverzona)
        return "skkgymleverzona";
    else if(id == lskkgymmassage)
        return "skkgymmassage";
    else if(id == lskkgymmedic)
        return "skkgymmedic";
    else if(id == lskkgymzal)
        return "skkgymzal";
    else if(id == lterminal)
        return "terminal";
    else if(id == lterminaloffice)
        return "terminaloffice";
    else if(id == ltruckparking)
        return "truckparking";
    else if(id == lvokzal)
        return "vokzal";

    //city center
    else if(id == lagentned)
        return "agentned";
    else if(id == lbank)
        return "bank";
    else if(id == lbordel)
        return "bordel";
    else if(id == lbordelgo)
        return "bordelgo";
    else if(id == lbouling)
        return "bouling";
    else if(id == lburger)
        return "burger";
    else if(id == lbutik)
        return "butik";
    else if(id == lcenter)
        return "center";
    else if(id == lclub)
        return "club";
    else if(id == lfitgirl)
        return "fitgirl";
    else if(id == lfitness)
        return "fitness";
    else if(id == lfoto)
        return "foto";
    else if(id == lkamerakpz)
        return "kamerakpz";
    else if(id == lkiskis)
        return "kiskis";
    else if(id == loffice)
        return "office";
    else if(id == lpornstudio)
        return "pornstudio";
    else if(id == lrestoran)
        return "restoran";
    else if(id == lsalon)
        return "salon";
    else if(id == lsexshop)
        return "sexshop";
    else if(id == lstripclub)
        return "stripclub";
    else if(id == ltanyaapartment)
        return "tanyaapartment";
    else if(id == lvipclub)
        return "vipclub";

    //city center university
    else if(id == luniversity)
        return "university";
    else if(id == lunicampus)
        return "unicampus";
    else if(id == lunidorm)
        return "unidorm";

    //city south
    else if(id == lapteka)
        return "apteka";
    else if(id == lbdsm)
        return "bdsm";
    else if(id == lbdsmclub)
        return "bdsmclub";
    else if(id == lbilliard)
        return "billiard";
    else if(id == ldanceclass)
        return "danceclass";
    else if(id == lfrontdoor)
        return "frontdoor";
    else if(id == lhomeyard)
        return "homeyard";
    else if(id == lkafe)
        return "kafe";
    else if(id == lkatspalnya)
        return "katspalnya";
    else if(id == llake)
        return "lake";
    else if(id == lnudelake)
        return "nudelake";
    else if(id == lpizza)
        return "pizza";
    else if(id == lpoli)
        return "poli";
    else if(id == lsouth)
        return "south";
    else if(id == lsouthmarket)
        return "southmarket";
    else if(id == lsouthoffice)
        return "southoffice";
    else if(id == ltrashplace)
        return "trashplace";
    else if(id == lschoolboy)
        return "schoolboy";

    //city south apart
    else if(id == lbalkon)
        return "balkon";
    else if(id == lbedr)
        return "bedr";
    else if(id == lkorr)
        return "korr";
    else if(id == lkuhr)
        return "kuhr";
    else if(id == lsitr)
        return "sitr";
    else if(id == lstwork)
        return "stwork";
}

LocId getLocId(QString id)
{
    if(id == "bathroom")
        return lbathroom;
    else if(id == "beach")
        return lbeach;
    else if(id == "icerink")
        return licerink;
    else if(id == "cinema")
        return lcinema;
    else if(id == "gamehall")
        return lgamehall;
    else if(id == "metro")
        return lmetro;
    else if(id == "bandahome")
        return lbandahome;
    else if(id == "bandasklad")
        return lbandasklad;
    else if(id == "tailor")
        return ltailor;
    else if(id == "taxi")
        return ltaxi;
    else if(id == "zoo")
        return lzoo;
    else if(id == "park")
        return lpark;
    else if(id == "shop")
        return lshop;

    //gadukino
    else if(id == "backwater")
        return lbackwater;
    else if(id == "gadbana")
        return lgadbana;
    else if(id == "gadbeach")
        return lgadbeach;
    else if(id == "gaddvor")
        return lgaddvor;
    else if(id == "gadfield")
        return lgadfield;
    else if(id == "gadforest")
        return lgadforest;
    else if(id == "gadforestswamp")
        return lgadforestswamp;
    else if(id == "gadgarden")
        return lgadgarden;
    else if(id == "gadhouse")
        return lgadhouse;
    else if(id == "gadmarket")
        return lgadmarket;
    else if(id == "gadriver")
        return lgadriver;
    else if(id == "gadroad")
        return lgadroad;
    else if(id == "gadsarai")
        return lgadsarai;
    else if(id == "gadukino")
        return lgadukino;
    else if(id == "meadow")
        return lmeadow;
    else if(id == "mirahome")
        return lmirahome;
    else if(id == "swamp")
        return lswamp;
    else if(id == "swamphouse")
        return lswamphouse;
    else if(id == "swampspring")
        return lswampspring;
    else if(id == "swampyard")
        return lswampyard;

    //road dacha
    else if(id == "dachi")
        return ldachi;
    else if(id == "road")
        return lroad;

    //pavlovo
    else if(id == "meyhome")
        return lmeyhome;
    else if(id == "bedrpar")
        return lbedrpar;
    else if(id == "bedrpar2")
        return lbedrpar2;
    else if(id == "korrpar")
        return lkorrpar;
    else if(id == "kuhrpar")
        return lkuhrpar;
    else if(id == "sitrpar")
        return lsitrpar;
    else if(id == "barbershop")
        return lbarbershop;
    else if(id == "cafeparco")
        return lcafeparco;
    else if(id == "carwash")
        return lcarwash;
    else if(id == "dancegev")
        return ldancegev;
    else if(id == "gargazel")
        return lgargazel;
    else if(id == "gdk")
        return lgdk;
    else if(id == "gdkbibl")
        return lgdkbibl;
    else if(id == "gdkin")
        return lgdkin;
    else if(id == "gdkintoilet")
        return lgdkintoilet;
    else if(id == "gdkkru")
        return lgdkkru;
    else if(id == "gdksport")
        return lgdksport;
    else if(id == "ghomeyard")
        return lghomeyard;
    else if(id == "gkafe")
        return lgkafe;
    else if(id == "glake")
        return lglake;
    else if(id == "glakenude")
        return lglakenude;
    else if(id == "glakenudeforest")
        return lglakenudeforest;
    else if(id == "gorodok")
        return lgorodok;
    else if(id == "gpoli")
        return lgpoli;
    else if(id == "grinok")
        return lgrinok;
    else if(id == "gschool")
        return lgschool;
    else if(id == "gschooltoilet")
        return lgschooltoilet;
    else if(id == "gshveyfab")
        return lgshveyfab;
    else if(id == "hotel")
        return lhotel;
    else if(id == "igorhome")
        return ligorhome;
    else if(id == "juliamilhome")
        return ljuliamilhome;
    else if(id == "kotovdom")
        return lkotovdom;
    else if(id == "lariskahome")
        return llariskahome;
    else if(id == "mishahome")
        return lmishahome;
    else if(id == "natbelhome")
        return lnatbelhome;
    else if(id == "podezd")
        return lpodezd;
    else if(id == "shulgaroom")
        return lshulgaroom;
    else if(id == "shulgahome")
        return lshulgahome;
    else if(id == "vokzalg")
        return lvokzalg;
    else if(id == "vokzalgin")
        return lvokzalgin;
    else if(id == "volley")
        return lvolley;
    else if(id == "albinaev")
        return lalbinaev;
    else if (id == "dimagohome2")
        return ldimagohome2;
        

    //city
    else if(id == "casino")
        return lcasino;
    else if(id == "casino2")
        return lcasino2;

    //city north
    else if(id == "autosalonf")
        return lautosalonf;
    else if(id == "autoservicef")
        return lautoservicef;
    else if(id == "autotraidf")
        return lautotraidf;
    else if(id == "buklinik")
        return lbuklinik;
    else if(id == "dk")
        return ldk;
    else if(id == "kazinosvid")
        return lkazinosvid;
    else if(id == "lakecafe")
        return llakecafe;
    else if(id == "laketoilet")
        return llaketoilet;
    else if(id == "logist")
        return llogist;
    else if(id == "north")
        return lnorth;
    else if(id == "pirsingsalon")
        return lpirsingsalon;
    else if(id == "skk")
        return lskk;
    else if(id == "skkelevator")
        return lskkelevator;
    else if(id == "skkgym")
        return lskkgym;
    else if(id == "skkblockzona")
        return lskkblockzona;
    else if(id == "skkgymcabtrener")
        return lskkgymcabtrener;
    else if(id == "skkgymcardiozona")
        return lskkgymcardiozona;
    else if(id == "skkgymfreezona")
        return lskkgymfreezona;
    else if(id == "skkgymgirl")
        return lskkgymgirl;
    else if(id == "skkgymkor")
        return lskkgymkor;
    else if(id == "skkgymleverzona")
        return lskkgymleverzona;
    else if(id == "skkgymmassage")
        return lskkgymmassage;
    else if(id == "skkgymmedic")
        return lskkgymmedic;
    else if(id == "skkgymzal")
        return lskkgymzal;
    else if(id == "terminal")
        return lterminal;
    else if(id == "terminaloffice")
        return lterminaloffice;
    else if(id == "truckparking")
        return ltruckparking;
    else if(id == "vokzal")
        return lvokzal;

    //city center
    else if(id == "agentned")
        return lagentned;
    else if(id == "bank")
        return lbank;
    else if(id == "bordel")
        return lbordel;
    else if(id == "bordelgo")
        return lbordelgo;
    else if(id == "bouling")
        return lbouling;
    else if(id == "burger")
        return lburger;
    else if(id == "butik")
        return lbutik;
    else if(id == "center")
        return lcenter;
    else if(id == "club")
        return lclub;
    else if(id == "fitgirl")
        return lfitgirl;
    else if(id == "fitness")
        return lfitness;
    else if(id == "foto")
        return lfoto;
    else if(id == "kamerakpz")
        return lkamerakpz;
    else if(id == "kiskis")
        return lkiskis;
    else if(id == "office")
        return loffice;
    else if(id == "pornstudio")
        return lpornstudio;
    else if(id == "restoran")
        return lrestoran;
    else if(id == "salon")
        return lsalon;
    else if(id == "sexshop")
        return lsexshop;
    else if(id == "stripclub")
        return lstripclub;
    else if(id == "tanyaapartment")
        return ltanyaapartment;
    else if(id == "vipclub")
        return lvipclub;

    //city center university
    else if(id == "university")
        return luniversity;
    else if(id == "unicampus")
        return lunicampus;
    else if(id == "unidorm")
        return lunidorm;

    //city south
    else if(id == "apteka")
        return lapteka;
    else if(id == "bdsm")
        return lbdsm;
    else if(id == "bdsmclub")
        return lbdsmclub;
    else if(id == "billiard")
        return lbilliard;
    else if(id == "danceclass")
        return ldanceclass;
    else if(id == "frontdoor")
        return lfrontdoor;
    else if(id == "homeyard")
        return lhomeyard;
    else if(id == "kafe")
        return lkafe;
    else if(id == "katspalnya")
        return lkatspalnya;
    else if(id == "lake")
        return llake;
    else if(id == "nudelake")
        return lnudelake;
    else if(id == "pizza")
        return lpizza;
    else if(id == "poli")
        return lpoli;
    else if(id == "south")
        return lsouth;
    else if(id == "southmarket")
        return lsouthmarket;
    else if(id == "southoffice")
        return lsouthoffice;
    else if(id == "trashplace")
        return ltrashplace;
    else if(id == "schoolboy")
        return lschoolboy;

    //city south apart
    else if(id == "balkon")
        return lbalkon;
    else if(id == "bedr")
        return lbedr;
    else if(id == "korr")
        return lkorr;
    else if(id == "kuhr")
        return lkuhr;
    else if(id == "sitr")
        return lsitr;
    else if(id == "stwork")
        return lstwork;
}
