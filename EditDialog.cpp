#include "EditDialog.h"
#include "ui_EditDialog.h"

EditDialog::EditDialog(QWidget *parent, vector<std::shared_ptr<Book>>& booksRef)
    : QDialog(parent), books(booksRef), ui(new Ui::EditDialog)
{
    ui->setupUi(this);

    for(const auto& book : books)
    {
        QString bookInfo = QString::fromLocal8Bit(book->title);
        ui->listWidget->addItem(bookInfo);
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
    if (currentRow < 0 || currentRow >= books.size())
        return;

    auto book = books[currentRow];
    EditBook edtBook(this, book);

    if (edtBook.exec() == QDialog::Accepted)
    {
        ui->listWidget->item(currentRow)->setText(QString::fromLocal8Bit(book->title.c_str()));
        on_listWidget_currentRowChanged(currentRow);
    }
}

void EditDialog::on_DeleteButton_clicked()
{
    int currentRow = ui->listWidget->currentRow();
    if(currentRow < 0)
        return;
    books.erase(books.begin() + currentRow);
    delete ui->listWidget->takeItem(currentRow);
}

// void EditDialog::on_AddButton_clicked()
// {
//     books.push_back(QPointF(data.points.size() * 50, data.points.size() * 50));
//     ui->listWidget->addItem(pointToString(data.points.back()));
//     ui->listWidget->setCurrentRow(data.points.size()-1);
//     updateControls();
// }

// void EditDialog::saveBook(shared_ptr<Book>& book)
// {
//     // Сохраните изменения обратно в объект книги
//     book->title = ui->titleEdit->text().toStdString();
//     book->author = ui->authorEdit->text().toStdString();
//     book->release_year = ui->releaseEdit->value();
//     book->publishing_house = ui->publishingEdit->text().toStdString();
//     book->in_stock = ui->ratingEdit->value();
//     book->rating = ui->urlEdit->text().toStdString();
// }



// void EditDialog::updateControls()
// {
//     bool show = !data.points.empty();
//     ui->labelX->setVisible(show);
//     ui->labelY->setVisible(show);
//     ui->spinX->setVisible(show);
//     ui->spinY->setVisible(show);
//     ui->deleteButton->setEnabled(show);
// }

// void EditDialog::on_sliderW_valueChanged(int value)
// {
//     emit setWidth(value);
// }


// void EditDialog::on_sliderH_valueChanged(int value)
// {
//     emit setHeight(value);
// }
