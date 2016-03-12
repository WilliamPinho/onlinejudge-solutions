#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rep(i,n) for(auto i=0; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

class Graph {
private:
  map<char,vector<char>> adj;
  set<char> V;
  set<char> visited;
  int trees = 0;
public:
  Graph() { };
  void addEdge(char u, char v) {
    this->adj[u].push_back(v);
    this->adj[v].push_back(u);
  }
  void addVertex(char u) { this->V.emplace(u); }
  void cc() {
    for(auto it = this->V.begin(); it != this->V.end(); ++it) {
      if(this->adj.count(*it) > 0 && this->visited.count(*it) <= 0) {
	this->dfs(*it);
	++trees;
      }
    }
  }
  void dfs(char u) {
    this->visited.emplace(u);
    vector<char> neighbours(this->adj[u]);
    for(int i = 0; i < neighbours.size(); ++i)
      if(visited.count(neighbours[i]) <= 0)
	this->dfs(neighbours[i]);
  }
  void print_cc() {
    cout << "There are " << trees << " tree(s) and " << this->V.size() - this->adj.size() << " acorn(s)." << endl;
  }
};

int main() {
  int t;
  cin >> t;
  string line;
  while(t>0) {
    bool end_descrip = false;
    Graph G;
    while(!end_descrip) {
      cin >> line;
      if(line[0] == '*') {
	cin >> line;
	for(int i = 0; i < line.size(); i+=2) G.addVertex(line[i]); 
	end_descrip = true;
      } else {
	G.addEdge(line[1],line[3]);
      }
    }
    G.cc();
    G.print_cc();
    t--;
  }
  return 0;
}

