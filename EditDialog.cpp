#include "EditDialog.h"
#include "ui_EditDialog.h"
#include <QMessageBox>

EditDialog::EditDialog(QWidget *parent, vector<std::shared_ptr<Book>>& booksRef)
    : QDialog(parent), books(booksRef), ui(new Ui::EditDialog)
{
    ui->setupUi(this);

    QFont font;
    font.setPointSize(11);
    this->setFont(font);

    for(const auto& book : books)
    {
        QString bookInfo = QString::fromLocal8Bit(book->title);
        ui->listWidget->addItem(bookInfo);
    }

    if (ui->listWidget->count() > 0) {
        ui->listWidget->setCurrentRow(0);
        on_listWidget_currentRowChanged(0);
    }

    ui->titleEdit->setReadOnly(true);
    ui->authorEdit->setReadOnly(true);
    ui->releaseEdit->setReadOnly(true);
    ui->publishingEdit->setReadOnly(true);
    ui->instockEdit->setReadOnly(true);
    ui->ratingEdit->setReadOnly(true);
    ui->urlEdit->setReadOnly(true);

    ui->titleEdit->installEventFilter(this);
    ui->authorEdit->installEventFilter(this);
    ui->releaseEdit->installEventFilter(this);
    ui->publishingEdit->installEventFilter(this);
    ui->instockEdit->installEventFilter(this);
    ui->ratingEdit->installEventFilter(this);
    ui->urlEdit->installEventFilter(this);
}

EditDialog::~EditDialog()
{
    delete ui;
}

bool EditDialog::eventFilter(QObject* obj, QEvent* event)
{
    QLineEdit* lineEdit = qobject_cast<QLineEdit*>(obj);
    if (lineEdit && event->type() == QEvent::KeyPress)
    {
        return true;
    }
    return QDialog::eventFilter(obj, event);
}

void EditDialog::on_listWidget_currentRowChanged(int currentRow)
{
    if(currentRow < 0 || currentRow >= books.size())
        return;

    ui->titleEdit->setText(QString::fromLocal8Bit(books[currentRow]->title.c_str()));
    ui->authorEdit->setText(QString::fromLocal8Bit(books[currentRow]->author.c_str()));
    ui->releaseEdit->setText(QString::number(books[currentRow]->release_year));
    ui->publishingEdit->setText(QString::fromLocal8Bit(books[currentRow]->publishing_house.c_str()));
    ui->instockEdit->setText(QString::number(books[currentRow]->in_stock));
    ui->ratingEdit->setText(QString::number(books[currentRow]->rating));

    auto eBook = dynamic_pointer_cast<EBook>(books[currentRow]);
    if (eBook) {
        ui->url->setVisible(1);
        ui->urlEdit->setVisible(1);
        ui->urlEdit->setText(QString::fromLocal8Bit(eBook->link.c_str()));
    } else {
        ui->urlEdit->clear();
        ui->url->setVisible(0);
        ui->urlEdit->setVisible(0);
    }
}

void EditDialog::on_EditButton_clicked()
{
    int currentRow = ui->listWidget->currentRow();
    if (currentRow < 0 || currentRow >= books.size()) {
        QMessageBox::information(this, "Нет книг", "У вас нет книг для редактирования.");
        return;
    }

    auto book = books[currentRow];

    AddBook editBookDialog(this, book, AddBook::Edit);

    if (editBookDialog.exec() == QDialog::Accepted) {
        auto updatedBook = editBookDialog.getNewBook();
        if (updatedBook) {
            books[currentRow] = updatedBook;

            QString updatedBookInfo = QString::fromLocal8Bit(updatedBook->title.c_str());
            ui->listWidget->item(currentRow)->setText(updatedBookInfo);

            on_listWidget_currentRowChanged(currentRow);
        }
    }
}

void EditDialog::on_DeleteButton_clicked()
{
    int currentRow = ui->listWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::information(this, "Нет книг", "У вас нет книг для удаления.");
        return;
    }
    books.erase(books.begin() + currentRow);
    delete ui->listWidget->takeItem(currentRow);

    if (books.empty()) {
        ui->titleEdit->clear();
        ui->authorEdit->clear();
        ui->releaseEdit->clear();
        ui->publishingEdit->clear();
        ui->instockEdit->clear();
        ui->ratingEdit->clear();
        ui->urlEdit->clear();
        ui->url->setVisible(false);
        ui->urlEdit->setVisible(false);
    }
}

void EditDialog::on_AddButton_clicked()
{
    shared_ptr<Book> newBook;
    AddBook addBook(this, newBook);

    if (addBook.exec() == QDialog::Accepted) {
        newBook = addBook.getNewBook();
        if (newBook) {
            books.push_back(newBook);
                 QString bookInfo = QString::fromLocal8Bit(newBook->title.c_str());
                 ui->listWidget->addItem(bookInfo);
                 ui->listWidget->setCurrentRow(books.size() - 1);
                 on_listWidget_currentRowChanged(books.size() - 1);
        }
    }
}
