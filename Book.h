#include <iostream>

#ifndef BOOK_H
#define BOOK_H

using namespace std;

class Book
{
private:
    // Static array of conditions
    // 0: New, 1: Like New, 2: Good,
    // 3: Fair, 4: Poor
    static const string conditions[];
    // Book attributes
	string title;
	string author;
    int pages;
    int year;
	bool hardCover; //true for hard, false for paperback
    bool checkOut; // true if book is checked out, false otherwise
    int condition; // index for conditions array

public:

    // Constructor
    // Initializes the book with title, author, pages, year, and cover type
    // Sets checkOut to false and condition to "New", so they are not needed as parameters
	Book(string title,
	         string author,
             int pages,
             int year,
	         bool hardCover);

    //for part 2 (will probably need so just implemented)
	string getTitle() const { return title; }
	string getAuthor() const { return author; }
    int getCondition() const { return condition; }
	int getPages() const { return pages; }
    int getYear() const { return year; }
    bool getHardCover() const { return hardCover; }
    bool getCheckOut() const { return checkOut; }


    void setTitle(string titleS) { title = titleS; }
	void setAutho(string authorS) { author = authorS; }
    void setCondition(int conditionS) { condition = conditionS; }
	void setPages(int pagesS) { pages = pagesS; }
    void setYear(int yearS) { year = yearS; }
    void setHardCover(bool hardCoverS) { hardCover = hardCoverS; }
    void setCheckOut(bool checkOutS) { checkOut = checkOutS; }

    //decrement condition of book every time it is checked out
    void decrementCondition();
    //repair book to a specific condition
    bool repairBook(int newCondition);

	bool operator==(const Book& other) const;

	friend ostream& operator<<(ostream& os, const Book& b);
};

#endif
