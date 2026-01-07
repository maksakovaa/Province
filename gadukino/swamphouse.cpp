#include "swamphouse.h"
#include "../menu/buttons.h"
#include "../Functions.h"

SwampHouse::SwampHouse(LocationHandler* ptr): Location(ptr) {}

void SwampHouse::show(QString arg)
{
    if(arg.isEmpty())
        actionHandler("swamphouse");
    else
        actionHandler(arg);
}

LocId SwampHouse::getLocId()
{
    return lswamphouse;
}

LocId SwampHouse::getLocIn()
{
    return lgadukino;
}

QString SwampHouse::getLocName()
{
    return "Изба";
}

bool SwampHouse::isParent()
{
    return true;
}

LocId SwampHouse::getParId()
{
    return lswampyard;
}

void SwampHouse::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &SwampHouse::actionHandler);
    addActBtn(btn);
}

QString SwampHouse::str(int id)
{
    QString str[124];
    str[0] = "Охотничья избушка. В маленькой комнате с низким потолком есть <a href='bed'>топчан</a> на котором вы можете поспать.";
    str[1] = "В углу стоит <a href='bucket'>ведро</a> с водой.";
    str[2] = "В углу стоит пустое ведро.";
    str[3] = "Возле него висит старый <a href='washstand'>умывальник</a> и небольшое <a href='mirror'>зеркало</a>, а под ними стоит <a href='basin'>тазик</a>.";
    str[4] = "В другом углу стоит небольшая <a href='stove'>печка</a>. На ней при наличии воды и грибов можно сварить нехитрую еду. Еще можно нагреть воды, чтобы помыться в тазике.";
    str[5] = "Возле неё лежит стопка потрепаных <a href='stackmagazines'>журналов</a>, скорее всего для розжига.";
    str[6] = "На полке лежит ваша <a href='dress_after_shower'>одежда</a>.";
    str[7] = "Над печкой сушится ваша одежда.";
    str[8] = "За столом сидят <a href='hanterstable'>охотники</a>.";
    str[9] = "В избушке вы видите <a href='hantersrelax'>охотников</a>.";
    str[10] = "На топчанах спят охотники.";
    str[11] = "Вы поели ягод.";
    str[12] = "Вы не стеснясь разделись, оставшись в чем мать родила.";
    str[13] = "Несмотря на жару вы все таки стесняетесь раздеться, а вдруг кто-нибудь увидит?";
    str[14] = "Вы нашли кусок мешковины... Ну хоть что-то.";
    str[15] = "Зайдя в избушку вы увидели Игоря. Он с улыбкой подошел к вам и впился в ваши губы страстным поцелуем."
            "- Света, я хочу тебя, - прошептал он, прервав поцелуй.";
    str[16] = "Улыбнувшись вы подмигиваете Игорю. Он, все прекрасно понимая, берет вас за руку и ведет за собой.";
    str[17] = "- Нет, Игорь, давай не сейчас, - сказали вы, и стараясь не смотреть на расстерявшегося парня ушли.";
    str[18] = "Ведро с водой. В нем еще " + intQStr(gVEvent(bucket)) + " литров воды.";
    str[19] = "Вода в вас больше не лезет.";
    str[20] = "Вы с удовольствием выпили стакан воды.";
    str[21] = "Старый умывальник. При наличии воды можно умыться.";
    str[22] = "Вы тщательно умыли лицо и смыли косметику.";
    str[23] = "Вы замыли пятна спермы на своей одежде.";
    str[24] = "Неказистая печка-буржуйка, однако свои со своими функциями успешно справляется. При наличии 5 литров воды можно её нагреть для стирки или мытья. Или при наличии грибов приготовить еду.";
    str[25] = "Вы приготовили простенький грибной суп.";
    str[26] = "Вы нагрели воду, теперь можно помыться в тазике или постирать вещи.";
    str[27] = "Стопка самых разнообразных журналов, есть даже один с \"интересными\" картинками.";
    str[28] = "<b>Текст расплывается по странице, похоже вы испортили зрение. Нужно обратиться к окулисту.</b>";
    str[29] = "Вы решили полистать научный журнал, пытаясь понять всякие умные фразочки и разобраться в предмете описания.";
    str[30] = "<p style='color:red;'>Текст расплывается по странице, похоже вы испортили зрение. Нужно будет сходить к окулисту.</p>";
    str[31] = "Зайдя в избушку вы увидели Сергея. Он с улыбкой подошел и впился в ваши губы долгим поцелуем."
            "- Света, я хочу тебя, - сказал он, прервав поцелуй.";
    str[32] = "Улыбнувшись вы подмигиваете Сергею. Он, все прекрасно понимая, берет вас за руку и ведет за собой.";
    str[33] = "- Нет, Сергей, давай не сейчас, - сказали вы, и стараясь не смотреть на расстерявшегося парня ушли.";
    str[34] = "Зайдя в избушку вы увидели Андрея. Неожиданно он впился в ваши губы страстным поцелуем и ни слова не говоря потянул вас за собой.";
    str[35] = "Вы идете с Андреем держась за руки, прекрасно понимая, куда и зачем он вас ведет. И вы совсем даже не против.";
    str[36] = "- Нет, Андрей, давай не сейчас, - сказали вы, и стараясь не смотреть на него ушли.";
    str[37] = "В избушке вы увидели Андрея с Сергеем."
              "- Пора, так сказать, исполнять супружеский долг, - сказал Андрей шутливым тоном. - Готовь Светик попу."
              "- Из избушки только уйти нужно, и в кусты поглубже спрятаться, - добавил Сергей. - А то Игорь у нас сильно правильный, не поймет.";
    str[38] = "Вы идете с парнями держась за руки, прекрасно понимая, куда и зачем они вас ведут. И вы совсем даже не против.";
    str[39] = "Вы зашли в избушку и увидели выпивающих охотников."
              "- О, Света, давай к нам! - начали на перебой приглашать они.";
    str[40] = "Вы зашли в избушку и увидели выпивающих охотников."
              "- О, Света, давай к нам! - заметив вас предложил Андрей.";
    str[41] = "Вы зашли в избушку и увидели выпивающих охотников."
              "- О, Света, давай к нам! - заметив вас позвал Сергей.";
    str[42] = "Вы зашли в избушку и увидели выпивающих охотников."
            "- О, Света, давай к нам! - перекрикивая разговор позвал Игорь.";
    str[43] = "Вы зашли в избушку и увидели завтракающих охотников."
            "- О, Света, ты вовремя, присоеденяйся! - начали на перебой приглашать они.";
    str[44] = "Увидев в избушке мужчин вы ойкнув, принялись прикрываться руками...";
    str[45] = "Увидев вас голую, парни возбудились..."
            "- Светик, подойди-ка к нам, - позвал вас один из парней.";
    str[46] = "Увидев вас голую, парни только покачали головами..."
            "- Смотри Светик, допрыгаешься у нас, если будешь прелестями тут светить, - шутливо сказал кто-то из парней.";
    str[47] = "И, сломя голову, кинулись в избушку одеваться.";
    str[48] = "И быстро кинулись в избушку и прикрылись куском мешковины... Ну хоть что-то.";
    str[49] = "Но потом решили пощекотать себе нервы и оставили все как есть. Мужчины старательно отводят глаза от вашего обнаженного тела."
              "- Ну ты, Светик, блин даешь, - услышали вы только фразу Андрея.";
    str[50] = "Вы занимались своими делами, когда в избушку ввалился Андрей.<br>- Пошли Светик, - сказал он и больше ни слова не говоря потянул вас за собой на топчан.";
    str[51] = "Вы занимались своими делами, когда в избушку вошел Сергея. Заметив вас он направился в вашу сторону.<br>- Пошли отойдем Светик, что-то приспичило, - сказал он и потянул вас за собой на топчан.";
    str[52] = "Вы занимались своими делами, когда заметили вошедшего в избушку Игоря. Увидев вас он улыбнуся и подошел.<br>- Светик, мне нужно напряжение скинуть, давай отойдем,/// - сказал он улыбаясь и повел вас за собой.";
    str[53] = "Вы покорно пошли следом, прекрасно понимая куда и зачем вас ведут.";
    str[54] = "- Надо, так надо, - подумали вы и пошли с парнем, прекрасно понимая куда и зачем вас ведут.";
    str[55] = "- Отлично, то что нужно, главное вовремя,// - подумали вы, чувствуя как ваша киска изнывает от желания. Вы пошли с парнем, чуть ли не обгоняя его, и уже не ясно было, кто кого ведет.";
    str[56] = "Вы решили полистать литературный журнал... тягомотина редкая.";
    str[57] = "Вы листаете развлекательный журнал, погружаясь в мир моды и шоу-бизнеса.";
    str[58] = "Вы листаете порно журнал читая истории и разглядывая картинки, потихоньку возбуждение начинает охватывать вас.";
    str[59] = "Старый таз. При наличии горячей воды можно помыться или постирать одежду.";
    str[60] = "Вы вымылись дочиста и почувствоали себя гораздо лучше.";
    str[61] = "Вы разделись и постирали свою грязную одежду.";
    str[62] = "Вы развесили одежду сушиться внутри избушки.";
    str[63] = "Вы развесили одежду сушиться на улице.";
    str[64] = "На самодельном столе стоят бутылки с водкой и пивом, разложена закусь. Андрей с Сергеем и Игорем выпивают и весело разговаривают.";
    str[65] = "За самодельным столом едят и неспешно беседуют охотники.";
    str[66] = "Вы поболтали с ребятами с ребятами на разные темы...";
    str[67] = "Ребята предлагают выйти на перекур.";
    str[68] = "Вы вышли из избушки, ребята угостили вас сигареткой и вы покурили, продолжая прерванный разговор.";
    str[69] = "Андрей предлагает выйти на перекур.";
    str[70] = "Вы вышли из избушки, Андрей угостил вас сигаретой и вы покурили, продолжая прерванный разговор.";
    str[71] = "Вы вышли из избушки, Андрей угостил вас сигаретой и вы покурили, продолжая прерванный разговор. Вдруг Андрей, положив руку вам на коленку и заглянув в глаза, сказал:"
            "- Светик, а не могла бы ты мне помочь?"
            "- Конечно, Андрей, я даже рада буду, - ответили вы, потом уже менее уверенно добавили. - А как именно я могу помочь тебе?"
            "- Как ты знаешь Светик, я уже давно в разводе, - начал Андрей. - Но я же нормальный мужчина, мне нужно изредка снимать напряжение, ну ты понимаешь о чем я..."
            "Вы с изумлением посмотрели на него."
            "- Так вот Светик, если бы ты мне хоть изредка помогала его снимать, я был бы тебе очень благодарен, - продолжил Андрей."
            "Вы с недоверием смотрели на него, не шутит ли он. Но Андрей говорил вполне серьёзно."
            "- Об этом естественно никто не узнает, не волнуйся, - быстро добавил он. - Ну так как, Светик, ты согласна?";
    str[72] = "Вы вышли из избушки, чтобы покурить, но Андрей сразу же сказал:"
              "- К черту перекур, Светик, пошли за избушку.";
    str[73] = "Услышав такое вы надолго задумались. Помочь другу это конечно хорошо, но вот сам способ вызывал у вас сомнения."
            "- Хорошо Андрей, я согласна, - наконец решились вы ответить. - А каким именно способом тебе помогать и где?"
            "- Блин, Светик, я знал, что будешь не против, - ответил он. - Ну а на счет способа не волнуйся, поработай ротиком, мне и этого хватит."
            "- Пошли за избушку, чтобы никто не увидел, - добавил он вставая с лавки.";
    str[74] = "Услышав такое вы надолго задумались. Помочь другу это конечно хорошо, но вот сам способ вызывал у вас сомнения."
            "- Нет Андрей, я не согласна, - наконец решились вы ответить. - Как ты вообще мог мне такое предложить?"
            "И встав с лавки быстро ушли назад в избушку.";
    str[75] = "- Знаешь Андрей, я передумала, - сказали вы набравшись смелости. - Я конечно рада помочь другу, но я не шлюха какая-нибудь, чтобы сосать по подворотням."
              "И встав с лавки быстро убежали назад в избушку.";
    str[76] = "Сергей предлагает выйти на перекур.";
    str[77] = "Вы вышли из избушки, Сергей угостил вас сигаретой и вы покурили, продолжая прерванный разговор.";
    str[78] = "Игорь предлагает выйти на перекур.";
    str[79] = "Вы вышли из избушки, Игорь угостил вас сигаретой и вы покурили, продолжая прерванный разговор.";
    str[80] = "Вы напились в стельку, мозги уже почти не соображают, да и двигаетесь уже с трудом...";
    str[81] = "Вы отключились и уснули прямо за столом...";
    str[82] = "Вы проспали часа 3, проснувшись среди ночи. Голова болела и вы смутно помнили, что вчера происходило.";
    str[83] = "Вы пытались дойти до кровати, но вырубились прямо на полу, так и не дойдя до нее...";
    str[84] = "Вы проспали часа 4, проснувшись среди ночи, растрепанная еле встали с пола. Голова болела и вы смутно помнили, что вчера происходило.";
    str[85] = "Вы кое-как добрались до лежака и вырубились не раздеваясь...";
    str[86] = "Вы проспали некоторое время, проснувшись растрепанная еле оторвали голову от подушки. Голова болела и вы смутно помнили, что вчера происходило.";
    str[87] = "Пьяные ребята предложили вам порадовать их и станцевать, Андрей включил музыку и вы пьяно покачиваясь вылезли из за стола...";
    str[88] = "Но встав на ноги, вы поняли, что вы не то что танцевать, вам до кровати дойти сложно будет. Поэтому махнув разочарованым ребятам рукой вы отправились спать.";
    str[89] = "Вы проспали некоторое время, проснувшись растрепанная еле встали с кровати. Голова болела и вы смутно помнили, что вчера происходило.";
    str[90] = "Выбравшись из-за стола вы принялись изображать ритмичный танец, под дружные аплодисменты ребят.";
    str[91] = "Но немного потанцевав, вы поняли что ноги вас уже не держат, поэтому махнув разочарованым ребятам рукой вы отправились спать.";
    str[92] = "Вы проспали некоторое время, проснувшись растрепанная еле встали с кровати. Голова болела и вы смутно помнили, что вчера происходило.";
    str[93] = "В порыве танца, под одобрительные аплодисменты парней, вы срываете верхнюю часть одежды, оставшись только в бюстгалтере...";
    str[94] = "Но немного потанцевав, вы поняли что ноги вас уже не держат, поэтому махнув разочарованым ребятам рукой вы отправились спать.";
    str[95] = "Под одобрительные крики парней вы раздеваетесь дальше, оставшись только в нижнем белье...";
    str[96] = "Вы проспали часа 4, проснувшись среди ночи, растрепанная еле встали с пола. Голова болела и вы смутно помнили, что вчера происходило.";
    str[97] = "Танцуя вы раздеваетесь дальше, лифчик летит в сторону и под одобрительные крики парней вы трясете перед ними своими грудями " + intQStr(gVBody(breastsSize)) + " размера.";
    str[98] = "Танцуя вы раздеваетесь дальше и остаетесь в чем мать родила. Судя по возбужденным лицам парней их это очень заводит.";
    str[99] = "Вы явно переоценили свои силы и возможности организма. Поэтому немного потанцевав, неожиданно для парней, вырубились прямо на полу, там где танцевали....";
    str[100] = "Вы проспали часа 4, проснувшись среди ночи, растрепанная еле встали с пола. Голова болела и вы смутно помнили, что вчера происходило.";
    str[101] = "Вы хотели присесть за стол и поесть с ребятами, но не тут-то было..."
            "- Не так быстро Светик, - шутливо сказал Андрей. - Ты же понимаешь, что сыр бесплатный , только в мышеловке бывает."
               "- Хочешь кушать, заработай, - добавил он усмехнувшись и указал под стол.";
    str[102] = "Увидев вас, ребята расплылись в улыбках..."
               "- О! Наша Светик пришла, - шутливо сказал Андрей. - Нам только тебя и не хватало, садись за стол.";
    str[103] = "Вы хотели присесть за стол и поесть с ребятами, но не тут-то было..."
               "- Фу, блин, Светик, - сказал Андрей. - Ты бы хоть наши художества с лица смыла, прежде чем за стол садиться.";
    str[104] = "- Вот же гады, поесть спокойно и то не дадут, - подумали вы и полезли под стол...";
    str[105] = "Андрей";
    str[106] = "Вы устроились поудобнее под столом и приблизили свое лицо к его члену....";
    str[107] = "Вскоре член Андрея напрягся и вы поняли что он сейчас кончит...";
    str[108] = "Андрей вынул член из вашего рта и тут же вам в лицо ударила струя горячей спермы, потом еще и еще пока наконец он не прекратил кончать.";
    str[109] = "Сергей";
    str[110] = "Вскоре член Сергея напрягся и вы поняли что он сейчас кончит...";
    str[111] = "Сергей вынул член из вашего рта и тут же вам в лицо ударила струя горячей спермы, потом еще и еще пока наконец он не прекратил кончать.";
    str[112] = "Игорь";
    str[113] = "Вскоре член Сергея напрягся и вы поняли что он сейчас кончит...";
    str[114] = "Игорь вынул член из вашего рта и тут же вам в лицо ударила струя горячей спермы, потом еще и еще пока наконец он не прекратил кончать.";
    str[115] = "Вы выпили рюмку водки";
    str[116] = "Вы больше не можете есть.";
    str[117] = "Вы через силу затолкали в себя еду.";
    str[118] = "Вы с удовольствием съели приготовленную еду.";
    str[119] = "В избушке вы видите Сергея, Андрея и Игоря. Они заняты каждый своим делом.";
    str[120] = "Вы устроились поудобнее на коленях и приблизили свое лицо к его члену...";
    str[121] = "Андрей все не кончал, поэтому вы продолжили сосать...";
    str[122] = "- Круто, блин, Светик, - сказал довольный Андрей. - Ты прямо мастерица."
               "Приведя себя в порядок вы отправились с Андреем обратно в избушку.";
    str[123] = "Зайдя в очередной раз в избушку, вы заметили, сколько там накопилось разного мусора и грязи.<br>- С этим нужно что-то делать, - подумали вы, и найдя веник и тряпку принялись за уборку. Через некоторое врямя избушка сияла чистотой и порядком.";
    return str[id];
}

