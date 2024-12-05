
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int result = 0;

map<int, set<int>> ordering;

void print_vec(vector<int> &v)
{
  for (auto e : v)
  {
    cout << e << ' ';
  }
  cout << endl;
}

int main(void)
{
  string line;
  ifstream MyReadFile("input");

  while (getline(MyReadFile, line))
  {
    if (line == "")
      break;
    istringstream iss(line);
    int first, second;
    iss >> first;
    iss >> second;
    ordering[first].insert(second);
  }

  while (getline(MyReadFile, line))
  {
    istringstream iss(line);
    int a;
    set<int> pattern;
    vector<int> patternvec;
    bool ok = true;
    while (iss >> a)
    {
      set<int> &forbidden = ordering[a];
      vector<int> inter;
      set_intersection(pattern.begin(), pattern.end(), forbidden.begin(), forbidden.end(), back_inserter(inter));
      ok = ok && (inter.size() == 0);
      pattern.insert(a);
      patternvec.push_back(a);
    }
    if (!ok)
    {
      print_vec(patternvec);
      sort(patternvec.begin(), patternvec.end(),
           [](const int &a, const int &b)
           { return (bool)ordering[a].count(b); });
      result += patternvec[patternvec.size() / 2];
    }
  }
  MyReadFile.close();

  cout << result << endl;
  return 0;
}
