#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  while (cin >> N, N != 0) {
    while (true) {
      int start = 1, next;
      vector<int> v;
      bool can = true;
      for (int i = 0; i < N; i++) {
        cin >> next;
        if (next == 0) break;
        while ((v.empty() || v.back() != next) && start != N+1 && start != next) {
          v.push_back(start++);
        }
        if (!v.empty() && v.back() == next) {
          v.pop_back();
        } else if (start != next) {
          can = false;
        } else {
          start++;
        }
      }

      if (next == 0) {
        cout << endl;
        break;
      }

      cout << (can ? "Yes" : "No") << endl;
    }
  }
}
