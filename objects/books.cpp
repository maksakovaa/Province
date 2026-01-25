#include "books.h"
#include "bookform.h"
#include "../menu/buttons.h"
#include "../Functions.h"
#include "../npc/npc_enum.h"
#include "../game.h"

Books::Books(Game *ptr): root(ptr) {}

QString Books::getName()
{
    return "books";
}

QString Books::getImage()
{
    return "data/img/items/books/" + intQStr(curBook) + ".jpg";
}

QString Books::getDesc()
{
    return QString();
}

QString Books::getBookName(int id)
{
    return m_books[id].name;
}

void Books::viewBooks()
{
    root->clearActions();
    if(m_books.empty())
        initBooks();
    root->rendObjPage(this);
    for (int i = 0; i < m_books.size(); ++i)
    {
        if(m_books[i].exist && i != root->vEvent(sister_book) && i != root->vEvent(book_in_bag))
        {
            makeBookWgt(m_books[i].id,m_books[i].name,m_books[i].page);
        }
    }
    makeActBtn("back_to_loc",act(0));
}

void Books::initBooks()
{
    for (int i = 0; i < 40; ++i)
    {
        m_books.push_back(Book(i,str(i),0,false));
    }

    m_books[getRandInt(0,9)].exist = true;
    m_books[getRandInt(10,14)].exist = true;
    m_books[getRandInt(14,19)].exist = true;
    m_books[getRandInt(20,24)].exist = true;
    m_books[getRandInt(25,29)].exist = true;
}

int Books::sisBook()
{
    std::vector<int> existBooks;
    for(int i = 0; i < m_books.size(); ++i)
    {
        if(m_books[i].exist)
            existBooks.push_back(i);
    }
    return existBooks[getRandInt(0,existBooks.size() - 1)];
}

void Books::readBook(int id)
{
    root->clearActions();
    root->rendObjPage(this);
    layout = new QVBoxLayout;
    lbl = new QLabel;
    layout->addWidget(lbl);
    layout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    root->addLayoutsInObjPage(layout);
    curBook = id;
    QString page = "<img src='" + getImage() + "'></img>";
    page += "<br>" + str(40) + intQStr(m_books[id].page * 20) +  str(41);
    lbl->setText(page);
    qDebug() << m_books[id].page/20 << "  alko block: " << root->alkoBlock();
    if(m_books[id].page/20 == 0 && root->alkoBlock() == 0 && root->drugBlock() == false)
        makeActBtn("readBook_act",act(1));
    makeActBtn("back_to_books",act(2));
}

void Books::read_procedure()
{
    root->sendNotif(str(44));
    m_books[curBook].page += 1;
    root->vEvent(read_per_day) += 1;
    root->incTime(getRandInt(50,70));
    if(root->vEvent(read_per_day) > 1)
        root->vBody(blizoruk) += 1;
    if(root->vStatus(nerdism) > 0)
    {
        root->vStatus(nerdism) += 20;
        root->vStatus(mood) += 30 ;
    }
    else
    {
        if(curBook >= 10 && curBook < 20)
        {
            if(m_books[curBook].page < 20)
                root->vStatus(mood) += 10 ;
            else
                root->vStatus(mood) += 5;
        }
        if(curBook >= 20 && curBook < 30)
        {
            if(m_books[curBook].page < 20)
            {
                root->vStatus(horny) += 5;
                root->vStatus(mood) += 5;
            }
            else
            {
                root->vStatus(horny) += 3;
                root->vStatus(mood) += 3;
            }
            if(root->vBody(blizoruk) == 200 && root->vQuest(glassQW) == 0)
            {
                root->vQuest(glassQW) = 1;
                lbl->setText(lbl->text() + "<br>" + str(42));
            }
        }
        if(curBook >= 30 && curBook < 40)
        {
            if(m_books[curBook].page < 20)
                root->vStatus(horny) += 10;
            else
                root->vStatus(horny) += 5;
        }
    }
}

