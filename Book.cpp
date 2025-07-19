#include <iomanip>
#include "Book.h"

// Static array of conditions
const string Book::conditions[5] = {
    "New",
    "Like New",
    "Good",
    "Fair",
    "Poor"
};

// Constructor
// Initializes the book with title, author, pages, year, and cover type
// Sets checkOut to false and condition to "New", so they are not needed as parameters
Book::Book(string title, string author, int pages, int year, bool hardCover) 
    : title(title), 
    author(author), 
    pages(pages), 
    year(year),
    hardCover(hardCover), 
    checkOut(false), // Initialize checkOut to false
    condition(0) // Initialize condition to "New"
    {}

// Decrement condition of book every time it is checked out
// If condition is already at the worst state, it does nothing
void Book::decrementCondition() 
{
    if (condition < 4) 
    {
        condition++;
    } 
    else 
    {
        cout << "Book already at worst condition" << endl;
    }
}

// Repair book to a specific condition
// Valid conditions are 0 to 4, where 0 is "New" and 4 is "Poor"
// If the new condition is better than the current condition, it updates the condition and returns true
// If the new condition is worse or equal to the current condition, it returns false
bool Book::repairBook(int newCondition) 
{
    if (newCondition >= 0 && newCondition < 5 && newCondition < condition) 
    {
        cout << "Updating book to condition: " << conditions[newCondition] << endl;
        condition = newCondition;
        return true;
    } 
    return false;
}

// Overloaded equality operator to compare two Book objects
bool Book::operator==(const Book& other) const
{
    return title == other.title 
        && author == other.author 
        && pages == other.pages
        && year == other.year
        && hardCover == other.hardCover;
}

// Overloaded output operator to display book information
ostream& operator<<(ostream& os, const Book& b)
{
    os << left << setw(50) << b.title
	   << setw(20) << b.author 
	   << setw(15) << b.pages
	   << setw(15) << b.year
	   << setw(15) << (b.hardCover ? "Hardcover" : "Paperback")
       << setw(15) << b.conditions[b.condition];
    return os;
}