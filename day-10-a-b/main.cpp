#include <bits/stdc++.h>

using namespace std;

long long int result = 0;
long long int resultb = 0;

void count_trails(int row, int col, int n, const vector<string> &mapa, set<pair<int, int>> &peaks, long long int &resultb)
{
  if (mapa[row][col] == n + '0')
  {
    if (n == 9)
    {
      peaks.insert({row, col});
      resultb++;
    }
    else
    {
      count_trails(row + 1, col, n + 1, mapa, peaks, resultb);
      count_trails(row - 1, col, n + 1, mapa, peaks, resultb);
      count_trails(row, col + 1, n + 1, mapa, peaks, resultb);
      count_trails(row, col - 1, n + 1, mapa, peaks, resultb);
    }
  }
}

int main(void)
{
  string line;
  ifstream MyReadFile("input");
  vector<string> mapa;

  mapa.push_back(".............................................................................................................");

  while (getline(MyReadFile, line))
  {
    line = "." + line + ".";
    mapa.push_back(line);
  }
  mapa.push_back(".............................................................................................................");

  for (size_t row = 0; row < mapa.size(); row++)
  {
    for (size_t col = 0; col < mapa[1].length(); col++)
    {
      if (mapa[row][col] == '0')
      {
        set<pair<int, int>> peaks;
        count_trails(row, col, 0, mapa, peaks, resultb);
        result += peaks.size();
      }
    }
  }

  cout << result << endl;
  cout << resultb << endl;
  return 0;
}
