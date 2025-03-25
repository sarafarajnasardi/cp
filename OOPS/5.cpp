#include <iostream>
using namespace std;

class Base {
private:
    int privateData;

public:
    Base(int val) : privateData(val) {}
    void showBase() { cout << "Base Private Data: " << privateData << endl; }
};

class Derived : public Base {
public:
    Derived(int val) : Base(val) {}
};

int main() {
    Derived obj(50);
    obj.showBase();
    return 0;
}
