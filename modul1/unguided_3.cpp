#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, string> kbbi;
    kbbi["sahur"] = "makan pada dini hari (disunahkan menjelang fajar sebelum subuh) bagi orang-orang yang akan menjalankan ibadah puasa";
    kbbi["implikasi"] = "keterlibatan atau keadaan terlibat";
    kbbi["royal"] = "berlebih-lebihan (dalam mengeluarkan uang, dalam makan minum); melampaui batas";
    string kata;
    cout << "Masukkan Kata : ";
    cin >> kata;
    if (kbbi[kata] == "") {
        cout << "Tidak ada arti kata : " << kata;
        return 0;
    }
    cout << "Arti : " << kbbi[kata] << endl;
}