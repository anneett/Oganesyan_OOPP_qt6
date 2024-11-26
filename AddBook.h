#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QDialog>
#include "Book.h"
#include "EBook.h"

namespace Ui {
class AddBook;
}

class AddBook : public QDialog
{
    Q_OBJECT
    shared_ptr<Book> book;

public:
    enum Mode { Add, Edit };

    explicit AddBook(QWidget *parent, shared_ptr<Book>&, Mode mode = Add);
    ~AddBook();
    shared_ptr<Book> getNewBook() const { return book; }

private:
    Ui::AddBook *ui;
    Mode currentMode;
    void setLabels(bool checked);
    void setupUiByMode();
    void accept() override;

private slots:
    void on_checkBox_checkStateChanged(const Qt::CheckState &state);
};

#endif // ADDBOOK_H
