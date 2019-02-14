#include<iostream>
#include<bitset>

using namespace std;
const int  MAX = 1000001;

template<size_t N>
bool setInterval(bitset<N>& b, int s, int e) {
  for (int i = s; i < e && i < MAX; i++) {
    if (b.test(i)) return false;
    b.set(i);
  }
  return true;
}

int main() {
  int N, M, s, e, p;
  while (cin >> N >> M, N != 0 || M != 0) {
    bitset<MAX> b;
    bool overlap = false;
    
    while (N--) {
      cin >> s >> e;
      if(!overlap && !setInterval(b, s, e))
        overlap = true;  
    }

    while (M--) {
      cin >> s >> e >> p;
      while (!overlap && s < MAX) {
        if (!setInterval(b, s, e))
          overlap = true;
        s += p;
        e += p;
      }
    }

    cout << (overlap ? "" : "NO ") << "CONFLICT" << endl;
  } 
}
