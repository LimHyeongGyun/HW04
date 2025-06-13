#ifndef BOOK_H_
#define BOOK_H_

#include <string>

using namespace std;

class Book {
public:
	string title;
	string author;

	Book(const string& title, const string& author);
};

#endif