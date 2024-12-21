#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

enum Hari{
    Senin,
    Selasa,
    Rabu,
    Kamis,
    Jumat,
    Sabtu,
    Minggu
};

enum KondisiPesawat {
    Baik,
    PerluPerawatan,
    Rusak
};

enum KondisiSistemKeamanan {
    Berfungsi,
    TidakBerfungsi,
    PerluPemeriksaan
};

struct Pesawat{
    int jumlahMaksPenumpang;
    vector<Hari> hariTerbang;
    int kapasitasBensin;
    int bensinTerisi;
    bool keadaanSemuaSistem; // True berarti aman semua, false berarti ada yang tidak berfungsi/perlu pemeriksaan
    KondisiPesawat kondisi;
    KondisiSistemKeamanan gps;
    KondisiSistemKeamanan sistemKebakaran;
    KondisiSistemKeamanan layar;
    KondisiSistemKeamanan lampuPeringatan;
    KondisiSistemKeamanan hidrolik;
};

void MasukinJumlahPenumpang(int JumlahPenumpangTiapHari[]){
    /*  Bagian Arifin
    Minta user masukin jumlah penumpang tiap hari
    */
    cout << "Masukkan jumlah penumpang di bandara untuk setiap hari berikut." << endl;
    string namaHari[] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu"};

    for (int i = Senin; i <= Minggu; i++) {
        cout << namaHari[i] << ": ";
        cin >> JumlahPenumpangTiapHari[i];
    }
}


void cekKeadaanTiapHari(int JumlahPenumpangTiapHari[], const vector<Pesawat> tiapPesawat){
    /* Bagian Zefanya + Dhimas
    Cek berapa banyak penumpang di hari X dan jumlah maksimum penumpang dari setiap pesawat X
    Contoh output:
    Senin: Kebanyakan! 18 orang tidak bisa masuk karena semua pesawat penuh!
    Selasa: Pas
    Rabu: Ada 9 kursi yang tersisa.
    ...
    */
   const char* namaHari[7] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu"};
   int totalKapasitasHarian[7] = {0};
   for (const Pesawat& Airplane: tiapPesawat) {
        if(!Airplane.keadaanSemuaSistem){
            continue;
        }
        for(int i = 0; i < 3; i++){
            totalKapasitasHarian[Airplane.hariTerbang[i]] += Airplane.jumlahMaksPenumpang;
            }        
        }
   cout << " " << endl;
   cout << "Kondisi Bandara Untuk Minggu ini: " << endl;
   for (int i = 0; i < 7; i++) {
        cout << namaHari[i] << ": " ;
        if (JumlahPenumpangTiapHari[i] == 0 && totalKapasitasHarian[i] == 0){
            cout << "Tidak ada penumpang & pesawat hari ini!" << endl;
        } else if (totalKapasitasHarian[i] == 0){
            cout << "Tidak Ada Pesawat hari ini! Semua penumpang tidak bisa berangkat." << endl;
        } else if (JumlahPenumpangTiapHari[i] == 0){
            cout << "Tidak ada penumpang hari ini!" << endl;
        } else if (totalKapasitasHarian[i] < JumlahPenumpangTiapHari[i]){
            cout << "Kebanyakan! " << JumlahPenumpangTiapHari[i] - totalKapasitasHarian[i] << " orang tidak bisa masuk karena semua pesawat penuh!" << endl;
        } else if (totalKapasitasHarian[i] == JumlahPenumpangTiapHari[i]){
            cout << "Pas!" << endl;
        } else if (totalKapasitasHarian[i] > JumlahPenumpangTiapHari[i]) {
            cout << "Ada " << totalKapasitasHarian[i] - JumlahPenumpangTiapHari[i] << " kursi yang tersisa dari semua pesawat yang berfungsi dengan baik." << endl;
        }
   }
}

void outputKeadaan(){
    cout << "0: Berfungsi\n"
         << "1: Tidak Berfungsi\n"
         << "2: Perlu Pemeriksaan\n";
}

string keadaan(KondisiSistemKeamanan kondisiAirplane){
    switch (kondisiAirplane){
        case (Berfungsi):
            return "Berfungsi";
            break;
        case (TidakBerfungsi):
            return "Tidak Berfungsi";
            break;
        case (PerluPemeriksaan):
            return "Perlu Pemeriksaan";
            break;
        default:
            return "Error";
            break;
    }
}

void delay(int milliseconds) {
    // Prosedur untuk menghentikan program sejenak
    clock_t start_time = clock();  
    while (clock() < start_time + milliseconds * (CLOCKS_PER_SEC / 1000)) {
    }
}

