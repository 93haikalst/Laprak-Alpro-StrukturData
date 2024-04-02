#include <iostream>
#include <iomanip>
using namespace std;

class Barang {
public:
    string namaProduk;
    int harga;
    Barang* prev;
    Barang* next;
};

class DoubleLinkedList {
public:
    Barang* head;
    Barang* tail;

    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void tambah(string namaProduk, int harga) {
        Barang* newNode = new Barang;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void tambahSetelah(string namaProduk, int harga, string keyNamaProduk) {
        Barang* current = head;
        while (current != nullptr && current->namaProduk != keyNamaProduk) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Produk " << keyNamaProduk << " tidak ditemukan.\n";
            return;
        }

        Barang* newNode = new Barang;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = current;
        newNode->next = current->next;

        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
    }

    void hapus(string namaProduk) {
        Barang* current = head;
        while (current != nullptr && current->namaProduk != namaProduk) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Produk " << namaProduk << " tidak ditemukan.\n";
            return;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        delete current;
    }

    bool perbarui(string oldNamaProduk, string newNamaProduk, int newHarga) {
        Barang* current = head;
        while (current != nullptr && current->namaProduk != oldNamaProduk) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Produk " << oldNamaProduk << " tidak ditemukan.\n";
            return false;
        }

        current->namaProduk = newNamaProduk;
        current->harga = newHarga;
        return true;
    }

    void hapusSemua() {
        Barang* current = head;
        while (current != nullptr) {
            Barang* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void tampilkan() {
        Barang* current = head;
        cout << left << setw(20) << "Nama Produk" << setw(10) << "Harga" << endl;
        while (current != nullptr) {
            cout << left << setw(20) << current->namaProduk << setw(10) << current->harga << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    
    DoubleLinkedList list;
    list.tambah("Originote", 60000);
    list.tambah("Somethinc", 150000);
    list.tambah("Skintific", 100000);
    list.tambah("Wardah", 50000);
    list.tambah("Hanasui", 30000);

    while (true) {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Perbarui Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << endl;

        int choice;
        cout << "Masukkan your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1: {
                string namaProduk;
                int harga;
                cout << "Masukkan nama produk: ";
                cin >> namaProduk;
                cout << "Masukkan harga: ";
                cin >> harga;
                list.tambah(namaProduk, harga);
                break;
            }
            case 2: {
                string namaProduk;
                cout << "Masukkan nama produk yang akan dihapus: ";
                cin >> namaProduk;
                list.hapus(namaProduk);
                break;
            }
            case 3: {
                string oldNamaProduk, newNamaProduk;
                int newHarga;
                cout << "Masukkan nama produk yang akan diperbarui: ";
                cin >> oldNamaProduk;
                cout << "Masukkan nama produk baru: ";
                cin >> newNamaProduk;
                cout << "Masukkan harga baru: ";
                cin >> newHarga;
                bool updated = list.perbarui(oldNamaProduk, newNamaProduk, newHarga);
                if (!updated) {
                    cout << "Data tidak ditemukan" << endl;
                }
                break;
            }
            case 4: {
                string namaProduk, keyNamaProduk;
                int harga;
                cout << "Masukkan nama produk yang akan ditambahkan setelahnya: ";
                cin >> keyNamaProduk;
                cout << "Masukkan nama produk baru: ";
                cin >> namaProduk;
                cout << "Masukkan harga: ";
                cin >> harga;
                list.tambahSetelah(namaProduk, harga, keyNamaProduk);
                break;
            }
            case 5: {
                string namaProduk;
                cout << "Masukkan nama produk yang akan dihapus: ";
                cin >> namaProduk;
                list.hapus(namaProduk);
                break;
            }
            case 6: {
                list.hapusSemua();
                cout << "Semua data telah dihapus." << endl;
                break;
            }
            case 7: {
                cout << "Data Produk:\n";
                list.tampilkan();
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        }
    }
    return 0;
}
