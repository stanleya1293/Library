#include "Library.h"
#include <iostream>
#include <list>
#include <fstream>
#include <string>

Library::Library() {
  
}

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

void Library::read_from_file(std::string file) {
  std::ifstream infile;
  infile.open(file);
  std::string title;
  std::string author_name;
  int pages;
  std::string isbn;
  float cover_price;
  int year;
  while (true) {
    std::getline(infile, title);
    std::getline(infile, author_name);
    infile >> pages;
    std::getline(infile, isbn);
    infile >> pages;
    infile >> year;
    if (infile) {
      push_front(title, author_name, pages, isbn, cover_price, year);
    }
    else {
      break;
    }
  }
  infile.close();
} 

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

void Library::find_author(std::string author) {
  std::list<Book>::iterator it;
  for (it = lib_list.begin(); it != lib_list.end(); it++) {
    if (it->author_name == author) {
      std::cout << it->title << "\n";
    }
  }
}

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

void Library::delete_book(std::string author, std::string book) {
  std::list<Book>::iterator it;
  for (it = lib_list.begin(); it != lib_list.end(); it++) {
    if (it->author_name == author && it->title == book) {
      it = lib_list.erase(it);
    }
  }
}

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
  
