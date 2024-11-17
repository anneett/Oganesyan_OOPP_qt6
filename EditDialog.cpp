#include "EditDialog.h"
#include "ui_EditDialog.h"

// extern QString pointToString(QPointF& p);

EditDialog::EditDialog(QWidget *parent, vector<std::shared_ptr<Book>>& booksRef)
    : QDialog(parent), books(booksRef), ui(new Ui::EditDialog)
{
    ui->setupUi(this);
    // ui->checkBox->setChecked(data.labels);
    qDebug() << "Books count in EditDialog constructor: " << books.size();
    for(const auto& book : books)
    {
        QString bookInfo = QString::fromLocal8Bit(book->title);
        qDebug() << "Adding book: " << bookInfo;
        ui->listWidget->addItem(bookInfo);
    }
    ui->listWidget->setCurrentRow(0);
    // ui->sliderH->setValue(data.h);
    // ui->sliderW->setValue(data.w);

    // connect(ui->listWidget, &QListWidget::currentRowChanged, this, &EditDialog::onBookSelected);

    // // Инициализируем поля для первой книги (если список не пуст)
    // if (!books.empty()) {
    //     populateFields(0);
    // }
}

EditDialog::~EditDialog()
{
    delete ui;
}

// void EditDialog::on_checkBox_checkStateChanged(const Qt::CheckState &state)
// {
//     emit setLabels(state == Qt::Checked);
// }

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

// void EditDialog::on_spinX_valueChanged(int x)
// {
//     int currentRow = ui->listWidget->currentRow();
//     if(currentRow < 0)
//         return;
//     data.points[currentRow].setX(x);
//     ui->listWidget->currentItem()->setText(pointToString(data.points[currentRow]));
// }


// void EditDialog::on_spinY_valueChanged(int y)
// {
//     int currentRow = ui->listWidget->currentRow();
//     if(currentRow < 0)
//         return;
//     data.points[currentRow].setY(y);
//     ui->listWidget->currentItem()->setText(pointToString(data.points[currentRow]));
// }


// void EditDialog::on_addButton_clicked()
// {
//     data.points.push_back(QPointF(data.points.size() * 50, data.points.size() * 50));
//     ui->listWidget->addItem(pointToString(data.points.back()));
//     ui->listWidget->setCurrentRow(data.points.size()-1);
//     updateControls();
// }


// void EditDialog::on_deleteButton_clicked()
// {
//     int currentRow = ui->listWidget->currentRow();
//     if(currentRow < 0)
//         return;
//     data.points.erase(data.points.begin() + currentRow);
//     delete ui->listWidget->takeItem(currentRow);
//     updateControls();
// }




// void EditDialog::on_sliderW_valueChanged(int value)
// {
//     emit setWidth(value);
// }


// void EditDialog::on_sliderH_valueChanged(int value)
// {
//     emit setHeight(value);
// }
