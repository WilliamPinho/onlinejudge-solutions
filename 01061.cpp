#include <iostream>
#include <vector>

using namespace std;

void genChildType(string p1, string p2, vector<string>& answer) {
  vector<string> types;
  if(p1[0] == 'A' || p2[0] == 'A') types.push_back("A");
  if(p1[0] == 'B' || p2[0] == 'B' || p1.size() == 3 || p2.size() == 3) types.push_back("B");
  if(p1.length() == 2 && p2.length() == 2) types.push_back("O");
  if(((p1.length() == 3 || p2.length() == 3) && p1[0] != 'O' && p2[0] != 'O') || types.size() == 3) types.push_back("AB");
  bool hasPos = p1.back() == '+' || p2.back() == '+';
  for(int i = 0; i < types.size(); ++i) {
    if(hasPos) answer.push_back(types[i] + "+");
    answer.push_back(types[i] + "-");
  }
}

void genParentType(string p, string c, vector<string>& answer) {
  if((c[0] == 'O' && (p.size() == 3)) ||(c.size() == 3 && p[0] == 'O')) return;
  vector<string> types;
  if(c[0] == 'O') types.push_back("A"), types.push_back("B"), types.push_back("O");
  else if(c.size() == 3) {
    types.push_back("AB");
    if(p.size() == 3) types.push_back("A"), types.push_back("B");
    else types.push_back(p[0] == 'A' ? "B" : "A");
  } else {
    types.push_back("AB");
    types.push_back(c[0] == 'A' ? "A" : "B");
    if(p.size() == 3 || p[0] == c[0]) types.push_back(c[0] == 'A' ? "B" : "A");
    if(p.size() == 3 || p[0] == c[0])  types.push_back("O");
  }
  bool justPos = p.back() == '-' && c.back() == '+';
  for(int i = 0; i < types.size(); ++i) {
    if(!justPos) answer.push_back(types[i] + "-");
    answer.push_back(types[i] + "+");
  }
}

string types[] = { "A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-" }, p1, p2, c;
int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  int k = 1;
  while(cin >> p1 >> p2 >> c, p1 != "E") {
    vector<string> answer;
    if(c == "?") genChildType(p1, p2, answer);
    else genParentType(p1 != "?" ? p1 : p2, c, answer); 
    string result = answer.size() > 1 ? "{" : "";
    for(int i = 0; i < answer.size(); ++i) {
      result.append(answer[i]);
      if(i != answer.size()-1) result.append(", ");
    }
    if(answer.size() > 1) result.append("}");
    if(answer.size() == 0) result = "IMPOSSIBLE";
    cout << "Case " << k << ": " << (p1 == "?" ? result : p1) << " " << (p2 == "?" ? result : p2) << " " << (c == "?" ? result : c) << endl;
    k++;
  }
  return 0;
}
