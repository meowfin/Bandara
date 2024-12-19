#include <iostream>
#include <vector>

using namespace std;

enum Hari{
    Senin,
    Selasa,
    Rabu,
    Kamis,
    Jumat,
    Minggu
};

struct Pesawat{
    int jumlahMaksPenumpang;
    enum Hari hariTerbang;
};

void MasukinJumlahPenumpang(int JumlahPenumpangTiapHari[]){
    /*  Bagian Arifin
    Minta user masukin jumlah penumpang, nanti di layar gini:
    Masukkan jumlah penumpang di bandara untuk setiap hari berikut.
    Senin: (user masukin)
    Selasa: (user masukin)
    ... 
    */
}


void cekKeadaanTiapHari(int JumlahPenumpangTiapHari[], vector<Pesawat> tiapPesawat){
    /* Bagian Zefanya
    Cek berapa banyak penumpang di hari X dan jumlah maksimum penumpang dari setiap pesawat X
    Contoh output:
    Senin: Kebanyakan! 18 orang tidak bisa masuk karena semua pesawat penuh!
    Selasa: Pas
    Rabu: Ada 9 kursi yang tersisa.
    ...
    */
}

void MasukinKeadaanTiapPesawat(vector<Pesawat> *tiapPesawat){
    /* Bagian Afif
    Masukin hari terbang untuk setiap pesawat (pake enum yh)
    */
}

int main(){
    int JumlahPenumpangTiapHari[7];
    vector<Pesawat> tiapPesawat;

    MasukinJumlahPenumpang(JumlahPenumpangTiapHari);
    MasukinKeadaanTiapPesawat(&tiapPesawat);
    cekKeadaanTiapHari(JumlahPenumpangTiapHari, tiapPesawat);
    return 0;
}