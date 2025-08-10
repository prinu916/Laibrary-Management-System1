#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    int id;
    bool isIssued;

    Book() {
        title = "";
        author = "";
        id = 0;
        isIssued = false;
    }
    void addBook() {
        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);
        isIssued = false;
        cout << "Book Added Successfully!\n";
    }
    void displayBook() {
        cout << "ID: " << id << " | Title: " << title
             << " | Author: " << author
             << " | Status: " << (isIssued ? "Issued" : "Available") << "\n";
    }
};
int main() {
    Book library[50];
    int count = 0;
    int choice;
    do {
        cout << "\n====== Library Management System ======\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        if (choice == 1) {
            if (count < 50) {
                library[count].addBook();
                count++;
            } else {
                cout << "Library Full! Cannot add more books.\n";
            }
        }
        else if (choice == 2) {
            if (count == 0) {
                cout << "No books in library.\n";
            } else {
                cout << "\nList of Books:\n";
                for (int i = 0; i < count; i++) {
                    library[i].displayBook();
                }
            }
        }
        else if (choice == 3) {
            int bookId;
            cout << "Enter Book ID to issue: ";
            cin >> bookId;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (library[i].id == bookId) {
                    if (!library[i].isIssued) {
                        library[i].isIssued = true;
                        cout << "Book Issued Successfully.\n";
                    } else {
                        cout << "Book already issued.\n";
                    }
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Book not found.\n";
        }
        else if (choice == 4) {
            int bookId;
            cout << "Enter Book ID to return: ";
            cin >> bookId;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (library[i].id == bookId) {
                    if (library[i].isIssued) {
                        library[i].isIssued = false;
                        cout << "Book Returned Successfully.\n";
                    } else {
                        cout << "Book was not issued.\n";
                    }
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Book not found.\n";
        }
        else if (choice == 5) {
            cout << "Exiting Program...\n";
        }
        else {
            cout << "Invalid Choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
