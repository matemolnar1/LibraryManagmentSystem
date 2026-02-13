# C++ Library Management System

A console-based application for managing a book collection, built with C++. This project demonstrates Object-Oriented Programming (OOP), file persistence, and dynamic data management.

## 🚀 Features

* **Add Books:** Create new entries with Title, Author, and auto-generated unique IDs (e.g., B1, B2).
* **View Library:** Display a formatted list of all books and their availability status.
* **Search:** Find books instantly by title (case-sensitive).
* **Data Persistence:**
    * **Save:** Export your library to a text file (CSV format).
    * **Load:** Import books from a file and restore the state of the application.
* **Smart ID Management:** The system remembers the last used ID even after restarting the program, preventing duplicates.
* **Input Validation:** Handles incorrect user inputs (e.g., entering letters instead of numbers) without crashing.

## 🛠️ Technical Concepts Used

* **Object-Oriented Programming (OOP):** Encapsulation with a `Book` class.
* **STL Containers:** Uses `std::vector` for dynamic memory management.
* **File I/O:** Uses `std::fstream` for reading and writing data.
* **String Manipulation:** Parsing CSV-style data and handling substrings.
* **Exception Handling:** safely parses IDs using `try-catch` blocks.