void Books::readed()
{
    root->rendObjPage(this);
    QString page = "<img src='" + getImage() + "'></img>";
    page += m_books[curBook].name + "<br>" + str(45);
    lbl = new QLabel;
    lbl->setText(page);
    root->addQWidgetInObjPage(lbl);
    makeActBtn("back_to_books",act(4));
}

void Books::erotic_enable()
{
    // ! возникает при выполенении одного из условий:
    // ! сестра спалила за мастурбацией
    // ! сестра в курсе, что ГГ дает
    // ! ГГ прочла хоть один дамский роман
    // ! обязательное условие - отличные отношения с сестрой
    root->rendImagePage(this);
    root->setImage(media(1));
    if(root->vEvent(sisterKnowMastr) + root->vEvent(sisterKnowSlut) > 0)
        root->setText(str(46) + str(47));
    else
        root->setText(str(46) + str(48));
    root->vEvent(pornmarkonce) = 1;
    root->vEvent(sister_book) = 34;
    root->vEvent(reading_erotic_enable) = 1;
    m_books[34].exist = true;
    makeActBtn("bedrPar",act(0));
}

int Books::novel_readed()
{
    int counter = 0;
    for (int i = 20; i < 30; i++)
    {
        if(m_books[i].page >= 20)
            counter++;
    }
    return counter;
}

int Books::ero_readed()
{
    int counter = 0;
    for (int i = 30; i < 40; i++)
    {
        if(m_books[i].page >= 20)
            counter++;
    }
    return counter;
}

void Books::erotic_block()
{
    QString string = str(49);
    if(root->gNPC(mother).relation < 40)
    {
        root->changeRep('-',mother,20);
        string += str(50);
        root->vEvent(reading_erotic_enable) = -1;
        remove_ero();
        root->setText(string);
        makeActBtn("bedrPar",act(4));
    }
    else
    {
        string += str(51);
        root->setText(string);
        root->incTime(5);
        makeActBtn("silent",act(5));
        makeActBtn("interrupt",act(6));
    }
}

void Books::remove_ero()
{
    for (int i = 30; i < 40; ++i)
    {
        m_books[i].exist = false;
    }
}

void Books::shop(QString arg)
{
    root->rendObjPage(this);
    lbl = new QLabel;
    layout = new QVBoxLayout;
    layout->addWidget(lbl);
    layout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    root->addLayoutsInObjPage(layout);
    if(m_books.empty())
        initBooks();
    int size, i;

    if(arg == "ero") { i = 30; size = 40; }
    else { i = 0; size = 30; }
    QString table = "<table width=700>";
    for (; i < size; ++i)
    {
        //headers
        if(arg == "ero")
        {
            if(i == 30)
            {
                table += "<tr bgcolor=#bbee77><td colspan=2 align=center>";
                table += str(59);
                table += "</td></tr>";
            }
        }
        else
        {
            if(i == 0)
            {
                table += "<tr bgcolor=#bbee77><td colspan=2 align=center>";
                table += str(60);
                table += "</td></tr>";
            }
            if(i == 10)
            {
                table += "<tr bgcolor=#bbee77><td colspan=2 align=center>";
                table += str(61);
                table += "</td></tr>";
            }
            if(i == 20)
            {
                table += "<tr bgcolor=#bbee77><td colspan=2 align=center>";
                table += str(62);
                table += "</td></tr>";
            }
        }
        //books
        if(m_books[i].exist == false)
        {
            table += "<tr><td width=600>" + m_books[i].name + "</td>";
            table += "<td>";
            int price = getPrice(i);
            if(root->vStatus(money) > price)
                table += "<a href='buy" +intQStr(i) + "'>" + act(8) + "</a>";
            else
                table += act(8);
            table += "</td></tr>";
        }
    }
    table += "</table>";
    lbl->setText(table);
}

int Books::getPrice(int id)
{
    if(id < 10) return 300;
    else if(id >= 10 && id < 20) return 250;
    else if(id >= 20 && id < 30) return 200;
    else return 500;
}