QString SwampHouse::act(int id)
{
    QString act[57];
    act[0] = "Есть";
    act[1] = "Встать из за стола";
    act[2] = "Поесть ягод";
    act[3] = "Далее";
    act[4] = "Снять одежду";
    act[5] = "Назад";
    act[6] = "Мастурбировать";
    act[7] = "Искать одежду";
    act[8] = "Убираться в избушке";
    act[9] = "Выйти во двор";
    act[10] = "Согласиться";
    act[11] = "Отказаться";
    act[12] = "Идти";
    act[13] = "Уйти";
    act[14] = "Попить воды";
    act[15] = "Отойти";
    act[16] = "Умыться";
    act[17] = "Оттирать сперму с одежды";
    act[18] = "Закончить";
    act[19] = "Приготовить грибной суп";
    act[20] = "Греть воду";
    act[21] = "Читать научный журнал";
    act[22] = "Читать литературный журнал";
    act[23] = "Читать развлекательный журнал";
    act[24] = "Читать порно журнал";
    act[25] = "Отложить книгу";
    act[26] = "Идти с Андреем";
    act[27] = "Идти с парнями";
    act[28] = "Присоединиться";
    act[29] = "Вежливо отказаться";
    act[30] = "Одеться";
    act[31] = "Помыться";
    act[32] = "Стирать одежду";
    act[33] = "Развесить одежду в избушке";
    act[34] = "Развесить на поляне";
    act[35] = "Выпить водки";
    act[36] = "Выпить пива";
    act[37] = "Поболтать";
    act[38] = "Выйти из зв стола";
    act[39] = "Есть";
    act[40] = "Вернуться за стол";
    act[41] = "Вырубиться";
    act[42] = "Проснуться";
    act[43] = "Отказаться от этой затеи";
    act[44] = "Танцевать";
    act[45] = act[44] + " дальше";
    act[46] = "Лезть под стол";
    act[47] = "Сесть за стол";
    act[48] = "Сосать Андрею";
    act[49] = "Сосать Сергею";
    act[50] = "Сосать Игорю";
    act[51] = "Вылезти из под стола";
    act[52] = "Сосать дальше";
    act[53] = "Закусить";
    act[54] = "Поговорить с Андреем";
    act[55] = "Поговорить с Сергеем";
    act[56] = "Поговорить с Игорем";
    return act[id];
}

