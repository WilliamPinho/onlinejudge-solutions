#include<iostream>

using namespace std;

int main() {
  int N, a, b, val;
  bool bitA = true;
  while (cin >> N, N != 0) {
    a = b = 0;
    bitA = true;
    for (int i = 0; i < sizeof(int)*8; i++) {
      if ((N >> i) & 1) {
        if (bitA) {
          a |= 1 << i;
        } else {
          b |= 1 << i;
        }
        bitA = !bitA;
      }
    }
    cout << a << " " << b << endl;
  }

}
