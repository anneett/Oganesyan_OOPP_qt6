#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "WidgetOganesyan.h"
#include "EditDialog.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    ui->scrollArea->setWidgetResizable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Открыть"), QDir::currentPath(), tr("Файл данных (*.dat)"));
    if (!fileName.isEmpty()) {
        ui->widgetOganesyanInstance->load(fileName);

        // Проверяем после загрузки
        qDebug() << "Books loaded in WidgetOganesyan: " << ui->widgetOganesyanInstance->books.size();
    }
}
void MainWindow::on_actionSaveAs_triggered()
{
    fileName = QFileDialog::getSaveFileName(this, tr("Сохранить как"), QDir::currentPath(), tr("Файл данных (*.dat)"));
    if (!fileName.isEmpty())
        save();
}

void MainWindow::on_actionNew_triggered()
{
    (ui->widgetOganesyanInstance)->clean();
    fileName = "";
}

void MainWindow::save()
{
    (ui->widgetOganesyanInstance)->save(fileName);
}

void MainWindow::on_actionEdit_books_triggered()
{
    // Проверяем, есть ли книги в WidgetOganesyan
    auto widgetBooks = ui->widgetOganesyanInstance->books;
    qDebug() << "Books count before opening EditDialog: " << widgetBooks.size();

    if (widgetBooks.size() == 0) {
        qDebug() << "У вас нет книг для редактирования";
        return;
    }
    // Создаем диалог и передаем книги из WidgetOganesyan
    EditDialog dlg(this, ui->widgetOganesyanInstance->books);

    // Проверяем, что книги переданы в конструктор
    qDebug() << "Books count in EditDialog constructor: " << ui->widgetOganesyanInstance->books.size();

    // Если изменения подтверждены, обновляем виджет
    if (dlg.exec() == QDialog::Accepted) {
        ui->widgetOganesyanInstance->update();
    }
}
