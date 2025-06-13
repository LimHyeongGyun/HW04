#ifndef BORROWMANAGER_H_
#define BORROWMANAGER_H_

#include <map>
#include <unordered_map>

#include "book.h"

class BorrowManager {
private:
	unordered_map<string, int> stock;

public:
	unordered_map<string, int> borrowMap; //main���� ����ϱ� ������ public����

	void initializeStock(Book book, int quantity = 3);
	void borrowBook(string title);
	void returnBook(string title);
	void displayStock();
};
#endif