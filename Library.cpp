#include "Library.h"
#include "Book.h"

// return book to the library
bool Library::returnBook(Book book)
{
    for (Book& b : mLibrary) 
    {
        // Check if the book exists in the library
        // If it does, check if it is checked out
        // If it is checked out, set checkOut to false (meaning in-library) and return true
        if (b == book) 
        {
            if (b.getCheckOut() == false) 
            {
                cout << "~~~Book is not checked out!~~~\n";
                return false; // Book is not checked out, cannot return
            }
            b.setCheckOut(false); // Set the book's checkOut status to false
            return true; // Book found, return true
        }
    }
    cout << "~~~Error: Book is not in the system~~~\n";
    return false;
}

// add a book by title
bool Library::addBook(Book book)
{
    for (const auto& b : mLibrary) 
    {
        if (b == book) 
        {
            return false; // Book already exists
        }
    }
    mLibrary.push_back(book);
    return true; // Book added successfully
}

// Check out a book by title
// If the book is in poor condition, it cannot be checked out
// If the book is found, decrement its condition and set checkOut to true
bool Library::checkOutBook(string title)
{
    int index = -1;
    
    for (int i = 0; i < mLibrary.size(); i++)
    {
        string title1 = "";
        string title2 = "";
        if (mLibrary[i].getTitle().length() == title.length())
        {
            for (int j = 0; j < mLibrary[i].getTitle().length(); j++)
            {
                title1 += tolower(mLibrary[i].getTitle()[j]);
                title2 += tolower(title[j]);
            }
            if (title1 == title2)
            {
                index = i;
                break;
            }
        }
    }

    if (index >= 0)
    {
        if (mLibrary[index].getCondition() == 4) 
        {
            cout << "~~~Error: Book is in poor condition and cannot be checked out!~~~\n";
            return false; // Book is in poor condition
        }
        mLibrary[index].decrementCondition(); // Decrement condition
        mLibrary[index].setCheckOut(true);
        return true;
    }
    return false;
}

// Get a book by title
// Returns a pointer to the book if found, otherwise returns nullptr
// The title comparison is case-insensitive
// If the book is not found, it returns nullptr
// This allows the user to check if the book exists in the library
// and retrieve its details if needed
Book* Library::getBookByTitle(string title)
{
    for (Book& b : mLibrary)
    {
        string libTitle = b.getTitle();
        for (char& c : libTitle) c = tolower(c);
        for (char& c : title) c = tolower(c);

        if (libTitle == title)
        {
            return &b; // Return pointer to the actual book
        }
    }
    return nullptr; // Not found
}

bool Library::operator==(const Library& other) const
{
	return mLibrary == other.mLibrary;
}

ostream& operator<<(ostream& os, const Library& s)
{
    for (int i = 0; i < s.mLibrary.size(); i++)
    {
        if (!s.mLibrary[i].getCheckOut())
        {
            os << s.mLibrary[i] << "\n";
        }
    }
	return os;
}