void Books::book2bag()
{
    std::vector<int> freeBooks;
    for (int i = 0; i < m_books.size(); ++i)
    {
        if(m_books[i].exist == true && i != root->vEvent(sister_book))
            freeBooks.push_back(i);
    }
    root->vEvent(book_in_bag) = freeBooks[(getRandInt(0,freeBooks.size() - 1))];
}

void Books::readOnWalk()
{
    curBook = root->vEvent(book_in_bag);
    if(m_books[curBook].page/20 != 0)
    {
        root->setImage(getImage());
        root->setText(str(54));
        makeActBtn("back_to_loc",act(7));
    }
    else if(root->vQuest(glassQW) == 1)
    {
        root->setImage(media(2));
        root->setText(str(42));
        makeActBtn("back_to_loc",act(3));
    }
    else
    {
        makeActBtn("back_to_loc",act(7));
        QString string;
        if((root->vEvent(read_per_day) >= 3 && root->vStatus(nerdism) == 0) ||
            (root->vEvent(read_per_day) >= 5 && root->vStatus(nerdism) != 0))
            string = str(43);
        else
        {
            read_procedure();
            string = m_books[curBook].name + "<br>" + str(40) + intQStr(m_books[curBook].page * 20) + str(41) + "<br>" + str(55);
            if(root->getCurLoc() == lpark)
                string += str(56);
            else
                string += str(57);
            string += str(58);
            if(root->getCurLoc() != lpark)
            {
                root->vBody(hairStatus) = 1;
                if(root->getTemp() < 22)
                    root->vStatus(sweat) += 1;
                else if(root->getTemp() < 30)
                    root->vStatus(sweat) += 2;
                else
                    root->vStatus(sweat) += 3;
                if(root->getSunWeather() <= 2)
                {
                    if(root->isNude()) root->vBody(skinTan) += 2;
                    else root->vBody(skinTan) += 1;
                }
                else
                {
                    if(root->isNude()) root->vBody(skinTan) += 4;
                    else root->vBody(skinTan) += 2;
                }
            }
            if(m_books[curBook].page >= 20 && m_books[curBook].page % 20 == 0)
            {
                if(curBook < 10)
                {
                    if(m_books[curBook].page / 20 < 1)
                        root->vSkill(intellect) += 3;
                    else
                        root->vSkill(intellect) += 1;
                }
                string += "<br>" + str(45);
            }
            LocId id = root->getCurLoc();
            if(id == lpark)
            {
                if(root->getMonth() < 9) root->setImage(media(35));
                else root->setImage(media(36));
            }
            else if(id == lgadfield)
                root->setImage(media(getRandInt(3,4)));
            else
            {
                if(id == lgadbeach)
                {
                    if(root->isNude()) root->setImage(media(getRandInt(8,10)));
                    else root->setImage(media(getRandInt(5,7)));
                }
                if(id == lglake)
                {
                    if(root->isNude()) root->setImage(media(getRandInt(14,16)));
                    else root->setImage(media(getRandInt(11,13)));
                }
                if(id == lglakenude)
                {
                    if(root->isNude()) root->setImage(media(getRandInt(20,22)));
                    else root->setImage(media(getRandInt(17,19)));
                }
                if(id == llake)
                {
                    if(root->isNude()) root->setImage(media(getRandInt(26,28)));
                    else root->setImage(media(getRandInt(23,25)));
                }
                if(id == lnudelake)
                {
                    if(root->isNude()) root->setImage(media(getRandInt(32,34)));
                    else root->setImage(media(getRandInt(29,31)));
                }
            }
            root->setText(string);
        }
    }
}

