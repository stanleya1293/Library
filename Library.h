/**
 * @file Library.h
 * @author Arden Stanley / Trey Wright
 * @date 2023-11-01
 * @brief The library class, which acts a linked list that stores book entries
 * 
 * 
 */

#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <list>

struct Book {
  std::string title;
  std::string author_name;
  int pages;
  std::string isbn;
  float cover_price;
  int year;
};

class Library {
private:
  std::list<Book> lib_list;
public:
  Library();
  void push_back(std::string title, std::string author_name, int pages, std::string isbn, float cover_price, int year);  //pushes entry to the back
  void push_front(std::string title, std::string author_name, int pages, std::string isbn, float cover_price, int year); //pushes entry to the front
  void push_middle();
  void read_from_file(std::string file);                                                                                 //Read the book from file input
  void write_to_file(std::string file);                                                                                  //writes multiple files into 1    
  void insert_sorted(std::string title, std::string author_name, int pages, std::string isbn, float cover_price, int year); //entry gets sorted in order
  void find_author(std::string author);                                                                        //finds the author user is looking for
  void find_album(std::string title);                                                                          //finds the book from the user inputed tile
  void delete_book(std::string author, std::string book);                                          //delete book from name and other info prompted to user 
  void print();                                                                                    // Prints the file inputed 
  ~Library();
};


#endif
