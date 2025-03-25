#include <iostream>
using namespace std;

class Base {
protected:
    int protectedData;

public:
    Base(int val) : protectedData(val) {}
};

class Derived : public Base {
public:
    Derived(int val) : Base(val) {}
    void show() { cout << "Protected Data: " << protectedData << endl; }
};

int main() {
    Derived obj(42);
    obj.show();
    return 0;
}
