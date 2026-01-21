#ifndef NPC_EDITOR_H
#define NPC_EDITOR_H

#include "npc.h"
#include <QWidget>
#include "../player/enums.h"
#include "../events/questenums.h"
#include "../events/eventenums.h"

class NPC_Editor: public QObject
{
    Q_OBJECT
public:
    NPC_Editor(QWidget * ptr);
    void init();
    NPC& gNPC(int id);
    QString getNpcTex(int id);
    QString getNpcLink(int id);
    QString getNpcGroup(int id);
    QString makeNpcGroup(int group);
    int getAvgRelation(npcGroup group);
    void rendNpcProfile(NPCId id);
    void rendRealationList();
    void changeRep(char act, int id, int val = 0, int cup = 0, bool msgShow = true);
private slots:
    void slotActHandler(QString link);
private:
    int getAge();
    int gVStatus(Status param);
    int gVSKill(Skills param);
    int gVQuest(QuestParams param);
    int gVEvent(EventParams param);
    LocId getCurLocId();
    void sendNotif(QString msg);
    void message(QString type);
    NPC genRandboyfriend(int i);
    QString str(int id);
    QString media(int id);
private:
    int curNpc;
    std::vector<NPC> npcs;
    QWidget* root;
};

#endif // NPC_EDITOR_H
