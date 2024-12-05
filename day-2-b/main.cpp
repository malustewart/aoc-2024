
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

uint32_t safe = 0;

int is_safe(list<int>& report) {
    for (auto it = report.begin(); it != --report.end();) {
      auto itprev = it++;
      *itprev = *it - *itprev;
    }
    report.pop_back();
    if (report.front()<0)
    for (auto& r : report) {
      r *= -1;
    }
    int i = 0;
    for(auto it = report.begin(); it != report.end(); it++) {
      if (*it<=0 || *it > 3) {
        return i;
      }
      i++;
    }
    return -1;
}

int main (void)
{
  string line;
  ifstream MyReadFile("input");

  int index = -1;
  while (getline (MyReadFile, line)) {
    index ++;
    bool skipped = false;
    list<int> report_i;
    int a;
    istringstream iss(line);
    while(iss >> a) {
      report_i.push_back(a);
    }
    list<int> report(report_i);
    size_t error_pos = is_safe(report);
    cout << index+1 << " " << error_pos << endl;

    if (error_pos == -1) {
      safe++;
      continue;
    }
    list<int> report2(report_i);
    report2.pop_front();
    if (is_safe(report2) == -1) {
      safe++;
      continue;
    }
    list<int> report3(report_i);
    auto iter = report3.begin();
    advance(iter, error_pos + 1);
    report3.erase(iter);
    if (is_safe(report3) == -1) {
      safe++;
      continue;
    }

    list<int> report4(report_i);
    auto iter4 = report4.begin();
    advance(iter4, error_pos);
    report4.erase(iter4);
    if (is_safe(report4) == -1) {
      safe++;
      continue;
    }

  }
  MyReadFile.close();
  cout << safe << endl;
  return 0;
}
