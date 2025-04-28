#include <vector>
#include <iostream>
class QuickFind {

std::vector<int> id;

public:
int i;
  QuickFind(int N){
    id.resize(N);
    for (i=0; i<N; ++i){
    id[i] = i;
    }
  }

  bool terhubung(int p, int q) {
    return id[p] == id[q];
  }

  void gabungElemen(int p, int q) {
    int pid = id[p];
    int qid = id[q];

    for (i=0; i<id.size(); ++i) {
      if (id[i] == pid) {
        id[i]=qid;
      }
    }
  }

  void cetakId() {
    for(i=0; i<id.size(); ++i) {
    std::cout << id[i] << " ";
    }
    std::cout << std::endl;
  }
};
int main() {
  int N = 10;
  QuickFind uf(N);

  uf.gabungElemen(4, 9);
  uf.gabungElemen(8, 4);

  std::cout << std::boolalpha;
  std::cout << "Terhubung(8, 9): " << uf.terhubung(8, 9) << std::endl;
  std::cout << "Terhubung(5, 0): " << uf.terhubung(5, 0) << std::endl;

  uf.cetakId();
  return 0;
}
