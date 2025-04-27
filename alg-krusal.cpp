#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edges;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y) {
    parent[x] = y;
}

void kruskalMST(Graph& graph) {
        // Mengurutkan edges berdasarkan bobot
        sort(graph.edges.begin(), graph.edges.end(), compare);

        int parent[graph.V];
        fill_n(parent, graph.V, -1);
    
        vector<Edge> result; // Untuk menyimpan hasil MST
    
        for (auto edge : graph.edges) {
            int x = find(parent, edge.src);
            int y = find(parent, edge.dest);
    
            // Jika x dan y tidak berada dalam satu set, tambahkan edge ke MST
            if (x != y) {
                result.push_back(edge);
                unionSet(parent, x, y);
            }
        }
    
        // Menampilkan MST
        cout << "Edge \tWeight\n";
        for (auto edge : result) {
            cout << (char)('A' + edge.src) << " - " << (char)('A' + edge.dest) << "\t" << edge.weight << endl;
        }
    }
    
    int main() {
        int V = 5; // Jumlah kota
        int E = 7; // Jumlah jalan
    
        Graph graph;
        graph.V = V;
        graph.E = E;
    
        // Menambahkan edges ke graf
        graph.edges.push_back({0, 1, 2}); // A - B
        graph.edges.push_back({0, 3, 6}); // A - D
        graph.edges.push_back({1, 2, 3}); // B - C
        graph.edges.push_back({1, 4, 5}); // B - E
        graph.edges.push_back({2, 4, 7}); // C - E
        graph.edges.push_back({3, 4, 9}); // D - E
        graph.edges.push_back({3, 1, 8}); // D - B
    
        kruskalMST(graph);
    
        return 0;
    }
