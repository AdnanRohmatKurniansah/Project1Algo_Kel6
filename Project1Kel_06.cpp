// Kelompok 6: 
// 123250063 - Satria Wicaksana 
// 123250078 - Rizqy Prasetyo Landung Nugroho
// 123250085 - Adnan Rohmat Kurniansah

#include <iostream>
#include <iomanip>
#include <fstream>

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

void tampilDaftarFile();
bool cekFileTerdaftar(string namaFile);
void simpanDaftarFile(string namaFile);

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

int bacaFile(Ijazah ijazah[], string namaFile);
void fileOperation(int *jmlIjazah, Ijazah ijazah[]);
void splittingFile(int *jmlIjazah, Ijazah ijazah[]);

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
		cout << "5. OPERASI FILE" << endl;
		cout << "6. EXIT" << endl;
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
                system("cls");
                fileOperation(&jmlIjazah, ijazah);
                break;
            case 6:
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

void tampilDaftarFile() {
    ifstream fileList("daftar_file.txt");
    string namaFile;
    bool ada = false;

    cout << "Daftar FILE :" << endl;
    cout << "===============" << endl;

    while (getline(fileList, namaFile)) {
        cout << namaFile << endl;
        ada = true;
    }

    if (!ada) {
        cout << "Belum ada file yang disimpan" << endl;
    }

    cout << endl;

    fileList.close();
}

bool cekFileTerdaftar(string namaFile) {
    ifstream fileList("daftar_file.txt");
    string file;

    while (getline(fileList, file)) {
        if (file == namaFile) {
            fileList.close();
            return true;
        }
    }

    fileList.close();
    return false;
}

void simpanDaftarFile(string namaFile) {
    ofstream fileWrite("daftar_file.txt");

    fileWrite << namaFile << endl;

    fileWrite.close();
}

void tambahData(int *jmlIjazah, Ijazah ijazah[]) {
    string namaFile;
    int modeFile = 0;

    tampilDaftarFile();

    cout << "INPUT DATA" << endl;
    cout << "==================================" << endl;

    cout << "Jumlah data (max 10): ";
    cin >> *jmlIjazah;
    cin.ignore();

    if (*jmlIjazah > 10) {
        cout << "Jumlah data lebih dari 10!" << endl;
        cout << "==================================" << endl;
        return;
    }

    cout << "Disimpan di file : ";
    getline(cin, namaFile);

    cout << endl;

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

    ifstream cekFile(namaFile);

    if (cekFile) {
        cout << "File sudah ada, overwriting(0) atau append(1)? ";
        cin >> modeFile;
    }

    cekFile.close();

    ofstream file;

    if (modeFile == 0) {
        file.open(namaFile);
    } else {
        file.open(namaFile, ios::app);
    }

    if (!file) {
        cout << "File gagal dibuat!" << endl;
        return;
    }

    if (!cekFileTerdaftar(namaFile)) {
        ofstream daftar("daftar_file.txt", ios::app);
        daftar << namaFile << endl;
        daftar.close();
    }

    for (int i = 0; i < *jmlIjazah; i++) {
        file << "Data ke-" << i + 1 << endl;
        file << "No Ijasah    : " << ijazah[i].NoIjasah << endl;
        file << "Jenis Ijasah : " << ijazah[i].JenisIjasah << endl;
        file << "Nama         : " << ijazah[i].Nama << endl;
        file << "==================================" << endl;
    }

    file.close();

    cout << endl;
    cout << "==================================" << endl;
}

int bacaFile(Ijazah ijazah[], string namaFile) {
    ifstream file(namaFile);
    string dummy;
    int index = 0;

    if (!file) return 0;

    while (getline(file, dummy)) {
        if (dummy.find("Data ke-") != string::npos) {

            file.ignore(1000, ':');
            file >> ijazah[index].NoIjasah;
            file.ignore();

            file.ignore(1000, ':');
            getline(file, ijazah[index].JenisIjasah);

            if (ijazah[index].JenisIjasah[0] == ' ')
                ijazah[index].JenisIjasah.erase(0, 1);

            file.ignore(1000, ':');
            getline(file, ijazah[index].Nama);

            if (ijazah[index].Nama[0] == ' ')
                ijazah[index].Nama.erase(0, 1);

            getline(file, dummy);
            index++;
        }
    }

    file.close();
    return index;
}