QString SwampHouse::media(int id)
{
    QString med[71];
    med[0] = "data/locations/gadukino/swamp/dirty_swamphouse.jpg";
    med[1] = "data/actions/swamphouse/readmagazines.jpg";
    med[2] = "data/actions/swamphouse/readmagazines_tanga.jpg";
    med[3] = "data/actions/swamphouse/readmagazines_nude.jpg";
    med[4] = "data/locations/gadukino/swamp/swampizba.jpg";
    med[5] = "data/actions/backwater/hanterswork1.2.jpg";
    med[6] = "data/actions/backwater/hanterlove1.4.jpg";
    med[7] = "data/locations/gadukino/swamp/hanterstable.jpg";
    med[8] = "data/npc/gadukino/swamp/AndreiHanter.jpg";
    med[9] = "data/npc/gadukino/swamp/SergeiHanter.jpg";
    med[10] = "data/npc/gadukino/swamp/IgorHanter.jpg";
    med[11] = "data/locations/gadukino/swamp/swamphousenude.jpg";
    med[12] = "data/locations/gadukino/swamp/swamphousenude1.jpg";
    med[13] = "data/locations/gadukino/swamp/soup.jpg";
    med[14] = "data/locations/gadukino/forest/bilberry.jpg";
    med[15] = "data/locations/gadukino/swamp/swamphouseundress.jpg";
    med[16] = "data/actions/backwater/noundress.jpg";
    med[17] = "data/locations/gadukino/swamp/swamphouse_tkancloth.jpg";
    med[18] = "data/actions/backwater/hanterflirt2." + intQStr(getRandInt(4,6)) + ".jpg";
    med[19] = "data/qwest/gadukino/otel4.jpg";
    med[20] = "data/actions/backwater/hanterhands.jpg";
    med[21] = "data/locations/gadukino/swamp/doublehanterlove.jpg";
    med[22] = "data/locations/gadukino/swamp/swampdvornude1.jpg";
    med[23] = "data/locations/gadukino/swamp/vedro2.jpg";
    med[24] = "data/locations/gadukino/swamp/washstand.jpg";
    med[25] = "data/actions/bathroom/facesp.jpg";
    med[26] = "data/actions/bathroom/frotsp.jpg";
    med[27] = "data/locations/gadukino/swamp/basin.jpg";
    med[28] = "data/actions/backwater/basinswim.jpg";
    med[29] = "data/actions/backwater/basinwash.jpg";
    med[30] = "data/actions/Washclothes1.jpg";
    med[31] = "data/actions/backwater/basinwash1.jpg";
    med[32] = "data/actions/Washclothes2.jpg";
    med[33] = "data/actions/backwater/basinwash2.jpg";
    med[34] = "data/actions/Washclothes2.jpg";
    med[35] = "data/locations/gadukino/swamp/stove.jpg";
    med[36] = "data/locations/gadukino/swamp/hotsoup.jpg";
    med[37] = "data/locations/gadukino/swamp/hotwater.jpg";
    med[38] = "data/locations/gadukino/swamp/stackmagazines.jpg";
    med[39] = "data/locations/city/center/university/work/library0.jpg";
    med[40] = "data/actions/swamphouse/readpornomag";
    QString add;
    if(!isNude())
        med[40] += "";
    else if(!isPanties())
        med[40] += "_nude";
    else
        med[40] += "_tanga";
    med[40] += ".jpg";
    med[41] = "data/locations/gadukino/swamp/hantersmoker1.jpg";
    med[42] = "data/locations/gadukino/swamp/swamphousedrunkgirl.jpg";
    med[43] = "data/locations/gadukino/swamp/swamphousedrunkgirl1.jpg";
    med[44] = "data/actions/swamphouse/hanterstable2.jpg";
    med[45] = "data/actions/swamphouse/hanterstableBJ1." + intQStr(getRandInt(1,5))+ ".jpg";
    med[46] = "data/actions/swamphouse/hanterstableCum1." + intQStr(getRandInt(1,5))+ ".jpg";
    med[47] = "data/locations/gadukino/swamp/hantersmoker2.jpg";
    med[48] = "data/actions/backwater/thinks" + intQStr(getRandInt(1,2)) + ".jpg";
    med[49] = "data/actions/swamphouse/snack1." + intQStr(getRandInt(1,2)) + ".jpg";
    med[50] = "data/actions/kuh/vodka2.jpg";
    med[51] = "data/actions/kuh/beer2.jpg";
    med[52] = "data/locations/gadukino/swamp/swamphousedrunkgirl2.jpg";
    med[53] = "data/actions/drunk_ev/sleep7.jpg";
    med[54] = "data/actions/drunk_ev/sleep4.jpg";
    med[55] = "data/actions/drunk_ev/pohmel1.jpg";
    med[56] = "data/actions/drunk_ev/pohmel4.jpg";
    med[57] = "data/actions/drunk_ev/pohmel2.jpg";
    med[58] = "data/actions/drunk_ev/Pjanaja5.jpg";
    med[59] = "data/actions/drunk_ev/sleep11.jpg";
    med[60] = "data/actions/swamphouse/dance1." + intQStr(getRandInt(1,2)) + ".jpg";
    med[61] = "data/actions/swamphouse/dance2." + intQStr(getRandInt(1,2)) + ".jpg";
    med[62] = "data/actions/swamphouse/dance3.jpg";
    med[63] = "data/actions/drunk_ev/sleep10.jpg";
    med[64] = "data/actions/swamphouse/dance4.jpg";
    med[65] = "data/actions/drunk_ev/sleep17.jpg";
    med[66] = "data/actions/drunk_ev/pohmel3.jpg";
    med[67] = "data/actions/swamphouse/dance5.jpg";
    med[68] = "data/locations/gadukino/swamp/hantersrelax1." + intQStr(getRandInt(1,8)) + ".jpg";
    med[69] = "data/actions/swamphouse/hantersmokBJ1." + intQStr(getRandInt(1,3)) + ".jpg";
    med[70] = "data/actions/swamphouse/hantersmokCUM.jpg";
    return med[id];
}

