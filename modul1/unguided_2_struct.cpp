#include <iostream>

using namespace std;

struct Paket {
  int no_resi;
  string isi;
  string alamat;
};

int main() {
  Paket produk1{12111, "Sambal Terasi", "Jalan Di Panjaitan"};

  cout << "Nomor Resi: " << produk1.no_resi << endl;
  cout << "Produk: " << produk1.isi << endl;
  cout << "Alamat Penerima: " << produk1.alamat << endl;

  return 0;
}
