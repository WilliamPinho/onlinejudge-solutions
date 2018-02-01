#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef multimap<string,string>::iterator mmap_iter;

bool isBlank(string& s) { 
  return s.size() == 0;
}
bool comparePair (pair<string,string> p1 ,pair<string,string> p2) {
  int ans = p1.first.compare(p2.first);
  return (ans == 0 ? p1.second.compare(p2.second) < 0 : ans < 0);
}

int main() {
  ios::sync_with_stdio(false);
  int t;
  string line;
  cin >> t;
  getline(cin,line);
  getline(cin,line);
  while(t--) {
    multimap<string,string> anagrams;
    while(getline(cin,line), !isBlank(line)) {
      string key;
      for (int i = 0; i < line.size(); ++i) if(line[i] != ' ') key.push_back(line[i]);
      sort(key.begin(), key.end());
      anagrams.emplace(key, line);
    }
    vector<pair<string,string>> pairs;
    mmap_iter g_it;
    for(mmap_iter it = anagrams.begin(); it != anagrams.end(); it = g_it) {
      string key = it->first;
      pair<mmap_iter,mmap_iter> range = anagrams.equal_range(key);
      for(g_it = range.first; g_it != prev(range.second); ++g_it) {
        for(mmap_iter o_it = next(g_it); o_it != range.second; o_it++) {
          string s1(g_it->second), s2(o_it->second);
          if(s1.compare(s2) == 0) continue;
          if(s1.compare(s2) < 0) pairs.push_back(make_pair(s1,s2));
          else pairs.push_back(make_pair(s2,s1));
        }
      }
      g_it++;
    }
    sort(pairs.begin(), pairs.end(), comparePair);
    for (int i = 0; i < pairs.size(); ++i)
      cout << pairs[i].first << " = " << pairs[i].second << endl;
    if(t != 0) cout << endl;
  }
  return 0;
}
