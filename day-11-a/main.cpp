#include <bits/stdc++.h>

using namespace std;

long long int result = 0;
long long int resultb = 0;

int main(void)
{
  string line;
  ifstream MyReadFile("input");
  list<long long int> stones;

  getline(MyReadFile, line);

  istringstream iss(line);
  long long int a;
  while(iss >> a)
  {
    stones.push_back(a);
  }

  for (size_t i = 0; i < 25; i++)
  {
    for (auto it = stones.begin(); it != stones.end(); it++)
    {
      if (*it == 0ll)
      {
        *it = 1ll;
        continue;
      }
      auto str = to_string(*it);
      auto len = str.length();
      if (len % 2)
      {
        *it *= 2024ll;
      }
      else
      {
        stones.insert(it, stoi(str.substr(0, len/2)));
        *it = stoi(str.substr(len/2, len/2));
      }
    }
    cout << i << " " << stones.size() << endl;
  }
  result = stones.size();

  cout << result << endl;
  cout << resultb << endl;
  return 0;
}
