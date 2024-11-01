#ifndef EBOOK_H
#define EBOOK_H

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
};

BOOST_CLASS_VERSION(EBook, 1)

#endif // EBOOK_H
