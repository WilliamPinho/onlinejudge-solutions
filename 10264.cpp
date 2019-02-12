#include<iostream>

using namespace std;

bool is_neighbor(int i, int j) {
  int d = i ^ j;
  return (d != 0 && (d&(d-1)) == 0);    
}

int main() {
  ios::sync_with_stdio(false);
  int N;
  while (cin >> N) {
    int max = 1 << N, x;
    int v[max] = {};
    for (int i = 0; i < max; i++) {
      cin >> x;
      for (int j = 0; j < max; j++) {
        if (is_neighbor(i,j)) {
          v[j] += x;
        }
      }
    }

    int answer = 0;
    for (int i = 0; i < max; i++) {
      for (int j = 0; j < max; j++) {
        if (is_neighbor(i,j) && v[i] + v[j] > answer) {
          answer = v[i] + v[j];
        }
      }
    }
    cout << answer << endl;
  }
}

