
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int result = 0;
bool _do = true;

int main (void)
{
  string line;
  ifstream MyReadFile("input");

  int index = -1;
  while (getline (MyReadFile, line)) {
    regex r("mul\\([0-9]{1,3},[0-9]{1,3}\\)|do\\(\\)|don't\\(\\)");
    auto muls_begin = sregex_iterator(line.begin(), line.end(), r);
    auto muls_end = sregex_iterator();
    for (auto it = muls_begin; it != muls_end; it++)
    {
      cout << (*it).str() << endl;
      char c = (*it).str()[2];
      if (c == '(')
      {
        _do = true;
      }
      else if (c == 'n')
      {
        _do = false;
      }
      else if(_do)
      {
        regex r_f("\\([0-9]{1,3},");
        auto first_begin = sregex_iterator((*it).str().begin(), (*it).str().end(), r_f);
        auto first = (*first_begin).str();
        auto first_int = stoi(first.substr(1, first.size()-2));
        regex r_s(",[0-9]{1,3}\\)");
        auto second_begin = sregex_iterator((*it).str().begin(), (*it).str().end(), r_s);
        auto second = (*second_begin).str();
        auto second_int = stoi(second.substr(1, second.size()-2));
        result += first_int * second_int;
      }
    }
  }
  MyReadFile.close();
  cout << result << endl;
  return 0;
}
