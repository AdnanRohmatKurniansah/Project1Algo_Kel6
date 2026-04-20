// Kelompok 6: 
// 123250063 - Satria Wicaksana 
// 123250078 - Rizqy Prasetyo Landung Nugroho
// 123250085 - Adnan Rohmat Kurniansah

#include <iostream>

using namespace std;

void kembaliMenu();

bool ulang = false;

int main() {
    int opsiMenu;

    do {
		cout << "MENU :" << endl;
        cout << "=========================" << endl;
        cout << "1. INPUT DATA" << endl;
		cout << "2. TAMPIL DATA" << endl;
		cout << "3. SEARCHING" << endl;
		cout << "4. SORTING" << endl;
		cout << "5. EXIT" << endl;
        cout << "=========================" << endl;
		cout << "Pilih : ";
		cin >> opsiMenu;

        switch (opsiMenu) {
            case 1:
                system("cls");

                // code

                kembaliMenu();
                break;
            case 2:
                system("cls");

                // code

                kembaliMenu();
                break;
            case 3:
                system("cls");

                // code

                kembaliMenu();
                break;
            case 4:
                system("cls");

                // code

                kembaliMenu();
                break;
            case 5:
                ulang = false;
				system("cls");
				cout << "\nKeluar dari program...\n" << endl;
				exit(0);
                break;
            default:
				system("cls");
                cout << "Pilihan menu tidak ada..." << endl;
                cout << "==================================" << endl;

                kembaliMenu();
                break;
        }

    } while (ulang == true);
}

void kembaliMenu() {
	char kembali;

    cout << "\nKembali ke Menu Utama(y/t)? ";
	cin >> kembali;
				
    if (kembali == 'y' || kembali == 'Y') {
		ulang = true;
		system("cls");
	} else {
		system("cls");
		cout << "\nKeluar dari program...\n" << endl;
		exit(0);
	}
}