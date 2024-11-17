/********************************************************************************
** Form generated from reading UI file 'EditDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIALOG_H
#define UI_EDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EditDialog
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;
    QLabel *title;
    QLabel *author;
    QLabel *release;
    QLabel *publishing;
    QLabel *instock;
    QLabel *rating;
    QLabel *url;
    QLineEdit *releaseEdit;
    QLineEdit *publishingEdit;
    QLineEdit *instockEdit;
    QLineEdit *ratingEdit;
    QLineEdit *urlEdit;
    QPushButton *AddButton;
    QPushButton *EditButton;
    QPushButton *DeleteButton;
    QLineEdit *authorEdit;
    QLineEdit *titleEdit;

    void setupUi(QDialog *EditDialog)
    {
        if (EditDialog->objectName().isEmpty())
            EditDialog->setObjectName("EditDialog");
        EditDialog->resize(1007, 558);
        buttonBox = new QDialogButtonBox(EditDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(650, 490, 171, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        listWidget = new QListWidget(EditDialog);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(25, 21, 481, 511));
        title = new QLabel(EditDialog);
        title->setObjectName("title");
        title->setGeometry(QRect(590, 30, 91, 21));
        author = new QLabel(EditDialog);
        author->setObjectName("author");
        author->setGeometry(QRect(590, 90, 91, 21));
        release = new QLabel(EditDialog);
        release->setObjectName("release");
        release->setGeometry(QRect(590, 150, 91, 21));
        publishing = new QLabel(EditDialog);
        publishing->setObjectName("publishing");
        publishing->setGeometry(QRect(590, 210, 111, 16));
        instock = new QLabel(EditDialog);
        instock->setObjectName("instock");
        instock->setGeometry(QRect(590, 270, 91, 21));
        rating = new QLabel(EditDialog);
        rating->setObjectName("rating");
        rating->setGeometry(QRect(590, 330, 91, 21));
        url = new QLabel(EditDialog);
        url->setObjectName("url");
        url->setGeometry(QRect(590, 390, 91, 21));
        releaseEdit = new QLineEdit(EditDialog);
        releaseEdit->setObjectName("releaseEdit");
        releaseEdit->setGeometry(QRect(760, 150, 191, 28));
        publishingEdit = new QLineEdit(EditDialog);
        publishingEdit->setObjectName("publishingEdit");
        publishingEdit->setGeometry(QRect(760, 210, 191, 28));
        instockEdit = new QLineEdit(EditDialog);
        instockEdit->setObjectName("instockEdit");
        instockEdit->setGeometry(QRect(760, 270, 191, 28));
        ratingEdit = new QLineEdit(EditDialog);
        ratingEdit->setObjectName("ratingEdit");
        ratingEdit->setGeometry(QRect(760, 330, 191, 28));
        urlEdit = new QLineEdit(EditDialog);
        urlEdit->setObjectName("urlEdit");
        urlEdit->setGeometry(QRect(760, 390, 191, 28));
        AddButton = new QPushButton(EditDialog);
        AddButton->setObjectName("AddButton");
        AddButton->setGeometry(QRect(530, 440, 121, 31));
        EditButton = new QPushButton(EditDialog);
        EditButton->setObjectName("EditButton");
        EditButton->setGeometry(QRect(680, 440, 121, 31));
        DeleteButton = new QPushButton(EditDialog);
        DeleteButton->setObjectName("DeleteButton");
        DeleteButton->setGeometry(QRect(830, 440, 121, 31));
        authorEdit = new QLineEdit(EditDialog);
        authorEdit->setObjectName("authorEdit");
        authorEdit->setGeometry(QRect(760, 90, 191, 28));
        titleEdit = new QLineEdit(EditDialog);
        titleEdit->setObjectName("titleEdit");
        titleEdit->setGeometry(QRect(760, 30, 191, 28));

        retranslateUi(EditDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EditDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EditDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EditDialog);
    } // setupUi

    void retranslateUi(QDialog *EditDialog)
    {
        EditDialog->setWindowTitle(QCoreApplication::translate("EditDialog", "Dialog", nullptr));
        title->setText(QCoreApplication::translate("EditDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        author->setText(QCoreApplication::translate("EditDialog", "\320\220\320\262\321\202\320\276\321\200", nullptr));
        release->setText(QCoreApplication::translate("EditDialog", "\320\223\320\276\320\264 \320\262\321\213\320\277\321\203\321\201\320\272\320\260", nullptr));
        publishing->setText(QCoreApplication::translate("EditDialog", "\320\230\320\267\320\264\320\260\321\202\320\265\320\273\321\214\321\201\321\202\320\262\320\276", nullptr));
        instock->setText(QCoreApplication::translate("EditDialog", "\320\222 \320\275\320\260\320\273\320\270\321\207\320\270\320\270", nullptr));
        rating->setText(QCoreApplication::translate("EditDialog", "\320\240\320\265\320\271\321\202\320\270\320\275\320\263", nullptr));
        url->setText(QCoreApplication::translate("EditDialog", "\320\241\321\201\321\213\320\273\320\272\320\260", nullptr));
        AddButton->setText(QCoreApplication::translate("EditDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        EditButton->setText(QCoreApplication::translate("EditDialog", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        DeleteButton->setText(QCoreApplication::translate("EditDialog", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditDialog: public Ui_EditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIALOG_H
