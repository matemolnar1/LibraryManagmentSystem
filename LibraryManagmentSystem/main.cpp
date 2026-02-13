#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
    string title;
    string author;
    string ID;
    bool isAvailable;  
    string generateID() {
        static int idCounter = 1;
        return "B" + to_string(idCounter++);
	}
public:
	Book(const string& title, const string& author) : title(title), author(author), isAvailable(true) {
        ID = generateID();
    }
	Book() : title(""), author(""), isAvailable(true) {
        ID = generateID();
    }
    string getTitle() const {
        return title;
    }
    string getAuthor() const {
        return author;
    }
    string getID() const {
        return ID;
    }
    bool getAvailability() const {
        return isAvailable;
    }  
    void setTitle(const string& title) {
        this->title = title;
    }
    void setAuthor(const string& author) {
        this->author = author;
    }
    void setID(const string& ID) {
        this->ID = ID;
    }
    void setAvailability(bool isAvailable) {
        this->isAvailable = isAvailable;
	}

};
void addBook(vector<Book>& library, const Book& book) {
    library.push_back(book);
}
void displayAllBooks(const vector<Book>& library) {
    int i = 1;
    for(const auto& Book : library) {
        cout << i++ << ". Title: " << Book.getTitle() << ", Author: " << Book.getAuthor() << ", ID: " << Book.getID() << ", Available: " << (Book.getAvailability() ? "Yes" : "No") << endl;
	}
}
void searchBookByTitle(const vector<Book>& library, const string& title) {
    for(const auto& Book : library) {
        if(Book.getTitle() == title) {
            cout << "Found: Title: " << Book.getTitle() << ", Author: " << Book.getAuthor() << ", ID: " << Book.getID() << ", Available: " << (Book.getAvailability() ? "Yes" : "No") << endl;
            return;
        }
    }
    cout << "Book with title '" << title << "' not found." << endl;
}
int main() {
    vector<Book> library;

    Book book1("1984", "George Orwell");
    Book book2("Harry Potter", "J.K. Rowling");
    addBook(library, book1);
    addBook(library, book2);

    displayAllBooks(library);

    searchBookByTitle(library, "1984");
    searchBookByTitle(library, "The Great Gatsby");

    return 0;
}