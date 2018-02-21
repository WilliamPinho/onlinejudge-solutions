#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
  string hour, min;
  while(getline(cin,hour,':')) {
    cin >> min;
    float h = stoi(hour), m = stoi(min);
    if(h == 0 && m == 0) return 0;
    float alpha = 6*m, beta = 30*h + m/2;
    float diff = abs(alpha-beta);
    cout << fixed << setprecision(3) << (diff > 180 ? 360-diff : diff) << endl;
  }
  return 0;
}
