#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  priority_queue<long> upper;
  priority_queue<long, vector<long>, greater<long>> bottom;
  int i;
  while(cin >> i) {
    upper.push(i);
    bottom.push(upper.top());
    upper.pop();
    if(bottom.size() == upper.size()+2) {
      upper.push(bottom.top());
      bottom.pop();
    }
    cout << (bottom.size() == upper.size() ? (bottom.top() + upper.top())/2 : bottom.top()) << endl;
  }
  return 0;
}
