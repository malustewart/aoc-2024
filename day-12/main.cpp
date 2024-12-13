#include <bits/stdc++.h>

using namespace std;

long long int result = 0;
long long int resultb = 0;

int count_corners(int r, int c, const vector<string> &m)
{
  char crop = m[r][c];
  bool n, w, s, e, nw, sw, se, ne;
  n = m[r - 1][c] == crop;
  w = m[r][c - 1] == crop;
  s = m[r + 1][c] == crop;
  e = m[r][c + 1] == crop;
  nw = m[r - 1][c - 1] == crop;
  sw = m[r + 1][c - 1] == crop;
  se = m[r + 1][c + 1] == crop;
  ne = m[r - 1][c + 1] == crop;

  int perp = (int)n + (int)s + (int)e + (int)w;
  int diag = (int)nw + (int)sw + (int)ne + (int)se;

  if (perp == 0)
  {
    return 4;
  }
  if (perp == 1)
  {
    return 2;
  }
  if (perp == 2)
  {
    if ((n && s) || (e && w))
    {
      return 0;
    }
    if ((n && w && nw) || (s && w && sw) || (n && e && ne) || (s && e && se))
    {
      return 1;
    }
    else
    {
      return 2;
    }
  }
  if (perp == 3)
  {
    if (!n)
    {
      return 2 - (int)se - (int)sw;
    }
    if (!s)
    {
      return 2 - (int)ne - (int)nw;
    }
    if (!w)
    {
      return 2 - (int)se - (int)ne;
    }
    if (!e)
    {
      return 2 - (int)sw - (int)nw;
    }
  }
  if (perp == 4)
  {
    return 4 - diag;
  }
  return 0;
}

bool get_region(char crop, int row, int col, vector<pair<int, int>> &region, vector<string> &mapa, const vector<string> &mapa2, long int &perim, long int &corners)
{
  if (crop == mapa[row][col])
  {
    region.push_back({row, col});
    mapa[row][col] = '.';
    get_region(crop, row + 1, col, region, mapa, mapa2, perim, corners);
    get_region(crop, row - 1, col, region, mapa, mapa2, perim, corners);
    get_region(crop, row, col + 1, region, mapa, mapa2, perim, corners);
    get_region(crop, row, col - 1, region, mapa, mapa2, perim, corners);

    if (mapa2[row + 1][col] != crop)
      perim++;
    if (mapa2[row - 1][col] != crop)
      perim++;
    if (mapa2[row][col + 1] != crop)
      perim++;
    if (mapa2[row][col - 1] != crop)
      perim++;
    
    corners += count_corners(row, col, mapa2);

    return true;
  }
  return false;
}

int main(void)
{
  string line;
  ifstream MyReadFile("input");

  vector<string> mapa;

  vector<vector<pair<int, int>>> regions;
  vector<long int> perims;
  vector<long int> sides;

  mapa.push_back("....................................................................................................................................................................................................................................................................................");

  while (getline(MyReadFile, line))
  {
    mapa.push_back("." + line + ".");
  }
  mapa.push_back("....................................................................................................................................................................................................................................................................................");
  auto mapa2 = mapa;

  for (size_t row = 1; row < mapa.size() - 1; row++)
  {
    for (size_t col = 1; col < mapa[1].size() - 1; col++)
    {
      vector<pair<int, int>> region;
      long int perim = 0;
      long int corners = 0;
      char crop = mapa[row][col];
      if (crop != '.')
      {
        get_region(crop, row, col, region, mapa, mapa2, perim, corners);
      }
      if (region.size())
      {
        regions.push_back(region);
        perims.push_back(perim);
        sides.push_back(corners);
      }
    }
  }

  // for (auto &&region : regions)
  // {
  //   for (auto &&pos : region)
  //   {
  //     cout << pos.first << " " << pos.second << " -- ";
  //   }
  //   cout << endl << endl;
  // }

  // for (auto &&perim : perims)
  // {
  //   cout << perim << endl;
  // }

  for (size_t i = 0; i < regions.size(); i++)
  {
    result += regions[i].size() * perims[i];
    resultb += regions[i].size() * sides[i];
  }

  cout << result << endl;
  cout << resultb << endl;
  return 0;
}
