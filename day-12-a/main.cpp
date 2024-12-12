#include <bits/stdc++.h>

using namespace std;

long long int result = 0;
long long int resultb = 0;

bool get_region(char crop, int row, int col, vector<pair<int,int>>& region, vector<string>& mapa, const vector<string>& mapa2, long int& perim)
{
  if (crop == mapa[row][col])
  {
    region.push_back({row,col});
    mapa[row][col] = '.';
    get_region(crop, row+1, col, region, mapa, mapa2, perim);
    get_region(crop, row-1, col, region, mapa, mapa2, perim);
    get_region(crop, row, col+1, region, mapa, mapa2, perim);
    get_region(crop, row, col-1, region, mapa, mapa2, perim);

    if (mapa2[row+1][col] != crop) perim++;
    if (mapa2[row-1][col] != crop) perim++;
    if (mapa2[row][col+1] != crop) perim++;
    if (mapa2[row][col-1] != crop) perim++;
    
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
  vector<long int> areas;
  vector<long int> perims;

  mapa.push_back("....................................................................................................................................................................................................................................................................................");

  while(getline(MyReadFile, line))
  {
    mapa.push_back("." + line + ".");
  }
  mapa.push_back("....................................................................................................................................................................................................................................................................................");


  auto mapa2 = mapa;

  for (size_t row = 1; row < mapa.size()-1; row++)
  {
    for (size_t col = 1; col < mapa[1].size()-1; col++)
    {
      vector<pair<int, int>> region;
      long int perim = 0;
      char crop = mapa[row][col];
      if (crop != '.')
      {
        get_region(crop, row, col, region, mapa, mapa2, perim);
      }
      if (region.size())
      {
        regions.push_back(region);
        perims.push_back(perim);
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
    result += regions[i].size()*perims[i];
  }
  

  cout << result << endl;
  cout << resultb << endl;
  return 0;
}
