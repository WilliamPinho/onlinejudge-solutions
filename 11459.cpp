#include <iostream>

using namespace std;

int main() {
  int t, a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    int table[100];
    for (int i = 0; i < 100; ++i) table[i] = i;
    int player[a] = {};
    int orig, dest;
    while(b--) {
      cin >> orig >> dest;
      table[orig-1] = dest-1; 
    }
    int dice;
    bool finished = false;
    for (int i = 0; i < c; ++i) {
      cin >> dice;
      if(!finished) {
        player[i%a] = player[i%a] + dice < 99 ? table[player[i%a] + dice] : 99;
        finished = player[i%a] == 99;
      }
    }
    for(int i = 0; i < a; ++i) cout << "Position of player " << i+1 << " is " << player[i]+1 << "." << endl;
  }
}