void tampilData(int *jmlIjazah, Ijazah ijazah[]) {
    string namaFile;

    cout << "TAMPIL DATA" << endl;
    cout << "==================================" << endl << endl;

    tampilDaftarFile();

    cout << "Nama file yang akan ditampilkan : ";
    getline(cin, namaFile);

    *jmlIjazah = bacaFile(ijazah, namaFile);

    if (*jmlIjazah == 0) {
        cout << "\nFile tidak ditemukan atau kosong!" << endl;
        cout << "==================================" << endl;
        return;
    }

    cout << endl;
    dataTabel(ijazah, *jmlIjazah);
}

void sortingData(int *jmlIjazah, Ijazah ijazah[]) {
    ulangOpsi = false;
    Ijazah tempIjazah[10];

    int opsiSorting;
    string judulSort;
    string namaFile;
    char simpan;
    string namaFileSimpan;
    char ulangiSort;

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
        cin.ignore();

        if (opsiSorting == 7) {
            ulangOpsi = false;
            kembaliUtama();
            break;
        }

        if (opsiSorting < 1 || opsiSorting > 6) {
            system("cls");
            cout << "Pilihan di menu sorting tidak ada..." << endl;
            cout << "==================================" << endl;
            cout << endl;
            ulangOpsi = true;
            continue;
        }

        cout << endl;
        tampilDaftarFile();
        cout << "Data yang akan disorting dari file : ";
        getline(cin, namaFile);

        *jmlIjazah = bacaFile(ijazah, namaFile);
        if (*jmlIjazah == 0) {
            system("cls");
            cout << "\nFile tidak ditemukan atau kosong!" << endl;
            cout << "==================================" << endl;
            cout << endl;
            ulangOpsi = true;
            continue;
        }

        for (int i = 0; i < *jmlIjazah; i++) {
            tempIjazah[i] = ijazah[i];
        }
        
        cout << "\nData Sebelum disorting :" << endl;
        dataTabel(ijazah, *jmlIjazah);

        switch (opsiSorting) {
            case 1:
                bubblesort(tempIjazah, *jmlIjazah);
                judulSort = "Data urut by No Ijasah dengan BUBBLE SORT";
                break;
            case 2:
                selectionSort(tempIjazah, *jmlIjazah);
                judulSort = "Data urut by Jenis Ijasah dengan SELECTION SORT (Asc)";
                break;
            case 3:
                insertionSort(tempIjazah, *jmlIjazah);
                judulSort = "Data urut by Nama dengan INSERTION SORT";
                break;
            case 4:
                shellSort(tempIjazah, *jmlIjazah);
                judulSort = "Data urut by No Ijasah dengan SHELL SORT";
                break;
            case 5:
                quickSort(tempIjazah, 0, *jmlIjazah - 1);
                judulSort = "Data urut by Jenis Ijasah dengan QUICK SORT";
                break;
            case 6:
                mergeSort(tempIjazah, 0, *jmlIjazah - 1);
                judulSort = "Data urut by Nama dengan MERGE SORT";
                break;
        }

        cout << "\n" << judulSort << endl;
        dataTabel(tempIjazah, *jmlIjazah);

        cout << "\nIngin disimpan hasil sorting ke file (y/t)? ";
        cin >> simpan;
        cin.ignore();

        if (simpan == 'y' || simpan == 'Y') {
            cout << "Nama file : ";
            getline(cin, namaFileSimpan);

            ofstream fileSimpan(namaFileSimpan);
            if (!fileSimpan) {
                cout << "\nFile gagal dibuat!" << endl;
            } else {
                for (int i = 0; i < *jmlIjazah; i++) {
                    fileSimpan << "Data ke-" << i + 1 << endl;
                    fileSimpan << "No Ijasah    : " << tempIjazah[i].NoIjasah << endl;
                    fileSimpan << "Jenis Ijasah : " << tempIjazah[i].JenisIjasah << endl;
                    fileSimpan << "Nama         : " << tempIjazah[i].Nama << endl;
                    fileSimpan << "==================================" << endl;
                }
                fileSimpan.close();

                if (!cekFileTerdaftar(namaFileSimpan)) {
                    ofstream daftar("daftar_file.txt", ios::app);
                    daftar << namaFileSimpan << endl;
                    daftar.close();
                }

                cout << "\nBerhasil disimpan" << endl;
            }
        }

        cout << "\nUlangi proses Sorting(y/t) : ";
        cin >> ulangiSort;
        cin.ignore();

        if (ulangiSort == 'y' || ulangiSort == 'Y') {
            ulangOpsi = true;
            system("cls");
        } else {
            ulangOpsi = false;
            kembaliUtama();
        }

    } while (ulangOpsi == true);
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
    Ijazah tempIjazah[10];

    do {
        cout << "MENU SEARCHING" << endl;
        cout << "==================================" << endl;
        cout << "1. SEQUENTIAL SEARCH" << endl;
        cout << "2. BINARY SEARCH" << endl;
        cout << "3. Kembali ke MENU UTAMA" << endl;
        cout << "==================================" << endl;
        cout << "Pilih : ";
        cin >> opsiSearching;
        cin.ignore();

        switch (opsiSearching) {
            case 1: {
                cout << endl;
                string namaFile;

                tampilDaftarFile();

                cout << "Data yang akan dicari dari file : ";
                getline(cin, namaFile);

                *jmlIjazah = bacaFile(ijazah, namaFile);
                if (*jmlIjazah == 0) {
                    cout << "\nFile tidak ditemukan atau kosong!" << endl;
                    ulangOpsiMenu();
                    break;
                }

                int hasil = sequentialSearch(ijazah, *jmlIjazah);
                if (hasil != -1) {
                    cout << "\nData ditemukan" << endl;
                    cout << "==========================" << endl;
                    cout << "No Ijasah    : " << ijazah[hasil].NoIjasah << endl;
                    cout << "Jenis Ijasah : " << ijazah[hasil].JenisIjasah << endl;
                    cout << "Nama         : " << ijazah[hasil].Nama << endl;
                    cout << "==========================" << endl;
                } else {
                    cout << "\nNomor Ijazah tidak ditemukan!" << endl;
                }
                ulangOpsiMenu();
                break;
            }
            case 2: {
                cout << endl;
                string namaFile;

                tampilDaftarFile();

                cout << "Data yang akan dicari dari file : ";
                getline(cin, namaFile);

                *jmlIjazah = bacaFile(ijazah, namaFile);
                if (*jmlIjazah == 0) {
                    cout << "\nFile tidak ditemukan atau kosong!" << endl;
                    ulangOpsiMenu();
                    break;
                }

                for (int i = 0; i < *jmlIjazah; i++) {
                    tempIjazah[i] = ijazah[i];
                }
                shellSort(tempIjazah, *jmlIjazah);

                int hasil = binarySearch(tempIjazah, *jmlIjazah);
                if (hasil != -1) {
                    cout << "\nData ditemukan" << endl;
                    cout << "==========================" << endl;
                    cout << "No Ijasah    : " << tempIjazah[hasil].NoIjasah << endl;
                    cout << "Jenis Ijasah : " << tempIjazah[hasil].JenisIjasah << endl;
                    cout << "Nama         : " << tempIjazah[hasil].Nama << endl;
                    cout << "==========================" << endl;
                } else {
                    cout << "\nNomor Ijazah tidak ditemukan!" << endl;
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

int sequentialSearch(Ijazah ijazah[], int size){
    int dicari;
    cout << "\nSEQUENTIAL SEARCH" << endl;
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
    cout << "\nBINARY SEARCH" << endl;
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

void fileOperation(int *jmlIjazah, Ijazah ijazah[]) {
    ulangOpsi = false;
    int opsiFile;

    do {
        cout << "MENU OPERASI FILE" << endl;
        cout << "==================================" << endl;
        cout << "1. MERGING SAMBUNG" << endl;
        cout << "2. MERGING URUT" << endl;
        cout << "3. SPLITTING" << endl;
        cout << "4. UPDATING DATA" << endl;
        cout << "5. HAPUS DATA" << endl;
        cout << "6. Kembali ke MENU UTAMA" << endl;
        cout << "==================================" << endl;
        cout << "Pilih : ";
        cin >> opsiFile;
        cin.ignore();

        switch (opsiFile) {
            case 3: {
                splittingFile(jmlIjazah, ijazah);
                break;
            }
            case 6:
                ulangOpsi = false;
                kembaliUtama();
                break;
            default:
                system("cls");
                cout << "Pilihan di menu operasi file tidak ada..." << endl;
                cout << "==================================" << endl;
                ulangOpsiMenu();
                break;
        }
    } while(ulangOpsi == true);
}

void splittingFile(int *jmlIjazah, Ijazah ijazah[]) {
    string namaFile;
    string namaFileSplit[3];
    int batasBawah[3], batasAtas[3];
    int jmlFile;

    cout << endl;
    tampilDaftarFile();

    cout << "SPLITTING FILE" << endl;
    cout << "----------------" << endl;
    cout << "Nama File yang mau di splitting : ";
    getline(cin, namaFile);

    *jmlIjazah = bacaFile(ijazah, namaFile);
    if (*jmlIjazah == 0) {
        cout << "\nFile tidak ditemukan atau kosong!" << endl;
        ulangOpsiMenu();
        return;
    }

    cout << endl;
    dataTabel(ijazah, *jmlIjazah);

    cout << "\nBanyaknya file hasil splitting (file berstruktur sama, max 3 file) : ";
    cin >> jmlFile;
    cin.ignore();

    if (jmlFile < 1 || jmlFile > 3) {
        cout << "\nJumlah file tidak valid (max 3)!" << endl;
        ulangOpsiMenu();
        return;
    }

    for (int i = 0; i < jmlFile; i++) {
        cout << "Nama File " << i + 1 << " : ";
        getline(cin, namaFileSplit[i]);
        cout << "Batas bawah No Ijasah : ";
        cin >> batasBawah[i];
        cout << "Batas atas No Ijasah  : ";
        cin >> batasAtas[i];
        cin.ignore();
    }

    cout << "\nHasil SPLITTING FILE :" << endl;

    for (int i = 0; i < jmlFile; i++) {
        cout << "Nama File " << i + 1 << " : " << namaFileSplit[i] << endl;

        ofstream fileSplit(namaFileSplit[i]);
        int jumlahData = 0;

        for (int j = 0; j < *jmlIjazah; j++) {
            if (ijazah[j].NoIjasah >= batasBawah[i] && ijazah[j].NoIjasah <= batasAtas[i]) {
                fileSplit << "Data ke-" << jumlahData + 1 << endl;
                fileSplit << "No Ijasah    : " << ijazah[j].NoIjasah << endl;
                fileSplit << "Jenis Ijasah : " << ijazah[j].JenisIjasah << endl;
                fileSplit << "Nama         : " << ijazah[j].Nama << endl;
                fileSplit << "==================================" << endl;
                jumlahData++;
            }
        }

        fileSplit.close();

        if (jumlahData == 0) {
            cout << "\nFile kosong!" << endl;
        } else {
            Ijazah hasilSplit[10];
            int jmlHasil = bacaFile(hasilSplit, namaFileSplit[i]);
            dataTabel(hasilSplit, jmlHasil);
        }

        if (!cekFileTerdaftar(namaFileSplit[i])) {
            ofstream daftar("daftar_file.txt", ios::app);
            daftar << namaFileSplit[i] << endl;
            daftar.close();
        }
    }

    ulangOpsiMenu();
}