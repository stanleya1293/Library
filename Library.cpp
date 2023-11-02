/**
 * @file Library.cpp
 * @author Arden Stanley / Trey Wright
 * @date 2023-11-01
 * @brief implementations for Library class
 * 
 * 
 */

#include "Library.h"
#include <iostream>
#include <list>
#include <fstream>
#include <string>

Library::Library() {
  
}
//pushes to the back of the file
void Library::push_back(std::string title, std::string author_name, int pages, std::string isbn, float cover_price, int year) {
  Book new_book;
  new_book.title = title;
  new_book.author_name = author_name;
  new_book.pages = pages;
  new_book.isbn = isbn;
  new_book.cover_price = cover_price;
  new_book.year = year;
  lib_list.push_back(new_book);
}
//pushes to the front of the file
void Library::push_front(std::string title, std::string author_name, int pages, std::string isbn, float cover_price, int year) {
  Book new_book;
  new_book.title = title;
  new_book.author_name = author_name;
  new_book.pages = pages;
  new_book.isbn = isbn;
  new_book.cover_price = cover_price;
  new_book.year = year;
  lib_list.push_front(new_book);
}
//Reads in a new file and takes in all of its data
void Library::read_from_file(std::string file) {
  std::ifstream infile;
  infile.open(file); 
  std::string title;
  std::string author_name;
  int pages;
  std::string isbn;
  float cover_price;
  int year;
  std::getline(infile, title);
  std::getline(infile, author_name);
  infile >> pages;
  infile.ignore();
  std::getline(infile, isbn);
  infile >> cover_price;
  infile.ignore();
  infile >> year;
  infile.ignore();
  push_back(title, author_name, pages, isbn, cover_price, year);
  while (infile) {
    std::getline(infile, title);
    std::getline(infile, author_name);
    infile >> pages;
    infile.ignore();
    std::getline(infile, isbn);
    infile >> cover_price;
    infile.ignore();
    infile >> year;
    infile.ignore();
    if (infile) {
      push_back(title, author_name, pages, isbn, cover_price, year);
    }
  }
} 
// writes existing files that have been read and compiles then into one new file that has both combined
void Library::write_to_file(std::string file) {
  std::ofstream outfile;
  outfile.open(file);
  std::list<Book>::iterator it;
  for (it = lib_list.begin(); it != lib_list.end(); it++) {
    outfile << it->title << std::endl
	    << it->author_name << std::endl
	    << it->pages << std::endl
	    << it->isbn << std::endl
	    << it->cover_price << std::endl
	    << it->year << std::endl;
  }
  outfile.close();
}
// adds a new book to the file 
void Library::insert_sorted(std::string title, std::string author_name, int pages, std::string isbn, float cover_price, int year) {
  if (lib_list.empty()) {
    push_back(title, author_name, pages, isbn, cover_price, year);
  }
  else if (lib_list.size() == 1) {
    if (lib_list.front().author_name < author_name) {
      push_back(title, author_name, pages, isbn, cover_price, year);
    }
    else {
      push_front(title, author_name, pages, isbn, cover_price, year);
    }    
  }
  else {
    std::list<Book>::iterator it;
    Book book;
    book.title = title;
    book.author_name = author_name;
    book.pages = pages;
    book.isbn = isbn;
    book.cover_price = cover_price;
    book.year = year;
    for (it = lib_list.begin(); it != lib_list.end(); it++) {
      if (it == lib_list.end()) {
	push_back(title, author_name, pages, isbn, cover_price, year);
      }
      else if (it->author_name >= author_name) {
	lib_list.insert(it, book);
	break;
      }
    }
  }
}
// searches for a author by the name that the user has inputed
void Library::find_author(std::string author) {
  std::list<Book>::iterator it;
  for (it = lib_list.begin(); it != lib_list.end(); it++) {
    if (it->author_name == author) {
      std::cout << it->title << "\n";
    }
  }
}
// searches for the book by the title that the user has inputed
void Library::find_album(std::string title) {
  std::list<Book>::iterator it;
  for (it = lib_list.begin(); it != lib_list.end(); it++) {
    if (it->title == title) {
      std::cout << "Title: " << it->title << std::endl
		<< "Author: " << it->author_name << std::endl
		<< "Pages: " << it->pages << std::endl
		<< "isbn: " << it->isbn << std::endl
		<< "Cover Price: " << it->cover_price <<  std::endl
		<< "Year: " << it->year << std::endl << std::endl;
    }
  }
}
// deletes the book specified by the user from the file 
void Library::delete_book(std::string author, std::string book) {
  std::list<Book>::iterator it;
  for (it = lib_list.begin(); it != lib_list.end(); it++) {
    if (it->author_name == author && it->title == book) {
      it = lib_list.erase(it);
    }
  }
}
// prints out all the books in the file/files that have been read in
void Library::print() {
  std::list<Book>::iterator it;
  for (it = lib_list.begin(); it != lib_list.end(); it++) {
    std::cout << "Title: " << it->title << std::endl
	      << "Author: " << it->author_name << std::endl
	      << "Pages: " << it->pages << std::endl
	      << "isbn: " << it->isbn << std::endl
	      << "Cover Price: " << it->cover_price << std::endl
	      << "Year: " << it->year << std::endl << std::endl;
  }
}

Library::~Library() {

}
  
