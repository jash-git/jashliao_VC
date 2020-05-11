#include <iostream>
using namespace std;

class Employee {
public:
    Employee() {
        _num = 0;
        _years = 0.0;
    }

    Employee(int num, double years) {
        _num = num;
        _years = years;
    }

    int num() {
        return _num;
    }

    double years() {
        return _years;
    }

private:
    int _num;
    double _years;
};

int main() {
    Employee p1(101, 3.5);
    Employee p2 = p1;

    cout << "p1 addr:\t" << &p1 << endl;
    cout << "p1.num: \t" << p1.num() << endl;
    cout << "p1.years:\t" << p1.years() << endl;

    cout << "p2 addr:\t" << &p2 << endl;
    cout << "p2.num: \t" << p2.num() << endl;
    cout << "p2.years:\t" << p2.years() << endl;

    return 0;
}
