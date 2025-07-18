#include <iostream>

#ifndef BOOK_H
#define BOOK_H

using namespace std;

class Book
{
private:
	string title;
	string author;
    int pages;
    int year;
    int bookID;
	bool hardCover; //true for hard, false for paperback

public:

	Book(string title,
	         string author,
             int pages,
             int year,
             int bookID,
	         bool hardCover);

    //for part 2 (will probably need so just implemented)
	string getTitle() const { return title; }
	string getAuthor() const { return author; }
	int getPages() const { return pages; }
    int getYear() const { return year; }
    int getBookID() const { return bookID; }
    bool getHardCover() const { return hardCover; }


    void setTitle(string titleS) { title = titleS; }
	void setAutho(string authorS) { author = authorS; }
	void setPages(int pagesS) { pages = pagesS; }
    void setYear(int yearS) { year = yearS; }
    void setBookID(int bookIDS) { bookID = bookIDS; }
    void setHardCover(bool hardCoverS) { hardCover = hardCoverS; }

	bool operator==(const Book& other) const;

	friend ostream& operator<<(ostream& os, const Book& b);
};

#endif
