#include <iostream>

#include "bookManager.h"

void BorrowManager::initializeStock(Book book, int quantity) {

	stock[book.title] = quantity;
}

void BorrowManager::borrowBook(string title) {
	if (stock.empty()) {
		cout << "현재 빌릴 수 있는 책이 없습니다." << endl;
		return;
	}
	else {
		//stock 안에서 title 책 찾기
		auto it = stock.find(title);

		//책을 찾았다면 빌렸다고 띄워주기
		if (it != stock.end() && it->second > 0) {
			stock[title]--; //stock에서 빌린 책 수 빼주기
			cout << title << " 책을 빌렸습니다." << endl;

			auto it = borrowMap.find(title);
			//기존에 대여했던 중복된 책이라면
			if (it != borrowMap.end()) {
				borrowMap[title]++;
			}
			//기존에 빌리지 않았던 책이라면
			else {
				borrowMap[title] = 1; //책 이름과 빌린 권 수 대입해주기
			}
		}
		else if (it != stock.end() && it->second <= 0) {
			cout << "해당 모든 책이 대출 중이라 빌릴 수 없습니다." << endl;
		}

		cout << "내가 대여한 책의 목록" << endl;

		for (auto& pair : borrowMap) {
			cout << "빌린 책 이름: " << pair.first << "/" << "빌린 권 수: " << pair.second << endl;
		}
	}
}

void BorrowManager::returnBook(string title) {

	auto it = stock.find(title);
	auto b = borrowMap.find(title);

	//해당 책을 빌렸었다면
	if (b != borrowMap.end()) {
		borrowMap[title]--; //대여한 목록에서 반납한 수 만큼 빼주기
		//대여 목록에서 해당하는 책을 다 반납했다면
		if (b->second == 0) {
			//맵에서 책의 값 지워주기
			borrowMap.erase(title);
		}

		stock[title]++; //반납한 책 수 만큼 증가

		cout << "남은 내 대여목록" << endl;
		for (auto& pair : borrowMap) {
			cout << "빌린 책 이름: " << pair.first << "/" << "빌린 권 수: " << pair.second << endl;
		}
	}
	//해당 책을 빌린적이 없다면
	else if (b == borrowMap.end()) {
		cout << "해당 이름의 책의 대여 내역이 없습니다. 이름을 다시 확인해주세요." << endl;
	}
}

void BorrowManager::displayStock() {

	if (stock.empty()) {
		cout << "현재 남은 책이 없습니다." << endl;
		return;
	}
	else {
		for (const auto& pair : stock) {
			cout << "책 이름: " << pair.first << "/" << " 남은 권 수: " << pair.second << endl;
		}
	}
}