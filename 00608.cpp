#include <iostream>
#include <cmath>

using namespace std;

int level[12];
bool even[12], appeared[12];
string leftSide, rightSide, status;

inline void update(bool isLeft, int pos) {
  appeared[pos] = true;
  if(status == "even") even[pos] = true;
  if(even[pos]) return;
  level[pos] += (isLeft && status == "up") || (!isLeft && status == "down") ? 1 : -1;
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  int n, ans;
  cin >> n;
  while(n--) {
    for (int i = 0; i < 12; ++i) level[i] = 0, even[i] = false, appeared[i] = false;    
    for (int i = 0; i < 3; ++i) {
      cin >> leftSide >> rightSide >> status;
      for (int j = 0; j < leftSide.size(); ++j) update(true, leftSide[j] - 'A'), update(false, rightSide[j] - 'A');
    }
    int max = 0;
    for (int i = 0; i < 12; ++i) if(!appeared[i]) even[i] = true;
    for (int i = 0; i < 12; ++i) if(abs(level[i]) > abs(max) && !even[i]) max = level[i], ans = i;
    cout << (char)('A' + ans) << " is the counterfeit coin and it is " << (max < 0 ? "light" : "heavy") << "." << endl;
  }  
  return 0;
}
