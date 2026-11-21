#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
class Vehicle {
    string reg; double rate; bool rented=false;
public:
    Vehicle(string r,double d):reg(r),rate(d){}
    virtual ~Vehicle()=default;
    bool rent(){ if(rented) return false; rented=true; return true; }
    double baseCharge(int days) const { return days*rate; }
    virtual double charge(int days,double usage=0) const=0;
    virtual string type() const=0;
    void returned(){ rented=false; }
};
class Bicycle:public Vehicle {
public: using Vehicle::Vehicle;
    double charge(int days,double=0) const override{return baseCharge(days);}
    string type() const override{return "Bicycle";}
};
class Car:public Vehicle {
    double fuelPrice;
public: Car(string r,double rate,double p):Vehicle(r,rate),fuelPrice(p){}
    double charge(int days,double litres) const override{return baseCharge(days)+litres*fuelPrice;}
    string type() const override{return "Car";}
};
int main(){
    vector<unique_ptr<Vehicle>> fleet;
    fleet.push_back(make_unique<Bicycle>("B01",100));
    fleet.push_back(make_unique<Car>("C01",1500,100));
    cout << fleet[0]->type() << " 3-day charge: " << fleet[0]->charge(3) << '\n';
    cout << fleet[1]->type() << " 3-day charge: " << fleet[1]->charge(3,10) << '\n';
}
