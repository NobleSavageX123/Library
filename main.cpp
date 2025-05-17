#include <iostream>
#include <string>
using namespace std;

const int totalBooks = 100;
int bookIDs[totalBooks];
string bookTitles[totalBooks];
string bookAuthors[totalBooks];
bool bookStatus[totalBooks];
int bookCount = 0;

void addBook();
void displayBooks();
void borrowBook();
void returnBook();

int main() {
    int choice;
    
    cout << "*********Library Management System*********" << endl;
    cout << "*********-------------------------*********" << endl;
    
    while (true) {
        cout << "Please Enter your choice: " << endl;
        cout << "1. Add a new book" << endl;
        cout << "2. Display all books" << endl;
        cout << "3. Borrow a book" << endl;
        cout << "4. Return a book" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                cout << "System Closing....." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    return 0;
}

void addBook() {
    if (bookCount >= totalBooks) {
        cout << "No more slots for a new book. Please choose another action:" << endl;
        return;
    }
    
    cout << "Enter Book ID: ";
    cin >> bookIDs[bookCount];
    
    cout << "Enter Book Title: ";
    cin >> bookTitles[bookCount];
    
    cout << "Enter Author Name: ";
    cin >> bookAuthors[bookCount];
    
    bookStatus[bookCount] = true;
    bookCount++;
    
    cout << "Book has been added successfully!" << endl;
}

void displayBooks() {
    if (bookCount == 0) {
        cout << "Library is empty." << endl;
        return;
    }
    
    cout << "All Books:" << endl;
    cout << "ID\tTitle\tAuthor\tStatus" << endl;
    cout << "-------------------------" << endl;
    
    for (int i = 0; i < bookCount; i++) {
        
        string status = "";
        if (bookStatus[i] == true) {
            status = "Available";
        }
        else {
            status = "Borrowed";
        }
        
        cout << bookIDs[i] << "\t" 
             << bookTitles[i] << "\t" 
             << bookAuthors[i] << "\t"
             << status << endl;
    }
}

void borrowBook() {
    if (bookCount == 0) {
        cout << "Library is empty, you cannot borrow a book." << endl;
        return;
    }
    
    int id;
    cout << "Enter Book's ID to borrow: ";
    cin >> id;
    
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (bookIDs[i] == id) {
            found = true;
            if (bookStatus[i]) {
                bookStatus[i] = false;
                cout << "Book has been borrowed successfully!" << endl;
            } else {
                cout << "Book is borrowed, Please try again with a different book." << endl;
            }
            break;
        }
    }
    
    if (!found) {
        cout << "Book with ID " << id << " not found." << endl;
    }
}

void returnBook() {
    if (bookCount == 0) {
        cout << "No books in the library to return." << endl;
        return;
    }
    
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;
    
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (bookIDs[i] == id) {
            found = true;
            if (!bookStatus[i]) {
                bookStatus[i] = true;
                cout << "Book returned successfully!" << endl;
            } else {
                cout << "Book was not borrowed." << endl;
            }
            break;
        }
    }
    
    if (!found) {
        cout << "Book with ID " << id << " not found." << endl;
    }
}
