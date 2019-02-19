#include <iostream>
#include <vector>
using namespace std;

int main() {
  string s;
  int t = 1;
  while (cin >> s, s != "end") {
    vector<vector<char>> v;
    for (char c : s) {
      int pos = -1;
      for (int i = 0; i < v.size(); i++) {
        int cur_d = v[i].back() - c;
        if (cur_d >= 0) {
          pos = i;
          break;
        }
      }
      if (pos != -1) {
        v[pos].push_back(c);
      } else {
        v.push_back(vector<char>());
        v.back().push_back(c);
      }
    }
    cout << "Case " << t++ << ": " << v.size() << endl;  
  }
}



