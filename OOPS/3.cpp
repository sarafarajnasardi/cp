#include <iostream>
using namespace std;

class Base1 {
public:
    void show1() { cout << "Base1 Function\n"; }
};

class Base2 {
public:
    void show2() { cout << "Base2 Function\n"; }
};

class Derived : public Base1, public Base2 {
public:
    void showDerived() { cout << "Derived Class Function\n"; }
};

int main() {
    Derived obj;
    obj.show1();
    obj.show2();
    obj.showDerived();
    return 0;
}
