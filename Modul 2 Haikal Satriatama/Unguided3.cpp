#include <iostream>
using namespace std;

int main() {

    int arr[100];
    int n;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    cout << "Masukkan elemen-elemen array:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Elemen ke-" << i+1 << ": ";
        cin >> arr[i];
    }

    char choice;
    cout << "\nPilih operasi:\n";
    cout << "1. Mencari nilai maksimum\n";
    cout << "2. Mencari nilai minimum\n";
    cout << "3. Mencari nilai rata-rata\n";
    cout << "Pilihan Anda (1/2/3): ";
    cin >> choice;

    switch (choice) {
        case '1': {
            int max = arr[0];
            for (int i = 1; i < n; ++i) {
                if (arr[i] > max) {
                    max = arr[i];
                }
            }
            cout << "Nilai maksimum: " << max << endl;
            break;
        }
        case '2': {
            int min = arr[0];
            for (int i = 1; i < n; ++i) {
                if (arr[i] < min) {
                    min = arr[i];
                }
            }
            cout << "Nilai minimum: " << min << endl;
            break;
        }
        case '3': {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += arr[i];
            }
            double average = static_cast<double>(sum) / n;
            cout << "Nilai rata-rata: " << average << endl;
            break;
        }
        default:
            cout << "Pilihan tidak valid!\n";
    }

    return 0;
}
