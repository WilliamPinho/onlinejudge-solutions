#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rep(i,n) for(auto i=0; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

class UnionFind {
private:
  vi parent, size;
public:
  UnionFind(int N) {
    size.assign(N,1);
    parent.assign(N,0);
    for(int i = 0; i < N; ++i) parent[i] = i;
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
  void _union(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    if(rootP == rootQ) return;
    if(size[rootP] < size[rootQ]) {
      parent[rootP] = parent[rootQ];
      size[rootQ] += size[rootP];
    } else {
      parent[rootQ] = parent[rootP];
      size[rootP] += size[rootQ];
    }
  }
};


int main() {
  int t, p, q, N;
  char cmd;
  cin >> t;
  while(t > 0) {
    cin >> N;
    int success = 0, fail = 0;
    UnionFind uf(N);
    string line;
    getline(cin, line);
    getline(cin, line);
    stringstream ss;
    while(!line.empty()) {
      ss << line;
      ss >> cmd >> p >> q;
      p--;
      q--;
      if(cmd == 'c')
	uf._union(p,q);
      else {
	if(uf.connected(p,q)) success++;
	else fail++;
      }
      ss.str(string());
      ss.clear();
      getline(cin,line);
    }
    cout << success << ',' << fail << endl;
    if(t!=1) cout << endl;
    t--;
  }
  return 0;
}

