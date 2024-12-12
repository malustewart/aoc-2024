#include <bits/stdc++.h>

using namespace std;

long long int result = 0;
long long int resultb = 0;

int main(void)
{
  string line;
  ifstream MyReadFile("input");
  map<long long int, long long int> stones;

  getline(MyReadFile, line);

  istringstream iss(line);
  long long int a;
  while(iss >> a)
  {
    stones[a]++;;
  }

  for (size_t i = 0; i < 75; i++)
  {
    map<long long int, long long int> stones_copy = stones;
    stones.erase(stones.begin(), stones.end());
    for(auto& [key,val] : stones_copy)
    {
      if (key == 0ll)
      {
        stones[1ll] += val;
        continue;
      }
      auto str = to_string(key);
      auto len = str.length();
      if (len % 2)
      {
        stones[2024ll*key] += val;
      }
      else
      {
        stones[stoi(str.substr(0, len/2))] += val;
        stones[stoi(str.substr(len/2, len/2))] += val;
      }
    }
    long long int r = 0;
    for(auto& [key,val] : stones)
    {
      r += val;
    }
    cout << i << " " << r << "\n===\n\n" << endl;
    for(auto& [key,val] : stones)
    {
      cout << key << " x " << val << "\n";
    }
    cout << endl << endl;
  }
  for(auto& [key,val] : stones)
  {
    result += val;
  }
  cout << result << endl;
  cout << resultb << endl;
  return 0;
}
