/********************************************************************************
** Form generated from reading UI file 'AddBook.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOOK_H
#define UI_ADDBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddBook
{
public:
    QDialogButtonBox *buttonBox;
    QCheckBox *checkBox;
    QLabel *checkmessage;
    QLineEdit *releaseAdd;
    QLineEdit *publishingAdd;
    QLineEdit *instockAdd;
    QLineEdit *ratingAdd;
    QLineEdit *urlAdd;
    QLineEdit *authorAdd;
    QLineEdit *titleAdd;
    QLabel *Atitle;
    QLabel *Aauthor;
    QLabel *Arelease;
    QLabel *Apublishing;
    QLabel *Ainstock;
    QLabel *Arating;
    QLabel *Aurl;

    void setupUi(QDialog *AddBook)
    {
        if (AddBook->objectName().isEmpty())
            AddBook->setObjectName("AddBook");
        AddBook->resize(781, 556);
        buttonBox = new QDialogButtonBox(AddBook);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(320, 500, 171, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        checkBox = new QCheckBox(AddBook);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(580, 40, 93, 26));
        checkmessage = new QLabel(AddBook);
        checkmessage->setObjectName("checkmessage");
        checkmessage->setGeometry(QRect(70, 30, 401, 41));
        releaseAdd = new QLineEdit(AddBook);
        releaseAdd->setObjectName("releaseAdd");
        releaseAdd->setGeometry(QRect(410, 210, 271, 28));
        publishingAdd = new QLineEdit(AddBook);
        publishingAdd->setObjectName("publishingAdd");
        publishingAdd->setGeometry(QRect(410, 270, 271, 28));
        instockAdd = new QLineEdit(AddBook);
        instockAdd->setObjectName("instockAdd");
        instockAdd->setGeometry(QRect(410, 330, 271, 28));
        ratingAdd = new QLineEdit(AddBook);
        ratingAdd->setObjectName("ratingAdd");
        ratingAdd->setGeometry(QRect(410, 390, 271, 28));
        urlAdd = new QLineEdit(AddBook);
        urlAdd->setObjectName("urlAdd");
        urlAdd->setGeometry(QRect(410, 450, 271, 28));
        authorAdd = new QLineEdit(AddBook);
        authorAdd->setObjectName("authorAdd");
        authorAdd->setGeometry(QRect(410, 150, 271, 28));
        titleAdd = new QLineEdit(AddBook);
        titleAdd->setObjectName("titleAdd");
        titleAdd->setGeometry(QRect(410, 90, 271, 28));
        Atitle = new QLabel(AddBook);
        Atitle->setObjectName("Atitle");
        Atitle->setGeometry(QRect(130, 90, 161, 20));
        Aauthor = new QLabel(AddBook);
        Aauthor->setObjectName("Aauthor");
        Aauthor->setGeometry(QRect(130, 150, 161, 20));
        Arelease = new QLabel(AddBook);
        Arelease->setObjectName("Arelease");
        Arelease->setGeometry(QRect(130, 210, 161, 20));
        Apublishing = new QLabel(AddBook);
        Apublishing->setObjectName("Apublishing");
        Apublishing->setGeometry(QRect(130, 270, 161, 20));
        Ainstock = new QLabel(AddBook);
        Ainstock->setObjectName("Ainstock");
        Ainstock->setGeometry(QRect(130, 330, 161, 20));
        Arating = new QLabel(AddBook);
        Arating->setObjectName("Arating");
        Arating->setGeometry(QRect(130, 390, 161, 20));
        Aurl = new QLabel(AddBook);
        Aurl->setObjectName("Aurl");
        Aurl->setGeometry(QRect(130, 450, 161, 20));

        retranslateUi(AddBook);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddBook, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddBook, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddBook);
    } // setupUi

    void retranslateUi(QDialog *AddBook)
    {
        AddBook->setWindowTitle(QCoreApplication::translate("AddBook", "Dialog", nullptr));
        checkBox->setText(QCoreApplication::translate("AddBook", "EBook", nullptr));
        checkmessage->setText(QCoreApplication::translate("AddBook", "\320\224\320\273\321\217 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\320\276\320\271 \320\272\320\275\320\270\320\263\320\270 \320\276\321\202\320\274\320\265\321\202\321\214\321\202\320\265 \321\204\320\273\320\260\320\266\320\272\320\276\320\274:", nullptr));
        Atitle->setText(QCoreApplication::translate("AddBook", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        Aauthor->setText(QCoreApplication::translate("AddBook", "\320\220\320\262\321\202\320\276\321\200", nullptr));
        Arelease->setText(QCoreApplication::translate("AddBook", "\320\223\320\276\320\264 \320\262\321\213\320\277\321\203\321\201\320\272\320\260", nullptr));
        Apublishing->setText(QCoreApplication::translate("AddBook", "\320\230\320\267\320\264\320\260\321\202\320\265\320\273\321\214\321\201\321\202\320\262\320\276", nullptr));
        Ainstock->setText(QCoreApplication::translate("AddBook", "\320\222 \320\275\320\260\320\273\320\270\321\207\320\270\320\270", nullptr));
        Arating->setText(QCoreApplication::translate("AddBook", "\320\240\320\265\320\271\321\202\320\270\320\275\320\263", nullptr));
        Aurl->setText(QCoreApplication::translate("AddBook", "\320\241\321\201\321\213\320\273\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddBook: public Ui_AddBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOK_H
