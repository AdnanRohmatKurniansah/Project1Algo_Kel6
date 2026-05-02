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
} Ijazah;

bool ulang = false; // menu utama
bool ulangOpsi = false; // opsi menu disetiap pil. menu (child menu)

void kembaliUtama();
void ulangOpsiMenu();

void tambahData(int *jmlIjazah, Ijazah ijazah[]);
void tampilData(int *jmlIjazah, Ijazah ijazah[]);
void sortingData(int *jmlIjazah, Ijazah ijazah[]);
void searching(int *jmlIjazah, Ijazah ijazah[]);

void dataTabel(Ijazah ijazah[], int jmlIjazah); // untuk melihat data dm format tabel

// searching
int sequentialSearch(Ijazah ijazah[], int size);
int binarySearch(Ijazah ijazah[], int size);

// sorting
void shellSort(Ijazah ijazah[], int size);

void bubblesort(Ijazah ijazah[], int size);

void selectionSort(Ijazah ijazah[], int size);

void insertionSort(Ijazah ijazah[], int size);

int partition(Ijazah ijazah[], int low, int high);
void quickSort(Ijazah ijazah[], int low, int high);

void merge(Ijazah ijazah[], int left, int mid, int right);
void mergeSort(Ijazah ijazah[], int left, int right);

