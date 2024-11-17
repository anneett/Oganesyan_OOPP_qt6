#pragma once

#include <QDialog>
#include "WidgetOganesyan.h"
#include "EditBook.h"

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
    // void updateControls();
signals:
    // void setLabels(bool);
    // void setWidth(int);
    // void setHeight(int);
private slots:
    // void on_checkBox_checkStateChanged(const Qt::CheckState&);
    void on_listWidget_currentRowChanged(int currentRow);
    bool eventFilter(QObject* obj, QEvent* event)  override;
    // void on_spinX_valueChanged(int);
    // void on_spinY_valueChanged(int);
    // void on_AddButton_clicked();
    void on_EditButton_clicked();
    void on_DeleteButton_clicked();
    // void on_sliderW_valueChanged(int value);
    // void on_sliderH_valueChanged(int value);
};
