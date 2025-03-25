#include <iostream>
using namespace std;

class Base {
public:
    int publicData;
    Base(int val) : publicData(val) {}
};

class Derived : public Base {
public:
    Derived(int val) : Base(val) {}
    void show() { cout << "Public Data: " << publicData << endl; }
};

int main() {
    Derived obj(100);
    obj.show();
    return 0;
}
