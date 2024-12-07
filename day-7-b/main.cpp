
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int result = 0;
long long int errors = 0;

vector<vector<int>> mapa;
vector<vector<int>> mapavisitado;
int guard_x, guard_y, guard_dir;



bool can_create(vector<long int>& ops, int end, long int res)
{
  if (end == 1)
  {
    return res == ops[0];
  }
  else if (can_create(ops, end-1, res - ops[end-1]))
  {
    return true;
  }
  else if ((res % ops[end-1]) == 0 && can_create(ops, end-1, res / ops[end-1]))
  {
    return true;
  } 
  else
  {
    string sres = to_string(res);
    string sops = to_string(ops[end-1]);
    if(sres.length() < sops.length())
    {
      return false;
    }
    string sres_a = sres.substr(0, sres.length() - sops.length()); //can create
    string sres_b = sres.substr(sres.length() - sops.length(), sres.length()); // match sops
    if (sres_a != "" && sops == sres_b && can_create(ops, end-1, stoull(sres_a)))
    {
      return true;
    }
  }
  return false;
}

int main(void)
{
  string line;
  ifstream MyReadFile("input");

  while (getline(MyReadFile, line))
  {
    istringstream iss(line);
    long long int res, a;
    iss >> res;
    vector<long int>opline;
    while (iss>>a)
    {
      opline.push_back(a);
    }
    cout << line << endl;
    if(can_create(opline, opline.size(), res))
    {
      cout << "XXXXXXXXXXX" << endl;
      result += res;
    }
  }

  cout << result << endl;
  return 0;
}
