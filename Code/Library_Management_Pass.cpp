#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <bits/stdc++.h>
#include <conio.h> // Windows-specific for getch()

using namespace std;

// ----------- Password Setup & Hidden Input --------------
const string ADMIN_PASSWORD = "sharmi1313";

string getHiddenPassword() {
    string password = "";
    char ch;

    while (true) {
        ch = _getch(); // get char without echo

        if (ch == 13) { // Enter key pressed
            cout << endl;
            break;
        } else if (ch == 8) { // Backspace key
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b"; // backspace effect in console
            }
        } else {
            password += ch;
            cout << '$'; // show *
        }
    }

    return password;
}

bool checkPassword() {
    cout << "Enter admin password: ";
    string pass = getHiddenPassword();
    if (pass == ADMIN_PASSWORD) {
        return true;
    } else {
        cout << "Incorrect password!\n";
        return false;
    }
}
// ---------------------------------------------------------

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book() {}

    Book(int i, string t, string a, bool issued = false) {
        id = i;
        title = t;
        author = a;
        isIssued = issued;
    }

    void display() const {
        cout << setw(5) << id << " | "
             << setw(20) << title << " | "
             << setw(20) << author << " | "
             << (isIssued ? "Issued" : "Available") << endl;
    }
};

class Library {
private:
    vector<Book> books;

    void loadFromFile() {
        books.clear();
        ifstream file("books.txt");
        int id;
        string title, author;
        int issued;
        while (file >> id) {
            file.ignore(); // Skip newline
            getline(file, title);
            getline(file, author);
            file >> issued;
            file.ignore(); // Skip newline
            books.push_back(Book(id, title, author, issued));
        }
        file.close();
    }

    void saveToFile() {
        ofstream file("books.txt");
        for (auto& book : books) {
            file << book.id << endl;
            file << book.title << endl;
            file << book.author << endl;
            file << book.isIssued << endl;
        }
        file.close();
    }

public:
    Library() {
        loadFromFile();
    }

    void addBook() {
    int id;
    string title, author;

    // Validation for positive ID
    do {
        cout << "Enter Book ID (positive only): ";
        cin >> id;
        if (id <= 0) {
            cout << " Invalid ID! Please enter a positive number.\n";
        }
    } while (id <= 0);

    cin.ignore(); // clear input buffer

    cout << "Enter Book Title: ";
    getline(cin, title);
    cout << "Enter Author Name: ";
    getline(cin, author);

    books.push_back(Book(id, title, author));
    saveToFile();
    cout << " Book added successfully.\n";
}


    void displayBooks() {
        if (!checkPassword()) return;

        cout << "\nAll Books:\n";
        cout << "ID   | Title                | Author               | Status\n";
        cout << "---------------------------------------------------------------\n";
        for (auto& book : books) {
            book.display();
        }
    }

    void searchBook() {
        if (!checkPassword()) return;

        int id;
        cout << "Enter Book ID to search: ";
        cin >> id;
        for (auto& book : books) {
            if (book.id == id) {
                cout << "\nBook Found:\n";
                book.display();
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void issueBook() {
        if (!checkPassword()) return;

        int id;
        cout << "Enter Book ID to issue: ";
        cin >> id;
        for (auto& book : books) {
            if (book.id == id) {
                if (book.isIssued) {
                    cout << "Book is already issued.\n";
                } else {
                    book.isIssued = true;
                    saveToFile();
                    cout << "Book issued successfully.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook() {
        if (!checkPassword()) return;

        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;
        for (auto& book : books) {
            if (book.id == id) {
                if (!book.isIssued) {
                    cout << "Book is not currently issued.\n";
                } else {
                    book.isIssued = false;
                    saveToFile();
                    cout << "Book returned successfully.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n=== Library Management System ===\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.displayBooks(); break;
            case 3: lib.searchBook(); break;
            case 4: lib.issueBook(); break;
            case 5: lib.returnBook(); break;
            case 0: cout << "Exiting system...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
