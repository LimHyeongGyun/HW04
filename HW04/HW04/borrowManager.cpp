#include <iostream>

#include "bookManager.h"

void BorrowManager::initializeStock(Book book, int quantity) {

	stock[book.title] = quantity;
}

void BorrowManager::borrowBook(string title) {
	if (stock.empty()) {
		cout << "���� ���� �� �ִ� å�� �����ϴ�." << endl;
		return;
	}
	else {
		//stock �ȿ��� title å ã��
		auto it = stock.find(title);

		//å�� ã�Ҵٸ� ���ȴٰ� ����ֱ�
		if (it != stock.end() && it->second > 0) {
			stock[title]--; //stock���� ���� å �� ���ֱ�
			cout << title << " å�� ���Ƚ��ϴ�." << endl;

			auto it = borrowMap.find(title);
			//������ �뿩�ߴ� �ߺ��� å�̶��
			if (it != borrowMap.end()) {
				borrowMap[title]++;
			}
			//������ ������ �ʾҴ� å�̶��
			else {
				borrowMap[title] = 1; //å �̸��� ���� �� �� �������ֱ�
			}
		}
		else if (it != stock.end() && it->second <= 0) {
			cout << "�ش� ��� å�� ���� ���̶� ���� �� �����ϴ�." << endl;
		}

		cout << "���� �뿩�� å�� ���" << endl;

		for (auto& pair : borrowMap) {
			cout << "���� å �̸�: " << pair.first << "/" << "���� �� ��: " << pair.second << endl;
		}
	}
}

void BorrowManager::returnBook(string title) {

	auto it = stock.find(title);
	auto b = borrowMap.find(title);

	//�ش� å�� ���Ⱦ��ٸ�
	if (b != borrowMap.end()) {
		borrowMap[title]--; //�뿩�� ��Ͽ��� �ݳ��� �� ��ŭ ���ֱ�
		//�뿩 ��Ͽ��� �ش��ϴ� å�� �� �ݳ��ߴٸ�
		if (b->second == 0) {
			//�ʿ��� å�� �� �����ֱ�
			borrowMap.erase(title);
		}

		stock[title]++; //�ݳ��� å �� ��ŭ ����

		cout << "���� �� �뿩���" << endl;
		for (auto& pair : borrowMap) {
			cout << "���� å �̸�: " << pair.first << "/" << "���� �� ��: " << pair.second << endl;
		}
	}
	//�ش� å�� �������� ���ٸ�
	else if (b == borrowMap.end()) {
		cout << "�ش� �̸��� å�� �뿩 ������ �����ϴ�. �̸��� �ٽ� Ȯ�����ּ���." << endl;
	}
}

void BorrowManager::displayStock() {

	if (stock.empty()) {
		cout << "���� ���� å�� �����ϴ�." << endl;
		return;
	}
	else {
		for (const auto& pair : stock) {
			cout << "å �̸�: " << pair.first << "/" << " ���� �� ��: " << pair.second << endl;
		}
	}
}