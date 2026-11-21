#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
class Book {
    string title, author; int copies;
public:
    Book(const string& t, const string& a, int c) : title(t), author(a), copies(c) {
        if (c < 0) throw invalid_argument("number of copies cannot be negative");
    }
    explicit Book(const string& t) : Book(t, "Unknown", 1) {}
    Book() : Book("Untitled", "Unknown", 0) {}
    void print() const { cout << title << " | " << author << " | " << copies << '\n'; }
};
int main() {
    Book a("Wings of Fire", "A.P.J. Abdul Kalam", 5), b("Gitanjali"), c;
    a.print(); b.print(); c.print();
    try { Book bad("Invalid", "Unknown", -1); bad.print(); }
    catch (const invalid_argument& e) { cout << e.what() << '\n'; }
}
