#include "AddBook.h"
#include "ui_AddBook.h"

AddBook::AddBook(QWidget *parent, shared_ptr<Book>& bookRef)
    : QDialog(parent), book(bookRef), ui(new Ui::AddBook)
{
    ui->setupUi(this);

}

AddBook::~AddBook()
{
    delete ui;
}
