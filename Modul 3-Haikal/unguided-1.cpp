#include <iostream>
using namespace std;

struct Node {
    string nama;
    int umur;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to insert data at the beginning of the list
    void insertDepan(string nama, int umur) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->umur = umur;
        newNode->next = head;
        head = newNode;
    }

    // Function to insert data at the end of the list
    void insertBelakang(string nama, int umur) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->umur = umur;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to insert data after a specific node
    void insertTengah(string nama, int umur, string keyNama) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != keyNama) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Nama " << keyNama << " tidak ditemukan.\n";
            return;
        }

        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->umur = umur;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete a node with given nama
    void deleteNode(string nama) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->nama == nama) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->nama != nama) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Data dengan nama " << nama << " tidak ditemukan.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    // Function to display all data in the list
    void display() {
        Node* temp = head;
        cout << "Nama\tumur\n";
        while (temp != nullptr) {
            cout << temp->nama << "\t" << temp->umur << endl;
            temp = temp->next;
        }
    }
};

int main() {

    
    LinkedList list;
    list.insertDepan("Haikal", 19);
    list.insertBelakang("John", 19);
    list.insertBelakang("Jane", 20);
    list.insertBelakang("Michael", 18);
    list.insertBelakang("Yusuke", 19);
    list.insertBelakang("Akechi", 20);
    list.insertBelakang("Hoshino", 18);
    list.insertBelakang("Karin", 18);

    cout << "Data awal:\n";
    list.display();

    cout << "\nHapus data Akechi:\n";
    list.deleteNode("Akechi");
    list.display();

    cout << "\nTambahkan data Futaba setelah John:\n";
    list.insertTengah("Futaba", 18, "John");
    list.display();

    cout << "\nTambahkan data Igor di awal:\n";
    list.insertDepan("Igor", 20);
    list.display();

    cout << "\nUbah data Michael menjadi Reyn:\n";
    list.deleteNode("Michael");
    list.insertBelakang("Reyn", 18);
    list.display();

    return 0;
}
