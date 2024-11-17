#ifndef EDITBOOK_H
#define EDITBOOK_H

#include <QDialog>
#include "EditDialog.h"

namespace Ui {
class EditBook;
}

class EditBook : public QDialog
{
    Q_OBJECT
    shared_ptr<Book> book;

public:
    explicit EditBook(QWidget *parent, shared_ptr<Book>& bookRef);
    ~EditBook();

private:
    Ui::EditBook *ui;

signals:

private slots:

};

#endif // EDITBOOK_H
