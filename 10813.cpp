#include <iostream>
#include <map>
#include <utility>

using namespace std;

bool isBingo(int primDiag, int secDiag, int* rowCount, int* colCount) {
  if (primDiag == 4 || secDiag == 4 || rowCount[2] == 4 || colCount[2] == 4) return true;
  for(int i = 0; i < 5; ++i) if(rowCount[i] == 5 || colCount[i] == 5) return true;
  return false;
}

int main(int argc, char *argv[]) {
  int t, k;
  ios::sync_with_stdio(false);
  cin >> t;
  map<int, pair<int,int>> numbers;
  while(t--) {
    numbers.clear();
    int rowCount[5] = {};
    int colCount[5] = {};
    int primDiag = 0;
    int secDiag = 0;
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        if (i == 2 && j == 2) continue;
        cin >> k;
        numbers.insert(make_pair(k, make_pair(i,j)));
      }
    }
    int n = 0;
    for (int i = 0; i < 75; ++i) {
      cin >> k;
      if (n == 0 && numbers.count(k) > 0) {
        pair<int,int> p = numbers[k];
        if(p.first == p.second) primDiag++;
        if(p.first + p.second == 4) secDiag++;
        rowCount[p.first]++;
        colCount[p.second]++;
        if(isBingo(primDiag, secDiag, rowCount, colCount)) n = i+1;
      }
    }
    cout << "BINGO after " << n << " numbers announced" << endl;
  }
  return 0;
}
