#ifndef BOOK_H
#define BOOK_H

#include "Boost.h"

class Book
{
    friend class boost::serialization::access;

protected:

public:

    virtual ~Book() = default;

    string title = "";
    string author = "";
    int release_year = 0;
    string publishing_house = "";
    bool in_stock = 0;
    double rating = 0;

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& title;
        ar& author;
        ar& release_year;
        ar& publishing_house;
        ar& in_stock;
        ar& rating;
    }
};

#endif // BOOK_H