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
    QLineEdit *titleEdit;
    QLineEdit *authorEdit;
    QLineEdit *releaseEdit;
    QLineEdit *publishingEdit;
    QLineEdit *instockEdit;
    QLineEdit *ratingEdit;
    QLineEdit *urlEdit;

    void setupUi(QDialog *EditDialog)
    {
        if (EditDialog->objectName().isEmpty())
            EditDialog->setObjectName("EditDialog");
        EditDialog->resize(976, 558);
        buttonBox = new QDialogButtonBox(EditDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(650, 480, 171, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        listWidget = new QListWidget(EditDialog);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(25, 21, 481, 511));
        title = new QLabel(EditDialog);
        title->setObjectName("title");
        title->setGeometry(QRect(530, 40, 91, 21));
        author = new QLabel(EditDialog);
        author->setObjectName("author");
        author->setGeometry(QRect(530, 90, 91, 21));
        release = new QLabel(EditDialog);
        release->setObjectName("release");
        release->setGeometry(QRect(530, 140, 91, 21));
        publishing = new QLabel(EditDialog);
        publishing->setObjectName("publishing");
        publishing->setGeometry(QRect(530, 200, 111, 16));
        instock = new QLabel(EditDialog);
        instock->setObjectName("instock");
        instock->setGeometry(QRect(530, 250, 91, 21));
        rating = new QLabel(EditDialog);
        rating->setObjectName("rating");
        rating->setGeometry(QRect(530, 290, 91, 21));
        url = new QLabel(EditDialog);
        url->setObjectName("url");
        url->setGeometry(QRect(540, 340, 91, 21));
        titleEdit = new QLineEdit(EditDialog);
        titleEdit->setObjectName("titleEdit");
        titleEdit->setGeometry(QRect(730, 40, 191, 28));
        authorEdit = new QLineEdit(EditDialog);
        authorEdit->setObjectName("authorEdit");
        authorEdit->setGeometry(QRect(730, 90, 191, 28));
        releaseEdit = new QLineEdit(EditDialog);
        releaseEdit->setObjectName("releaseEdit");
        releaseEdit->setGeometry(QRect(730, 140, 191, 28));
        publishingEdit = new QLineEdit(EditDialog);
        publishingEdit->setObjectName("publishingEdit");
        publishingEdit->setGeometry(QRect(730, 190, 191, 28));
        instockEdit = new QLineEdit(EditDialog);
        instockEdit->setObjectName("instockEdit");
        instockEdit->setGeometry(QRect(730, 240, 191, 28));
        ratingEdit = new QLineEdit(EditDialog);
        ratingEdit->setObjectName("ratingEdit");
        ratingEdit->setGeometry(QRect(730, 290, 191, 28));
        urlEdit = new QLineEdit(EditDialog);
        urlEdit->setObjectName("urlEdit");
        urlEdit->setGeometry(QRect(730, 340, 191, 28));

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
    } // retranslateUi

};

namespace Ui {
    class EditDialog: public Ui_EditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIALOG_H
