#include <iostream>

#define print(i, k) (i > k ? "Blank" : to_string(i)) 
using namespace std;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  int n;
  while(cin >> n, n) {
    cout << "Printing order for " << n << " pages:" << endl;
    int k = (n&3) ? (((n >> 2) << 2) + 4) : n;
    for(int i = 1; i <= (k >> 1); ++i) {
      int smaller = i, bigger = k-i+1;
      if(smaller > n && bigger > n) continue;
      cout << "Sheet " << (i+1)/2 << ", ";
      if(i&1) cout << "front: " << print(bigger, n) << ", " << print(smaller, n);
      else cout << "back : " << print(smaller,n) << ", " << print(bigger,n);
      cout << endl;  
    }
  } 
  return 0;
}
