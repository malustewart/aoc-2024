
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int result = -1;

vector<vector<int>> mapa;
vector<vector<int>> mapavisitado;
int orig_x, orig_y, orig_dir, guard_x, guard_y, guard_dir;

int main(void)
{
  string line;
  ifstream MyReadFile("input");

  int y = 1;
  vector<int> ml(200, -1);
  vector<int> libre(200, 0);
  mapa.push_back(ml);
  mapavisitado.push_back(libre);
  while (getline(MyReadFile, line))
  {
    vector<int> mapalinea;
    mapalinea.push_back(-1);
    int x = 1;
    for (char c : line)
    {
      if (c == '#')
        mapalinea.push_back(1);
      else
        mapalinea.push_back(0);

      if (c == '^')
      {
        orig_dir = guard_dir = 0;
        orig_x = guard_x = x;
        orig_y = guard_y = y;
      }
      if (c == '>')
      {
        orig_dir = guard_dir = 1;
        orig_x = guard_x = x;
        orig_y = guard_y = y;
      }
      if (c == 'v')
      {
        orig_dir = guard_dir = 2;
        orig_x = guard_x = x;
        orig_y = guard_y = y;
      }
      if (c == '<')
      {
        orig_dir = guard_dir = 3;
        orig_x = guard_x = x;
        orig_y = guard_y = y;
      }
      x++;
    }
    mapalinea.push_back(-1);
    mapa.push_back(mapalinea);
    mapavisitado.push_back(libre);
    y++;
  }
  mapa.push_back(ml);
  mapavisitado.push_back(libre);

  while (1)
  {
    int new_guard_x = guard_x;
    int new_guard_y = guard_y;

    switch (guard_dir)
    {
    case 0:
      new_guard_y--;
      break;
    case 1:
      new_guard_x++;
      break;
    case 2:
      new_guard_y++;
      break;
    case 3:
      new_guard_x--;
      break;
    }
    if (mapa[new_guard_y][new_guard_x] == 1)
    {
      guard_dir = (guard_dir + 1) % 4;
    }
    else
    {
      guard_x = new_guard_x;
      guard_y = new_guard_y;
      if (mapavisitado[guard_y][guard_x] == 0)
      {
        mapavisitado[guard_y][guard_x] = 1;
      }
    }

    if (mapa[new_guard_y][new_guard_x] == -1)
    {
      break;
    }
  }

  int i = 0;
  for (auto &filamapa : mapa)
  {
    int j = 0;
    for (auto &pos : filamapa)
    {
      if (mapavisitado[i][j])
      {
        pos = 1;
        array<array<array<int, 5>, 200>, 200> mapavisitado2 = {0};
        guard_x = orig_x;
        guard_y = orig_y;
        guard_dir = orig_dir;
        // cout << "============" << endl;
        // cout << i << ' ' << j << endl;
        // cout << "============" << endl;

        while (1)
        {
          // cout << guard_y << " " << guard_x << " " << guard_dir << endl;
          int new_guard_x = guard_x;
          int new_guard_y = guard_y;

          switch (guard_dir)
          {
          case 0:
            new_guard_y--;
            break;
          case 1:
            new_guard_x++;
            break;
          case 2:
            new_guard_y++;
            break;
          case 3:
            new_guard_x--;
            break;
          }
          if (mapa[new_guard_y][new_guard_x] == 1)
          {
            guard_dir = (guard_dir + 1) % 4;
          }
          else
          {
            guard_x = new_guard_x;
            guard_y = new_guard_y;
            if (mapavisitado2[guard_y][guard_x][guard_dir] == 0)
            {
              mapavisitado2[guard_y][guard_x][guard_dir] = 1;
            }
            else if (mapavisitado2[new_guard_y][new_guard_x][guard_dir] == 1)
            {
              result++;
              break;
            }
          }

          if (mapa[new_guard_y][new_guard_x] == -1)
          {
            break;
          }
        }

        pos = 0;
      }
      j++;

    }
    i++;
  }

  cout << result << endl;
  return 0;
}
