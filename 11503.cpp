#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef vector<int> vi;


class UnionFind {
private:
  vi parent, size;
  int counter;
  map<string,int> name_map;
public:
  UnionFind(int N) {
    size.assign(N,1);
    parent.assign(N,0);
    counter = 0;
    for(int i = 0; i < N; ++i) parent[i] = i;
  }
  int map_name(string s) {
    if(name_map.count(s) > 0)
      return name_map[s];
    else {
      counter++;
      name_map.emplace(s,counter);
      return counter;
    }
  }
  int find(int p) {
    while(parent[p] != p) {
      parent[p] = parent[parent[p]];
      p = parent[p];
    }
    return p;
  }
  bool connected(int p, int q) { 
    return (find(p) == find(q)); 
  }
  int _union(string s1, string s2) {
    int p = map_name(s1);
    int q = map_name(s2);
    int rootP = find(p);
    int rootQ = find(q);
    if(rootP == rootQ) return size[rootP];
    if(size[rootP] < size[rootQ]) {
      parent[rootP] = parent[rootQ];
      return size[rootQ] += size[rootP];
    } else {
      parent[rootQ] = parent[rootP];
      return size[rootP] += size[rootQ];
    }
  }
};

int main() {
  int t, n;
  ios::sync_with_stdio(false);
  cin >> t;
  while(t>0) {
    cin >> n;
    UnionFind uf(2*n);
    while(n>0) {
      string s1, s2;
      cin >> s1 >> s2;
      cout << uf._union(s1,s2) << endl;
      n--;
    }
    t--;
  }
}
