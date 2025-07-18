#include <iomanip>
#include "Book.h"

Book::Book(string title, string author, int pages, int year, int bookID, bool hardCover) : title(title), author(author), pages(pages), year(year), bookID(bookID), hardCover(hardCover) {}

bool Book::operator==(const Book& other) const
{
    return title == other.title 
        && author == other.author 
        && pages == other.pages
        && year == other.year
        && bookID == other.bookID
        && hardCover == other.hardCover;
}

ostream& operator<<(ostream& os, const Book& b)
{
    os << left << setw(50) << b.title
	   << setw(20) << b.author 
	   << setw(10) << b.pages
	   << setw(10) << b.year 
	   << setw(15) << b.bookID 
	   << setw(10) << (b.hardCover ? "Hardcover" : "Paperback");
    return os;
}