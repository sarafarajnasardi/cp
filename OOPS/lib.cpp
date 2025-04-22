#include <bits/stdc++.h>
#include <fstream>
using namespace std;

// ------------------------ Book Class ------------------------
class Book {
public:
    int id;
    string book_name;
    string author_name;
    int price;
    bool issued;

    Book() {}

    Book(int id, string book_name, int price, string author_name) {
        this->id = id;
        this->book_name = book_name;
        this->author_name = author_name;
        this->price = price;
        this->issued = false;
    }

    // Operator Overloading
    bool operator==(const Book& other) {
        return (id == other.id && book_name == other.book_name);
    }

    // Friend Function
    friend void compare(Book& a, Book& b);
};

void compare(Book& a, Book& b) {
    if (a.price > b.price)
        cout << a.book_name << " is costlier than " << b.book_name << endl;
    else if (a.price < b.price)
        cout << b.book_name << " is costlier than " << a.book_name << endl;
    else
        cout << "Both books have the same price\n";
}

// ------------------------ IssueBook Class ------------------------
class IssueBook : public Book {
public:
    string issue_date;
    string due_date;
    string issued_to;

    IssueBook() {}

    IssueBook(int id, string book_name, int price, string author_name,
              string issue_date, string due_date, string issued_to)
        : Book(id, book_name, price, author_name) {
        this->issue_date = issue_date;
        this->due_date = due_date;
        this->issued_to = issued_to;
        this->issued = true;
    }
};

// ------------------------ Library Class ------------------------
class Library {
public:
    static int issued_book_count;
    static int book_count;
    Book books[100];
    IssueBook issued_books[100];

    Library() {
        book_count = 0;
        issued_book_count = 0;
    }

    void add(int id, string name, int price, string author) {
        books[book_count++] = Book(id, name, price, author);
    }

    void issue(int id, string issue_date, string due_date, string issued_to) {
        for (int i = 0; i < book_count; i++) {
            if (books[i].id == id && !books[i].issued) {
                books[i].issued = true;
                issued_books[issued_book_count++] =
                    IssueBook(books[i].id, books[i].book_name, books[i].price,
                              books[i].author_name, issue_date, due_date, issued_to);
                cout << "Book issued successfully!\n";
                return;
            }
        }
        cout << "Book not found or already issued.\n";
    }

    void display_books() {
        cout << "\nAll Books:\n";
        for (int i = 0; i < book_count; i++) {
            cout << books[i].id << " " << books[i].book_name << " by "
                 << books[i].author_name << " - Rs." << books[i].price
                 << (books[i].issued ? " (Issued)\n" : " (Available)\n");
        }
    }

    void display_issued() {
        cout << "\nIssued Books:\n";
        for (int i = 0; i < issued_book_count; i++) {
            cout << issued_books[i].book_name << " issued to "
                 << issued_books[i].issued_to << " on "
                 << issued_books[i].issue_date << ", due: "
                 << issued_books[i].due_date << endl;
        }
    }

    // ---------- File Handling ----------
    void saveBooksToFile(string filename) {
        ofstream fout(filename);
        if (!fout) {
            cout << "Error opening file for writing!\n";
            return;
        }
        for (int i = 0; i < book_count; i++) {
            fout << books[i].id << "," << books[i].book_name << "," << books[i].author_name
                 << "," << books[i].price << "," << books[i].issued << "\n";
        }
        
        fout.close();
        cout << "Books saved to file successfully.\n";
    }

    void loadBooksFromFile(string filename) {
        ifstream fin(filename);
        if (!fin) {
            cout << "File not found!\n";
            return;
        }

        string line;
        while (getline(fin, line)) {
            stringstream ss(line);
            string idStr, name, author, priceStr, issuedStr;
            getline(ss, idStr, ',');
            getline(ss, name, ',');
            getline(ss, author, ',');
            getline(ss, priceStr, ',');
            getline(ss, issuedStr, ',');

            int id = stoi(idStr);
            int price = stoi(priceStr);
            bool issued = (issuedStr == "1");

            books[book_count++] = Book(id, name, price, author);
            books[book_count - 1].issued = issued;
        }
        fin.close();
        cout << "Books loaded from file successfully.\n";
    }

    void searchBookInFile(string filename, int bookId) {
        ifstream fin(filename);
        if (!fin) {
            cout << "File not found!\n";
            return;
        }

        string line;
        while (getline(fin, line)) {
            stringstream ss(line);
            string idStr, name, author, priceStr, issuedStr;
            getline(ss, idStr, ',');
            getline(ss, name, ',');
            getline(ss, author, ',');
            getline(ss, priceStr, ',');
            getline(ss, issuedStr, ',');

            int id = stoi(idStr);
            if (id == bookId) {
                cout << "Book Found: " << name << " by " << author
                     << " Rs." << priceStr
                     << (issuedStr == "1" ? " (Issued)\n" : " (Available)\n");
                fin.close();
                return;
            }
        }
        cout << "Book not found in file.\n";
        fin.close();
    }
};

// ---------- Static Member Initialization ----------
int Library::book_count = 0;
int Library::issued_book_count = 0;

// ---------- Template Function ----------
template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

// ------------------------ Main Function ------------------------
int main() {
    Library lib;

    // Add books
    lib.add(1, "C++ Basics", 300, "Bjarne");
    lib.add(2, "DSA Mastery", 500, "Sahni");

    // Display books
    lib.display_books();

    // Issue a book
    lib.issue(2, "2025-04-21", "2025-05-21", "Sarafaraj");

    // Display issued books
    lib.display_issued();

    // Compare books
    compare(lib.books[0], lib.books[1]);

    // Operator overloading check
    if (lib.books[0] == lib.books[1])
        cout << "Both books are the same (== overloaded)\n";
    else
        cout << "Books are different (== overloaded)\n";

    // File handling
    lib.saveBooksToFile("books.txt");
    lib.loadBooksFromFile("books.txt");
    lib.searchBookInFile("books.txt", 2);
    
    lib.display_books();
    // Template usage
    cout << "Max of 10 and 20: " << getMax(10, 20) << endl;
    cout << "Max of 'a' and 'b': " << getMax('a', 'b') << endl;

    return 0;
}
