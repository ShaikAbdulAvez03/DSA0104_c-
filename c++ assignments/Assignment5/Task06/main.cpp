#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
class Bill {
protected: string patient;
public:
    explicit Bill(const string& p):patient(p){}
    virtual ~Bill()=default;
    virtual double total() const=0;
    virtual string type() const=0;
    void print() const { cout << type() << ' ' << patient << ": " << total() << '\n'; }
};
class OutPatient:public Bill {
    double consultation,tests;
public: OutPatient(const string& p,double c,double t):Bill(p),consultation(c),tests(t){}
    double total() const override{return consultation+tests;}
    string type() const override{return "OP";}
};
class InPatient:public Bill {
    int days; double perDay,surgery;
public: InPatient(const string& p,int d,double r,double s):Bill(p),days(d),perDay(r),surgery(s){}
    double total() const override{return days*perDay+surgery;}
    string type() const override{return "IP";}
};
int main(){
    vector<unique_ptr<Bill>> bills;
    bills.push_back(make_unique<OutPatient>("Ravi",500,1200));
    bills.push_back(make_unique<InPatient>("Meena",3,2500,40000));
    double sum=0; for(const auto& b:bills){b->print();sum+=b->total();}
    cout << "Total " << sum << '\n';
}
