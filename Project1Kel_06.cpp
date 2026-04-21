// Kelompok 6: 
// 123250063 - Satria Wicaksana 
// 123250078 - Rizqy Prasetyo Landung Nugroho
// 123250085 - Adnan Rohmat Kurniansah

#include <iostream>
#include <iomanip>

using namespace std;

typedef struct {
    int NoIjasah;
    string JenisIjasah;
    string Nama;
} Mahasiswa;

bool ulang = false; // menu utama
bool ulangOpsi = false; // opsi menu disetiap pil. menu (child menu)

void kembaliUtama();
void ulangOpsiMenu();

void tambahData(int *jmlMhs, Mahasiswa mhs[]);
void sortingData(int *jmlMhs, Mahasiswa mhs[]);

void dataTabel(Mahasiswa mhs[], int jmlMhs);
void shellSort(Mahasiswa mhs[], int size);

void bubblesort(Mahasiswa mas[], int size);
int partition(Mahasiswa mhs[], int low, int high);
void quickSort(Mahasiswa mhs[], int low, int high);
void merge(Mahasiswa mhs[], int left, int mid, int right);
void mergeSort(Mahasiswa mhs[], int left, int right); 

int main() {
    int opsiMenu;

    Mahasiswa mhs[10];
    int jmlMhs = 0;

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

        cin.ignore();

        switch (opsiMenu) {
            case 1:
                system("cls");

                tambahData(&jmlMhs, mhs);

                kembaliUtama();
                break;
            case 2:
                system("cls");

                // code 
                
                kembaliUtama();
                break;
            case 3:
                system("cls");

                // code 

                break;
            case 4:
                system("cls");

                sortingData(&jmlMhs, mhs);

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

                kembaliUtama();
                break;
        }

    } while (ulang == true);
}

