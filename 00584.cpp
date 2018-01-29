#include <iostream>
#include <cctype>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  string line;
  int total, frame, roll, i;;
  while(getline(cin, line), line != "Game Over") {
    int k = line.size();
    total = 0, frame = 0, roll = 0;
    for(int i = 0; frame < 10; ++i) {
      if(line[i] == ' ') continue;
      if(line[i] == 'X') {
        total += 10, roll = 2;
        if(i+2 < k) total += (isdigit(line[i+2]) ? line[i+2] - '0' : 10);
        if(i+4 < k) total += (isdigit(line[i+4]) ? line[i+4] - '0' : (line[i+4] == 'X' ? 10 : 10 - line[i+2] + '0'));
      } else if (line[i] == '/') {
        total += (10 - line[i-2] + '0'), roll = 2;
        if(i+2 < k) total += (isdigit(line[i+2]) ? line[i+2] - '0' : 10);
      } else total += (line[i] -'0'), roll++;
      if(roll == 2) roll = 0, frame++;
    }
    cout << total << endl;
  }
}
