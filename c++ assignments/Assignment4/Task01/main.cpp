#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
constexpr double DA_RATE=0.42;
class Staff {
protected: string name; int id;
public:
    Staff(const string& n,int i):name(n),id(i){}
    virtual double pay() const=0;
    virtual ~Staff()=default;
    void show() const { cout << id << ' ' << name << " Rs." << pay() << '\n'; }
};
class Professor: public Staff {
    double basic,research;
public: Professor(const string& n,int i,double b,double r):Staff(n,i),basic(b),research(r){}
    double pay() const override { return basic+basic*DA_RATE+research; }
};
class LabAssistant: public Staff {
    double basic;
public: LabAssistant(const string& n,int i,double b):Staff(n,i),basic(b){}
    double pay() const override { return basic+basic*DA_RATE; }
};
class GuestFaculty: public Staff {
    double hours,rate;
public: GuestFaculty(const string& n,int i,double h,double r):Staff(n,i),hours(h),rate(r){}
    double pay() const override { return hours*rate; }
};
int main(){
    vector<unique_ptr<Staff>> staff;
    staff.push_back(make_unique<Professor>("Ravi",1,50000,5000));
    staff.push_back(make_unique<LabAssistant>("Meena",2,20000));
    staff.push_back(make_unique<GuestFaculty>("Arun",3,10,1500));
    for(const auto& s:staff) s->show();
}
