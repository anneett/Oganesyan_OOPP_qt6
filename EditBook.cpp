#include "EditBook.h"
#include "ui_EditBook.h"

EditBook::EditBook(QWidget *parent, shared_ptr<Book>& bookRef)
    : QDialog(parent), book(bookRef), ui(new Ui::EditBook)
{
    ui->setupUi(this);

    ui->titleEditBook->setText(QString::fromLocal8Bit(book->title.c_str()));
    ui->authorEditBook->setText(QString::fromLocal8Bit(book->author.c_str()));
    ui->releaseEditBook->setText(QString::number(book->release_year));
    ui->publishingEditBook->setText(QString::fromLocal8Bit(book->publishing_house.c_str()));
    ui->in_stockEditBook->setText(QString::number(book->in_stock));
    ui->ratingEditBook->setText(QString::number(book->rating));

    auto eBook = dynamic_pointer_cast<EBook>(book);
    if (eBook) {
        ui->urlBook->setVisible(1);
        ui->urlEditBook->setVisible(1);
        ui->urlEditBook->setText(QString::fromLocal8Bit(eBook->link.c_str()));
    } else {
        ui->urlEditBook->clear();
        ui->urlBook->setVisible(0);
        ui->urlEditBook->setVisible(0);
    }
}

EditBook::~EditBook()
{
    delete ui;
}