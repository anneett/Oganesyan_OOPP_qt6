#include "WidgetOganesyan.h"
#include <QPainter>
#include <QMouseEvent>
#include <algorithm>
#include <functional>
#include <QFontMetrics>

BOOST_SERIALIZATION_SPLIT_FREE(QPointF)

namespace boost {
namespace serialization {
template<class Archive>
void load(Archive & ar, QPointF& p, const unsigned int) {
    qreal x, y;
    ar >> x;
    ar >> y;
    p.setX(x);
    p.setY(y);
}
}
}

QString pointToString(QPointF& p) {
    return QString("[%1;%2]").arg(p.x()).arg(p.y());
}

WidgetOganesyan::WidgetOganesyan(QWidget *parent)
    : QWidget{parent}, showLabels(false) {
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

    std::vector<int> columnWidths(headers.size(), 0);
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

    int totalWidth = std::accumulate(columnWidths.begin(), columnWidths.end(), 0) + 20; // 20 for padding
    int totalHeight = (books.size() + 1) * rowHeight + 20; // 20 for padding

    // Set minimum size for the widget based on the table dimensions
    setMinimumSize(totalWidth, totalHeight);
    int numRows = books.size() + 1;

    for (int i = 0; i < headers.size(); ++i) {
        painter.drawText(startX + accumulate(columnWidths.begin(), columnWidths.begin() + i, 0), startY + rowHeight / 2, headers[i]);
    }

    // Переменная для отслеживания строки
    int row = 1;

    for_each(books.begin(), books.end(), bind(&WidgetOganesyan::drawBookRow, this, placeholders::_1, ref(painter), ref(row), rowHeight, columnWidths, startX, startY));

    // Рассчёт ширины таблицы по колонкам для ограничения горизонтальных линий
    int tableWidth = std::accumulate(columnWidths.begin(), columnWidths.end(), 0) + startX;

    // Отрисовка линий сетки
    for (int i = 0; i <= numRows; ++i) {
        int y = startY + i * rowHeight;
        painter.drawLine(startX, y, tableWidth, y); // Используем tableWidth вместо totalWidth
    }

    for (int i = 0; i <= headers.size(); ++i) {
        int x = startX + std::accumulate(columnWidths.begin(), columnWidths.begin() + i, 0);
        painter.drawLine(x, startY, x, startY + numRows * rowHeight);
    }
}


void WidgetOganesyan::drawBookRow(const std::shared_ptr<Book>& book, QPainter& painter, int& row, int rowHeight, const std::vector<int>& columnWidths, int startX, int startY) {
    int yPosition = startY + row * rowHeight + rowHeight / 2;

    painter.drawText(startX + 8, yPosition, QString::fromLocal8Bit(book->title.c_str()));
    painter.drawText(startX + 8 + columnWidths[0], yPosition, QString::fromLocal8Bit(book->author.c_str()));
    painter.drawText(startX + 8 + columnWidths[0] + columnWidths[1], yPosition, QString::number(book->release_year));
    painter.drawText(startX + 8 + columnWidths[0] + columnWidths[1] + columnWidths[2], yPosition, QString::fromLocal8Bit(book->publishing_house.c_str()));
    painter.drawText(startX + 8 + columnWidths[0] + columnWidths[1] + columnWidths[2] + columnWidths[3], yPosition, QString::number(book->in_stock));
    painter.drawText(startX + 8 + columnWidths[0] + columnWidths[1] + columnWidths[2] + columnWidths[3] + columnWidths[4], yPosition, QString::number(book->rating));

    auto eBook = std::dynamic_pointer_cast<EBook>(book);
    if (eBook) {
        painter.drawText(startX + 8 + columnWidths[0] + columnWidths[1] + columnWidths[2] + columnWidths[3] + columnWidths[4] + columnWidths[5], yPosition, QString::fromStdString(eBook->link));
    } else {
        painter.drawText(startX + 8 + columnWidths[0] + columnWidths[1] + columnWidths[2] + columnWidths[3] + columnWidths[4] + columnWidths[5], yPosition, "N/A");
    }

    row++;
}

void WidgetOganesyan::load(const QString& path) {
    std::ifstream inFile(path.toStdString(), std::ios::binary);
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
    std::ofstream out(path.toStdWString(), std::ofstream::binary);
    boost::archive::binary_oarchive oa(out);
    oa << books;
}

void WidgetOganesyan::clean()
{
    books.clear();
    update();
}
