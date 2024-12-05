
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int result = 0;

vector<string> matrix;

void check_x(int row, int col, int _1, int _3, int _5, int _7, int _9)
{
  if (matrix[row][col] == _1 && matrix[row][col + 2] == _3 && matrix[row + 1][col + 1] == _5 && matrix[row + 2][col] == _7 && matrix[row + 2][col + 2] == _9)
  {
    result++;
  }
}

int main(void)
{
  string line;
  ifstream MyReadFile("input");

  int index = -1;
  getline(MyReadFile, line);

  string padding(line.length() + 4, '.');
  matrix.push_back(padding);
  matrix.push_back(".." + line + "..");
  while (getline(MyReadFile, line))
  {
    matrix.push_back(".." + line + "..");
  }
  MyReadFile.close();

  matrix.push_back(padding);
  matrix.push_back(padding);
  int side = matrix.size();
  for (size_t row = 0; row < side; row++)
  {
    for (size_t col = 0; col < side; col++)
    {
      check_x(row, col, 'M', 'M', 'A', 'S', 'S');
      check_x(row, col, 'M', 'S', 'A', 'M', 'S');
      check_x(row, col, 'S', 'S', 'A', 'M', 'M');
      check_x(row, col, 'S', 'M', 'A', 'S', 'M');
    }
  }
  cout << result << endl;
  return 0;
}
