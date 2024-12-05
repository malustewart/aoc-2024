
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

uint32_t safe = 0;

int main (void)
{
  string line;
  ifstream MyReadFile("input");

  while (getline (MyReadFile, line)) {
    vector<int> report;
    int a;
    istringstream iss(line);
    while(iss >> a) {
      report.push_back(a);
    }
    for (int i = 0; i < report.size() - 1; i++) {
      report[i] = report[i+1] - report[i];
    }
    report[report.size()-1] = report[report.size()-2];
    if (report [0]>0) {
      auto one = count(report.begin(), report.end(), 1);
      auto two = count(report.begin(), report.end(), 2);
      auto three = count(report.begin(), report.end(), 3);
      if(one + two + three == report.size()) {safe++;}
    } else {
      auto one = count(report.begin(), report.end(), -1);
      auto two = count(report.begin(), report.end(), -2);
      auto three = count(report.begin(), report.end(), -3);
      if(one + two + three == report.size()) {safe++;}
    }
  }
  MyReadFile.close();
  cout << safe << endl;
  return 0;
}
