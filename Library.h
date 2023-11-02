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
  list<Book> lib_list;
public:
  Library();
  void push_back();
  void push_front();
  void push_middle();
  void read_from_file(std::string file);
  void write_to_file(std::string file);
  void insert_sorted();
  std::string find_author();
  std::string find_album();
  void delete(std::string author, std::string book);
  void print();
  ~Library();
};


#endif
