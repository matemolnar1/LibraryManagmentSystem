#include <iostream>

using namespace std;

class Book {
    string title;
    string author;
    int ID;
    bool isAvailable;
public:
	Book(const string& title, const string& author, int ID) : title(title), author(author), ID(ID), isAvailable(true) {}
	Book() : title(""), author(""), ID(0), isAvailable(true) {}
    string getTitle() const {
        return title;
    }
    string getAuthor() const {
        return author;
    }
    int getID() const {
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
    void setID(int ID) {
        this->ID = ID;
    }
    void setAvailability(bool isAvailable) {
        this->isAvailable = isAvailable;
	}
};
int main() {
   
    return 0;
}