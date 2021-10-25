#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:

  int MinNeededInteger(unsigned long long s) {
    if (s == 0) {
      return -1;
    }
    unsigned long long origin = s;
    vector<int> binaryDigit;
    while (s != 0) {
      binaryDigit.push_back(s & 1);
      s = s >> 1;
    }
    return min(NumOfDigitOne(origin),
          NumOfDigitOne(pow(2, binaryDigit.size()) - origin) + 1);
  }

  int NumOfDigitOne(unsigned long long s) {
    if (s == 0) {
      return 0;
    }
    int ret = 0;
    while (s != 0) {
      if (s & 1) {
        ret++;
        //cout << "s = " << s << " ret = " << ret;
      }
      s = s >> 1;
    }
    //cout << "Num =" << s << " #digit one =" << ret << endl;
    return ret;
  }
};

int main() {
  unsigned long long s;
  cin >> s;
  cout << "s = " << s << endl;
  Solution a;
  cout << "Result: " << a.MinNeededInteger(s) << endl;
  return 0;
}