int main() {
    int opsiMenu;

    Ijazah ijazah[10];
    int jmlIjazah = 0;

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

                tambahData(&jmlIjazah, ijazah);

                kembaliUtama();
                break;
            case 2:
                system("cls");

                tampilData(&jmlIjazah, ijazah);
                
                kembaliUtama();
                break;
            case 3:
                system("cls");

                searching(&jmlIjazah, ijazah); 

                break;
            case 4:
                system("cls");

                sortingData(&jmlIjazah, ijazah);

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

void tambahData(int *jmlIjazah, Ijazah ijazah[]) {
    cout << "INPUT DATA" << endl;
    cout << "==================================" << endl;
    cout << "Jumlah data (max 10): ";
    cin >> *jmlIjazah;

    if (*jmlIjazah > 10) {
        system("cls");

        cout << "Jumlah data lebih dari 10!" << endl;
        cout << "==================================" << endl;
    } else {
        cout << "\n";
        for (int i = 0; i < *jmlIjazah; i++) {
            cout << "Data ke-" << i + 1 << endl;
            cout << "  " << left << setw(15) << "No Ijasah" << ": ";
            cin >> ijazah[i].NoIjasah;
            cin.ignore();

            cout << "  " << left << setw(15) << "Jenis Ijasah" << ": ";
            getline(cin, ijazah[i].JenisIjasah);

            cout << "  " << left << setw(15) << "Nama" << ": ";
            getline(cin, ijazah[i].Nama);
        }
        cout << "==================================" << endl;
    }
}

void tampilData(int *jmlIjazah, Ijazah ijazah[]) {
    cout << "TAMPIL DATA" << endl;
    if (*jmlIjazah < 1) {
        cout << "Data belum diinput" << endl;
        cout << "==========================================" << endl;
    } else {
        dataTabel(ijazah, *jmlIjazah);
    }
}

void sortingData(int *jmlIjazah, Ijazah ijazah[]) {
    ulangOpsi = false;
    
    int opsiSorting;
    Ijazah tempIjazah[10]; // data hanya untuk menampilkan hasil sorting tanpa mengubah data asli

    if (*jmlIjazah < 1) {
        cout << "MENU SORTING" << endl;
        cout << "==================================" << endl;
        cout << "Data belum diinput" << endl;
        cout << "==================================" << endl;

        kembaliUtama();
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
                    dataTabel(ijazah, *jmlIjazah);

                    for (int i = 0; i < *jmlIjazah; i++) {
                        tempIjazah[i] = ijazah[i];
                    }
                    bubblesort(tempIjazah, *jmlIjazah);
                    cout << "\nData urut by No Ijasah dengan BUBBLE SORT" << endl;
                    dataTabel(tempIjazah, *jmlIjazah);

                    ulangOpsiMenu();
                    break;
                case 2:
                    cout << "\nData Sebelum disorting : " << endl;
                    dataTabel(ijazah, *jmlIjazah);
 
                    for (int i = 0; i < *jmlIjazah; i++) tempIjazah[i] = ijazah[i];
                    selectionSort(tempIjazah, *jmlIjazah);
 
                    cout << "\nData urut by Jenis Ijasah dengan SELECTION SORT (Asc)" << endl;
                    dataTabel(tempIjazah, *jmlIjazah);
 
                    ulangOpsiMenu();
                    break;
                case 3:
                    cout << "\nData Sebelum disorting : " << endl;
                    dataTabel(ijazah, *jmlIjazah);

                    for (int i = 0; i < *jmlIjazah; i++) {
                        tempIjazah[i] = ijazah[i];
                    }
                    insertionSort(tempIjazah, *jmlIjazah);

                    cout << "\nData urut by Nama dengan INSERTION SORT" << endl;
                    dataTabel(tempIjazah, *jmlIjazah);


                    ulangOpsiMenu();
                    break;
                case 4:
                    cout << "\nData Sebelum disorting : " << endl;
                    dataTabel(ijazah, *jmlIjazah);

                    for (int i = 0; i < *jmlIjazah; i++) {
                        tempIjazah[i] = ijazah[i];
                    }
                    shellSort(tempIjazah, *jmlIjazah);

                    cout << "\nData urut by No Ijasah dengan SHELL SORT" << endl;
                    dataTabel(tempIjazah, *jmlIjazah);

                    ulangOpsiMenu();
                    break;
                case 5:
                    cout << "\nData Sebelum disorting : " << endl;
                    dataTabel(ijazah, *jmlIjazah);

                    for (int i = 0; i < *jmlIjazah; i++) {
                        tempIjazah[i] = ijazah[i];
                    }
                    quickSort(tempIjazah, 0, *jmlIjazah - 1);

                    cout << "\nData urut by Jenis Ijasah dengan QUICK SORT" << endl;
                    dataTabel(tempIjazah, *jmlIjazah);

                    ulangOpsiMenu();
                    break;
                case 6:
                    cout << "\nData Sebelum disorting : " << endl;
                    dataTabel(ijazah, *jmlIjazah);

                    for (int i = 0; i < *jmlIjazah; i++) {
                        tempIjazah[i] = ijazah[i];
                    }
                    
                    mergeSort(tempIjazah, 0, *jmlIjazah - 1);
                    cout << "\nData urut by Nama dengan MERGE SORT" << endl;
                    dataTabel(tempIjazah, *jmlIjazah);

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
void dataTabel(Ijazah ijazah[], int jmlIjazah) {
    cout << "==========================================" << endl;
    cout << left << setw(15) << "  No Ijasah"
                 << setw(20) << "  Jenis Ijasah"
                 << setw(15) << "  Nama" << endl;
    cout << "==========================================" << endl;
    for (int i = 0; i < jmlIjazah; i++) {
        cout << left << setw(15) << ("  " + to_string(ijazah[i].NoIjasah))
                     << setw(20) << ("  " + ijazah[i].JenisIjasah)
                     << setw(15) << ("  " + ijazah[i].Nama) << endl;
    }
    cout << "==========================================" << endl;
}


// shell sort
void shellSort(Ijazah ijazah[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            Ijazah temp = ijazah[i];
            int j = i;
            while (j >= gap && ijazah[j - gap].NoIjasah > temp.NoIjasah) {
                ijazah[j] = ijazah[j - gap];
                j -= gap;
            }
            ijazah[j] = temp;
        }
    }
}
// bubblesort
void bubblesort(Ijazah ijazah[], int size){
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (ijazah[j].NoIjasah > ijazah[j+1].NoIjasah)
            {
                swap(ijazah[j], ijazah[j+1]);
            }
        }
    }
}

int partition(Ijazah ijazah[], int low, int high) {
    Ijazah pivot = ijazah[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (ijazah[j].JenisIjasah < pivot.JenisIjasah) {
            i++;
            swap(ijazah[i], ijazah[j]);
        }
    }
    swap(ijazah[i + 1], ijazah[high]);
    return (i + 1);
}

// quick sort
void quickSort(Ijazah ijazah[], int low, int high) {
    if (low < high) {
        int pi = partition(ijazah, low, high);
        quickSort(ijazah, low, pi - 1);
        quickSort(ijazah, pi + 1, high);
    }
}

