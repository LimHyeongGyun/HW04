#include <iostream>

#include "bookManager.h"

using namespace std;

Book::Book(const string& title, const string& author) : title(title), author(author) {
	
}

Book* BookManager::findByTitle(string title) {

	//책이 없을 때
	if (books.empty()) {
		cout << "현재 도서관에 등록된 책이 없습니다." << endl;
		return nullptr;
	}

	for (auto& book : books) {
		if (book.title == title) {
			cout << "책 제목: " << book.title << "/" << " 작가 이름: " << book.author << endl;
			return &book;
		}
	}
	
	cout << "찾으시는 제목으로 등록된 책이 없습니다." << endl;

	return nullptr;
}

Book* BookManager::findByAuthor(string author) {

	if (books.empty()) {
		cout << "현재 등록된 책이 없습니다." << endl;
		return nullptr;
	}

	for (auto& book : books) {
		if (book.author == author) {
			cout << "책 제목: " << book.title << "/" << " 작가 이름: " << book.author << endl;
			return &book;
		}
	}

	cout << "찾으시는 제목으로 등록된 책이 없습니다." << endl;

	return nullptr;
}

void BookManager::addBook(const string& title, const string& author) {

	//입력된 책 등록하기
	books.push_back(Book(title, author));
	
	bookMap[title] = author;
	authorMap[author] = title;

	borrow.initializeStock(Book(title, author), 3);

	cout << "책이 추가되었습니다: " << title << "by" << author << endl;
}

void BookManager::displayAllBooks() const {

	if (books.empty()) {
		cout << "현재 등록된 책이 없습니다." << endl;
		return ;
	}

	cout << "현재 도서 목록: " << endl;
	for (size_t i = 0; i < books.size(); i++) {
		cout << "책 이름: " << books[i].title << "by" << books[i].author <<  endl;
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