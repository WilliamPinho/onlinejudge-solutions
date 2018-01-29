#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  int n, m, k = 1;
   cin >> n >> m;
   do {
    int count[n][m] = {};
    string line;
    // Populate count board accordingly
    for (int i = 0; i < n; ++i) {
      cin >> line;
      for (int j = 0; j < m; ++j) {
        if(line[j] == '*') {
          count[i][j] = -1;
          if(i > 0) {
            if(j > 0 && count[i-1][j-1] != -1)    count[i-1][j-1]++;
            if(count[i-1][j] != -1)               count[i-1][j]++;
            if(j+1 < m && count[i-1][j+1] != -1)  count[i-1][j+1]++;
          }
          if(j > 0 && count[i][j-1] != -1)        count[i][j-1]++;
          if(j+1 < m && count[i][j+1] != -1)      count[i][j+1]++;
          if(i+1 < n) {
            if(j > 0 && count[i+1][j-1] != -1)    count[i+1][j-1]++;
            if(count[i+1][j] != -1)               count[i+1][j]++;
            if(j+1 < m && count[i+1][j+1] != -1)  count[i+1][j+1]++;
          }
        }
      }
    }

    cout << "Field #" << k++ << ":" << endl;
    // Print board
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) 
       cout << (count[i][j] == -1 ? '*' : (char)(count[i][j] + '0'));
      cout << endl;
    }
    
    cin >> n >> m;
    if(n!=0) cout << endl;
  } while(n);
  return 0;
}
