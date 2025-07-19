#ifndef LIBRARY_H //library is like BookList
#define LIBRARY_H

#include <vector>
#include "Book.h"

class Library
{
private:
    // Vector to hold the books in the library
    vector<Book> mLibrary;
public:
    //**using default constructor/destructor

    //add, edit, and delete functions
    bool addBook(Book book);
    bool returnBook(Book book);
    bool checkOutBook(string title);

    bool operator==(const Library& other) const;
	friend ostream& operator<<(ostream& os, const Library& l);

    Book* getBookByTitle(string title);
};


#endif //BOOKLIST_H