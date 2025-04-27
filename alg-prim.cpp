#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int V = 5; // Jumlah kota

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(int graph[V][V]) {
    int parent[V]; // Array untuk menyimpan MST
    int key[V];    // Nilai kunci untuk memilih edge minimum
    bool mstSet[V]; // Untuk melacak kota yang sudah termasuk MST

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX; // Inisialisasi semua kunci dengan nilai maksimum
        mstSet[i] = false; // Inisialisasi semua kota sebagai belum termasuk MST
    }

    key[0] = 0; // Memulai dari kota A
    parent[0] = -1; // Kota A adalah root

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            // Jika ada edge dari u ke v dan v belum termasuk MST
            // dan bobot edge u-v lebih kecil dari kunci v
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u; // Set parent v sebagai u
                key[v] = graph[u][v]; // Update kunci v
            }
        }
    }

    // Menampilkan MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << (char)('A' + parent[i]) << " - " << (char)('A' + i) << "\t" << graph[i][parent[i]] << endl;
    }
}

int main() {
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    primMST(graph);
    return 0;
}
