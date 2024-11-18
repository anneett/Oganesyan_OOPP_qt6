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
    QLabel *label;
    QLineEdit *releaseAdd;
    QLineEdit *publishingAdd;
    QLineEdit *instockAdd;
    QLineEdit *ratingAdd;
    QLineEdit *urlAdd;
    QLineEdit *authorAdd;
    QLineEdit *titleAdd;

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
        label = new QLabel(AddBook);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 30, 401, 41));
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

        retranslateUi(AddBook);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddBook, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddBook, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddBook);
    } // setupUi

    void retranslateUi(QDialog *AddBook)
    {
        AddBook->setWindowTitle(QCoreApplication::translate("AddBook", "Dialog", nullptr));
        checkBox->setText(QCoreApplication::translate("AddBook", "EBook", nullptr));
        label->setText(QCoreApplication::translate("AddBook", "\320\224\320\273\321\217 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\320\276\320\271 \320\272\320\275\320\270\320\263\320\270 \320\276\321\202\320\274\320\265\321\202\321\214\321\202\320\265 \321\204\320\273\320\260\320\266\320\272\320\276\320\274:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddBook: public Ui_AddBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOK_H
