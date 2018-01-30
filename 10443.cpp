#include <iostream>
#include <algorithm>

using namespace std;
int t, r, c, n;

char winner(char a, char b) {
  if(a==b) return a;
  char _a = (a&3)^(b&3);
  return (char)('P' | ((((a&1)|(b&1))<<1)|((_a>>1)&_a&1)));
}

void setWinner(char** grid, char** grid2, int i, int j) {
  unsigned char cur = (grid2[i][j] = grid[i][j]);
  if (i > 0 && winner(cur, grid[i-1][j]) != cur) grid2[i][j] = grid[i-1][j]; 
  else if (i < r-1 && winner(cur, grid[i+1][j]) != cur) grid2[i][j] = grid[i+1][j];
  else if (j > 0 &&  winner(cur, grid[i][j-1]) != cur) grid2[i][j] = grid[i][j-1];
  else if (j < c-1 && winner(cur, grid[i][j+1]) != cur) grid2[i][j] = grid[i][j+1];
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin >> t;
  while(t--) {
    cin >> r >> c >> n;
    // Create grids
    char** grid = new char*[r];
    char** grid2 = new char*[r];
    for (int i = 0; i < r; ++i) grid[i] = new char[c], grid2[i] = new char[c];
    char cur;
    // Build grid
    for (int i = 0; i < r; ++i) 
      for (int j = 0; j < c; ++j) 
        cin >> grid[i][j];
    // Perform steps
    while(n--) {
      for (int i = 0; i < r; ++i) 
        for (int j = 0; j < c; ++j) 
          setWinner(grid, grid2, i, j);
      swap(grid, grid2);
    }
    // Print result
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) 
        cout << (char)(grid[i][j]);
      cout << endl;
    }
    for (int i = 0; i < r; ++i) delete grid[i], delete grid2[i];
    if(t > 0) cout << endl;
  }
  return 0;
}
