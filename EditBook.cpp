// #include "EditBook.h"
// #include "ui_EditBook.h"

// #include <QMessageBox>

// EditBook::EditBook(QWidget *parent, shared_ptr<Book>& bookRef)
//     : QDialog(parent), book(bookRef), ui(new Ui::EditBook)
// {
//     ui->setupUi(this);

//     ui->titleEditBook->setText(QString::fromLocal8Bit(book->title.c_str()));
//     ui->authorEditBook->setText(QString::fromLocal8Bit(book->author.c_str()));
//     ui->releaseEditBook->setText(QString::number(book->release_year));
//     ui->publishingEditBook->setText(QString::fromLocal8Bit(book->publishing_house.c_str()));
//     ui->in_stockEditBook->setText(QString::number(book->in_stock));
//     ui->ratingEditBook->setText(QString::number(book->rating));

//     auto eBook = dynamic_pointer_cast<EBook>(book);
//     if (eBook) {
//         ui->urlBook->setVisible(1);
//         ui->urlEditBook->setVisible(1);
//         ui->urlEditBook->setText(QString::fromLocal8Bit(eBook->link.c_str()));
//     } else {
//         ui->urlEditBook->clear();
//         ui->urlBook->setVisible(0);
//         ui->urlEditBook->setVisible(0);
//     }
// }

// EditBook::~EditBook()
// {
//     delete ui;
// }

// void EditBook::accept()
// {
//     bool valid = true;

//     QString title = ui->titleEditBook->text();
//     if (title.isEmpty()) {
//         QMessageBox::warning(this, "Ошибка ввода", "Название книги не может быть пустым.");
//         valid = false;
//     }

//     int releaseYear = ui->releaseEditBook->text().toInt();
//     if (releaseYear < 1000 || releaseYear > 2024) {
//         QMessageBox::warning(this, "Ошибка ввода", "Год выпуска должен быть в пределах от 1000 до 2024.");
//         valid = false;
//     }

//     QString publishingHouse = ui->publishingEditBook->text();
//     if (publishingHouse.isEmpty()) {
//         QMessageBox::warning(this, "Ошибка ввода", "Издательство не может быть пустым.");
//         valid = false;
//     }

//     int in_stock = ui->in_stockEditBook->text().toInt();
//     if (in_stock < 0 || in_stock > 1) {
//         QMessageBox::warning(this, "Ошибка ввода", "Показатель 'В наличии' должен быть 0 или 1.");
//         valid = false;
//     }

//     double rating = ui->ratingEditBook->text().toDouble();
//     if (rating < 0.0 || rating > 5.0) {
//         QMessageBox::warning(this, "Ошибка ввода", "Рейтинг должен быть числом от 0.0 до 5.0.");
//         valid = false;
//     }

//     if (valid) {
//         book->title = ui->titleEditBook->text().toLocal8Bit().constData();
//         book->author = ui->authorEditBook->text().toLocal8Bit().constData();
//         book->release_year = ui->releaseEditBook->text().toInt();
//         book->publishing_house = ui->publishingEditBook->text().toLocal8Bit().constData();
//         book->in_stock = ui->in_stockEditBook->text().toInt();
//         book->rating = ui->ratingEditBook->text().toInt();

//         auto eBook = dynamic_pointer_cast<EBook>(book);
//         if (eBook) {
//             eBook->link = ui->urlEditBook->text().toLocal8Bit().constData();
//         }

//         QDialog::accept();
//     }
// }
