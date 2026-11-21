#include <iostream>
#include <iomanip>
using namespace std;
enum class Zone { Inner, Middle, Outer };
constexpr long long BASE[] = {1000, 2000, 3000};
constexpr long long MIN_BALANCE = 5000;
constexpr int PEAK_PERCENT = 20;
long long fare(Zone z, bool peak) {
    long long amount = 0;
    switch (z) {
        case Zone::Inner: amount = BASE[0]; break;
        case Zone::Middle: amount = BASE[1]; break;
        case Zone::Outer: amount = BASE[2]; break;
    }
    if (peak) amount += amount * PEAK_PERCENT / 100;
    return amount;
}
bool canTravel(long long balance, long long cost) {
    return balance - cost >= MIN_BALANCE;
}
int main() {
    long long balance = 10000;
    struct Trip { Zone zone; bool peak; } trips[] = {
        {Zone::Inner, false}, {Zone::Outer, true}, {Zone::Middle, false}
    };
    for (const auto& t : trips) {
        long long cost = fare(t.zone, t.peak);
        if (canTravel(balance, cost)) {
            balance -= cost;
            cout << "Fare Rs " << cost / 100 << '.' << setw(2) << setfill('0') << cost % 100 << setfill(' ');
        } else cout << "Denied (low balance)";
        cout << " balance Rs " << balance / 100 << '\n';
    }
}