void SwampHouse::dirtySwampHouse()
{
    if(gVEvent(dirty_swamphouse) > 10)
    {
        incTime(60);
        uVStatus(sweat,1);
    }
    if(gVEvent(dirty_swamphouse) >=10 && gVEvent(dirty_swamphouse) < 20)
    {
        incTime(120);
        uVStatus(sweat,2);
    }
    if(gVEvent(dirty_swamphouse) >= 20)
    {
        incTime(180);
        uVStatus(sweat,3);
    }
    if(gVQuest(hantersAndreiQW) < 15)
        uVQuest(hantersAndreiQW,1);
    if(gVQuest(hantersIgorQW) < 15)
        uVQuest(hantersIgorQW,1);
    if(gVQuest(hantersSergeiQW) < 15)
        uVQuest(hantersSergeiQW,1);
    setImage(media(0));
    setDesc(str(123));
    makeActBtn("swamphouse",act(3));
}

void SwampHouse::clothes_read_magazines()
{
    if(!isNude())
        setImage(media(1));
    if(isNude() && isPanties())
        setImage(media(2));
    if(isNude() && !isPanties())
        setImage(media(3));
}

void SwampHouse::actionHandler(QString action)
{
    clearActions();
    if(action == "wearCloth")
        redressOld();
    if(action == "storeCloth")
        redress(ClothType::Main,nullptr);
    if(action == "swamphouse")
    {
        sVEvent(hantslutsexrand, getRandInt(1,3));
        int tmp = getRandInt(1,5);
        setImage(media(4));
        setDesc(str(0));
        if(gVEvent(bucket) > 0)
            addText(str(1));
        if(gVEvent(bucket) == 0)
            addText(str(2));
        addText(str(3));
        addText(str(4));
        addText(str(5));
        if(gVStatus(clothesswamphouse) == 1 && gVStatus(clearClothes) == 0)
            addText(str(6));
        if(gVStatus(clearClothes) > 0 && gVStatus(clearclothesH) == 1)
            addText(str(7));
        if(isHanters() && gVEvent(hantersKnow) > 0)
        {
            if(getHour() == 20 || getHour() == 7)
                addText(str(8));
            if(getHour() > 20 && getHour() < 23)
                addText(str(9));
            if(getHour() == 23 || (getHour() >= 0 && getHour() < 7))
                addText(str(10));
        }
        if(gVStatus(edahot) > 0)
            makeActBtn("eat",act(0));
        if(gVStatus(bilberry) > 0)
            makeActBtn("eat_bilberry",act(2));
        if((!isNude() && gVStatus(clothesswamphouse) == 0) || gVStatus(swamp_clothes) == 1)
            makeActBtn("undress_cloth",act(4));
        if((gVStatus(horny) >= 50 && gVEvent(hanters) == 0) || (gVStatus(horny) >= 50 && isHanters() && getHour() >= 8 && getHour() < 20))
            makeActBtn("mastr",act(6));
        if(isNude() && gVStatus(swamp_clothes) == 0)
            makeActBtn("search_cloth",act(7));
        if(gVEvent(dirty_swamphouse) > 25)
            makeActBtn("dirty_swamphouse",act(8));
        makeActBtn("go_swamp_yard",act(9));

        if(getHour() > 8 && getHour() < 19)
        {
            //секс с Игорем
            if(gVEvent(hantersIgorLove) > 0 && gVQuest(hantersIgorQW) >= 10 && tmp == 1 && gVEvent(hantersIgorsex) == 0)
            {
                incTime(5);
                uVStatus(horny,5);
                sVEvent(hantersIgorsex,getRandInt(12,36));
                setImage(media(6));
                setDesc(str(15));
                makeActBtn("agree_igor_sex",act(10));
                makeActBtn("decline_igor_sex",act(11));
            }
            //секс с Сергеем
            if(gVEvent(hantersSergeiLove) > 0 && gVStatus(horny) <= 60 && gVQuest(hantersSergeiQW) >= 10 && tmp == 2 && gVEvent(hantersSergeisex) == 0)
            {
                incTime(5);
                uVStatus(horny,5);
                sVEvent(hantersSergeisex,getRandInt(9,30));
                setImage(media(6));
                setDesc(str(31));
                makeActBtn("agree_sergei_sex",act(10));
                makeActBtn("decline_sergei_sex",act(11));
            }
            //секс с Андреем
            if(gVEvent(hantersAndreiLove) > 0 && gVStatus(horny) <= 60 && gVQuest(hantersAndreiQW) >= 10 && tmp == 3 && gVEvent(hantersAndreisex) == 0)
            {
                incTime(5);
                uVStatus(horny,5);
                sVEvent(hantersAndreisex,getRandInt(6,24));
                setImage(media(6));
                setDesc(str(34));
                makeActBtn("agree_andrei_sex",act(26));
                makeActBtn("decline_andrei_sex",act(11));
            }
        }
        //трио ГГ, Андрей и Сергей, если любовь
        if(isHanters() && gVEvent(doublehanterlove) == 1 && getHour() >= 8 && getHour() < 20 && (gVEvent(hantersAndreisex) == 0 || gVEvent(hantersSergeisex) == 0))
        {
            incTime(5);
            sVEvent(hantersAndreisex,getRandInt(6,24));
            sVEvent(hantersSergeisex,getRandInt(9,30));
            setImage(media(5));
            setDesc(str(37));
            makeActBtn("go_with_AS",act(27));
            makeActBtn("decline_AS_sex",act(11));
        }

        //охотники приглашают за стол
        if(getHour() == 20  && isHanters() && gVEvent(hantersKnow) > 0 && gVEvent(hantersKnowSlut) == 0 && gVEvent(hanter_refuse) == 0)
        {
            if(getHour() >= 20 && getHour() <= 23)
            {
                incTime(1);
                int tmp = getRandInt(1,4);
                if(tmp == 1)
                {
                    setImage(media(7));
                    setDesc(str(39));
                }
                else if(tmp == 2)
                {
                    uVQuest(hantersAndreiQW,1);
                    setImage(media(8));
                    setDesc(str(40));
                }
                else if(tmp == 3)
                {
                    uVQuest(hantersSergeiQW,1);
                    setImage(media(9));
                    setDesc(str(41));
                }
                else
                {
                    uVQuest(hantersIgorQW,1);
                    setImage(media(10));
                    setDesc(str(42));
                }
            }
            else
            {
                setImage(media(7));
                setDesc(str(43));
            }
            makeActBtn("hanterstable",act(28));
            makeActBtn("refuse_hanters",act(29));
        }

        //если ГГ голая и охотники в избушке
        if((isNude() && isHanters() && getHour() >= 20 && getHour() < 23 && gVEvent(hanterknowday) != getDay()) ||
            (isNude() && isHanters() && getHour() == 7 && gVEvent(hanterknowday) != getDay()))
        {
            if(gVEvent(hantersKnowSlut) == 0)
            {
                setImage(media(11));
                setDesc(str(44));
                if(gVStatus(clothesswamphouse) == 1 && gVStatus(clearClothes) == 0)
                    makeActBtn("wear_clothes",act(30));
                else
                    makeActBtn("wear_swamp_cloth",act(31));
                makeActBtn("stay_nude",act(32));
            }
            else if(gVEvent(hantersKnowSlut) > 0)
            {
                if(gVEvent(hantslutsex) == 0)
                {
                    setImage(media(12));
                    setDesc(str(45));
                    makeActBtn("hantersexnude",act(3));
                }
                else
                {
                    sVEvent(hanterknowday,getDay());
                    setImage(media(12));
                    setDesc(str(46));
                    makeActBtn("swamphouse",act(3));
                }
            }
        }

        // Секс если ГГ шлюха
        if(isHanters() && gVEvent(hantersRape) == 5 && gVEvent(hantslutsexrand) == 1 && gVEvent(hantslutsex) == 0 && getHour() >= 7 && getHour() < 23)
        {
            incTime(5);
            sVEvent(temphant,getRandInt(1,3));
            sVEvent(sluthomesex,1);
            switch (gVEvent(temphant)) {
            case 1:
            {
                setImage(media(8));
                setDesc(str(50));
            }
                break;
            case 2:
            {
                setImage(media(9));
                setDesc(str(51));
            }
                break;
            case 3:
            {
                setImage(media(10));
                setDesc(str(52));
            }
                break;
            default:
                break;
            }
            if(gVStatus(horny) < 40)
                addText(str(53));
            if(gVStatus(horny) >= 40 && gVStatus(horny) < 70)
                addText(str(54));
            if(gVStatus(horny) >= 70)
                addText(str(55));
            makeActBtn("hantersex",act(12));
        }
    }

    if(action == "eat")
    {
        eat("",media(13));
        makeActBtn("swamphouse",act(1));
    }
    if(action == "eat_bilberry")
    {
        incTime(30);
        uVStatus(energy,5);
        uVStatus(water,10);
        uVStatus(bilberry,-1);
        uVStatus(health,5);
        uVStatus(mood,10);
        setImage(media(14));
        setDesc(str(11));
        makeActBtn("swamphouse",act(3));
    }

    if(action == "undress_cloth")
    {
        if(gVEvent(hantersKnowSlut) > 0 || !isHanters() || (isHanters() && getHour() >= 8 && getHour() < 20 && gVEvent(hantersKnowSlut) == 0))
        {
            sVStatus(clothesswamphouse,1);
            incTime(5);
            redress(ClothType::Main,nullptr);
            setImage(media(15));
            setDesc(str(12));
            makeActBtn("swamphouse",act(5));
        }
        else
        {
            setImage(media(16));
            setDesc(str(13));
        }
    }

    if(action == "mastr")
    {
        startSelfPlay();
    }

    if(action == "search_cloth")
    {
        incTime(10);
        sVStatus(swamp_clothes,1);
        redress(ClothType::Main,new ClothMain(1,towel,"Мешковина"));
        setImage(media(17));
        setDesc(str(14));
        makeActBtn("swamphouse",act(5));
    }

    if(action == "dirty_swamphouse")
    {
        uVEvent(hanterslut,-1);
        dirtySwampHouse();
    }

    if(action == "go_swamp_yard")
    {
        sVEvent(hanter_refuse,0);
        changeLoc(lswampyard,5);
    }

    if(action == "agree_igor_sex")
    {
        incTime(5);
        uVQuest(hantersIgorQW,1);
        setImage(media(18));
        setDesc(str(16));
        makeActBtn("HantersLoveSex",act(12));
    }
    if(action == "decline_igor_sex")
    {
        incTime(5);
        uVQuest(hantersIgorQW,-1);
        setImage(media(19));
        setDesc(str(17));
        makeActBtn("swamphouse",act(13));
    }

    if(action == "agree_sergei_sex")
    {
        incTime(5);
        uVQuest(hantersSergeiQW,1);
        setImage(media(18));
        setDesc(str(32));
        makeActBtn("HantersLoveSex",act(12));
    }
    if(action == "decline_sergei_sex")
    {
        incTime(5);
        uVQuest(hantersSergeiQW,-1);
        setImage(media(19));
        setDesc(str(33));
        makeActBtn("swamphouse",act(12));
    }

    if(action == "agree_andrei_sex")
    {
        incTime(5);
        uVQuest(hantersAndreiQW,1);
        uVStatus(horny,5);
        setImage(media(20));
        setDesc(str(35));
        makeActBtn("HantersLoveSex",act(3));
    }
    if(action == "decline_andrei_sex")
    {
        incTime(5);
        uVQuest(hantersAndreiQW,-1);
        setImage(media(19));
        setDesc(str(36));
        makeActBtn("swamphouse",act(12));
    }

    if(action == "go_with_AS")
    {
        incTime(5);
        uVQuest(hantersAndreiQW,1);
        uVQuest(hantersSergeiQW,1);
        uVStatus(horny,5);
        sVEvent(doublelovesex,1);
        uVEvent(hanterslut,1);
        sVEvent(temphant,1);
        setImage(media(21));
        setDesc(str(38));
        makeActBtn("hantersex",act(3));
    }
    if(action == "decline_AS_sex")
    {
        incTime(5);
        uVQuest(hantersAndreiQW,-1);
        uVQuest(hantersSergeiQW,-1);
        setImage(media(19));
        setDesc(str(39));
        makeActBtn("swamphouse",act(12));
    }

    if(action == "refuse_hanters")
    {
        sVEvent(hanter_refuse,1);
        actionHandler("swamphouse");
    }

    if(action == "wear_clothes")
    {
        sVStatus(clothesswamphouse,0);
        incTime(5);
        redressOld();
        setImage(media(22));
        setDesc(str(47));
        makeActBtn("swamphouse",act(3));
    }
    if(action == "wear_swamp_cloth")
    {
        incTime(5);
        sVStatus(swamp_clothes,1);
        redress(ClothType::Main,new ClothMain(1,towel,"мешковина"));
        setImage(media(17));
        setDesc(str(48));
        makeActBtn("swamphouse",act(3));
    }
    if(action == "stay_nude")
    {
        uVEvent(hanterslut,1);
        sVEvent(hanterknowday,getDay());
        setImage(media(12));
        setDesc(str(49));
    }

    if(action == "HantersLoveSex")
    {
        startEvent("HantersLoveSex");
    }
    if(action == "hantersex")
    {
        startEvent("hantersex");
    }
    if(action == "hantersexnude")
    {
        sVEvent(hantersexnude,1);
        actionHandler("hantersex");
    }
    //A HREF LINKS
    if(action == "bucket")
    {
        incTime(1);
        setImage(media(23));
        setDesc(str(18));
        makeActBtn("drinkWater",act(14));
        makeActBtn("swamphouse",act(15));
    }
    if(action == "drinkWater")
    {
        incTime(5);
        sVStatus(cumLips,0);
        uVEvent(bucket,-1);
        if(gVStatus(water) >= 20)
            addText(str(19));
        else
        {
            uVStatus(water,20);
            addText(str(20));
        }
        makeActBtn("swamphouse",act(3));
    }
    if(action == "washstand")
    {
        incTime(1);
        setImage(media(24));
        setDesc(str(21));
        if(gVEvent(bucket) > 0)
        {
            makeActBtn("wash_face",act(16));
            if(gVStatus(cumFrot) > 0)
                makeActBtn("clear_sperm_cloth",act(17));
        }
        makeActBtn("swamphouse",act(15));
    }
    if(action == "wash_face")
    {
        incTime(5);
        sVBody(makeup,1);
        sVStatus(cumLips,0);
        sVStatus(cumFace,0);
        uVStatus(sweat,-1);
        uVEvent(bucket,-1);
        setImage(media(25));
        setDesc(str(22));
        makeActBtn("washstand",act(3));
    }
    if(action == "clear_sperm_cloth")
    {
        sVStatus(cumFrot,0);
        incTime(15);
        uVEvent(bucket,-1);
        setImage(media(26));
        setDesc(str(23));
        makeActBtn("washstand",act(18));
    }

    if(action == "mirror")
    {
        viewObj("mirror");
    }
    if(action == "basin")
    {
        incTime(1);
        setImage(media(27));
        setDesc(str(59));
        if(gVEvent(hotwater) == 1 && !isCloth())
            makeActBtn("wash_in_basin",act(31));
        if(gVEvent(hotwater) == 1 && gVStatus(dirtyClothes) == 1 && !isCloth())
            makeActBtn("wash_cloth_basin",act(32));
        makeActBtn("swamphouse",act(15));
    }
    if(action == "wash_in_basin")
    {
        sVStatus(cumPussy,0);
        sVStatus(cumBelly,0);
        sVStatus(cumAss,0);
        sVStatus(cumLips,0);
        sVStatus(cumFace,0);
        sVStatus(cumAnus,0);
        sVSex(lubonus,0);
        sVStatus(sweat,0);
        uVStatus(mood,5);
        incTime(30);
        sVEvent(hotwater,0);
        setImage(media(28));
        setDesc(str(60));
        makeActBtn("swamphouse",act(3));
    }
    if(action == "wash_cloth_basin")
    {
        incTime(60);
        sVStatus(dirtyClothes,0);
        sVEvent(hotwater,0);
        sVStatus(cumFrot,0);
        if(isNude())
            setImage(media(29));
        else
            setImage(media(30));
        setDesc(str(61));
        makeActBtn("hang_cloth_house",act(33));
        if(getMonth() >= 5 && getMonth() <= 9)
            makeActBtn("hang_cloth_yard",act(34));
    }
    if(action == "hang_cloth_house")
    {
        incTime(5);
        sVStatus(clearClothes,5);
        sVStatus(clearclothesH,1);
        if(isNude())
            setImage(media(31));
        else
            setImage(media(32));
        setDesc(str(62));
        makeActBtn("swampyard",act(3));
    }
    if(action == "hang_cloth_yard")
    {
        incTime(10);
        sVStatus(clearClothes,3);
        sVStatus(clearclothesH,0);
        if(isNude())
            setImage(media(33));
        else
            setImage(media(34));
        setDesc(str(63));
        makeActBtn("swamp_yard",act(3));
    }

    if(action == "stove")
    {
        incTime(1);
        setImage(media(35));
        setDesc(str(24));
        if(gVEvent(bucket) > 0 && gVStatus(boletus) > 0 && gVStatus(edahot) == 0)
            makeActBtn("cook_soap",act(19));
        if(gVEvent(bucket) >= 5 && gVEvent(hotwater) == 0)
            makeActBtn("heat_water",act(20));
        makeActBtn("swamphouse",act(15));
    }
    if(action == "cook_soap")
    {
        uVStatus(boletus,-1);
        incTime(30);
        uVEvent(bucket,-1);
        uVStatus(edahot,1);
        setImage(media(36));
        setDesc(str(25));
        makeActBtn("swamphouse",act(3));
    }
    if(action == "heat_water")
    {
        incTime(30);
        uVEvent(bucket,-5);
        uVEvent(hotwater,1);
        setImage(media(37));
        setDesc(str(26));
        makeActBtn("swamphouse",act(3));
    }

    if(action == "stackmagazines")
    {
        incTime(1);
        setImage(media(38));
        setDesc(str(27));
        makeActBtn("read_science",act(21));
        makeActBtn("read_liter",act(22));
        makeActBtn("read_fun",act(23));
        makeActBtn("read_porn",act(24));
        makeActBtn("swamphouse",act(15));
    }
    if(action == "read_science")
    {
        if(gVQuest(glassQW) == 1)
        {
            setImage(media(39));
            setDesc(str(28));
            makeActBtn("swamphouse",act(25));
        }
        if(gVStatus(nerdism) > 0)
            uVStatus(nerdism,10);
        uVSkill(intellect,1);
        uVBody(blizoruk,1);
        uVStatus(mood,10);
        incTime(60);
        clothes_read_magazines();
        setDesc(str(29));
        if(gVBody(blizoruk) == 200 && gVQuest(glassQW) == 0)
        {
            sVQuest(glassQW,1);
            addText(str(30));
        }
        makeActBtn("stackmagazines",act(3));
    }
    if(action == "read_liter")
    {
        if(gVQuest(glassQW) == 1)
        {
            setImage(media(39));
            setDesc(str(28));
            makeActBtn("swamphouse",act(25));
        }
        if(gVStatus(nerdism) > 0)
            uVStatus(nerdism,20);
        uVBody(blizoruk,1);
        uVStatus(mood,10);
        incTime(60);
        if(gVEvent(library_day) != getDay() /* && school[sertificate] == 0 */)
        {
            sVEvent(library_day,getDay());
            uVSchool(progress,1);
        }
        clothes_read_magazines();
        setDesc(str(56));
        if(gVBody(blizoruk) == 200 && gVQuest(glassQW) == 0)
        {
            sVQuest(glassQW,1);
            addText(str(30));
        }
        makeActBtn("stackmagazines",act(3));
    }
    if(action == "read_fun")
    {
        if(gVQuest(glassQW) == 1)
        {
            setImage(media(39));
            setDesc(str(28));
            makeActBtn("swamphouse",act(25));
        }
        if(gVStatus(nerdism) > 0)
            uVStatus(nerdism,30);
        uVBody(blizoruk,1);
        sVStatus(mood,100);
        incTime(60);
        clothes_read_magazines();
        setDesc(str(57));
        if(gVBody(blizoruk) == 200 && gVQuest(glassQW) == 0)
        {
            sVQuest(glassQW,1);
            addText(str(30));
        }
        makeActBtn("stackmagazines",act(3));
    }
    if(action == "read_porn")
    {
        if(gVQuest(glassQW) == 1)
        {
            setImage(media(39));
            setDesc(str(28));
            makeActBtn("swamphouse",act(25));
        }
        uVBody(blizoruk,1);
        sVStatus(mood,100);
        incTime(60);
        uVStatus(horny,50);
        setImage(media(40));
        setDesc(str(58));
        if(gVBody(blizoruk) == 200 && gVQuest(glassQW) == 0)
        {
            sVQuest(glassQW,1);
            addText(str(30));
        }
        makeActBtn("stackmagazines",act(3));
    }

    if(action == "dress_after_shower")
    {
        redressOld();
        sVStatus(clothesswamphouse,0);
        sVStatus(swamp_clothes,0);
        actionHandler("swamphouse");
    }

    if(action == "hanterstable")
    {
        if(getHour() >= 20 && getHour() < 23)
            sVEvent(hantersdrink,1);
        else
            sVEvent(hantersdrink,0);
        incTime(1);
        int smoker = getRandInt(1,3);
        setImage(media(7));
        if(gVEvent(hantersdrink) ==1)
        {
            uVEvent(dirty_swamphouse,getRandInt(1,3));
            setDesc(str(64));
            makeActBtn("drink_vodka",act(35));
            makeActBtn("drink_bear",act(36));
            makeActBtn("talk_table",act(37));
            makeActBtn("exit_table",act(38));
            if(gVAddict(alko) > 3 && gVAddict(alko) < 8 && smoker == 1)
            {
                int tmp = getRandInt(1,4);
                if(tmp == 1)
                {
                    setImage(media(41));
                    setDesc(str(67));
                    makeActBtn("smoke1",act(10));
                    makeActBtn("hanterstable",act(11));
                }
                else if(tmp == 2)
                {
                    setImage(media(8));
                    setDesc(str(69));
                    if(gVQuest(hantersAndreiQW) < 15 && gVEvent(hantersAndreiLove) == 1 || gVEvent(hantersKnowSlut) == 0)
                        makeActBtn("smoke_Andrei1",act(10));
                    if(gVQuest(hantersAndreiQW) >= 15 && gVEvent(hantersKnowSlut) == 0 && gVEvent(hantersAndreiLove) == 0)
                    {
                        if(gVEvent(smokbj) == 0)
                            makeActBtn("smoke_Andrei2",act(10));
                        else
                            makeActBtn("smoke_Andrei3",act(10));
                    }
                    if(gVEvent(hantersKnowSlut) == 1)
                    {
                        makeActBtn("smoke_Andrei4",act(10));
                    }
                    makeActBtn("hanterstable",act(11));
                }
                else if(tmp == 3)
                {
                    setImage(media(9));
                    setDesc(str(76));
                    makeActBtn("smoke_Sergei_agree",act(10));
                    makeActBtn("hanterstable",act(11));
                }
                else if(tmp == 4)
                {
                    setImage(media(10));
                    setDesc(str(78));
                    makeActBtn("smoke_Igor_agree",act(10));
                    makeActBtn("hanterstable",act(11));
                }
            }
            if(gVAddict(alko) >= 8 && gVEvent(hantersKnowSlut) == 0)
            {
                int tmp = getRandInt(1,6);
                setImage(media(42));
                setDesc(str(80));
                if(gVEvent(hanterslut) <= 20)
                {
                    if(tmp == 1)
                        makeActBtn("drunk_sleep1",act(41));
                    if(tmp == 2)
                        makeActBtn("drunk_sleep2",act(41));
                    if(tmp == 3)
                        makeActBtn("drunk_sleep3",act(41));
                    if(tmp > 3)
                        makeActBtn("drunk_girl1",act(38));
                }
                if(gVEvent(hanterslut) > 20)
                {
                    makeActBtn("drunk_girl2",act(38));
                }
            }
            if(gVAddict(alko) >= 8 && gVEvent(hantersKnowSlut) > 0)
            {
                int tmp = getRandInt(1,6);
                setImage(media(43));
                setDesc(str(80));
                if(tmp == 1)
                    makeActBtn("drunk_sleep4",act(41));
                if(tmp == 2)
                    makeActBtn("drunk_sleep5",act(41));
                if(tmp == 3)
                    makeActBtn("drunk_sleep6",act(41));
                if(tmp > 3)
                    makeActBtn("drunk_girl3",act(38));
            }
        }
        else
        {
            uVEvent(dirty_swamp_yard,getRandInt(1,2));
            setDesc(str(65));
            makeActBtn("eat_table",act(39));
            makeActBtn("talk_table",act(37));
        }
        if(gVEvent(hantersKnowSlut) > 0 && gVEvent(hanterstableBj) == 0)
        {
            if(gVEvent(hantersdrink) == 0)
            {
                incTime(1);
                setImage(media(7));
                setDesc(str(101));
                makeActBtn("go_under_table",act(46));
                makeActBtn("swamphouse",act(11));
            }
            else
            {
                incTime(1);
                setImage(media(7));
                setDesc(str(102));
                makeActBtn("enableBJ",act(47));
            }
        }
        if((isNude() && (gVStatus(cumPussy) > 0 || gVStatus(cumBelly) > 0 || gVStatus(cumAss) > 0 || gVStatus(cumAnus) > 0)) || gVStatus(cumFace) > 0)
        {
            incTime(1);
            setImage(media(7));
            setDesc(str(103));
            makeActBtn("swamphouse",act(13));
        }
    }
    if(action == "go_under_table")
    {
        uVSkill(domination,-1);
        actionHandler("hanterstableBJ");
    }
    if(action == "hanterstableBJ")
    {
        incTime(1);
        sVEvent(hanterstableBj,1);
        uVSkill(domination,-1);
        setImage(media(44));
        setDesc(str(104));
        if(gVEvent(hanterstableBJA) == 0)
            makeActBtn("suck_ut_andrei",act(48));
        if(gVEvent(hanterstableBJS) == 0)
            makeActBtn("suck_ut_sergei",act(49));
        if(gVEvent(hanterstableBJI) == 0)
            makeActBtn("suck_ut_igor",act(50));
        if(gVEvent(hanterstableBJA) == 1 && gVEvent(hanterstableBJS) == 1 && gVEvent(hanterstableBJI) == 1)
            makeActBtn("get_out_undertable",act(51));
    }
    if(action == "suck_ut_andrei")
    {
        setBoyName(str(105));
        sVSex(dick,20);
        incTime(5);
        uVStatus(horny,10);
        uVSC(blowJob,1);
        sVEvent(hanterstableBJA,1);
        if(gVEvent(hantersAndreisex) == 0)
        {
            sVEvent(hantersAndreisex,1);
            uVSex(guy,1);
        }
        int tmp = getRandInt(1,2);
        setImage(media(45));
        setDesc(str(106));
        fnBlowJob();
        setDesc(str(107));
        if(tmp == 1)
            makeActBtn("suck_ut_andrei_cum1",act(52));
        if(tmp == 2)
            makeActBtn("suck_ut_andrei_cum2",act(52));
    }
    if(action == "suck_ut_andrei_cum1")
    {
        incTime(1);
        fnCum("face");
        if(isNude())
            fnCum("belly");
        else
            uVStatus(cumFrot,getRandInt(0,1));
        setImage(media(46));
        setDesc(str(108));
        makeActBtn("hanterstableBJ",act(3));
    }
    if(action == "suck_ut_andrei_cum2")
    {
        incTime(1);
        uVSC(swallow,1);
        setImage(media(45));
        fnSwallow();
        makeActBtn("hanterstableBJ",act(3));
    }
    if(action == "suck_ut_sergei")
    {
        setBoyName(str(109));
        sVSex(dick,18);
        incTime(5);
        uVStatus(horny,10);
        uVSC(blowJob,1);
        sVEvent(hanterstableBJS,1);
        if(gVEvent(hantersSergeisex) == 0)
        {
            sVEvent(hantersSergeisex,1);
            uVSex(guy,1);
        }
        int tmp = getRandInt(1,2);
        setImage(media(45));
        setDesc(str(106));
        fnBlowJob();
        setDesc(str(110));
        if(tmp == 1)
            makeActBtn("suck_ut_sergei_cum1",act(52));
        if(tmp == 2)
            makeActBtn("suck_ut_sergei_cum2",act(52));
    }
    if(action == "suck_ut_sergei_cum1")
    {
        incTime(1);
        fnCum("face");
        if(isNude())
            fnCum("belly");
        else
            uVStatus(cumFrot,getRandInt(0,1));
        setImage(media((46)));
        setDesc(str(111));
        makeActBtn("hanterstableBJ",act(3));
    }
    if(action == "suck_ut_sergei_cum2")
    {
        incTime(1);
        uVSC(swallow,1);
        setImage(media(45));
        fnSwallow();
        makeActBtn("hanterstableBJ",act(3));
    }
    if(action == "suck_ut_igor")
    {
        setBoyName(str(112));
        sVSex(dick,16);
        incTime(5);
        uVStatus(horny,10);
        uVSC(blowJob,1);
        if(gVEvent(hantersIgorsex) == 0)
        {
            sVEvent(hantersIgorsex,1);
            uVSex(guy,1);
        }
        int tmp = getRandInt(1,5);
        setImage(media(45));
        setDesc(str(106));
        fnBlowJob();
        setDesc(str(113));
        if(tmp == 1)
            makeActBtn("suck_ut_igor_cum1",act(52));
        else
            makeActBtn("suck_ut_sergei_cum2",act(52));
    }
    if(action == "suck_ut_sergei_cum1")
    {
        incTime(1);
        fnCum("face");
        if(isNude())
            fnCum("belly");
        else
            uVStatus(cumFrot,getRandInt(0,1));
        setImage(media(46));
        setDesc(str(114));
        makeActBtn("hanterstableBJ",act(3));
    }
    if(action == "suck_ut_sergei_cum2")
    {
        incTime(1);
        uVSC(swallow,1);
        setImage(media(45));
        fnSwallow();
        makeActBtn("hanterstableBJ",act(3));
    }
    if(action == "get_out_undertable")
    {
        sVStatus(edahot,1);
        actionHandler("hanterstable");
    }
    if(action == "enableBJ")
    {
        sVEvent(hanterstableBj,1);
        actionHandler("hanterstable");
    }
    if(action == "smoke1")
    {
        incTime(15);
        uVStatus(mood,10);
        if(gVEvent(hantersKnowSlut) == 0)
        {
            uVQuest(hantersAndreiQW,1);
            uVQuest(hantersIgorQW,1);
            uVQuest(hantersSergeiQW,1);
        }
        setImage(media(47));
        setDesc(str(68));
        makeActBtn("hanterstable",act(40));
    }
    if(action == "smoke_Andrei1")
    {
        incTime(15);
        uVStatus(mood,10);
        uVQuest(hantersAndreiQW,1);
        setImage(media(47));
        setDesc(str(70));
        makeActBtn("hanterstable",act(40));
    }
    if(action == "smoke_Andrei2")
    {
        incTime(15);
        uVStatus(mood,10);
        uVQuest(hantersAndreiQW,1);
        setImage(media(8));
        setDesc(str(71));
        makeActBtn("smoke_Andrei_bj_agree",act(10));
        if(gVAddict(alko) < 6)
            makeActBtn("smoke_Andrei_bj_disagree",act(11));
    }
    if(action == "smoke_Andrei_bj_agree")
    {
        incTime(10);
        uVStatus(horny,10);
        uVEvent(hanterslut,2);
        uVEvent(smokbj,1);
        uVQuest(hantersAndreiQW,1);
        setImage(media(48));
        setDesc(str(73));
        makeActBtn("hantersmokBj",act(12));
    }
    if(action == "smoke_Andrei_bj_disagree")
    {
        incTime(10);
        uVEvent(hanterslut,-1);
        uVQuest(hantersAndreiQW,1);
        setImage(media(48));
        setDesc(str(74));
        makeActBtn("hanterstable",act(40));
    }
    if(action == "smoke_Andrei3")
    {
        incTime(10);
        uVStatus(horny,5);
        uVEvent(hanterslut,1);
        uVQuest(hantersAndreiQW,1);
        uVSC(blowJob,1);
        setImage(media(8));
        setDesc(str(72));
        makeActBtn("hantersmokBj",act(12));
        if(gVAddict(alko) < 6)
            makeActBtn("smoke_Andrei_bj_disagree2",act(11));
    }
    if(action == "smoke_Andrei_bj_disagree2")
    {
        incTime(10);
        uVEvent(hanterslut,-1);
        uVQuest(hantersAndreiQW,-50);
        setImage(media(48));
        setDesc(str(75));
        makeActBtn("hanterstable",act(40));
    }
    if(action == "smoke_Andrei4")
    {
        incTime(10);
        uVStatus(horny,5);
        uVSC(blowJob,1);
        setImage(media(8));
        setDesc(str(72));
        makeActBtn("hantersmokBj",act(12));
    }
    if(action == "smoke_Sergei_agree")
    {
        incTime(15);
        uVStatus(mood,10);
        if(gVEvent(hantersKnowSlut) == 0)
            uVQuest(hantersSergeiQW,1);
        setImage(media(47));
        setDesc(str(77));
        makeActBtn("hanterstable",act(40));
    }
    if(action == "smoke_Igor_agree")
    {
        incTime(15);
        uVStatus(mood,10);
        if(gVEvent(hantersKnowSlut) == 0)
            uVQuest(hantersIgorQW,1);
        setImage(media(47));
        setDesc(str(79));
        makeActBtn("hanterstable",act(40));
    }

    if(action == "drink_vodka")
    {
        fnAlko(3);
        setImage(media(50));
        setDesc(str(115));
        makeActBtn("have_a_snack",act(53));
    }
    if(action == "have_a_snack")
    {
        incTime(10);
        uVStatus(health,10);
        setImage(media(49));
        if(gVStatus(energy) >= 24)
            setDesc(str(116));
        else if(gVStatus(energy) >= 18 && gVStatus(energy) < 24)
            setDesc(str(117));
        else
            setDesc(str(118));
        makeActBtn("hanterstable",act(3));
    }
    if(action == "drink_bear")
    {
        fnAlko(2);
        setImage(media(51));
        makeActBtn("hanterstable",act(3));
    }
    if(action == "exit_table")
    {
        sVEvent(hantersdrink,0);
        sVEvent(hanter_refuse,1);
        actionHandler("swamphouse");
    }

    if(action == "drunk_sleep1")
    {
        incTime(1);
        if(gVEvent(hantersIgorLove) <= 1)
            uVEvent(hanterslut,1);
        setImage(media(52));
        setDesc(str(81));
        makeActBtn("wakeup1",act(42));
    }
    if(action == "drunk_sleep2")
    {
        incTime(3);
        if(gVEvent(hantersIgorLove) <= 1)
            uVEvent(hanterslut,1);
        setImage(media(53));
        setDesc(str(83));
        makeActBtn("wakeup2",act(42));
    }
    if(action == "drunk_sleep3")
    {
        incTime(5);
        setImage(media(54));
        setDesc(str(85));
        makeActBtn("wakeup3",act(42));
    }
    if(action == "wakeup1")
    {
        incTime(180);
        uVStatus(son,6);
        uVStatus(health,-15);
        uVStatus(mood,-25);
        setImage(media(55));
        setDesc(str(82));
        makeActBtn("swamphouse",act(3));
    }
    if(action == "wakeup2")
    {
        incTime(240);
        uVStatus(son,8);
        uVStatus(health,-20);
        uVStatus(mood,-25);
        setImage(media(56));
        setDesc(str(84));
        makeActBtn("swamphouse",act(3));
    }
    if(action == "wakeup3")
    {
        incTime(360);
        uVStatus(son,12);
        uVStatus(health,-10);
        uVStatus(mood,-25);
        setImage(media(57));
        setDesc(str(86));
        makeActBtn("swamphouse",act(3));
    }
    if(action == "wakeup4")
    {
        incTime(480);
        uVStatus(son,16);
        uVStatus(health,-5);
        uVStatus(mood,-25);
        setImage(media(57));
        setDesc(str(89));
        makeActBtn("swamphouse",act(3));
    }
    if(action == "wakeup5")
    {
        incTime(360);
        uVStatus(son,12);
        uVStatus(health,-15);
        uVStatus(mood,-25);
        setImage(media(57));
        setDesc(str(92));
        makeActBtn("swamphouse",act(3));
    }
    if(action == "wakeup6")
    {
        incTime(240);
        uVStatus(son,8);
        uVStatus(health,-5);
        uVStatus(mood,-25);
        setImage(media(56));
        setDesc(str(96));
        makeActBtn("swamphouse",act(3));
    }
    if(action == "drunk_girl1")
    {
        incTime(1);
        setImage(media(58));
        setDesc(str(87));
        if(gVEvent(hanterslut) < 5)
            makeActBtn("dont_strip",act(42));
        if(gVEvent(hanterslut) >= 5)
            makeActBtn("dance_strip",act(44));
    }
    if(action == "dont_strip")
    {
        incTime(5);
        setImage(media(59));
        setDesc(str(88));
        makeActBtn("wakeup4",act(42));
    }
    if(action == "dance_strip")
    {
        incTime(10);
        uVStatus(horny,getRandInt(5,10));
        setImage(media(60));
        setDesc(str(90));
        if(gVEvent(hanterslut) >= 10)
            makeActBtn("dance_strip2",act(45));
        else
            makeActBtn("strip_end1",act(42));
    }
    if(action == "dance_strip2")
    {
        incTime(10);
        uVStatus(horny,getRandInt(5,10));
        uVEvent(hanterslut,1);
        if(gVEvent(hantersIgorLove) > 0)
            uVQuest(hantersIgorQW,-1);
        if(gVEvent(hantersAndreiLove) > 0)
            uVQuest(hantersAndreiQW,-1);
        if(gVEvent(hantersSergeiLove) > 0)
            uVQuest(hantersSergeiQW,-1);
        setImage(media(61));
        setDesc(str(93));
        if(gVEvent(hanterslut) >= 15)
            makeActBtn("dance_strip3",act(45));
        else
            makeActBtn("strip_end2",act(42));
    }
    if(action == "dance_strip3")
    {
        incTime(10);
        uVStatus(horny,getRandInt(5,10));
        uVEvent(hanterslut,1);
        if(gVEvent(hantersIgorLove) > 0)
            uVQuest(hantersIgorQW,-1);
        if(gVEvent(hantersAndreiLove) > 0)
            uVQuest(hantersAndreiQW,-1);
        if(gVEvent(hantersSergeiLove) > 0)
            uVQuest(hantersSergeiQW,-1);
        setImage(media(62));
        setDesc(str(95));
        makeActBtn("strip_end3",act(42));
    }
    if(action == "strip_end1")
    {
        incTime(5);
        setImage(media(59));
        setDesc(str(91));
        makeActBtn("wakeup5",act(42));
    }
    if(action == "stip_end2")
    {
        incTime(5);
        setImage(media(59));
        setDesc(str(94));
        makeActBtn("wakeup5",act(3));
    }
    if(action == "strip_end3")
    {
        incTime(1);
        setImage(media(63));
        makeActBtn("wakeup6",act(42));
    }

    if(action == "drunk_girl2")
    {
        incTime(1);
        setImage(media(58));
        setDesc(str(87));
        makeActBtn("strpi1",act(44));
    }
    if(action == "strip1")
    {
        incTime(10);
        uVStatus(horny,getRandInt(5,10));
        setImage(media(60));
        setDesc(str(90));
        makeActBtn("strip2",act(45));
    }
    if(action == "strip2")
    {
        incTime(10);
        uVStatus(horny,getRandInt(5,10));
        uVEvent(hanterslut,1);
        if(gVEvent(hantersIgorLove) > 0)
            uVQuest(hantersIgorQW,-1);
        if(gVEvent(hantersAndreiLove) > 0)
            uVQuest(hantersAndreiQW,-1);
        if(gVEvent(hantersSergeiLove) > 0)
            uVQuest(hantersSergeiQW,-1);
        setImage(media(61));
        setDesc(str(93));
        makeActBtn("strip3",act(45));
    }
    if(action == "strip3")
    {
        incTime(10);
        uVStatus(horny,getRandInt(5,10));
        uVEvent(hanterslut,1);
        if(gVEvent(hantersIgorLove) > 0)
            uVQuest(hantersIgorQW,-1);
        if(gVEvent(hantersAndreiLove) > 0)
            uVQuest(hantersAndreiQW,-1);
        if(gVEvent(hantersSergeiLove) > 0)
            uVQuest(hantersSergeiQW,-1);
        setImage(media(62));
        setDesc(str(95));
        makeActBtn("strip4",act(45));
    }
    if(action == "strip4")
    {
        incTime(10);
        uVStatus(horny,getRandInt(5,10));
        uVEvent(hanterslut,1);
        if(gVEvent(hantersIgorLove) > 0)
            uVQuest(hantersIgorQW,-1);
        if(gVEvent(hantersAndreiLove) > 0)
            uVQuest(hantersAndreiQW,-1);
        if(gVEvent(hantersSergeiLove) > 0)
            uVQuest(hantersSergeiQW,-1);
        setImage(media(64));
        setDesc(str(97));
        int tmp = getRandInt(1,2);
        if(tmp == 1)
            makeActBtn("stip4_sleep",act(42));
        else
            makeActBtn("strip5",act(45));
    }
    if(action == "strip4_sleep")
    {
        incTime(1);
        setImage(media(65));
        setDesc(str(99));
        makeActBtn("wakeup7",act(42));
    }
    if(action == "wakeup7")
    {
        incTime(240);
        uVStatus(son,8);
        uVStatus(health,-20);
        uVStatus(mood,-25);
        setImage(media(66));
        setDesc(str(100));
        makeActBtn("swamphouse",act(3));
    }
    if(action == "strip5")
    {
        incTime(10);
        uVStatus(horny,getRandInt(5,10));
        sVEvent(hantdancesex,1);
        setImage(media(67));
        setDesc(str(98));
        makeActBtn("hantersex",act(3));
    }

    if(action == "drunk_sleep4")
    {
        incTime(1);
        setImage(media(52));
        setDesc(str(81));
        makeActBtn("wakeup1",act(42));
    }
    if(action == "drunk_sleep5")
    {
        incTime(3);
        setImage(media(53));
        setDesc(str(83));
        makeActBtn("wakeup2",act(42));
    }
    if(action == "drunk_sleep6")
    {
        incTime(5);
        setImage(media(54));
        setDesc(str(85));
        makeActBtn("wakeup3",act(42));
    }
    if(action == "drunk_girl3")
    {
        incTime(1);
        setImage(media(58));
        setDesc(str(87));
        makeActBtn("strip1",act(44));
    }

    if(action == "talk_table")
    {
        incTime(15);
        if(gVQuest(hantersAndreiQW) < 10)
            uVQuest(hantersAndreiQW,1);
        if(gVQuest(hantersIgorQW) < 10)
            uVQuest(hantersIgorQW,1);
        if(gVQuest(hantersSergeiQW) < 10)
            uVQuest(hantersSergeiQW,1);
        setImage(media(7));
        setDesc(str(66));
        if(gVEvent(hantersdrink) == 1)
            makeActBtn("hanterstable",act(3));
        else
            makeActBtn("swamphouse",act(38));
    }

    if(action == "hantersrelax")
    {
        incTime(1);
        setImage(media(68));
        setDesc(str(119));
        makeActBtn("talk_Andrei",act(54));
        makeActBtn("talk_Sergei",act(55));
        makeActBtn("talk_Igor",act(56));
        makeActBtn("swamphouse",act(13));
    }
    if(action == "hantersmokBj")
    {
        setBoyName(str(105));
        sVSex(dick,20);
        incTime(5);
        uVStatus(horny,5);
        if(gVEvent(hantersAndreisex) == 0)
        {
            sVEvent(hantersAndreisex,1);
            uVSex(guy,1);
        }
        int tmp = getRandInt(1,2);
        setImage(media(69));
        if(gVEvent(hantersmokBJ) == 0)
            setDesc(str(120));
        if(gVEvent(hantersmokBJ) == 1)
            setDesc(str(121));
        fnBlowJob();
        if(tmp == 1)
            makeActBtn("smokBJ2",act(52));
        if(tmp == 2)
            makeActBtn("smokBJnext",act(52));
    }
    if(action == "smokBJ2")
    {
        sVEvent(hantersmokBJ,1);
        actionHandler("hantersmokBj");
    }
    if(action == "smokBJnext")
    {
        incTime(1);
        uVSC(swallow,1);
        sVEvent(hantersmokBJ,0);
        setImage(media(70));
        fnSwallow();
        setDesc(str(122));
        makeActBtn("hanterstable",act(40));
    }
}
