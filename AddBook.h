#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QDialog>
#include "EditDialog.h"

namespace Ui {
class AddBook;
}

class AddBook : public QDialog
{
    Q_OBJECT
    shared_ptr<Book> book;

public:
    explicit AddBook(QWidget *parent, shared_ptr<Book>& bookRef);
    ~AddBook();
    void setLabels(bool);
    void on_checkBox_checkStateChanged(const Qt::CheckState &state);

private:
    Ui::AddBook *ui;
    void accept();

signals:

private slots:

};

#endif // ADDBOOK_H
