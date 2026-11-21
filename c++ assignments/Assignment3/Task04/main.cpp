#include <iostream>
#include <iomanip>
using namespace std;
class Money {
    long long paise;
public:
    Money(long long rupees=0, int p=0) : paise(rupees*100+p) {}
    Money operator+(const Money& other) const { Money r; r.paise=paise+other.paise; return r; }
    bool operator==(const Money& other) const { return paise==other.paise; }
    friend ostream& operator<<(ostream& os,const Money& m) {
        return os << "Rs " << m.paise/100 << '.' << setw(2) << setfill('0') << m.paise%100 << setfill(' ');
    }
};
int main() {
    Money a(120,75), b(79,25), c=a+b;
    cout << c << '\n' << boolalpha << (c==Money(200)) << '\n';
    Money x(0,75), y(0,50); cout << x << " + " << y << " = " << x+y << '\n';
}
