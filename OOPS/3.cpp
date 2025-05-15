#include <iostream>
using namespace std;

class Base1 {
public:
    void show() { cout << "Base1 Function\n"; }
};

class Base2 {
public:
    void show() { cout << "Base2 Function\n"; }
};

class Derived : public Base1, public Base2 {
public:
    void show() { cout << "Derived Class Function\n"; }
};

int main() {
    Derived obj;
    obj.Base2::show();
    return 0;
}
