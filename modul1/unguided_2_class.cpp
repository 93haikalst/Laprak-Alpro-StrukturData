#include <iostream>

using namespace std;

class Mobil {
  public:
    string merk;
    string plat_num;
    int tahun;

    string cetak() {
      return merk + " " + plat_num + " (" + to_string(tahun) + ")";
    }
};

int main() {
  Mobil mobil1;
  mobil1.merk = "Esemka";
  mobil1.plat_num = "B 10 HG";
  mobil1.tahun = 2020;

  cout << mobil1.cetak() << endl;

  return 0;
}
