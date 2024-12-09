
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int result = 0;

typedef pair<int, int> pos_t;

int main(void)
{
  vector<string> mapa;
  map<char, set<pair<int, int>>> antenas;
  set<pair<int, int>> antinodos;
  string line;
  ifstream MyReadFile("input");
  int r = 0;
  int c = 0;
  while (getline(MyReadFile, line))
  {
    mapa.push_back(line);
    c = -1;
    for (char ch : line)
    {
      c++;
      if (ch == '.' || ch == '#')
        continue;
      pos_t p = {r, c};
      antenas[ch].insert(p);
    }
    r++;
  }
  for (auto [types, antenas_] : antenas)
  {
    for (auto antena1 : antenas_)
    {
      for (auto antena2 : antenas_)
      {
        if (antena1.first == antena2.first && antena1.second == antena2.second)
          continue;
        auto antmin = (antena1.first < antena2.first) ? antena1 : antena2;
        auto antmax = (antena1.first < antena2.first) ? antena2 : antena1;

        int rowmin = antmin.first;
        int rowmax = antmax.first;
        int colmin = antmin.second;
        int colmax = antmax.second;

        antinodos.insert({rowmin - (rowmax - rowmin), colmin - (colmax - colmin)});
        antinodos.insert({rowmax + (rowmax - rowmin), colmax + (colmax - colmin)});
      }
    }
  }

  for (auto &antinodo : antinodos)
  {
    cout << antinodo.first << " " << antinodo.second << endl;
  }
  result = count_if(antinodos.begin(), antinodos.end(), [=](pos_t p)
           { return p.first < r && p.first >= 0 && p.second >= 0 && p.second < r; });
  cout << result << endl;
  return 0;
}
