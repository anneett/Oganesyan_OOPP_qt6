#include "WidgetOganesyan.h"
#include <QPainter>
#include <QMouseEvent>
#include <algorithm>
#include <functional>
#include <QFontMetrics>

WidgetOganesyan::WidgetOganesyan(QWidget *parent)
    : QWidget{parent} {
    headers = { "  Название", "  Автор", "  Год выпуска", "  Издательство", "  В наличии", "  Рейтинг", "  URL" };
}

void WidgetOganesyan::paintEvent(QPaintEvent*) {
    if (books.empty())
        return;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QFont font = painter.font();
    font.setPointSize(11);
    painter.setFont(font);

    int rowHeight = 30;
    int startX = 10;
    int startY = 10;

    vector<int> columnWidths(headers.size(), 0);
    QFontMetrics metrics(painter.font());

    for (int i = 0; i < headers.size(); ++i) {
        columnWidths[i] = metrics.horizontalAdvance(headers[i]) + 10;
    }

    for (const auto& book : books) {
        columnWidths[0] = max(columnWidths[0], metrics.horizontalAdvance(QString::fromStdString(book->title)) + 10);
        columnWidths[1] = max(columnWidths[1], metrics.horizontalAdvance(QString::fromStdString(book->author)) + 10);
        columnWidths[2] = max(columnWidths[2], metrics.horizontalAdvance(QString::number(book->release_year)) + 10);
        columnWidths[3] = max(columnWidths[3], metrics.horizontalAdvance(QString::fromStdString(book->publishing_house)) + 10);
        columnWidths[4] = max(columnWidths[4], metrics.horizontalAdvance(QString::number(book->in_stock)) + 10);
        columnWidths[5] = max(columnWidths[5], metrics.horizontalAdvance(QString::number(book->rating)) + 10);

        auto eBook = dynamic_pointer_cast<EBook>(book);
        if (eBook) {
            columnWidths[6] = max(columnWidths[6], metrics.horizontalAdvance(QString::fromStdString(eBook->link)) + 10);
        } else {
            columnWidths[6] = max(columnWidths[6], metrics.horizontalAdvance(QString("N/A")) + 10);
        }
    }

    int totalWidth = accumulate(columnWidths.begin(), columnWidths.end(), 0) + 20;
    int totalHeight = (books.size() + 1) * rowHeight + 20;
    setMinimumSize(totalWidth, totalHeight);
    int numRows = books.size() + 1;

    for (int i = 0; i < headers.size(); ++i) {
        painter.drawText(startX + accumulate(columnWidths.begin(), columnWidths.begin() + i, 0), startY + rowHeight / 2, headers[i]);
    }

    int row = 1;
    for_each(books.begin(), books.end(), bind(&WidgetOganesyan::drawBookRow, this, placeholders::_1, ref(painter), ref(row), rowHeight, columnWidths, startX, startY));
    int tableWidth = accumulate(columnWidths.begin(), columnWidths.end(), 0) + startX;

    for (int i = 0; i <= numRows; ++i) {
        int y = startY + i * rowHeight;
        painter.drawLine(startX, y, tableWidth, y);
    }

    for (int i = 0; i <= headers.size(); ++i) {
        int x = startX + accumulate(columnWidths.begin(), columnWidths.begin() + i, 0);
        painter.drawLine(x, startY, x, startY + numRows * rowHeight);
    }
}

void WidgetOganesyan::drawBookRow(const shared_ptr<Book>& book, QPainter& painter, int& row, int rowHeight, const vector<int>& columnWidths, int startX, int startY) {
    int yPosition = startY + row * rowHeight + rowHeight / 2;

    painter.drawText(startX + 8, yPosition, QString::fromLocal8Bit(book->title.c_str()));
    painter.drawText(startX + 8 + columnWidths[0], yPosition, QString::fromLocal8Bit(book->author.c_str()));
    painter.drawText(startX + 8 + columnWidths[0] + columnWidths[1], yPosition, QString::number(book->release_year));
    painter.drawText(startX + 8 + columnWidths[0] + columnWidths[1] + columnWidths[2], yPosition, QString::fromLocal8Bit(book->publishing_house.c_str()));
    painter.drawText(startX + 8 + columnWidths[0] + columnWidths[1] + columnWidths[2] + columnWidths[3], yPosition, QString::number(book->in_stock));
    painter.drawText(startX + 8 + columnWidths[0] + columnWidths[1] + columnWidths[2] + columnWidths[3] + columnWidths[4], yPosition, QString::number(book->rating));

    auto eBook = dynamic_pointer_cast<EBook>(book);
    if (eBook) {
        painter.drawText(startX + 8 + columnWidths[0] + columnWidths[1] + columnWidths[2] + columnWidths[3] + columnWidths[4] + columnWidths[5], yPosition, QString::fromStdString(eBook->link));
    } else {
        painter.drawText(startX + 8 + columnWidths[0] + columnWidths[1] + columnWidths[2] + columnWidths[3] + columnWidths[4] + columnWidths[5], yPosition, "N/A");
    }

    row++;
}

void WidgetOganesyan::load(const QString& path) {
    ifstream inFile(path.toStdString(), ios::binary);
    if (!inFile) {
        qDebug() << "Не удалось открыть файл для чтения.";
        return;
    }

    boost::archive::binary_iarchive ia(inFile);
    try {
        ia >> books;
    } catch (const std::exception& e) {
        qDebug() << "Ошибка десериализации:" << e.what();
        return;
    }

    update();
}

void WidgetOganesyan::save(const QString& path)
{
    ofstream out(path.toStdWString(), ofstream::binary);
    boost::archive::binary_oarchive oa(out);
    oa << books;
}

void WidgetOganesyan::clean()
{
    books.clear();
    update();
}
