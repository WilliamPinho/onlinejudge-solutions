#include <iostream>
#include <list>

using namespace std;

void place(string& w, list<string>& l, bool start) {
  if (start) {
    l.push_front(w);
  } else {
    l.push_back(w);
  }
}

int main() {
  string s;
  while (cin >> s) {
    list<string> l;
    bool start = true;
    string w;
    for (auto c : s) {
      if (c == '[' || c == ']') {
        place(w, l, start);
        start = c == '[' ? true : false;
        w.clear();
      } else {
        w.push_back(c);
      }
    }
    place(w,l,start);
    string answer;
    for (string str : l) {
      answer.append(str);
    }
    cout << answer << endl;
  }
}
