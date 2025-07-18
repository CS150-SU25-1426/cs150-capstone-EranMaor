#include <iostream>
#include <iomanip>
#include "Book.h"
using namespace std;

int main() {

    Book book1("Harry Potter and the Sorcerer's Stone", "J.K. Rowling", 223, 1997, 11111, false);
    cout << left << setw(50) << "TITLE"
	     << setw(20) << "AUTHOR" 
	     << setw(10) << "#PAGES"
	     << setw(10) << "YEAR"
	     << setw(15) << "ID"
	     << setw(10) << "COVER TYPE\n";
    cout << book1 << endl;



    return 0;
}