void merge(Ijazah ijazah[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;

    Ijazah temp[10];

    while (i <= mid && j <= right) {
        if (ijazah[i].Nama <= ijazah[j].Nama) {
            temp[k] = ijazah[i];
            i++;
        } else {
            temp[k] = ijazah[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = ijazah[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = ijazah[j];
        j++;
        k++;
    }

    for (int x = 0; x < k; x++) {
        ijazah[left + x] = temp[x];
    }
}

// merge sort
void mergeSort(Ijazah ijazah[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(ijazah, left, mid);
        mergeSort(ijazah, mid + 1, right);

        merge(ijazah, left, mid, right);
    }
}

// selection sort
void selectionSort(Ijazah ijazah[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (ijazah[j].JenisIjasah < ijazah[minIdx].JenisIjasah) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(ijazah[i], ijazah[minIdx]);
        }
    }
}

// insertion sort
void insertionSort(Ijazah ijazah[], int size){
    for(int i = 1; i < size; i++){
        Ijazah key = ijazah[i];
        int j = i - 1;

        while (j >= 0 && ijazah[j].Nama > key.Nama){
            ijazah[j+1] = ijazah[j];
            j--;
        }
        ijazah[j+1] = key;
    }
}

void searching(int *jmlIjazah, Ijazah ijazah[]){
    ulangOpsi = false;
    
    int opsiSearching;
    Ijazah tempIjazah[10]; // hanya utk tampil hasil searching tanpa mengubah data asli (only binary search)

    if (*jmlIjazah < 1) {
        cout << "MENU SEARCHING" << endl;
        cout << "==================================" << endl;
        cout << "Data belum diinput" << endl;
        cout << "==================================" << endl;

        kembaliUtama();
    } else {
        do {
            cout << "MENU SEARCHING" << endl;
            cout << "==================================" << endl;
            cout << "1. SEQUENTIAL SEARCH" << endl;
            cout << "2. BINARY SEARCH" << endl;
            cout << "3. Kembali ke MENU UTAMA" << endl;
            cout << "==================================" << endl;
            cout << "Pilih : ";
            cin >> opsiSearching;
            switch (opsiSearching) {
                case 1: {
                    int hasil = sequentialSearch(ijazah, *jmlIjazah);
                    if (hasil != -1) {
                        cout << "\nData ditemukan!\n";
                        cout << "No Ijasah   : " << ijazah[hasil].NoIjasah << endl;
                        cout << "Jenis Ijasah: " << ijazah[hasil].JenisIjasah << endl;
                        cout << "Nama        : " << ijazah[hasil].Nama << endl;
                    } else {
                        cout << "\nNomor Ijazah tidak ditemukan!\n";
                    }
                    ulangOpsiMenu();
                    break;
                }
                case 2: {
                    for (int i = 0; i < *jmlIjazah; i++) {
                        tempIjazah[i] = ijazah[i];
                    }
                    shellSort(tempIjazah, *jmlIjazah); 
    
                    int hasil = binarySearch(tempIjazah, *jmlIjazah);
                    if (hasil != -1) {
                        cout << "\nData ditemukan!\n";
                        cout << "No Ijasah   : " << tempIjazah[hasil].NoIjasah << endl;
                        cout << "Jenis Ijasah: " << tempIjazah[hasil].JenisIjasah << endl;
                        cout << "Nama        : " << tempIjazah[hasil].Nama << endl;
                    } else {
                        cout << "\nNomor Ijazah tidak ditemukan!\n";
                    }
                    ulangOpsiMenu();
                    break;
                }
                case 3:
                    ulangOpsi = false;
                    kembaliUtama();
                    break;
                default:
                    system("cls");
                    cout << "Pilihan di menu searching tidak ada..." << endl;
                    cout << "==================================" << endl;

                    ulangOpsiMenu();
                    break;
                }
        } while(ulangOpsi == true);
    }
}

int sequentialSearch(Ijazah ijazah[], int size){
    int dicari;
    system("cls");
    cout << "SEQUENTIAL SEARCH" << endl;
    cout << "================================================" << endl;
    cout << "Nomor Ijazah yang dicari : ";
    cin >> dicari;

    for(int i = 0; i < size; i++){
        if(ijazah[i].NoIjasah == dicari){
            return i;
        }
    }

    return -1;
}

int binarySearch(Ijazah ijazah[], int size) {
    int dicari;
    system("cls");
    cout << "BINARY SEARCH" << endl;
    cout << "================================================" << endl;
    cout << "Nomor Ijazah yang dicari : ";
    cin >> dicari;
 
    int low = 0, high = size - 1;
 
    while (low <= high) {
        int mid = (low + high) / 2;
 
        if (ijazah[mid].NoIjasah == dicari) {
            return mid;
        } else if (ijazah[mid].NoIjasah < dicari) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}