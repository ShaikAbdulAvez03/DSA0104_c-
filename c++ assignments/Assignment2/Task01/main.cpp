#include <iostream>
using namespace std;
void applyByValue(long long fee, int percent) { fee -= fee * percent / 100; }
void applyByReference(long long& fee, int percent) { fee -= fee * percent / 100; }
void applyByPointer(long long* fee, int percent) { if (fee) *fee -= *fee * percent / 100; }
int main() {
    long long fee = 45000;
    applyByValue(fee, 10); cout << "after value: " << fee << '\n';
    applyByReference(fee, 10); cout << "after reference: " << fee << '\n';
    applyByPointer(&fee, 10); cout << "after pointer: " << fee << '\n';
}
