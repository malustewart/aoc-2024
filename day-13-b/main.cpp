#include <bits/stdc++.h>

using namespace std;

long long int result = 0;

struct Button
{
  int x_offset;
  int y_offset;
};

struct Prize
{
  int x;
  int y;
};

int main()
{

  // Variables to store the parsed data
  vector<pair<int, int>> buttonsa;
  vector<pair<int, int>> buttonsb;
  vector<pair<int, int>> prizes;

  ifstream ifs("input");
  std::string linea, lineb, linep, _;

  while (getline(ifs, linea) && getline(ifs, lineb) && getline(ifs, linep))
  {
    getline(ifs, _);
    string button_name;
    int x_offset = 0, y_offset = 0;

    regex pattern(R"(Button\s+(\w):\s+X\+(\d+),\s+Y\+(\d+))");
    smatch match;

    // Match the line against the regex
    if (regex_match(linea, match, pattern))
    {
      button_name = match[1].str();
      x_offset = std::stoi(match[2].str());
      y_offset = std::stoi(match[3].str());
    }

    pair<long int, long int> buttona;
    buttona.first = x_offset;
    buttona.second = y_offset;
    buttonsa.push_back(buttona);

    // Match the line against the regex
    if (regex_match(lineb, match, pattern))
    {
      button_name = match[1].str();
      x_offset = std::stoi(match[2].str());
      y_offset = std::stoi(match[3].str());
    }

    pair<long int, long int> buttonb;
    buttonb.first = x_offset;
    buttonb.second = y_offset;

    buttonsb.push_back(buttonb);

    int x = 0, y = 0;

    // Regular expression to match the line
    std::regex patternp(R"(Prize:\s+X=(\d+),\s+Y=(\d+))");

    // Match the line against the regex
    if (std::regex_match(linep, match, patternp))
    {
      x = std::stoi(match[1].str());
      y = std::stoi(match[2].str());
    }

    pair<long int, long int> prize;
    prize.first = x + 10000000000000;
    prize.second = y + 10000000000000;
    prizes.push_back(prize);
  }

  for (size_t i = 0; i < buttonsa.size(); i++)
  {
    unsigned long int ax = buttonsa[i].first;
    unsigned long int ay = buttonsa[i].second;
    unsigned long int bx = buttonsb[i].first;
    unsigned long int by = buttonsb[i].second;
    unsigned long int px = prizes[i].first;
    unsigned long int py = prizes[i].second;
    unsigned long int b_num = px * ay - py * ax;
    unsigned long int b_den = bx * ay - by * ax;

    if (b_num % b_den)
    {
      continue;
    }
    unsigned long int b = b_num / b_den;
    unsigned long int a_num = px - b * bx;
    unsigned long int a_den = ax;
    if (a_num % a_den)
    {
      continue;
    }
    long int a = a_num / a_den;

    result += 3 * a + b;
  }

  cout << result << endl;
}