#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk menghapus karakter non-alfabet dari string
string removeNonAlphanumeric(string str) {
    string result = "";
    for (char c : str) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            result += tolower(c); // Ubah huruf menjadi lowercase
        }
    }
    return result;
}

// Fungsi untuk menentukan apakah string adalah palindrom atau tidak
bool isPalindrome(string str) {
    int kiri = 0;
    int kanan = str.length() - 1;

    while (kiri < kanan) {
        // Lewati karakter non-alfabet di kiri
        while (kiri < kanan && !isalpha(str[kiri])) {
            kiri++;
        }
        // Lewati karakter non-alfabet di kanan
        while (kiri < kanan && !isalpha(str[kanan])) {
            kanan--;
        }
        // Periksa apakah karakter di kiri sama dengan karakter di kanan
        if (tolower(str[kiri]) != tolower(str[kanan])) {
            return false;
        }
        kiri++;
        kanan--;
    }

    return true;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    string cleanedString = removeNonAlphanumeric(kalimat);
    if (isPalindrome(cleanedString)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}
