#include <iostream>

#include "bookManager.h"

using namespace std;

int main() {

    BookManager bookManager;
    BorrowManager borrowManager;

    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 책 제목으로 검색" << endl; //책 검색
        cout << "4. 작가이름으로 검색" << endl; //책 검색
        cout << "5. 책 빌리기" << endl; // 책 빌리기
        cout << "6. 책 반납하기" << endl; // 책 반납하기
        cout << "7. 종료" << endl; // 프로그램 종료
        cout << "선택: ";

        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;

        if (choice == 1) {
            // 1번 선택: 책 추가
            // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
            string title, author, number;
            
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)

            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)\

            bookManager.addBook(title, author); // 입력받은 책 정보를 추가
            borrowManager.initializeStock(Book(title, author), 3);
        }
        else if (choice == 2) {
            // 2번 선택: 모든 책 출력
            // 현재 BookManager에 저장된 책 목록을 출력합니다.
            bookManager.displayAllBooks();
        }
        else if (choice == 3) {
            //3번 선택 : 제목으로 책 검색
            string title; //책 제목으로 검색

            cout << "찾으시는 책의 이름을 입력해주세요.: ";
            cin.ignore();
            getline(cin, title);

            Book* bookinfo = bookManager.getBookByTitle(title); //이렇게 출력하면 정상출력
            cout << "[찾으시는 책 정보]" << "책 제목: " << bookinfo->title << "/ 작가: " << bookinfo->author << endl;
        }
        else if (choice == 4) {
            //4번 선택 : 작가로 책 검색
            string author; //작가로 검색

            cout << "찾으시는 작가의 이름을 입력해주세요.: ";
            cin.ignore();
            getline(cin, author);

            Book* authorinfo = bookManager.getBookByAuthor(author); //이렇게 출력하면 정상출력
            cout << "[찾으시는 작가 정보]" << "작가 이름: " << authorinfo->title << "/ 책 제목: " << authorinfo->author << endl;
        }
        else if (choice == 5) {
            //5번 선택 : 책 빌리기
            //빌릴 수 있는 책 확인
            borrowManager.displayStock();

            string title; //제목으로 검색

            cout << "대여할 책의 제목을 입력해주세요.: ";
            cin.ignore();
            getline(cin, title);

            borrowManager.borrowBook(title);
        }
        else if (choice == 6) {
            //6번 선택 : 책 반납하기
            //반납할 책 리스트 확인
            for (auto& pair : borrowManager.borrowMap) {
                cout << "빌린 책 이름: " << pair.first << "/" << "빌린 권 수: " << pair.second << endl;
            }

            string title; //제목으로 검색

            cout << "반납할 책의 제목을 입력해주세요.: ";
            cin.ignore();
            getline(cin, title);

            borrowManager.returnBook(title);
        }
        else if (choice == 7) {
            // 8번 선택: 종료
            // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
            cout << "프로그램을 종료합니다." << endl;

            break; // while 루프 종료
        }
        else {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

	return 0;
}