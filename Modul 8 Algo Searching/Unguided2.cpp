#include <iostream>
#include <string> 

using namespace std;

int main() {
    string kalimat;
    int jumlah = 0;

    cout << "--------------------------------------" << endl;
    cout << "    Program Menghitung Huruf Vokal    " << endl;
    cout << "--------------------------------------" << endl;

    cout << "Masukkan kalimat : ";
    getline(cin, kalimat); 

    for (int n_63 = 0; n_63 < kalimat.length(); n_63++) {
        char a = kalimat[n_63];
        if (a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o' ||
            a == 'A' || a == 'I' || a == 'U' || a == 'E' || a == 'O') {
            jumlah++;
        }
    }

    cout << "Jumlah huruf vokal pada kalimat: " << jumlah << endl;

    return 0;
}