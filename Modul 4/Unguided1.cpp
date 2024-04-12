#include <iostream>
#include <string> // Include string header explicitly if you use string directly
using namespace std;

struct mahasiswa
{
    string nama;
    string nim;
};

struct node
{
    mahasiswa ITTP;
    node *next;
};

node *head = nullptr; // Initialize pointers to nullptr
node *tail = nullptr;
node *bantu = nullptr;
node *hapus = nullptr;
node *before = nullptr;
node *baru = nullptr;

// Function prototypes
void init();
bool isEmpty();
mahasiswa Pendataan();
void insertDepan(mahasiswa ITTP);
void insertBelakang(mahasiswa ITTP);
int hitungList();
void insertTengah(mahasiswa identitas, int posisi);
void ubahDepan(mahasiswa data);
void ubahBelakang(mahasiswa data);
void ubahTengah(mahasiswa data);
void tampil();
void hapusDepan();
void hapusBelakang();
void hapusTengah();
void hapusList();

int main()
{
    init();
    mahasiswa ITTP;
back:
    int operasi, posisi;
    cout << " PROGRAM DATA MAHASISWA" << endl;
    cout << " =======================" << endl;
    cout << "1. Tambah Depan" << endl;
    cout << "2. Tambah Belakang" << endl;
    cout << "3. Tambah Tengah" << endl;
    cout << "4. Ubah Depan" << endl;
    cout << "5. Ubah Belakang" << endl;
    cout << "6. Ubah Tengah" << endl;
    cout << "7. Hapus depan" << endl;
    cout << "8. Hapus belakang" << endl;
    cout << "9. Hapus Tengah" << endl;
    cout << "10.Hapus list" << endl;
    cout << "11.Tampilkan" << endl;
    cout << "0. Exit" << endl;

    cout << "\nPilih Operasi :> ";
    cin >> operasi;

    switch (operasi)
    {
    case 1:
        cout << "tambah depan\n";
        insertDepan(Pendataan());
        cout << endl;
        goto back;
        break;

    case 2:
        cout << "tambah belakang\n";
        insertBelakang(Pendataan());
        cout << endl;
        goto back;
        break;
    case 3:
        cout << "tambah tengah\n";
        cout << "nama : ";
        cin >> ITTP.nama;
        cout << "NIM : ";
        cin >> ITTP.nim;
        cout << "Posisi: ";
        cin >> posisi;
        insertTengah(ITTP, posisi);
        cout << endl;
        goto back;
        break;
    case 4:
        cout << "ubah depan\n";
        ubahDepan(Pendataan());
        cout << endl;
        goto back;
        break;
    case 5:
        cout << "ubah belakang\n";
        ubahBelakang(Pendataan());
        cout << endl;
        goto back;
        break;
    case 6:
        cout << "ubah tengah\n";
        ubahTengah(Pendataan());
        cout << endl;
        goto back;
        break;
    case 7:
        cout << "hapus depan\n";
        hapusDepan();
        cout << endl;
        goto back;
        break;
    case 8:
        cout << "hapus belakang\n";
        hapusBelakang();
        cout << endl;
        goto back;
        break;
    case 9:
        cout << "hapus tengah\n";
        hapusTengah();
        cout << endl;
        goto back;
        break;
    case 10:
        cout << "hapus list\n";
        hapusList();
        cout << endl;
        goto back;
        break;
    case 11:
        tampil();
        cout << endl;
        goto back;
        break;

    case 0:
        cout << "\nEXIT PROGRAM\n";
        break;

    default:
        cout << "\nSalah input operasi\n";
        cout << endl;
        goto back;
        break;
    }

    return 0;
}

void init()
{
    head = nullptr;
    tail = nullptr;
}

bool isEmpty()
{
    return head == nullptr;
}

mahasiswa Pendataan()
{
    mahasiswa ITTP;
    cout << "\nMasukkan Nama\t: ";
    cin.ignore();
    getline(cin, ITTP.nama);
    cout << "Masukkan NIM\t: ";
    cin >> ITTP.nim;
    return ITTP;
}

