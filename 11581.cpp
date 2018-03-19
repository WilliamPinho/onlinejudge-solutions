#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  vector<vector<int>> g(3,vector<int>(3));
  char c;
  while(T--) {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        cin >> c;
        g[i][j] = c - '0';
      }
    }
    vector<vector<int>> prev(g);
    int k = 0;
    while(true) {
      bool isZero = true;
      for (int i = 0; i < 3 && isZero; ++i) {
        for (int j = 0; j < 3 && isZero; ++j) {
          if (g[i][j]) isZero = false;
        }
      }
      prev.swap(g);
      if (isZero) break;
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          g[i][j] = i > 0 ? prev[i-1][j] : 0;
          g[i][j] += i < 2 ? prev[i+1][j] : 0;
          g[i][j] += j > 0 ? prev[i][j-1] : 0;
          g[i][j] += j < 2 ? prev[i][j+1] : 0;
          g[i][j] = g[i][j]%2;
        }
      }
      k++;
    }
    cout << k-1 << endl;
  }  
  return 0;
}
