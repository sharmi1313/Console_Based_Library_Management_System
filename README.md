# Console_Based_Library_Management_System
# 📚 Library Management System (C++ Console Application)

A simple console-based Library Management System written in C++ that allows an administrator to manage books by adding, searching, issuing, and returning them. Access to certain features is protected by a password system with hidden input.

---

## 🔧 Features

- ✅ Add a new book with ID, title, and author.
- 🔍 Search books by ID.
- 📄 Display all books in the system.
- 📤 Issue a book.
- 📥 Return a book.
- 🔐 Admin password protection for sensitive operations.
- 💾 Data persistence using a text file (`books.txt`).

---

## 🖥️ Requirements

- C++11 or later
- Windows OS (uses <conio.h> for hidden password input)
- A C++ compiler like `g++`, `MSVC`, or IDEs like Code::Blocks or Dev-C++

## Menu Option:
1. Add Book
2. Display All Books     🔒 (Requires Admin Password)
3. Search Book by ID     🔒
4. Issue Book            🔒
5. Return Book           🔒
0. Exit

## File Stracture

📦 LibraryManagementSystem
 ┣ 📄 main.cpp         # Main C++ source code
 ┗ 📄 books.txt        # Auto-created on first run, stores book data

 ✅ Future Improvements (Ideas)

Switch to cross-platform input method instead of conio.h

Use a database instead of a text file

Add user management (e.g., member login, borrowing history)

Implement GUI using frameworks like Qt or wxW

🙋 Author

Developed by: [Sharmi Khatun]

```bash
g++ -o library main.cpp
