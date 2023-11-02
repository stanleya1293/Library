/**
 * @file main.cpp
 * @author Arden Stanley / Trey Wright
 * @date 2023-11-01
 * @brief The driver UI for the Library class
 * 
 * 
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Library.h"

using namespace std;

int main() {

  Library library;
  int choice;

  int answer = 0;

  //while loop to make the menu loop over and over until the user quits it
  while (answer != 8) {
    cout << "Welcome to the UTM Library!\n"
	 << "1 Read a Book from a file\n"
         << "2 Write the Book to a file\n"
         << "3 Print the Book\n"
         << "4 Lookup Book by Author\n"
         << "5 Lookup Book by Title\n"
         << "6 Add a book\n"
         << "7 Delete a book\n"
         << "8 Exit this program\n"
         << "Please enter your choice now: ";
    cin >> choice; //user input
    cout << "\n";

     if(choice == 1){ // Reads the file in, kinda like scanning documents
      string filename;
      cout << "Enter the file name to read from: ";
      cin >> filename;
      library.read_from_file(filename);
      cout << "Book read from file.\n";
      cout << "\n";
    }
     // writes the opened files to a new seperate file that has all of the changes done to it   
    else if(choice == 2){
      string filename;
      cout << "Enter the file name to write to: ";
      cin >> filename;
      library.write_to_file(filename);
      cout << "Book written to file.\n";
      cout << "\n";
    }
    
    else if(choice == 3){ // prints out Book
      library.print();
      cout << "\n";
    }
     // seach for book by author in the given file
    else if (choice == 4) {
      string author;
      cout << "Enter author to find book: ";
      cin.ignore();
      getline(cin, author);
      library.find_author(author);
      cout << "\n";
    }
     // search for book by title in the file   
    else if (choice == 5) {
      string title;
      cout << "Enter title to find book: ";
      cin.ignore();
      getline(cin, title);
      library.find_album(title);
      cout << "\n";
    }
     // adding new book function
    else if (choice == 6) {
      string title, author,isbn;
      int year, pages;
      float price;
      cout << "Enter a title:\n";
      cin.ignore();
      getline(cin, title);
      cout << "Enter a author:\n";
      getline(cin, author);
      cout << "Enter a number of pages:\n";
      cin >> pages;
      cout << "Enter a isbn:\n";
      cin >> isbn;
      cout << "Enter a price:\n";
      cin >> price;
      cout << "Enter a year:\n";
      cin >> year;
      library.insert_sorted(title, author, pages, isbn, price, year);
      cout << "\n";
    }
     // function used to delete books from the file
    else if (choice == 7) {
      string author, book;
      cout << "Enter author of book you wish to delete: ";
      cin.ignore();
      getline(cin, author);
      cout << "Enter title of book you wish to delete: ";
      getline(cin, book);
      library.delete_book(author, book);
      cout << "Book deleted.\n";
      cout << "\n";
    }

    else if(choice == 8){ //close program
      cout << "Exiting the program." <<endl;
      cout << "\n";
      return 0;
    }

    else{ // just incase an alien character was entered 
      cout << "Invalid choice. Please enter a valid option.\n" <<endl;
    }
    
  }
  return 0;
    
}
