
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int result = 0;

vector<string> matrix;

char get_next_letter(char letter)
{
  switch (letter)
  {
  case 'X':
    return 'M';
  case 'M':
    return 'A';
  case 'A':
    return 'S';
  case 'S':
  {
    result++;
  }
  }
  return 0;
}


void find_xmas(int row, int col, char letter, int dir)
{
  if (matrix[row][col] == letter)
  {
    find_xmas(row+(dir-1)/3-1, col+(dir-1)%3-1, get_next_letter(letter),dir);
  }
}

int main(void)
{
  string line;
  ifstream MyReadFile("input");

  int index = -1;
  getline(MyReadFile, line);

  string padding(line.length() + 2, '.');
  matrix.push_back(padding);
  matrix.push_back("." + line + ".");
  while (getline(MyReadFile, line))
  {
    matrix.push_back("." + line + ".");
  }
  MyReadFile.close();

  matrix.push_back(padding);
  int side = matrix.size();
  for (size_t row = 0; row < side; row++)
  {
    for (size_t col = 0; col < side; col++)
    {
      for (size_t dir = 1; dir < 10; dir++)
      {
        find_xmas(row, col, 'X', dir);
      }
      
    }
    
  }
  

  cout << result << endl;
  return 0;
}
