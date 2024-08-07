#include <iostream>

class MyClass {
public:
    int data;

    MyClass(int value) : data(value) {}

    // Surcharge de l'opérateur +
    MyClass operator+(const MyClass &other) const {
        return MyClass(data + other.data);
    }
};

int main() {
    MyClass obj1(10), obj2(20);
    MyClass obj3 = obj1 + obj2;  // Utilisation de l'opérateur + surchargé
    std::cout << obj3.data;
	return 0;
}
