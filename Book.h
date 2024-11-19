#pragma once

#include "Boost.h"

class Book
{
    friend class boost::serialization::access;

protected:

public:

    virtual ~Book() = default;

    string title = "";
    string author = "";
    int release_year;
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

    virtual void copyFrom(const Book& other) {
        title = other.title;
        author = other.author;
        release_year = other.release_year;
        publishing_house = other.publishing_house;
        in_stock = other.in_stock;
        rating = other.rating;
    }
};
