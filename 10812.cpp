#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int t;
  long long a, b;
  cin >> t;
  while(t--) {
    cin >> a >> b;
    long long x = (a + b)/2;
    long long y = a - x;
    if(x < 0 || y < 0 || x + y != a || x-y != b) cout << "impossible" << endl;
    else cout << x << " " << y << endl;
  }
  return 0;
}
