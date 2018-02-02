#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  int a, b, c;
  const int TIME_LIMIT = 5*60*60;
  while(cin >> a >> b, (a|b) != 0) {
    int light[100] = {a, b}, n = 1, answer = -1, total = 0;
    while(cin >> c, n++, c != 0) light[n] = c;
    bool on[100];
    fill(on, on+100, true);
    bool isGreen; 
    sort(light, light+n);
    for (int i = light[0]-5; i <= TIME_LIMIT && answer == -1; i++) {
      for (int j = 0; j < n; ++j) {
        isGreen = (i/light[j])%2==0 && (i%light[j]) < light[j]-5; 
        if (on[j] && !isGreen) total--, on[j] = false;
        else if (!on[j] && isGreen) total++, on[j] = true;
      }
      if (total == 0) answer = i;
    }
    if(answer == -1) cout << "Signals fail to synchronise in 5 hours";
    else cout << 
      setw(2) << setfill('0') << to_string(answer/3600) << ":" << 
      setw(2) << setfill('0') << to_string((answer%3600)/60) << ":" << 
      setw(2) << setfill('0') << to_string((answer%3600)%60);
    cout << endl;   
  }
  return 0;
}
