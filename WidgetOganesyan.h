#pragma once

#include "Boost.h"
#include <qwidget.h>
#include <QWidget>
#include <QTableWidget>
#include <QScrollArea>
#include "Book.h"
#include "EBook.h"

class WidgetOganesyan : public QWidget
{
    Q_OBJECT

private:

    vector<shared_ptr<Book>> books;
    QTableWidget* tableWidget;
    QScrollArea* scrollArea;
    QStringList headers;

    void drawBookRow(const std::shared_ptr<Book>& book, QPainter& painter, int& row, int rowHeight, const std::vector<int>& columnWidths, int startX, int startY);
    int lastTableWidth = 0;
    int lastTableHeight = 0;

public:

    explicit WidgetOganesyan(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void load(const QString& path);
    void save(const QString& path);
    void clean();

signals:

};
