#include <iostream>

#include "bookManager.h"

using namespace std;

Book::Book(const string& title, const string& author) : title(title), author(author) {
	
}

Book* BookManager::findByTitle(string title) {

	//å�� ���� ��
	if (books.empty()) {
		cout << "���� �������� ��ϵ� å�� �����ϴ�." << endl;
		return nullptr;
	}

	for (auto& book : books) {
		if (book.title == title) {
			cout << "å ����: " << book.title << "/" << " �۰� �̸�: " << book.author << endl;
			return &book;
		}
	}
	
	cout << "ã���ô� �������� ��ϵ� å�� �����ϴ�." << endl;

	return nullptr;
}

Book* BookManager::findByAuthor(string author) {

	if (books.empty()) {
		cout << "���� ��ϵ� å�� �����ϴ�." << endl;
		return nullptr;
	}

	for (auto& book : books) {
		if (book.author == author) {
			cout << "å ����: " << book.title << "/" << " �۰� �̸�: " << book.author << endl;
			return &book;
		}
	}

	cout << "ã���ô� �������� ��ϵ� å�� �����ϴ�." << endl;

	return nullptr;
}

void BookManager::addBook(const string& title, const string& author) {

	//�Էµ� å ����ϱ�
	books.push_back(Book(title, author));
	
	bookMap[title] = author;
	authorMap[author] = title;

	borrow.initializeStock(Book(title, author), 3);

	cout << "å�� �߰��Ǿ����ϴ�: " << title << "by" << author << endl;
}

void BookManager::displayAllBooks() const {

	if (books.empty()) {
		cout << "���� ��ϵ� å�� �����ϴ�." << endl;
		return ;
	}

	cout << "���� ���� ���: " << endl;
	for (size_t i = 0; i < books.size(); i++) {
		cout << "å �̸�: " << books[i].title << "by" << books[i].author <<  endl;
	}
}

Book* BookManager::getBookByTitle(string title) {
	Book* book = findByTitle(title);

	return book;
}

Book* BookManager::getBookByAuthor(string author) {
	Book* book = findByAuthor(author);

	return book;
}