void Books::slotActionHandler(QString action, int id)
{
    if(action == "read" && id >= 0)
    {
        readBook(id);
    }
    if(action == "putInBag" && id >= 0)
    {
        root->vEvent(book_in_bag) = id;
        viewBooks();
    }
    if(action == "sale" && id >= 0)
    {
        root->vStatus(money) += 300;
        m_books[id].exist = false;
        viewBooks();
    }

    if(action == "readBook_act")
    {
        root->clearActions();
        if(root->vQuest(glassQW) == 1)
        {
            root->rendImagePage(this);
            root->setImage(media(0));
            root->setText(str(42));
            makeActBtn("back_to_loc",act(3));
        }
        else if((root->vStatus(nerdism) >= 40 && root->vEvent(read_per_day) >= 5) ||
            (root->vStatus(nerdism) < 40 && root->vEvent(read_per_day) >= 3))
        {
            lbl->setText(lbl->text() + "<br>" + str(43));
            makeActBtn("back_to_loc",act(4));
        }
        else
        {
            read_procedure();
            if(m_books[curBook].page >= 20 && m_books[curBook].page % 20 == 0)
            {
                if(curBook < 10)
                {
                    if(m_books[curBook].page/20 < 1)
                        root->vSkill(intellect) += 3;
                    else
                        root->vSkill(intellect) += 1;
                }
                readed();
            }
            else
                readBook(curBook);
        }
        makeActBtn("back_to_books",act(3));
    }
    if(action == "back_to_books")
        viewBooks();
    if(action == "back_to_loc")
        root->changeLoc(root->getCurLoc());
    if(action == "silent")
    {
        root->clearActions();
        root->vSkill(domination) -= 1;
        root->vEvent(reading_erotic_enable) = -1;
        root->setText(str(52));
        remove_ero();
        makeActBtn("bedrPar",act(4));
    }
    if(action == "interrupt")
    {
        root->clearActions();
        root->vSkill(domination) += 1;
        root->vEvent(reading_erotic_enable) = 2;
        root->setText(str(53));
        makeActBtn("bedrPar",act(4));
    }
}

void Books::makeBookWgt(int id, QString name, int read)
{
    BookForm* book = new BookForm();
    book->setBook(id,name,read);
    root->addQWidgetInObjPage(book);
    connect(book, &BookForm::sigBookAct, this, &Books::slotActionHandler);
}

void Books::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action, "books");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, [this,action]() {this->slotActionHandler(action);});
    root->addActions(btn);
}

