#include "AddBook.h"
#include "ui_AddBook.h"
#include <QMessageBox>

AddBook::AddBook(QWidget *parent, shared_ptr<Book>& _book, Mode mode)
    : QDialog(parent), ui(new Ui::AddBook), book(_book), currentMode(mode)
{
    ui->setupUi(this);

    QFont font;
    font.setPointSize(11);
    this->setFont(font);

    setupUiByMode();

    if (currentMode == Edit && book) {
        ui->titleAdd->setText(QString::fromLocal8Bit(book->title.c_str()));
        ui->authorAdd->setText(QString::fromLocal8Bit(book->author.c_str()));
        ui->releaseAdd->setText(QString::number(book->release_year));
        ui->publishingAdd->setText(QString::fromLocal8Bit(book->publishing_house.c_str()));
        ui->instockAdd->setText(QString::number(book->in_stock));
        ui->ratingAdd->setText(QString::number(book->rating));

        auto eBook = dynamic_pointer_cast<EBook>(book);
        if (eBook) {
            ui->urlAdd->setText(QString::fromLocal8Bit(eBook->link.c_str()));
            ui->checkBox->setChecked(true);
        } else {
            ui->urlAdd->clear();
            ui->checkBox->setChecked(false);
        }
    }

    connect(ui->checkBox, &QCheckBox::checkStateChanged, this, &AddBook::on_checkBox_checkStateChanged);
}

AddBook::~AddBook()
{
    delete ui;
}

void AddBook::setupUiByMode()
{
    if (currentMode == Edit) {
        ui->checkBox->hide();
        ui->checkmessage->hide();
    }

    bool isChecked = ui->checkBox->isChecked();
    setLabels(isChecked);
}

void AddBook::setLabels(bool checked)
{
    ui->urlAdd->setVisible(checked);
    ui->Aurl->setVisible(checked);
}

void AddBook::on_checkBox_checkStateChanged(const Qt::CheckState &state)
{
    setLabels(state == Qt::Checked);
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

    if (!valid)
        return;

    bool isChecked = ui->checkBox->isChecked();
    if (isChecked) {
        auto eBook = make_shared<EBook>();
        eBook->title = ui->titleAdd->text().toLocal8Bit().constData();
        eBook->author = ui->authorAdd->text().toLocal8Bit().constData();
        eBook->release_year = ui->releaseAdd->text().toInt();
        eBook->publishing_house = ui->publishingAdd->text().toLocal8Bit().constData();
        eBook->in_stock = ui->instockAdd->text().toInt();
        eBook->rating = ui->ratingAdd->text().toDouble();
        eBook->link = ui->urlAdd->text().toLocal8Bit().constData();

        book = eBook;
    } else {
        book = make_shared<Book>();
        book->title = ui->titleAdd->text().toLocal8Bit().constData();
        book->author = ui->authorAdd->text().toLocal8Bit().constData();
        book->release_year = ui->releaseAdd->text().toInt();
        book->publishing_house = ui->publishingAdd->text().toLocal8Bit().constData();
        book->in_stock = ui->instockAdd->text().toInt();
        book->rating = ui->ratingAdd->text().toDouble();
    }

    QDialog::accept();
}