void MasukinKeadaanTiapPesawat(vector<Pesawat> *tiapPesawat){
    // Bagian Afif + Dhimas, Memasukkan keadaan untuk setiap pesawat di bandara
    int jumlahPesawat;

    Pesawat Airplane;
    int i;

    int kondisi;
    int kondisiGPS;
    int kondisiSistemKebakaran;
    int kondisiLayar;
    int kondisiLampuPeringatan;
    int kondisiHidrolik;

    cout << "Berapa jumah pesawat yang akan beroperasi: ";
    cin >> jumlahPesawat;

    for(i = 0; i < jumlahPesawat; i++){
        cout << "\nPesawat " << i + 1 << ":\n";

        cout << "Masukkan jumlah maksimal penumpang pada pesawat: ";
        cin >> Airplane.jumlahMaksPenumpang;

        cout << "\nJadwal Penerbaangan:\n";
        cout << "0: Senin\n"
             << "1: Selasa\n"
             << "2: Rabu\n"
             << "3: Kamis\n"
             << "4: Jumat\n"
             << "5: Sabtu\n"
             << "6: Minggu\n";
        Airplane.hariTerbang.resize(3);
        for (int j = 0; j < 3; j++) {
            cout << "Masukkan hari ke-" << j + 1 << " pesawat ini terbang: ";
            int hari;
            cin >> hari;
            bool isDuplicate = false;
            for (int k = 0; k < j; k++) {
                if (hari == Airplane.hariTerbang[k]) {
                    isDuplicate = true;
                    break;
                }
            }
            if (isDuplicate) {
                cout << "Anda memasukkan hari yang sama dengan sebelumnya! Masukkan ulang hari yang berbeda." << endl;
                j--;
            } 
            else {
                Airplane.hariTerbang[j] = (Hari)hari;
            }
        }   

        cout << endl;
        cout << "\nBerapa kapasitas tangki bensin (liter): ";
        cin >> Airplane.kapasitasBensin;

        cout << "Berapa jumlah bensin yang akan diisi (liter): ";
        cin >> Airplane.bensinTerisi;

        cout << "Sedang mengisi bensin"; delay(500);
        cout << "."; delay(500);
        cout << "."; delay(500);
        cout << ".\n"; delay(500);
        if (Airplane.bensinTerisi > Airplane.kapasitasBensin){
            cout << "Jumlah bensin yang terisi melebihi kapasitas!\nBensin yang tersisa akan dikurangi"; delay(2000);
            cout << "."; delay(1000);
            cout << "."; delay(1000);
            cout << ".\n"; delay(1000);
            Airplane.bensinTerisi = Airplane.kapasitasBensin;
        }
        cout << "Tangki bensin sudah terisi dengan baik!" << endl;


        cout << "\nKondisi Pesawat\n";
        outputKeadaan();
        cout << "Bagaimana kondisi pesawat: ";
        cin >> kondisi;
        Airplane.kondisi = (KondisiPesawat)kondisi;

        cout << "\nKondisi GPS\n";
        outputKeadaan();
        cout << "Bagaimana kondisi GPS pesawat: ";
        cin >> kondisiGPS;
        Airplane.gps = (KondisiSistemKeamanan)kondisiGPS;

        cout << "\nKondisi Sistem Kebakaran:\n";
        outputKeadaan();
        cout << "Bagaimana kondisi sistem kebakaran pada pesawat: ";
        cin >> kondisiSistemKebakaran;
        Airplane.sistemKebakaran = (KondisiSistemKeamanan)kondisiSistemKebakaran;

        cout << "\nKondisi Layar Kemudi Pesawat:\n";
        outputKeadaan();
        cout << "Bagaimana kondisi layar kemudi pesawat: ";
        cin >> kondisiLayar;
        Airplane.layar = (KondisiSistemKeamanan)kondisiLayar;

        cout << "\nKondisi Lampu Peringatan:\n";
        outputKeadaan();
        cout << "Bagaimana kondisi lampu peringatan pada pesawat: ";
        cin >> kondisiLampuPeringatan;
        Airplane.lampuPeringatan = (KondisiSistemKeamanan)kondisiLampuPeringatan;

        cout << "\nKondisi Hidrolik:\n";
        outputKeadaan();
        cout << "Bagaimana kondisi hidrolik pada pesawat: ";
        cin >> kondisiHidrolik;
        Airplane.hidrolik = (KondisiSistemKeamanan)kondisiHidrolik;

        tiapPesawat -> push_back(Airplane);

        cout << "\nKeadaan semua pesawat telah dimasukkan.\n";
    }
}

