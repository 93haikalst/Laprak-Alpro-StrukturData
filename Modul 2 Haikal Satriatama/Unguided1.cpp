#include <iostream>
using namespace std;

int main() {    
    int numb[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Data array :";
    for (int i = 0; i < 10; ++i) {
        cout << " " << numb[i];
    }
    cout << endl;

    cout << "Nomor genap :";
    for (int i = 0; i < 10; ++i) {
        if (numb[i] % 2 == 0) {
            cout << " " << numb[i];
        }
    }
    cout << endl;

    cout << "Nomor ganjil :";
    for (int i = 0; i < 10; ++i) {
        if (numb[i] % 2 != 0) {
            cout << " " << numb[i];
        }
    }
    cout << endl;

    return 0;
}
