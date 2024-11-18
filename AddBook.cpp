#include "AddBook.h"
#include "ui_AddBook.h"
#include <QMessageBox>

AddBook::AddBook(QWidget *parent, shared_ptr<Book>& bookRef)
    : QDialog(parent), book(bookRef), ui(new Ui::AddBook)
{
    ui->setupUi(this);

    ui->titleAdd->setText(QString::fromLocal8Bit(book->title.c_str()));
    ui->authorAdd->setText(QString::fromLocal8Bit(book->author.c_str()));
    ui->releaseAdd->setText(QString::number(book->release_year));
    ui->publishingAdd->setText(QString::fromLocal8Bit(book->publishing_house.c_str()));
    ui->instockAdd->setText(QString::number(book->in_stock));
    ui->ratingAdd->setText(QString::number(book->rating));

    auto eBook = dynamic_pointer_cast<EBook>(book);
    if (eBook) {
        ui->urlAdd->setText(QString::fromLocal8Bit(eBook->link.c_str()));
    } else {
        ui->urlAdd->clear();
    }

    bool isChecked = ui->checkBox->isChecked();
    ui->urlAdd->setVisible(isChecked);
    ui->Aurl->setVisible(isChecked);

    connect(ui->checkBox, &QCheckBox::checkStateChanged, this, &AddBook::on_checkBox_checkStateChanged);
}

AddBook::~AddBook()
{
    delete ui;
}

void AddBook::on_checkBox_checkStateChanged(const Qt::CheckState &state)
{
    if (state == Qt::Checked) {
        book = make_shared<EBook>(*dynamic_cast<EBook*>(book.get()));
    }
    emit setLabels(state == Qt::Checked);
}

void AddBook::setLabels(bool checked)
{
    ui->urlAdd->setVisible(checked);
    ui->Aurl->setVisible(checked);
}

void AddBook::accept()
{
    bool valid = true;

    QString title = ui->titleAdd->text();
    if (title.isEmpty()) {
        QMessageBox::warning(this, "Ошибка ввода", "Название книги не может быть пустым.");
        valid = false;
    }

    int releaseYear = ui->releaseAdd->text().toInt();
    if (releaseYear < 1000 || releaseYear > 2024) {
        QMessageBox::warning(this, "Ошибка ввода", "Год выпуска должен быть в пределах от 1000 до 2024.");
        valid = false;
    }

    QString publishingHouse = ui->publishingAdd->text();
    if (publishingHouse.isEmpty()) {
        QMessageBox::warning(this, "Ошибка ввода", "Издательство не может быть пустым.");
        valid = false;
    }

    int in_stock = ui->instockAdd->text().toInt();
    if (in_stock < 0 || in_stock > 1) {
        QMessageBox::warning(this, "Ошибка ввода", "Показатель 'В наличии' должен быть 0 или 1.");
        valid = false;
    }

    double rating = ui->ratingAdd->text().toDouble();
    if (rating < 0.0 || rating > 5.0) {
        QMessageBox::warning(this, "Ошибка ввода", "Рейтинг должен быть числом от 0.0 до 5.0.");
        valid = false;
    }

    if (valid) {
        book->title = ui->titleAdd->text().toLocal8Bit().constData();
        book->author = ui->authorAdd->text().toLocal8Bit().constData();
        book->release_year = releaseYear;
        book->publishing_house = ui->publishingAdd->text().toLocal8Bit().constData();
        book->in_stock = ui->instockAdd->text().toInt();
        book->rating = rating;

        auto eBook = dynamic_pointer_cast<EBook>(book);
        if (eBook) {
            eBook->link = ui->urlAdd->text().toLocal8Bit().constData();
        }

        QDialog::accept();
    }
}