void TampilkanInformasiPesawat(vector<Pesawat> &tiapPesawat){
    //Menampilkan semua informasi dari setiap pesawat yang ada
    int i;
    string KondisiPesawat;
    string hariTerbang[3];

    string kondisiGPS;
    string kondisiSistemKebakaran;
    string kondisiLayar;
    string kondisiLampuPeringatan;
    string kondisiHidrolik;
    

    cout << "\nInformasi Pesawat:\n";

    for (i = 0; i < tiapPesawat.size(); i++){
        Pesawat& Airplane = tiapPesawat[i];
        
        switch (Airplane.kondisi){
            case Baik: KondisiPesawat = "Baik";
            break;
            case PerluPerawatan: KondisiPesawat = "Perlu Perawatan";
            break;
            case Rusak: KondisiPesawat = "Rusak";
            break;
        }
        for(int j = 0; j < 3; j++){
            switch (Airplane.hariTerbang[j]){
            case Senin: hariTerbang[j] = "Senin";
            break;
            case Selasa: hariTerbang[j] = "Selasa";
            break;
            case Rabu: hariTerbang[j] = "Rabu";
            break;
            case Kamis: hariTerbang[j] = "Kamis";
            break;
            case Jumat: hariTerbang[j] = "Jumat";
            break;
            case Sabtu: hariTerbang[j] = "Sabtu";
            break;
            case Minggu: hariTerbang[j] = "Minggu";
            break;
            }
        }
        

        cout << "\nPesawat " << i+1 << ":\n";
        cout << "Jumlah Maksimal penumpang: " << Airplane.jumlahMaksPenumpang << endl;
        cout << "Hari Terbang: " << hariTerbang[0] << ", " << hariTerbang[1] << ", " << hariTerbang[2] << endl;
        cout << "Kapasitas Bensin: " << Airplane.kapasitasBensin << " liter\n";
        cout << "Bensin Terisi: " << Airplane.bensinTerisi << " liter\n";
        cout << "Kondisi Pesawat: " << KondisiPesawat << endl;
        
        kondisiGPS = keadaan(Airplane.gps);
        kondisiSistemKebakaran = keadaan(Airplane.sistemKebakaran);
        kondisiLayar = keadaan(Airplane.layar);
        kondisiLampuPeringatan = keadaan(Airplane.lampuPeringatan);
        kondisiHidrolik = keadaan(Airplane.hidrolik);

        cout << "Kondisi GPS: " << kondisiGPS << endl;
        cout << "Kondisi Sistem Kebakaran: " << kondisiSistemKebakaran << endl;
        cout << "Kondisi Layar: " << kondisiLayar << endl;
        cout << "Kondisi Lampu Peringatan: " << kondisiLampuPeringatan << endl;
        cout << "Kondisi Hidrolik: " << kondisiHidrolik << endl;
    }
}

void CekKeamananPesawat(vector<Pesawat>& tiapPesawat) {
    // Mengecek keamanan untuk setiap pesawat
    cout << "\nCek Sistem Keamanan Pesawat:\n";
    for (int i = 0; i < tiapPesawat.size(); i++) {
        Pesawat& Airplane = tiapPesawat[i];
        cout << "\nPesawat " << i + 1 << ":\n";

        bool kondisiPesawatBaik = true;  
        bool semuaSistemBerfungsi = true; 

        if (Airplane.kondisi != Baik) {
            kondisiPesawatBaik = false;
        }
        bool bensinPenuh = (Airplane.bensinTerisi == Airplane.kapasitasBensin);

        if (Airplane.gps != Berfungsi || Airplane.sistemKebakaran != Berfungsi || Airplane.layar != Berfungsi ||
            Airplane.lampuPeringatan != Berfungsi || Airplane.hidrolik != Berfungsi) {
            semuaSistemBerfungsi = false;
            }
       
        if (kondisiPesawatBaik && bensinPenuh && semuaSistemBerfungsi) {
            cout << "Pesawat siap terbang!" << endl;
        } else {
            if (!bensinPenuh) {
                cout << "- Tolong isi penuh bensin agar perjalanan lancar!" << endl;
            }
            if (!kondisiPesawatBaik) {
                cout << "- Kondisi pesawat tidak baik! Periksa kondisi pesawat segera.\n";
            }
            
        }

        if (Airplane.gps == TidakBerfungsi) {
            cout << "- GPS tidak berfungsi! Periksa sistem GPS segera.\n";
        }
        if (Airplane.sistemKebakaran == TidakBerfungsi) {
            cout << "- Sistem kebakaran tidak berfungsi! Periksa sistem kebakaran segera.\n";
        }
        if (Airplane.layar == TidakBerfungsi) {
            cout << "- Layar tidak berfungsi! Periksa layar segera.\n";
        }
        if (Airplane.lampuPeringatan == TidakBerfungsi) {
            cout << "- Lampu peringatan tidak berfungsi! Periksa lampu peringatan segera.\n";
        }
        if (Airplane.hidrolik == TidakBerfungsi) {
            cout << "- Hidrolik tidak berfungsi! Periksa sistem hidrolik segera.\n";
        }
       tiapPesawat[i].keadaanSemuaSistem = semuaSistemBerfungsi;
    }
}

int main(){
    int JumlahPenumpangTiapHari[7];
    vector<Pesawat> tiapPesawat;

    MasukinJumlahPenumpang(JumlahPenumpangTiapHari);
    MasukinKeadaanTiapPesawat(&tiapPesawat);
    TampilkanInformasiPesawat(tiapPesawat);
    CekKeamananPesawat(tiapPesawat);
    cekKeadaanTiapHari(JumlahPenumpangTiapHari, tiapPesawat);
    return 0;
}
