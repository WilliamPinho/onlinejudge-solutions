#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  int S, B, l, r;
  while(cin >> S >> B, S != 0 && B != 0) {
    vector<int> left(S), right(S);
    for (int i = 0; i < S; ++i)
      left[i] = i-1, right[i] = i+1;
    left[0] = -1, right[S-1] = -1;
    for (int i = 0; i < B; ++i) {
      cin >> l >> r;
      l--, r--;
      if(left[l] != -1) right[left[l]] = right[r];
      if(right[r] != -1) left[right[r]] = left[l];
      cout << (left[l] != -1 ? to_string(left[l]+1) : "*") << " ";
      cout << (right[r] != -1 ? to_string(right[r]+1) : "*") << endl;
    }
    cout << "-" << endl;
  }
  return 0;
}
