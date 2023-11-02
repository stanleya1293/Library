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
  void push_back(std::string title, std::string author_name, int pages, std::string isbn, float cover_price, int year);
  void push_front(std::string title, std::string author_name, int pages, std::string isbn, float cover_price, int year);
  void push_middle();
  void read_from_file(std::string file);
  void write_to_file(std::string file);
  void insert_sorted(std::string title, std::string author_name, int pages, std::string isbn, float cover_price, int year);
  void find_author(std::string author);
  void find_album(std::string title);
  void delete_book(std::string author, std::string book);
  void print();
  ~Library();
};


#endif