void kembaliUtama() {
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

void ulangOpsiMenu() {
    char kembaliOpsi;

	cout << "\nUlangi (y/t)? ";
    cin >> kembaliOpsi;
                            
    if (kembaliOpsi == 'y' || kembaliOpsi == 'Y') {
        ulangOpsi = true;
        system("cls");
    } else {
        ulangOpsi = false;
        kembaliUtama();
    }
}

void tambahData(int *jmlMhs, Mahasiswa mhs[]) {
    cout << "INPUT DATA" << endl;
    cout << "==================================" << endl;
    cout << "Jumlah data (max 10): ";
    cin >> *jmlMhs;

    if (*jmlMhs > 10) {
        system("cls");

        cout << "Jumlah data lebih dari 10!" << endl;
        cout << "==================================" << endl;
    } else {
        cout << "\n";
        for (int i = 0; i < *jmlMhs; i++) {
            cout << "Data ke-" << i + 1 << endl;
            cout << "  " << left << setw(15) << "No Ijasah" << ": ";
            cin >> mhs[i].NoIjasah;
            cin.ignore();

            cout << "  " << left << setw(15) << "Jenis Ijasah" << ": ";
            getline(cin, mhs[i].JenisIjasah);

            cout << "  " << left << setw(15) << "Nama" << ": ";
            getline(cin, mhs[i].Nama);
        }
        cout << "==================================" << endl;
    }
}

void sortingData(int *jmlMhs, Mahasiswa mhs[]) {
    ulangOpsi = false;
    
    int opsiSorting;
    Mahasiswa tempMhs[10]; // data hanya untuk menampilkan hasil sorting tanpa mengubah data asli

    if (*jmlMhs < 1) {
        cout << "MENU SORTING" << endl;
        cout << "==================================" << endl;
        cout << "Data belum diinput" << endl;
        cout << "==================================" << endl;
    } else {
        do {
            cout << "MENU SORTING" << endl;
            cout << "==================================" << endl;
            cout << "1. BUBBLE SORT" << endl;
            cout << "2. SELECTION SORT" << endl;
            cout << "3. INSERTION SORT" << endl;
            cout << "4. SHELL SORT" << endl;
            cout << "5. QUICK SORT" << endl;
            cout << "6. MERGE SORT" << endl;
            cout << "7. Kembali ke MENU UTAMA" << endl;
            cout << "==================================" << endl;
            cout << "Pilih : ";
            cin >> opsiSorting;

            switch (opsiSorting) {
                case 1:
                    cout << "\nData Sebelum disorting : " << endl;
                    dataTabel(mhs, *jmlMhs);

                    for (int i = 0; i < *jmlMhs; i++) {
                        tempMhs[i] = mhs[i];
                    }
                    bubblesort(tempMhs, *jmlMhs);
                    cout << "\nData urut by No Ijasah dengan BUBBLE SORT" << endl;
                    dataTabel(tempMhs, *jmlMhs);

                    ulangOpsiMenu();
                    break;
                case 2:
                    // code

                    ulangOpsiMenu();
                    break;
                case 3:
                    // code

                    ulangOpsiMenu();
                    break;
                case 4:
                    cout << "\nData Sebelum disorting : " << endl;
                    dataTabel(mhs, *jmlMhs);

                    for (int i = 0; i < *jmlMhs; i++) {
                        tempMhs[i] = mhs[i];
                    }
                    shellSort(tempMhs, *jmlMhs);

                    cout << "\nData urut by No Ijasah dengan SHELL SORT" << endl;
                    dataTabel(tempMhs, *jmlMhs);

                    ulangOpsiMenu();
                    break;
                case 5:
                    cout << "\nData Sebelum disorting : " << endl;
                    dataTabel(mhs, *jmlMhs);

                    for (int i = 0; i < *jmlMhs; i++) {
                        tempMhs[i] = mhs[i];
                    }
                    quickSort(tempMhs, 0, *jmlMhs - 1);

                    cout << "\nData urut by Jenis Ijasah dengan QUICK SORT" << endl;
                    dataTabel(tempMhs, *jmlMhs);

                    ulangOpsiMenu();
                    break;
                case 6:
                    cout << "\nData Sebelum disorting : " << endl;
                    dataTabel(mhs, *jmlMhs);

                    for (int i = 0; i < *jmlMhs; i++) {
                        tempMhs[i] = mhs[i];
                    }
                    
                    mergeSort(tempMhs, 0, *jmlMhs - 1);
                    cout << "\nData urut by Jenis Ijasah dengan QUICK SORT" << endl;
                    dataTabel(tempMhs, *jmlMhs);

                    ulangOpsiMenu();
                    break;
                case 7:
                    ulangOpsi = false;
                    kembaliUtama();
                    break;
                default:
                    system("cls");
                    cout << "Pilihan di menu sorting tidak ada..." << endl;
                    cout << "==================================" << endl;

                    ulangOpsiMenu();
                    break;  
            }
        } while (ulangOpsi == true);
    }
}

// tampil data dalam bentuk tabel
void dataTabel(Mahasiswa mhs[], int jmlMhs) {
    cout << "==========================================" << endl;
    cout << left << setw(15) << "  No Ijasah"
                 << setw(20) << "  Jenis Ijasah"
                 << setw(15) << "  Nama" << endl;
    cout << "==========================================" << endl;
    for (int i = 0; i < jmlMhs; i++) {
        cout << left << setw(15) << ("  " + to_string(mhs[i].NoIjasah))
                     << setw(20) << ("  " + mhs[i].JenisIjasah)
                     << setw(15) << ("  " + mhs[i].Nama) << endl;
    }
    cout << "==========================================" << endl;
}


// shell sort
void shellSort(Mahasiswa mhs[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            Mahasiswa temp = mhs[i];
            int j = i;
            while (j >= gap && mhs[j - gap].NoIjasah > temp.NoIjasah) {
                mhs[j] = mhs[j - gap];
                j -= gap;
            }
            mhs[j] = temp;
        }
    }
}
// bubblesort
void bubblesort(Mahasiswa mas[], int size){
    int temp = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i+1; j < size - 1 ; j++)
        {
            if (mas[j].NoIjasah > mas[j+1].NoIjasah)
            {
                temp = mas[j].NoIjasah;
                mas[j].NoIjasah = mas[j+1].NoIjasah;
                mas[j+1].NoIjasah = temp;
            }
            
        }
        
    }
    

}

// quick sort
int partition(Mahasiswa mhs[], int low, int high) {
    Mahasiswa pivot = mhs[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (mhs[j].JenisIjasah < pivot.JenisIjasah) {
            i++;
            swap(mhs[i], mhs[j]);
        }
    }
    swap(mhs[i + 1], mhs[high]);
    return (i + 1);
}

void quickSort(Mahasiswa mhs[], int low, int high) {
    if (low < high) {
        int pi = partition(mhs, low, high);
        quickSort(mhs, low, pi - 1);
        quickSort(mhs, pi + 1, high);
    }
}

void merge(Mahasiswa mhs[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;

    Mahasiswa temp[10];

    while (i <= mid && j <= right) {
        if (mhs[i].Nama <= mhs[j].Nama) {
            temp[k] = mhs[i];
            i++;
        } else {
            temp[k] = mhs[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = mhs[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = mhs[j];
        j++;
        k++;
    }

    for (int x = 0; x < k; x++) {
        mhs[left + x] = temp[x];
    }
}

void mergeSort(Mahasiswa mhs[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(mhs, left, mid);
        mergeSort(mhs, mid + 1, right);

        merge(mhs, left, mid, right);
    }
}