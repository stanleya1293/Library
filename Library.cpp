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
    outfile << it->title << "\n"
	    << it->author_name << "\n"
	    << it->pages << "\n"
	    << it->isbn << "\n"
	    << it->cover_price << "\n"
	    << it->year << "\n";
  }
  outfile.close();
}

void Library::insert_sorted() {
  
}

std::string Library::find_author() {
  
}

std::string Library::find_album() {

}

void Library::delete_book(std::string author, std::string book) {

}

void Library::print() {

}

Library::~Library() {

}
  
