#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

const int NP = 100, NQ = 9;

struct Team {
  int n;
  int penalty = 0;
  bool solved[NQ] = { 0 };
  int n_solved = 0;
  int incorrect[NQ] = { 0 };
  bool submitted = false;
};

bool compTeams(const Team& a, const Team& b) {
  return (a.n_solved != b.n_solved ? a.n_solved > b.n_solved : (a.penalty != b.penalty ? a.penalty < b.penalty : (a.n < b.n)));
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  int t, time, team, problem;
  char verdict;
  cin >> t;
  string s;
  cin.ignore(2);
  while(t--) {
    Team teams[NP];
    for(int i = 0; i < NP; i++) teams[i].n = i;
    while(getline(cin,s), s != "") {
      stringstream ss(s);
      ss >> team >> problem >> time >> verdict;
      team--, problem--;
      teams[team].submitted = true;
      if(!teams[team].solved[problem]) {
        if(verdict == 'I') teams[team].incorrect[problem]++;
        if(verdict == 'C') teams[team].n_solved++, teams[team].penalty += time + 20*teams[team].incorrect[problem];
        teams[team].solved[problem] = verdict == 'C';
      }
    }
    sort(teams, teams+100, compTeams);
    for(int i = 0; i < 100; ++i) 
      if(teams[i].submitted) 
        cout << teams[i].n+1 << " " << teams[i].n_solved << " " << teams[i].penalty << endl; 
    if(t != 0) cout << endl;
  }
  return 0;
}
