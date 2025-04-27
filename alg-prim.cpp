#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int jumlahKota = 5; // Jumlah kota

// Fungsi untuk mencari kota dengan kunci terkecil yang belum masuk MST
int cariKunciMinimum(int kunci[], bool sudahTermasuk[]) {
    int nilaiMinimum = INT_MAX, indeksMinimum = -1;

    for (int i = 0; i < jumlahKota; i++) {
        if (!sudahTermasuk[i] && kunci[i] < nilaiMinimum) {
            nilaiMinimum = kunci[i];
            indeksMinimum = i;
        }
    }

    return indeksMinimum;
}

void bangunMST(int graf[jumlahKota][jumlahKota]) {
    int induk[jumlahKota];
    int kunci[jumlahKota];
    bool sudahTermasuk[jumlahKota];

    for (int i = 0; i < jumlahKota; i++) {
        kunci[i] = INT_MAX;
        sudahTermasuk[i] = false;
    }

    kunci[0] = 0;
    induk[0] = -1; // Node akar tidak punya induk

    for (int langkah = 0; langkah < jumlahKota - 1; langkah++) {
        int u = cariKunciMinimum(kunci, sudahTermasuk);
        sudahTermasuk[u] = true;

        // Perbarui nilai tetangga dari simpul terpilih
        for (int v = 0; v < jumlahKota; v++) {
            if (graf[u][v] && !sudahTermasuk[v] && graf[u][v] < kunci[v]) {
                induk[v] = u;
                kunci[v] = graf[u][v];
            }
        }
    }

    // Cetak hasil MST
    cout << "Jaringan jalan terbaik (Minimum Spanning Tree):" << endl;
    int totalBiaya = 0;
    for (int i = 1; i < jumlahKota; i++) {
        cout << "Dari kota " << (char)('A' + induk[i])
             << " ke kota " << (char)('A' + i)
             << " dengan jarak " << graf[i][induk[i]] << endl;
        totalBiaya += graf[i][induk[i]];
    }
    cout << "Total jarak seluruh jalan: " << totalBiaya << endl;
}

int main() {
    int peta[jumlahKota][jumlahKota] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    bangunMST(peta);

    return 0;
}
