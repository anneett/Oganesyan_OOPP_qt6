#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "WidgetOganesyan.h"

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
    if (!fileName.isEmpty())
        (ui->widgetOganesyanInstance)->load(fileName);
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

