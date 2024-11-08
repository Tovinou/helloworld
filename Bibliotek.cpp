#include <iostream>
#include <string>
#include <vector>
#include <memory> // For smart pointers (polymorphism)

using namespace std;

// Base class for all library items
class Item {
protected:
    string title;
    string author;
    int year;

public:
    Item(const string& title, const string& author, int year)
        : title(title), author(author), year(year) {}

    virtual void display_info() const = 0; // Abstract method

    string getTitle() const { return title; }
};

// Subclass for books
class Book : public Item {
private:
    int pages;

public:
    Book(const string& title, const string& author, int year, int pages)
        : Item(title, author, year), pages(pages) {}

    void display_info() const override {
        cout << "Book - Title: " << title << ", Author: " << author
             << ", Year: " << year << ", Pages: " << pages << endl;
    }
};

// Subclass for magazines
class Magazine : public Item {
private:
    int issue;

public:
    Magazine(const string& title, const string& author, int year, int issue)
        : Item(title, author, year), issue(issue) {}

    void display_info() const override {
        cout << "Magazine - Title: " << title << ", Author: " << author
             << ", Year: " << year << ", Issue: " << issue << endl;
    }
};

// Class for library users
class LibraryUser {
private:
    string name;
    vector<shared_ptr<Item>> borrowed_items;

public:
    LibraryUser(const string& name) : name(name) {}

    void borrow(shared_ptr<Item> item) {
        borrowed_items.push_back(item);
        cout << name << " borrowed: " << item->getTitle() << endl;
    }

    void return_item(shared_ptr<Item> item) {
        for (auto it = borrowed_items.begin(); it != borrowed_items.end(); ++it) {
            if (*it == item) {
                borrowed_items.erase(it);
                cout << name << " returned: " << item->getTitle() << endl;
                return;
            }
        }
        cout << "Error: " << name << " did not borrow " << item->getTitle() << endl;
    }

    void list_borrowed_items() const {
        cout << name << " has borrowed the following items:" << endl;
        for (const auto& item : borrowed_items) {
            item->display_info();
        }
    }

    string getName() const { return name; }

    // Getter method for borrowed_items
    const vector<shared_ptr<Item>>& getBorrowedItems() const {
        return borrowed_items;
    }
};

// Class for the library
class Library {
private:
    vector<shared_ptr<Item>> items;
    vector<shared_ptr<LibraryUser>> users;

public:
    void add_item(shared_ptr<Item> item) {
        items.push_back(item);
        cout << "Item added: " << item->getTitle() << endl;
    }

    void remove_item(shared_ptr<Item> item) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (*it == item) {
                items.erase(it);
                cout << "Item removed: " << item->getTitle() << endl;
                return;
            }
        }
        cout << "Error: Item not found in the library." << endl;
    }

    void register_user(shared_ptr<LibraryUser> user) {
        users.push_back(user);
        cout << "User registered: " << user->getName() << endl;
    }

    void borrow_item(shared_ptr<LibraryUser> user, shared_ptr<Item> item) {
        for (const auto& borrowed_user : users) {
            if (borrowed_user != user) {
                for (const auto& borrowed_item : borrowed_user->getBorrowedItems()) {
                    if (borrowed_item == item) {
                        cout << "Error: The item is already borrowed." << endl;
                        return;
                    }
                }
            }
        }
        user->borrow(item);
    }

    void return_item(shared_ptr<LibraryUser> user, shared_ptr<Item> item) {
        user->return_item(item);
    }

    void list_items() const {
        cout << "List of all items in the library:" << endl;
        for (const auto& item : items) {
            item->display_info();
        }
    }

    void list_available_items() const {
        cout << "Available items in the library:" << endl;
        for (const auto& item : items) {
            bool is_borrowed = false;
            for (const auto& user : users) {
                for (const auto& borrowed_item : user->getBorrowedItems()) {
                    if (borrowed_item == item) {
                        is_borrowed = true;
                        break;
                    }
                }
                if (is_borrowed) break;
            }
            if (!is_borrowed) {
                item->display_info();
            }
        }
    }

    void summary() const {
        cout << "Summary of borrowed items:" << endl;
        for (const auto& user : users) {
            user->list_borrowed_items();
        }
    }
};

int main() {
    // Create library
    Library library;

    // Create books and magazines
    auto book1 = make_shared<Book>("C++ Programming", "Bjarne Stroustrup", 1991, 500);
    auto book2 = make_shared<Book>("Clean Code", "Robert C. Martin", 2008, 464);
    auto magazine1 = make_shared<Magazine>("Tech Monthly", "Various Authors", 2024, 10);

    // Add items to the library
    library.add_item(book1);
    library.add_item(book2);
    library.add_item(magazine1);

    // Create users
    auto user1 = make_shared<LibraryUser>("Alice");
    auto user2 = make_shared<LibraryUser>("Bob");

    // Register users
    library.register_user(user1);
    library.register_user(user2);

    // Borrow and return items
    library.borrow_item(user1, book1);
    library.borrow_item(user2, book1); // Should give an error
    library.borrow_item(user2, magazine1);
    library.return_item(user1, book1);
    library.borrow_item(user2, book1);

    // List available items
    library.list_available_items();

    // Summary of borrowed items
    library.summary();

    return 0;
}
