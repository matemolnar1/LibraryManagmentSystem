#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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
void saveToFile(const vector<Book>& library, const string & filename) {
    ofstream Fout(filename);
	if (!Fout) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    for(const auto& Book : library) {
        Fout << Book.getTitle() << "," << Book.getAuthor() << "," << Book.getID() << "," << (Book.getAvailability() ? "1" : "0") << endl;
    }
	Fout.close();
}
void loadFromFile(vector<Book>& library, const string& filename) {
    ifstream Fin(filename);
    if (!Fin) {
        cerr << "Error opening file for reading." << endl;
        return;
	}
    string line;
    while (getline(Fin, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);
        if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) {
            cerr << "Invalid data format in file." << endl;
            continue;
        }
        string title = line.substr(0, pos1);
        string author = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string ID = line.substr(pos2 + 1, pos3 - pos2 - 1);
        bool isAvailable = (line.substr(pos3 + 1) == "1");
        Book book(title, author);
        book.setID(ID);
        book.setAvailability(isAvailable);
        library.push_back(book);
    }
	Fin.close();
}

int main() {
    vector<Book> library;

    /*Book book1("1984", "George Orwell");
    Book book2("Harry Potter", "J.K. Rowling");
    addBook(library, book1);
    addBook(library, book2);

    displayAllBooks(library);
  
    searchBookByTitle(library, "1984");
    searchBookByTitle(library, "The Great Gatsby");*/
    while (true) {
       
		cout << "---------------------------" << endl;
        cout << "\t LIBRARY \t" << endl;
		cout << "---------------------------" << endl;
        cout << "1. Add Book" << endl;
		cout << "2. Display All Books" << endl;
        cout << "3. Search Book by Title" << endl;
        cout << "4. Exit" << endl;
		cout << "5. Save to File" << endl;
		cout << "6. Load from File" << endl;
        cout << "Choose an option: ";
        int choice;
        while (true) {
            cout << "Enter your choice: ";
            if (cin >> choice) {
                // Input was a valid integer!
                break;
            }
            else {
                // Input was NOT an integer
                cout << "Invalid input. Please enter a number.\n";
                cin.clear(); // 1. Reset the "fail" state
                cin.ignore(10000, '\n'); // 2. Throw away the bad input
            }
        }
        switch (choice) {
            case 1: {
                system("cls");
                string title, author;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                Book newBook(title, author);
                addBook(library, newBook);
                break;
            }
            case 2:
                system("cls");
                displayAllBooks(library);
                break;
            case 3: {
                system("cls");
                string title;
                cout << "Enter book title to search: ";
                cin.ignore();
                getline(cin, title);
                searchBookByTitle(library, title);
                break;
            }
            case 4:
                system("cls");
                cout << "Exiting..." << endl;
                return 0;
            case 5: {
                system("cls");
                string filename;
                cout << "Enter filename to save: ";
                cin.ignore();
                getline(cin, filename);
                saveToFile(library, filename);
                break;
			}
            case 6: {
                system("cls");
                string filename;
                cout << "Enter filename to load: ";
                cin.ignore();
                getline(cin, filename);
                loadFromFile(library, filename);
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}