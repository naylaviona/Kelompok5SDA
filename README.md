# Laporan Tugas SDA - Application
## Kelompok 5

### Anggota Kelompok:
- Atikah Putri Utami (G1A024027)
- Agief Vemas A (G1A024037)
- Nayla Viona Azahra (G1A024045)
- Rofid Fadhil (G1A024063)
- R. Noor Fikhri (G1A024075)
- Okta Kurnia Ariansyah (G1A024099)
---

## Deskripsi Proyek
Proyek ini merupakan implementasi algoritma **Dynamic Programming**, **Minimum Spanning Tree**, dan **Disjoint Sets** menggunakan bahasa pemrograman **C++**.  
Tujuan proyek ini adalah memahami aplikasi algoritma tersebut pada permasalahan dunia nyata.

---

## Application
### 1. Dynamic Programming
Dynamic Programming adalah metode untuk membuat algoritma

Dalam Dynamic Programming, masalah besar dipecah menjadi masalah-masalah kecil.
Setiap masalah kecil diselesaikan satu per satu, lalu hasilnya digabungkan untuk membentuk solusi lengkap dari masalah utama yang ingin kita selesaikan.

Untuk membuat algoritma menggunakan Dynamic Programming, masalah yang ingin diselesaikan harus punya dua sifat ini:

- Overlapping Subproblems (Submasalah yang Berulang): Artinya masalah besar bisa dipecah menjadi submasalah yang lebih kecil, dan beberapa submasalah ini muncul berulang kali. Solusi dari satu submasalah bisa membantu menyelesaikan submasalah lain.

- Optimal Substructure (Struktur Optimal): Aberarti solusi lengkap untuk sebuah masalah bisa dibentuk dari solusi-solusi masalah kecil di dalamnya. Jadi, selain masalahnya harus punya bagian-bagian kecil yang saling tumpang tindih, bagian-bagian kecil ini juga harus punya sifat "optimal" (terbaik), supaya bisa digabungkan menjadi solusi akhir yang benar.

- Contoh: Menghitung deret fibonacci.
- Prinsip: Memecah masalah menjadi sub-masalah kecil, menyimpan hasilnya untuk menghindari perhitungan ulang.

### 2. Minimum Spanning Tree (MST)

Spanning tree adalah sebuah konsep dalam graf, terutama graf yang tidak berarah dan terhubung. Bayangkan kamu punya sebuah peta kota dengan banyak persimpangan (node) dan jalan (edge) yang menghubungkan antar persimpangan itu. Kalau kita ingin tetap bisa pergi dari satu persimpangan ke persimpangan lain, tapi menggunakan sesedikit mungkin jalan, itulah ide dari spanning tree.

Dalam spanning tree, kita memilih beberapa edge dari graf sehingga semua node tetap terhubung, tetapi tidak boleh ada jalur berputar (tidak boleh ada siklus). Jadi, spanning tree adalah sebuah subset dari edge dalam graf, yang cukup untuk membuat semua node terhubung, namun tanpa ada jalur yang membuat kita bisa kembali ke titik awal melalui rute yang berbeda.

Ada satu sifat penting: jika sebuah graf punya V buah node, maka spanning tree-nya akan selalu punya tepat V-1 buah edge. Ini karena setiap kali kita menghubungkan dua node baru, kita hanya butuh satu edge, dan kita terus menambahkan node sampai semuanya terhubung.

Kalau graf asalnya sudah berbentuk tree, artinya dia sudah adalah spanning tree itu sendiri. Tapi kalau grafnya lebih kompleks dan punya banyak jalur alternatif (misalnya banyak siklus), kita harus pilih edge mana saja yang cukup untuk menjaga konektivitas tanpa membentuk putaran.

- Contoh: Menggunakan Algoritma Prim
- Prinsip: Mulai dari satu node, lalu selalu pilih edge dengan bobot terkecil yang menghubungkan node yang sudah dipilih ke node yang belum dipilih, hingga semua node terhubung.
- Contoh: Menggunakan Algoritma Kruskal.
- Prinsip: Menyusun graf berbobot minimum yang menghubungkan seluruh node.

### 3. Disjoint Sets
- Contoh: Union-Find Structure.
- Prinsip: Mengelola himpunan data secara efisien untuk operasi union dan find.

---

## Laporan dan PPT
1. Clone repository:
   ```bash
   [git clone https://github.com/username/nama-repo.git](https://github.com/ereanoor/Kelompok5SDA.git)
2. PPT
   https://www.canva.com/design/DAGlvI3Ty10/JWXsUaexBpyWKdXFM2czcQ/edit


