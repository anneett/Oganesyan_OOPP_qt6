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
    explicit AddBook(QWidget *parent, std::shared_ptr<Book>&);
    ~AddBook();
    void setLabels(bool);
    void on_checkBox_checkStateChanged(const Qt::CheckState &state);
    std::shared_ptr<Book> getNewBook() const { return book; }

private:
    Ui::AddBook *ui;
    void accept();

signals:

private slots:

};

#endif // ADDBOOK_H
