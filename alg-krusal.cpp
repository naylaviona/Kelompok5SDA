#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Sisi {
    int asal, tujuan, bobot;
};

struct Graf {
    int jumlahKota, jumlahSisi;
    vector<Sisi> daftarSisi;
};

bool bandingkan(Sisi a, Sisi b) {
    return a.bobot < b.bobot;
}

int cariInduk(int induk[], int i) {
    if (induk[i] == -1)
        return i;
    return cariInduk(induk, induk[i]);
}

void gabungkanSet(int induk[], int x, int y) {
    induk[x] = y;
}

void kruskalMST(Graf& graf) {
    // Mengurutkan sisi berdasarkan bobot
    sort(graf.daftarSisi.begin(), graf.daftarSisi.end(), bandingkan);

    int induk[graf.jumlahKota];
    fill_n(induk, graf.jumlahKota, -1);

    vector<Sisi> hasil; // Untuk menyimpan hasil MST

    for (auto sisi : graf.daftarSisi) {
        int x = cariInduk(induk, sisi.asal);
        int y = cariInduk(induk, sisi.tujuan);

        // Jika x dan y tidak berada dalam satu set, tambahkan sisi ke MST
        if (x != y) {
            hasil.push_back(sisi);
            gabungkanSet(induk, x, y);
        }
    }

    // Menampilkan MST
    cout << "Jaringan jalan terbaik (Minimum Spanning Tree) dengan Kruskal:" << endl;
    int totalBiaya = 0;
    for (auto sisi : hasil) {
        cout << "Dari kota " << (char)('A' + sisi.asal)
             << " ke kota " << (char)('A' + sisi.tujuan)
             << " dengan jarak " << sisi.bobot << endl;
        totalBiaya += sisi.bobot;
    }
    cout << "Total jarak seluruh jalan: " << totalBiaya << endl;
}

int main() {
    int jumlahKota = 5; // Jumlah kota
    int jumlahSisi = 8; // Jumlah sisi

    Graf graf;
    graf.jumlahKota = jumlahKota;
    graf.jumlahSisi = jumlahSisi;

    graf.daftarSisi.push_back({0, 1, 2}); // A - B
    graf.daftarSisi.push_back({0, 3, 6}); // A - D
    graf.daftarSisi.push_back({1, 2, 3}); // B - C
    graf.daftarSisi.push_back({1, 4, 1}); // B - E
    graf.daftarSisi.push_back({2, 4, 7}); // C - E
    graf.daftarSisi.push_back({3, 4, 9}); // D - E
    graf.daftarSisi.push_back({3, 1, 8}); // D - B
    graf.daftarSisi.push_back({2, 3, 2}); // C - D

    kruskalMST(graf);

    return 0;
}
