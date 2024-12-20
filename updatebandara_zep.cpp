#include <iostream>
#include <vector>
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
    Hari hariTerbang;
    int kapasitasBensin;
    int bensinTerisi;    
    KondisiPesawat kondisi;
    KondisiSistemKeamanan gps;
    KondisiSistemKeamanan sistemKebakaran;
    KondisiSistemKeamanan layar;
    KondisiSistemKeamanan lampuPeringatan;
    KondisiSistemKeamanan hidrolik;
};

void MasukinKeadaanTiapPesawat(vector<Pesawat> *tiapPesawat){
    /* Bagian Afif
    Masukin hari terbang untuk setiap pesawat (pake enum yh)
    */
    int jumlahPesawat;

    Pesawat Airplane;
    int i;

    int hari;

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
        cout << "Masukkan hari terbang: ";
        cin >> hari;
        Airplane.hariTerbang = (Hari)hari;

        cout << "\nBerapa kapasitas tangki bensin (liter): ";
        cin >> Airplane.kapasitasBensin;

        cout << "Berapa jumlah bensin yang terisi (liter): ";
        cin >> Airplane.bensinTerisi;

        if (Airplane.bensinTerisi > Airplane.kapasitasBensin){
            cout << "Jumlah bensin yang terisi melebihi kapasitas! Tolong sesuaikan!!!";
            Airplane.bensinTerisi = Airplane.kapasitasBensin;
        }

        cout << "\nKondisi Pesawat\n";
        cout << "0: Baik\n"
             << "1: Perlu Perawatan\n"
             << "2: Rusak\n";
        cout << "Bagaimana kondisi pesawat: ";
        cin >> kondisi;
        Airplane.kondisi = (KondisiPesawat)kondisi;

        cout << "\nKondisi GPS\n";
        cout << "0: Berfungsi\n"
             << "1: Tidak Berfungsi\n"
             << "2: Perlu Pemeriksaan\n";
        cout << "Bagaimana kondisi GPS pesawat: ";
        cin >> kondisiGPS;
        Airplane.gps = (KondisiSistemKeamanan)kondisiGPS;

        cout << "\nKondisi Sistem Kebakaran:\n";
        cout << "0: Berfungsi\n"
             << "1: Tidak Berfungsi\n"
             << "2: Perlu Pemeriksaan\n";
        cout << "Bagaimana kondisi sistem kebakaran pada pesawat: ";
        cin >> kondisiSistemKebakaran;
        Airplane.sistemKebakaran = (KondisiSistemKeamanan)kondisiSistemKebakaran;

        cout << "\nKondisi Layar Kemudi Pesawat:\n";
        cout << "0: Berfungsi\n"
             << "1: Tidak Berfungsi\n"
             << "2: Perlu Pemeriksaan\n";
        cout << "Bagaimana kondisi layar kemudi pesawat: ";
        cin >> kondisiLayar;
        Airplane.layar = (KondisiSistemKeamanan)kondisiLayar;

        cout << "\nKondisi Lampu Peringatan:\n";
        cout << "0: Berfungsi\n"
             << "1: Tidak Berfungsi\n"
             << "2: Perlu Pemeriksaan\n";
        cout << "Bagaimana kondisi lampu peringatan pada pesawat: ";
        cin >> kondisiLampuPeringatan;
        Airplane.lampuPeringatan = (KondisiSistemKeamanan)kondisiLampuPeringatan;

        cout << "\nKondisi Hidrolik:\n";
        cout << "0: Berfungsi\n"
             << "1: Tidak Berfungsi\n"
             << "2: Perlu Pemeriksaan\n";
        cout << "Bagaimana kondisi hidrolik pada pesawat: ";
        cin >> kondisiHidrolik;
        Airplane.hidrolik = (KondisiSistemKeamanan)kondisiHidrolik;

        tiapPesawat -> push_back(Airplane);

        cout << "\nKeadaan semua pesawat telah dimasukkan.\n";
    }
}

