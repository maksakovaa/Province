#include <QString>

class NPC
{
public:
    NPC();
    QString getName();
    int getSilaVag();
    void talk();
private:
    QString m_name;
    int m_silavag;
};