QString Books::str(int id)
{
    QString str[70];
    str[0] = "Перельман Я.И. «Занимательная арифметика».";
    str[1] = "Стивен Хокинг. «Краткая история времени»";
    str[2] = "Митио Каку. «Физика невозможного»";
    str[3] = "Тур Хейердал. «Путешествие на „Кон-Тики“»";
    str[4] = "Владимир Мезенцев. «Энциклопедия чудес»";
    str[5] = "Михаил Гаспаров. «Занимательная Греция. Рассказы о древнегреческой культуре»";
    str[6] = "Чарльз Дарвин. «Происхождение видов»";
    str[7] = "Билл Брайсон. «Краткая история почти всего»";
    str[8] = "Роберт Мартин. «Как мы делаем это: Эволюция и будущее репродуктивного поведения человека»";
    str[9] = "Стэнли Милгрэм. «Подчинение авторитету: Научный взгляд на власть и мораль»";
    str[10] = "Роберт Хайнлайн. \"Кошка, проходящая сквозь стены\"";
    str[11] = "Анджей Сапковский. \"Ведьмак\"";
    str[12] = "Гарри Гаррисон. \"Стальная крыса\"";
    str[13] = "Дж.Р.Р. Толкин. \"Властелин Колец\"";
    str[14] = "Роджер Желязны. \"Хроники Амбера\"";
    str[15] = "Майкл Суэнвик. \"Вакуумные цветы\"";
    str[16] = "Г.Л. Олди. \"Путь меча\"";
    str[17] = "Михаил Успенский. \"Приключения Жихаря\"";
    str[18] = "Уильям Гибсон. «Киберпространство»";
    str[19] = "Джоан Роулинг. \"Гарри Поттер\"";
    str[20] = "Сандра Браун. \"Сокровенные тайны\"";
    str[21] = "Джейн Энн Кренц. Сладкая судьба";
    str[22] = "Люсиль Картер. \"Невзгодам вопреки\"";
    str[23] = "Кимберли Рэнделл. \"Золушка-грешница\"";
    str[24] = "Эмма Дарси. \"Путешествие с шейхом\"";
    str[25] = "Сара Вуд. \"Островок любви\"";
    str[26] = "Кристина Дорсей. \"Сердце пирата\"";
    str[27] = "Тереза Карпентер. \"Эта несносная няня\"";
    str[28] = "Энн Мэтер. \"Наслаждение и боль\"";
    str[29] = "Шарлотта Бронте. \"Джейн Эйр\"";
    str[30] = "Франциска Вудворт. \"Аромат невинности\"";
    str[31] = "Дж. Р. Уорд. \"Освобожденный любовник\"";
    str[32] = "Саманта Янг. \"Город моей любви\"";
    str[33] = "Э. Л. Джеймс. \"Пятьдесят оттенков серого\"";
    str[34] = "Эммануэль Арсан. «Эммануэль»";
    str[35] = "Полин Реаж. «История О»";
    str[36] = "Владимир Набоков. \"Лолита\"";
    str[37] = "Маркиз де Сад. «Жюстина, или Несчастная судьба добродетели»";
    str[38] = "Элизабет Макнейл. «9 ½ недель»";
    str[39] = "Ги де Мопассан. «Милый друг».";
    str[40] = "Прочтено ";
    str[41] = " из 400 страниц";
    str[42] = "<b>Текст расплывается по странице, похоже вы испортили зрение. Нужно обратиться к окулисту.</b>";
    str[43] = "Нее, на сегодня хватит!";
    str[44] = "Вы прочли несколько страниц";
    str[45] = "Вы наконец-то прочли эту книгу.";
    str[46] = "<hero>- Привет, сестренка, что читаешь?</hero> - спросили вы Аньку.<br>";
    str[47] = "<npc>- Да ничего такого, чего б ты не знала!</npc> - хихикнула она. - <npc>Эротику!</npc><br><hero>- Дай и мне почитать</hero> - не угомонивались вы, пытаясь забрать у Аньки книгу.<br><npc>- Отстань, завтра возьмешь, я уже дочитываю.<br>- Не понравится эта - сходи на рынок - за центральным входом второй ряд налево и в самый конец - там лоток с порнухой и эротикой. Вот только порножурналы я не советовала б тащить домой, а то от мамки влетит по первое число.</npc>";
    str[48] = "<npc>- Да так, любовный роман...</npc> - ответила Анька, краснея и пытаясь спрятать книгу.<br>Быстро сообразив, что сестренка от вас что-то скрывает, вы ловко повалили ее на кровать и отобрали книгу - <hero>Эммануэль Арсан. «Эммануэль». Ничего себе, Анька, это же порнуха!</hero> - как на духу произнесли вы, прочитав название книги.<br><npc> - Никакая это не порнуха, а эротика. Поинтереснее твоих любовных романов с розовыми мечтами.</npc> - отсекла Анька. - <npc>Почитай как-нибудь, тебе понравится. Я оставлю на полке.<br>- Не понравится эта - сходи на рынок - за центральным входом второй ряд налево и в самый конец - там лоток с пор... эротикой.</npc>";
    str[49] = "Только вы вошли в свою комнату, как на вас набросилась мать:";
    str[50] = "<npc>- Это что еще такое? Порнуху в дом принесла, блядища ты этакая?! Нет, что б полезное что почитать!</npc> - кричала мать, тряся книгой у ваc перед лицом.<br>Ругаясь, мать собрала все книги, выдавшиейся ей порнографическими и ушла, громко хлопнув дверью.";
    str[51] = "<npc>- Это что еще такое, Света? Порнуху в дом принесла?</npc> - строго спросила мать, и, явно ожидая ответа, ткнула вам под нос книгу. Но не успели вы открыть рот, как она продолжила:<br><npc>- И не смей меня перебивать! Куда ж мир катится, в наше время-то...</npc>";
    str[52] = "Ругаясь, мать собрала все книги, выдавшиейся ей порнографическими и ушла, громко хлопнув дверью.";
    str[53] = "<hero>- Да в учебнике биологии порнографии больше, чем этих книгах, это эротика</hero>, - неожиданно, как для себя, так и для матери, выпалили вы. Мать, не сообразив, что ответить, лишь отдала вам книгу и сказав - <npc>уж лучше так с взрослой жизнью знакомится, чем с непонятными особями где-то в подворотье...</npc>, ушла.";
    str[54] = "Вы уже прочли эту книгу эту книгу и она вам не интересна.";
    str[55] = "Не обращая внимания на окружающих, вы ";
    str[56] = "забрались с ногами на лавочку";
    str[57] = "лежите, загорая, на пляжном полотенце,";
    str[58] = " и с упоением читаете книгу.";
    str[59] = "Эротика - 500р.";
    str[60] = "Научно-популярная литература";
    str[61] = "Фантастика/фентези - 250р.";
    str[62] = "Любовные романы - 200р.";
    return str[id];
}

