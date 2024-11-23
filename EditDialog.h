#pragma once

#include <QDialog>
#include "WidgetOganesyan.h"
#include "EditBook.h"
#include "AddBook.h"

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT
    vector<shared_ptr<Book>>& books;

public:
    explicit EditDialog(QWidget *parent, vector<shared_ptr<Book>>& booksRef);
    ~EditDialog();


private:
    Ui::EditDialog *ui;

private slots:
    void on_listWidget_currentRowChanged(int currentRow);
    bool eventFilter(QObject* obj, QEvent* event)  override;
    void on_AddButton_clicked();
    void on_EditButton_clicked();
    void on_DeleteButton_clicked();
};
