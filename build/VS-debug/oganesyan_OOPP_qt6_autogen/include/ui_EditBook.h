/********************************************************************************
** Form generated from reading UI file 'EditBook.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITBOOK_H
#define UI_EDITBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_EditBook
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *titleBook;
    QLabel *authorBook;
    QLabel *releaseBook;
    QLabel *publishigBook;
    QLabel *in_stockBook;
    QLabel *ratingBook;
    QLabel *urlBook;
    QLineEdit *titleEditBook;
    QLineEdit *authorEditBook;
    QLineEdit *releaseEditBook;
    QLineEdit *publishingEditBook;
    QLineEdit *in_stockEditBook;
    QLineEdit *ratingEditBook;
    QLineEdit *urlEditBook;

    void setupUi(QDialog *EditBook)
    {
        if (EditBook->objectName().isEmpty())
            EditBook->setObjectName("EditBook");
        EditBook->resize(807, 540);
        buttonBox = new QDialogButtonBox(EditBook);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(310, 460, 171, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        titleBook = new QLabel(EditBook);
        titleBook->setObjectName("titleBook");
        titleBook->setGeometry(QRect(110, 40, 151, 20));
        authorBook = new QLabel(EditBook);
        authorBook->setObjectName("authorBook");
        authorBook->setGeometry(QRect(110, 90, 151, 20));
        releaseBook = new QLabel(EditBook);
        releaseBook->setObjectName("releaseBook");
        releaseBook->setGeometry(QRect(110, 150, 151, 20));
        publishigBook = new QLabel(EditBook);
        publishigBook->setObjectName("publishigBook");
        publishigBook->setGeometry(QRect(110, 210, 151, 20));
        in_stockBook = new QLabel(EditBook);
        in_stockBook->setObjectName("in_stockBook");
        in_stockBook->setGeometry(QRect(110, 270, 151, 20));
        ratingBook = new QLabel(EditBook);
        ratingBook->setObjectName("ratingBook");
        ratingBook->setGeometry(QRect(110, 330, 151, 20));
        urlBook = new QLabel(EditBook);
        urlBook->setObjectName("urlBook");
        urlBook->setGeometry(QRect(110, 390, 151, 20));
        titleEditBook = new QLineEdit(EditBook);
        titleEditBook->setObjectName("titleEditBook");
        titleEditBook->setGeometry(QRect(430, 30, 271, 28));
        authorEditBook = new QLineEdit(EditBook);
        authorEditBook->setObjectName("authorEditBook");
        authorEditBook->setGeometry(QRect(430, 90, 271, 28));
        releaseEditBook = new QLineEdit(EditBook);
        releaseEditBook->setObjectName("releaseEditBook");
        releaseEditBook->setGeometry(QRect(430, 150, 271, 28));
        publishingEditBook = new QLineEdit(EditBook);
        publishingEditBook->setObjectName("publishingEditBook");
        publishingEditBook->setGeometry(QRect(430, 210, 271, 28));
        in_stockEditBook = new QLineEdit(EditBook);
        in_stockEditBook->setObjectName("in_stockEditBook");
        in_stockEditBook->setGeometry(QRect(430, 270, 271, 28));
        ratingEditBook = new QLineEdit(EditBook);
        ratingEditBook->setObjectName("ratingEditBook");
        ratingEditBook->setGeometry(QRect(430, 330, 271, 28));
        urlEditBook = new QLineEdit(EditBook);
        urlEditBook->setObjectName("urlEditBook");
        urlEditBook->setGeometry(QRect(430, 390, 271, 28));

        retranslateUi(EditBook);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EditBook, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EditBook, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EditBook);
    } // setupUi

    void retranslateUi(QDialog *EditBook)
    {
        EditBook->setWindowTitle(QCoreApplication::translate("EditBook", "Dialog", nullptr));
        titleBook->setText(QCoreApplication::translate("EditBook", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        authorBook->setText(QCoreApplication::translate("EditBook", "\320\220\320\262\321\202\320\276\321\200", nullptr));
        releaseBook->setText(QCoreApplication::translate("EditBook", "\320\223\320\276\320\264 \320\262\321\213\320\277\321\203\321\201\320\272\320\260", nullptr));
        publishigBook->setText(QCoreApplication::translate("EditBook", "\320\230\320\267\320\264\320\260\321\202\320\265\320\273\321\214\321\201\321\202\320\262\320\276", nullptr));
        in_stockBook->setText(QCoreApplication::translate("EditBook", "\320\222 \320\275\320\260\320\273\320\270\321\207\320\270\320\270", nullptr));
        ratingBook->setText(QCoreApplication::translate("EditBook", "\320\240\320\265\320\271\321\202\320\270\320\275\320\263", nullptr));
        urlBook->setText(QCoreApplication::translate("EditBook", "\320\241\321\201\321\213\320\273\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditBook: public Ui_EditBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITBOOK_H
