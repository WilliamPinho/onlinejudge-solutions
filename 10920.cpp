#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  long x, y, sz, p;
  while(cin >> sz >> p, sz != 0 && p != 0) {
    x = y = ((sz+1)>>1);
    long steps = 1, i = 0;
    int dir[2] = {1,0};
    bool repeatedStep = false;
    while (i < p-1) { 
      swap(dir[0], dir[1]);
      dir[0] *= -1;
      x += steps*dir[0];
      y += steps*dir[1];
      i+=steps;
      if(repeatedStep) {
        steps++;
        repeatedStep = false;
      } else repeatedStep = true;
    }
    steps = i - p + 1;
    x -= steps*dir[0];
    y -= steps*dir[1];
    cout << "Line = " << y << ", column = " << x << "." << endl;
  }
  return 0;
}
