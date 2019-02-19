#include <iostream>
#include <vector>
using namespace std;

void backtrack(string& s, string& t, int i, vector<char>& st, string& res, int k) {

  if (k == t.length() &&  i == s.length()) {
    for (int k = 0; k < res.length(); k++) {
      if (k) cout << " ";
      cout << res[k];
    }
    cout << endl; 
    return;
  }
  if (i < s.length()) {
    res.push_back('i');
    st.push_back(s[i]);
    backtrack(s, t, i+1, st, res, k);
    st.pop_back();
    res.pop_back();
  }
  if (!st.empty() && st.back() == t[k]) {
    res.push_back('o');
    char c = st.back();
    st.pop_back();
    backtrack(s, t, i, st, res, k+1);
    res.pop_back();
    st.push_back(c);
  }
}


int main() {
  string s, t;
  while (cin >> s >> t) {
    vector<char> st;
    string res;
    cout << "[" << endl;
    backtrack(s, t, 0, st, res, 0);
    cout << "]" << endl;
  }
}