void insertDepan(mahasiswa ITTP)
{
    node *baru = new node;
    baru->ITTP = ITTP;
    baru->next = nullptr;
    if (isEmpty())
    {
        head = tail = baru;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
    cout << "Data " << ITTP.nama << " berhasil diinput!\n";
}

void insertBelakang(mahasiswa ITTP)
{
    node *baru = new node;
    baru->ITTP = ITTP;
    baru->next = nullptr;
    if (isEmpty())
    {
        head = tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

int hitungList()
{
    int penghitung = 0;
    node *bantu = head;
    while (bantu != nullptr)
    {
        penghitung++;
        bantu = bantu->next;
    }
    return penghitung;
}

void insertTengah(mahasiswa identitas, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "posisi diluar jangakauan";
    }
    else if (posisi == 1)
    {
        cout << "INi bukan posisi tengah\n";
    }
    else
    {
        node *baru = new node;
        baru->ITTP = identitas;
        node *bantu = head;
        int penghitung = 1;
        while (penghitung != posisi - 1)
        {
            penghitung++;
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

void ubahDepan(mahasiswa data)
{
    if (!isEmpty())
    {
        string namaBefore = head->ITTP.nama;
        head->ITTP = data;
        cout << "data " << namaBefore << " telah diganti dengan data " << data.nama << endl;
    }
    else
    {
        cout << "List kosong" << endl;
    }
}

void ubahBelakang(mahasiswa data)
{
    if (!isEmpty())
    {
        string namaBefore = tail->ITTP.nama;
        tail->ITTP = data;
        cout << "data " << namaBefore << " telah diganti dengan data " << data.nama << endl;
    }
    else
    {
        cout << "List kosong" << endl;
    }
}

void ubahTengah(mahasiswa data)
{
    if (!isEmpty())
    {
        int posisi;
        cout << "\nMasukkan posisi data yang akan diubah : ";
        cin >> posisi;

        if (posisi < 1 || posisi > hitungList())
        {
            cout << "\nPosisi diluar jangkauan\n";
        }
        else if (posisi == 1)
        {
            cout << "\nBukan posisi tengah\n";
        }
        else
        {
            node *bantu = head;
            int penghitung = 1;
            while (penghitung != posisi)
            {
                penghitung++;
                bantu = bantu->next;
            }
            bantu->ITTP = data;
        }
    }
    else
    {
        cout << "List kosong" << endl;
    }
}

void tampil()
{
    node *bantu = head;
    cout << "Nama "
         << " Nim\n";
    while (bantu != nullptr)
    {
        cout << bantu->ITTP.nama << " " << bantu->ITTP.nim << endl;
        bantu = bantu->next;
    }
}

void hapusDepan()
{
    if (!isEmpty())
    {
        string dataBefore = head->ITTP.nama;
        node *hapus = head;
        if (head != tail)
        {
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = nullptr;
        }
        cout << "Data " << dataBefore << " berhasil dihapus\n";
    }
    else
    {
        cout << "List kosong" << endl;
    }
}

void hapusBelakang()
{
    if (!isEmpty())
    {
        string dataBefore = tail->ITTP.nama;
        if (head != tail)
        {
            node *hapus = tail;
            node *bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = nullptr;
            delete hapus;
        }
        else
        {
            head = tail = nullptr;
        }
        cout << "Data " << dataBefore << " berhasil dihapus\n";
    }
    else
    {
        cout << "List kosong" << endl;
    }
}

void hapusTengah()
{
    if (!isEmpty())
    {
        tampil();
        cout << endl;
        int posisi;
        cout << "Masukkan Posisi yang dihapus : ";
        cin >> posisi;
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "\nPosisi di luar jangkauan!\n";
        }
        else if (posisi == 1 || posisi == hitungList())
        {
            cout << "\nBukan Posisi tengah\n";
        }
        else
        {
            node *bantu = head;
            int penghitung = 1;
            while (penghitung <= posisi)
            {
                if (penghitung == posisi - 1)
                {
                    before = bantu;
                }
                if (penghitung == posisi)
                {
                    hapus = bantu;
                }
                bantu = bantu->next;
                penghitung++;
            }
            string dataBefore = hapus->ITTP.nama;
            before->next = bantu;
            delete hapus;
            cout << "\nData " << dataBefore << " berhasil dihapus!\n";
        }
    }
    else
    {
        cout << "\n!!! List Data Kosong !!!\n";
    }
}

void hapusList()
{
    node *bantu = head;
    while (bantu != nullptr)
    {
        hapus = bantu;
        delete hapus;
        bantu = bantu->next;
    }
    init();
    cout << "\nsemua data berhasil dihapus\n";
}
