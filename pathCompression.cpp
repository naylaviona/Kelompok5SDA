#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
private:
    vector<int> parent; // Array of 'n' parent pointers

public:   
    // Constructor 
    DisjointSet(int n) { 
        parent.resize(n + 1);  // index 1..n

        for (int i = 1; i <= n; ++i) {
            parent[i] = i; // semua jadi bos diri sendiri
        }
    }

    // find memakai path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Sekalian sambung langsung ke bos besar
        }
        return parent[x];
    }

    // Fungsi union
    void unionSets(int x, int y) {
        int bossX = find(x);
        int bossY = find(y); 
        if (bossX != bossY) {
            parent[bossY] = bossX; // sambungin bossY ke bossX
        } 
    }

    // Print isi parent array 
    void printParents() {
        cout << "Isi parent[] sekarang:\n";
        for (int i = 1; i < parent.size(); ++i) {
            cout << "parent[" << i << "] = " << parent[i] << endl;
        } 
    } 
};

int main() {
    DisjointSet ds(5); // 5 elemen
    cout << "Awal:\n";
    ds.printParents();

    cout << "\nGabung bertahap:\n";
    ds.unionSets(1, 2);
    ds.unionSets(2, 3);
    ds.unionSets(3, 4);
    ds.unionSets(4, 5);

    cout << "\nIsi parent setelah Semua Union berjalan:\n";
    ds.printParents();

    cout << "\nCari bos 3 :\n";
    int boss3 = ds.find(3);
    cout << "Bos dari 3 adalah: " << boss3 << endl;

    cout << "\nIsi parent[] :\n";
    ds.printParents();

    return 0; 
} 
