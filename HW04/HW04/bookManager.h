#ifndef BOOKMANAGER_H_
#define BOOKMANAGER_H_

#include <vector>

#include "borrowManager.h"

class BookManager {
private:
	vector<Book> books;

	map<string, string> bookMap;
	map<string, string> authorMap;

	Book* findByTitle(string title);
	Book* findByAuthor(string author);

public:
	void addBook(const string& title, const string& author);
	void displayAllBooks() const;
	Book* getBookByTitle(string title);
	Book* getBookByAuthor(string author);
};

#endif