void TampilkanInformasiPesawat(vector<Pesawat> &tiapPesawat){
    int i;
    string KondisiPesawat;
    string hariTerbang;

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

        switch (Airplane.hariTerbang){
            case Senin: hariTerbang = "Senin";
            break;
            case Selasa: hariTerbang = "Selasa";
            break;
            case Rabu: hariTerbang = "Rabu";
            break;
            case Kamis: hariTerbang = "Kamis";
            break;
            case Jumat: hariTerbang = "Jumat";
            break;
            case Sabtu: hariTerbang = "Sabtu";
            break;
            case Minggu: hariTerbang = "Minggu";
            break;
        }

        cout << "\nPesawat " << i+1 << ":\n";
        cout << "Jumlah Maksimal penumpang: " << Airplane.jumlahMaksPenumpang << endl;
        cout << "Hari Terbang: " << hariTerbang << endl;
        cout << "Kapasitas Bensin: " << Airplane.kapasitasBensin << " liter\n";
        cout << "Bensin Terisi: " << Airplane.bensinTerisi << " liter\n";
        cout << "Kondisi Pesawat: " << KondisiPesawat << endl;

        if(Airplane.gps == Berfungsi){
            kondisiGPS = "Berfungsi";
        } else if (Airplane.gps == TidakBerfungsi){
            kondisiGPS = "Tidak Berfungsi";
        } else {
            kondisiGPS = "Perlu Pemeriksaan";
        }

        if(Airplane.sistemKebakaran == Berfungsi){
            kondisiSistemKebakaran = "Berfungsi";
        } else if(Airplane.sistemKebakaran == TidakBerfungsi){
            kondisiSistemKebakaran = "Tidak Berfungsi";
        } else {
            kondisiSistemKebakaran = "Perlu Pemeriksaan";
        }

        if (Airplane.layar == Berfungsi){
            kondisiLayar = "Berfungsi";
        } else if (Airplane.layar == TidakBerfungsi){
            kondisiLayar = "Tidak Berfungsi";
        } else {
            kondisiLayar = "Perlu Pmeriksaan";
        }

        if (Airplane.lampuPeringatan == Berfungsi) {
            kondisiLampuPeringatan = "Berfungsi";
        } else if (Airplane.lampuPeringatan == TidakBerfungsi) {
            kondisiLampuPeringatan = "Tidak Berfungsi";
        } else {
            kondisiLampuPeringatan = "Perlu Pemeriksaan";
        }

        if (Airplane.hidrolik == Berfungsi) {
            kondisiHidrolik = "Berfungsi";
        } else if (Airplane.hidrolik == TidakBerfungsi) {
            kondisiHidrolik = "Tidak Berfungsi";
        } else {
            kondisiHidrolik = "Perlu Pemeriksaan";
        }

        cout << "Kondisi GPS: " << kondisiGPS << endl;
        cout << "Kondisi Sistem Kebakaran: " << kondisiSistemKebakaran << endl;
        cout << "Kondisi Layar: " << kondisiLayar << endl;
        cout << "Kondisi Lampu Peringatan: " << kondisiLampuPeringatan << endl;
        cout << "Kondisi Hidrolik: " << kondisiHidrolik << endl;


    }
}

void CekKeamananPesawat(vector<Pesawat>& tiapPesawat) {
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
    }
}

void cekKeadaanTiapHari(int JumlahPenumpangTiapHari[], const vector<Pesawat> tiapPesawat){
    /* Bagian Zefanya
    Cek berapa banyak penumpang di hari X dan jumlah maksimum penumpang dari setiap pesawat X
    Contoh output:
    Senin: Kebanyakan! 18 orang tidak bisa masuk karena semua pesawat penuh!
    Selasa: Pas
    Rabu: Ada 9 kursi yang tersisa.
    ...
    */
   const char* namaHari[7] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu"};
   int totalKapasitasHarian[7] = {0};
   for (const Pesawat& Airplane: tiapPesawat)
   {
    totalKapasitasHarian[Airplane.hariTerbang] += Airplane.jumlahMaksPenumpang;
   }
   
   for (int i = 0; i < 7; i++)
   {
    cout << namaHari[i] << ":" << endl;
    if (JumlahPenumpangTiapHari[i] == 0 && totalKapasitasHarian[i] == 0){
        cout << "Tidak ada penumpang & pesawat hari ini!" << endl;
    } else if (totalKapasitasHarian[i] == 0){
        cout << "Tidak Ada Pesawat Hari ini!" << endl;
    } else if (JumlahPenumpangTiapHari[i] == 0){
        cout << "Tidak ada penumpang hari ini!" << endl;
    } else if (totalKapasitasHarian[i] < JumlahPenumpangTiapHari[i]){
        cout << "Kebanyakan!" << JumlahPenumpangTiapHari[i] - totalKapasitasHarian[i] << "orang tidak bisa masuk karena semua pesawat penuh!" << endl;
    } else if (totalKapasitasHarian[i] == JumlahPenumpangTiapHari[i]){
        cout << "Pas!" << endl;
    } else if (totalKapasitasHarian[i] > JumlahPenumpangTiapHari[i]) {
        cout << "Ada " << totalKapasitasHarian[i] - JumlahPenumpangTiapHari[i] << " kursi yang tersisa." << endl;
    }
   }
   }

   





int main(){
    int JumlahPenumpangTiapHari[7];
    vector<Pesawat> tiapPesawat;
    MasukinKeadaanTiapPesawat(&tiapPesawat);
    TampilkanInformasiPesawat(tiapPesawat);
    CekKeamananPesawat(tiapPesawat);
    cekKeadaanTiapHari(JumlahPenumpangTiapHari, tiapPesawat);
    return 0;
}
