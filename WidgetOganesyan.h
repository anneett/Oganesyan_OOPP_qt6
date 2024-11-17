#pragma once

#include "Boost.h"
#include <qwidget.h>
#include <QWidget>
#include <QScrollArea>
#include "Book.h"
#include "EBook.h"

class WidgetOganesyan : public QWidget
{
    Q_OBJECT

private:

    QScrollArea* scrollArea;
    QStringList headers;

    void drawBookRow(const shared_ptr<Book>& book, QPainter& painter, int& row, int rowHeight, const vector<int>& columnWidths, int startX, int startY);

public:
    vector<shared_ptr<Book>> books;
    explicit WidgetOganesyan(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void load(const QString& path);
    void save(const QString& path);
    void clean();

signals:

};
