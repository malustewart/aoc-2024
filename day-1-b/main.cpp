
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main (void)
{
  list<int> left, right;
  string line;
  ifstream MyReadFile("input");

  while (getline (MyReadFile, line)) {
    int a,b;
    istringstream(line) >> a >> b;
    left.push_back(a);
    right.push_back(b);
  }
  MyReadFile.close();

  left.sort();
  left.unique();
  
  int sum = 0;
  for (auto& e : left) {
    sum += e * count(right.begin(), right.end(), e);
  }

  cout << sum;
  
  return 0;
}
