#ifndef BOOKS_H
#define BOOKS_H

#include "GameObj.h"
#include "objecthandler.h"

struct Book
{
    int id;
    QString name;
    int page;
    bool exist;
};

class Books: public GameObj
{
public:
    Books(ObjectHandler* ptr);
    ~Books(){};
    QString getName() override;
    QString getImage() override;
    QString getDesc() override;
    QString getBookName(int id);
    void viewBooks();
    void initBooks();
    int sisBook();
    void readBook(int id);
    void read_procedure();
    void readed();
    void erotic_enable();
    int novel_readed();
    int ero_readed();
    void erotic_block();
    void remove_ero();
    void shop(QString arg = "");
    int getPrice(int id);
    void buy();
    void book2bag();
    void readOnWalk();
    void customShelf(int min = 0, int max = 39);
private slots:
    void slotActionHandler(QString action, int id = -1);
private:
    void makeBookWgt(int id, QString name, int read);
    void makeActBtn(QString action, QString actName);
    QString str(int id);
    QString act(int id);
    QString media(int id);
    ObjectHandler* root;
    int curBook{-1};
    std::vector<Book> m_books;
    QLabel* lbl = nullptr;
    QVBoxLayout* layout = nullptr;
};

#endif // BOOKS_H
