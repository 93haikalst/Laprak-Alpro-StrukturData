#include <iostream>

using namespace std;

bool sisa_dibagi(int a, int b) {
    return a % b == 0;
} 

bool isGanjil(int c) {
    return c % 2 != 0;
}

int main() {
    int a = 3, b = 2;
    if (sisa_dibagi(a, b)){
        cout << a << " dan " << b << " sisa bila dibagi\n";
    } else {
        cout << a << " dan " << b << " tidak sisa bila dibagi\n";
    }

    if (isGanjil(a)) {
        cout << a << " ganjil\n";
    } else {
        cout << a << " genap\n";
    }

    if (isGanjil(b)) {
        cout << b << " ganjil\n";
    } else {
        cout << b << " genap\n";
    }
    return 0;
}