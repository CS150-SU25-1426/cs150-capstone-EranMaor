#include <iostream>
#include <iomanip>
#include <vector>

#include "Book.h"
#include "Library.h"
using namespace std;

int main() {


	Library library;
	string title, author;
	int pages, year;
	bool hardCover;

	int choice = 0;

	do {
		cout << "************************************************************************\n";
		cout << "**                                                                    **\n";
		cout << "**                          WELCOME TO ERAN'S                         **\n";
		cout << "**                               LIBRARY                              **\n";
		cout << "**                                                                    **\n";
		cout << "************************************************************************\n";
		cout << "** Please make a choice from the following options:                   **\n";
		cout << "**                                                                    **\n";
		cout << "** 1)  Add new book to Library                                        **\n";
		cout << "** 2)  Return a book to Library                                       **\n";
		cout << "** 3)  Checkout a book                                                **\n";
		cout << "** 4)  Edit Condition                                                 **\n";
		cout << "** 5)  Display all books in Library                                   **\n";
		cout << "** 6)  Exit                                                           **\n";
		cout << "************************************************************************\n";
		cout << ">> ";
		cin >> choice;
    
		cin.ignore(); // To ignore the \n after choice (preventing title from being "\n")
        string hold;

		switch (choice)
		{
			// Add Book
			case 1:
			{
				cout << "Enter Title: ";
				getline(cin, title);
				cout << "Enter author: ";
				getline(cin, author);
				cout << "Enter #pages: ";
				cin >> pages;
				cout << "Enter Year Written: ";
				cin >> year;
				cout << "Enter Cover Type (1: hardcover; 0: paperback): ";
				cin >> hardCover;

				if (library.addBook(Book(title, author, pages, year, hardCover)))
				{
					cout << "~~~Book added successfully!~~~\n";
				}
				else
				{
					cout << "~~~Error: Book already exists in the library!~~~\n";
				}
				

				cout << endl;
				break;
			}
			// Return Book
			case 2:
			{
				cout << "Enter Title: ";
				getline(cin, title);
				cout << "Enter author: ";
				getline(cin, author);
				cout << "Enter #pages: ";
				cin >> pages;
				cout << "Enter Year Written: ";
				cin >> year;
				cout << "Enter Cover Type (1: hardcover; 0: paperback): ";
				cin >> hardCover;

				Book book(title, author, pages, year, hardCover);
				if (library.returnBook(book)) 
				{
					cout << "~~~Book returned successfully!~~~\n";
				}

				cout << endl;
				break;
			}
			// Checkout Book
			case 3:
			{
				cout << left << setw(50) << "TITLE"
					<< setw(20) << "AUTHOR" 
					<< setw(15) << "#PAGES"
					<< setw(15) << "YEAR"
					<< setw(15) << "COVER TYPE" 
					<< setw(15) << "CONDITION" << endl;
				cout << library << endl;

				cout << "\nWhich book would you like to check out (title)? (or -1 to cancel) >> ";
				cin >> title;
				if (title == "-1") 
				{
					cout << "~~~Checkout cancelled~~~\n";
				} else if (library.checkOutBook(title)) 
				{
					cout << "~~~Book checked out successfully!~~~\n";
				} 
				else 
				{
					cout << "~~~Error: Book was not able to be checked out~~~\n";
				}
				cout << endl;
				
				break;
			}
			// Edit Condition
			case 4:
			{
				int cond;
				cout << "Enter Title: ";
				getline(cin, title);

				cout << "Enter new condition: \n";
				cout << "1) New\n";
				cout << "2) Like New\n";
				cout << "3) Good\n";
				cout << "4) Fair\n";
				cout << "5) Poor\n";
				cout << ">> ";
				cin >> cond;

				Book* bookPtr = library.getBookByTitle(title);
				if (bookPtr == nullptr)
				{
					cout << "~~~Error: Book not found in the library~~~\n";
				}
				else
				{
					if (bookPtr->repairBook(cond - 1))
					{
						cout << "~~~Condition updated successfully!~~~\n";
					}
					else
					{
						cout << "~~~Error: Unable to update condition~~~\n";
					}
				}
				break;
			}
			// Display all books in Library
			case 5:
			{
				cout << left << setw(50) << "TITLE"
					<< setw(20) << "AUTHOR" 
					<< setw(15) << "#PAGES"
					<< setw(15) << "YEAR"
					<< setw(15) << "COVER TYPE" 
					<< setw(15) << "CONDITION" << endl;
				cout << library << endl;
				
				cout << "\nPress Enter to Continue\n";
				getline(cin, hold);
				break;
			}
			// Exit
			case 6:
			{
				cout << "Exiting the program...\n";
				cout << "Thank you for using the library system!!!\n";
				break;
			}
	}

	} while (choice != 6);

    return 0;
}