QString Books::act(int id)
{
    QString act[10];
    act[0] = "Отойти";
    act[1] = "Читать";
    act[2] = "Поставить на место";
    act[3] = "Отложить книгу";
    act[4] = "...";
    act[5] = "Молчать";
    act[6] = "Перебить";
    act[7] = "Положить книгу в сумочку";
    act[8] = "Купить";
    return act[id];
}

QString Books::media(int id)
{
    QString med[37];
    med[0] = "data/locations/city/center/university/work/library0.jpg";
    med[1] = "data/npc/pavlovo/sister/sister_reading.jpg";
    med[2] = "data/actions/tired_eyes.jpg";
    med[3] = "data/actionsread_books/graze_cow_book1.jpg";
    med[4] = "data/actionsread_books/graze_cow_book2.jpg";
    med[5] = "data/actionsread_books/reading_gadbeach1.jpg";
    med[6] = "data/actionsread_books/reading_gadbeach2.jpg";
    med[7] = "data/actionsread_books/reading_gadbeach3.jpg";
    med[8] = "data/actionsread_books/reading_gadbeach_nude1.jpg";
    med[9] = "data/actionsread_books/reading_gadbeach_nude2.jpg";
    med[10] = "data/actionsread_books/reading_gadbeach_nude3.jpg";
    med[11] = "data/actionsread_books/reading_glake1.jpg";
    med[12] = "data/actionsread_books/reading_glake2.jpg";
    med[13] = "data/actionsread_books/reading_glake3.jpg";
    med[14] = "data/actionsread_books/reading_glake_nude1.jpg";
    med[15] = "data/actionsread_books/reading_glake_nude2.jpg";
    med[16] = "data/actionsread_books/reading_glake_nude3.jpg";
    med[17] = "data/actionsread_books/reading_glakenude1.jpg";
    med[18] = "data/actionsread_books/reading_glakenude2.jpg";
    med[19] = "data/actionsread_books/reading_glakenude3.jpg";
    med[20] = "data/actionsread_books/reading_glakenude_nude1.jpg";
    med[21] = "data/actionsread_books/reading_glakenude_nude2.jpg";
    med[22] = "data/actionsread_books/reading_glakenude_nude3.jpg";
    med[23] = "data/actionsread_books/reading_lake1.jpg";
    med[24] = "data/actionsread_books/reading_lake2.jpg";
    med[25] = "data/actionsread_books/reading_lake3.jpg";
    med[26] = "data/actionsread_books/reading_lake_nude1.jpg";
    med[27] = "data/actionsread_books/reading_lake_nude2.jpg";
    med[28] = "data/actionsread_books/reading_lake_nude3.jpg";
    med[29] = "data/actionsread_books/reading_nudelake1.jpg";
    med[30] = "data/actionsread_books/reading_nudelake2.jpg";
    med[31] = "data/actionsread_books/reading_nudelake3.jpg";
    med[32] = "data/actionsread_books/reading_nudelake_nude1.jpg";
    med[33] = "data/actionsread_books/reading_nudelake_nude2.jpg";
    med[34] = "data/actionsread_books/reading_nudelake_nude3.jpg";
    med[35] = "data/actionsread_books/reading_on_walk0.jpg";
    med[36] = "data/actionsread_books/reading_on_walk1.jpg";
    return med[id];
}
