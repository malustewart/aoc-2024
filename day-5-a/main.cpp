
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int result = 0;

map<int, set<int>> ordering;

int main(void)
{
  string line;
  ifstream MyReadFile("input");

  while (getline(MyReadFile, line))
  {
    if (line == "") break;
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
    while (iss>>a)
    {
      if(ok)
      {
        set<int> &forbidden = ordering[a];
        vector<int> inter;
        set_intersection(pattern.begin(), pattern.end(), forbidden.begin(), forbidden.end(), back_inserter(inter));
        ok = (inter.size() == 0);
        pattern.insert(a);
        patternvec.push_back(a);
      }
    }
    if(ok)
    {
      result += patternvec[patternvec.size()/2];
    }

  }
  MyReadFile.close();

  cout << result << endl;
  return 0;
}
