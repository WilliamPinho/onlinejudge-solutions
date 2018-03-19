#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  while(cin >> s, s != "#") {
    cout << (next_permutation(s.begin(), s.end()) ? s : "No Successor") << endl;
  }
  return 0;
}
