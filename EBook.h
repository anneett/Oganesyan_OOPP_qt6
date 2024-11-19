#pragma once

#include "Boost.h"
#include "Book.h"

class EBook: public Book
{
    friend class boost::serialization::access;

protected:

public:

    string link = "";

    BOOST_SERIALIZATION_SPLIT_MEMBER()

    virtual ~EBook() {}

    template<class Archive>
    void save(Archive& ar, const unsigned int version) const
    {
        ar & boost::serialization::base_object<Book>(*this);
        ar & link;
    }

    template<class Archive>
    void load(Archive& ar, const unsigned int version)
    {
        ar & boost::serialization::base_object<Book>(*this);
        ar & link;
    }

    void copyFrom(const Book& other) override {
        // Сначала копируем общие поля
        Book::copyFrom(other);

        // Если other — EBook, копируем и link
        const EBook* eBook = dynamic_cast<const EBook*>(&other);
        if (eBook) {
            link = eBook->link;
        }
    }
};

BOOST_CLASS_VERSION(EBook, 1)
