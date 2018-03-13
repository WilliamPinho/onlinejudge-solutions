#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void transpose(vector<vector<char>>& m, int n) {
  for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j)
      swap(m[i][j],m[j][i]);
}

void reverse(vector<vector<char>>& m, int n) {
  for (int i = 0; i < n; ++i)
    for (int j = 0, k = n-1; j < k; ++j, --k)
      swap(m[i][j], m[i][k]);
}

void rotate(vector<vector<char>>& m, int n) {
  transpose(m,n);
  reverse(m,n);
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  int N, n;
  while(cin >> N >> n, N != 0 && n != 0) {
    vector<vector<char>> M(N,vector<char>(N)), m(n,vector<char>(n));
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        cin >> M[i][j];
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        cin >> m[i][j];
    int result[4] = { 0 };
    for (int k = 0; k < 4; ++k) {
      for (int i = 0; i <= N-n; ++i) {
        for (int j = 0; j <= N-n; ++j) {
          bool isEqual = true;
          for (int x = 0; x < n && isEqual; ++x)
            for (int y = 0; y < n && isEqual; ++y)
              isEqual = m[x][y] == M[i+x][j+y];
          if(isEqual) result[k]++;
        }
      }
      rotate(m, n);
    }
    cout << result[0] << " " << result[1] << " " << result[2] << " " << result[3] << endl;
  }
  return 0;
}
