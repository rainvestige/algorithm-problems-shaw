#include <iostream>
#include <climits>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  vector<char> letter{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                      'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  int MinTimes(string& str, int m) {
    // Move operation. Emit operation.
    if (m >= (int)str.size() - 1) {
      return m + str.size();
    }
    int ret = INT_MAX;
    int tmp;
    for (int i = 1; i <= (int)str.size() - m; ++i) {
      // Only count move operation.
      tmp = UseMagicOperationAt(str, i, m);
      if (tmp < ret) {
        ret = tmp;
      }
    }
    return ret + str.size();
  }

  int UseMagicOperationAt(string& str, int index, const int m) {
    int count = 0;
    for (int i = 0; i < (int)str.size() - 1; ++i) {
      count += FigureOutCount(str, i, index, m);
    }
    return count;
  }

  int FigureOutCount(string& str, int i, int index, const int m) {
    // move from str[i] to str[i+1].
    if (i+1 >= index && i+1 < index + m) {
      return 1;
    }
    return min(abs(str[i+1] - str[i]), 26 - abs(str[i+1] - str[i]));
  }

};


int main() {
  string inputString;
  int m;
  cin >> inputString;
  cin >> m;

  Solution a;

  cout << "Result: " << a.MinTimes(inputString, m);
  //cout << inputString << "\t" << m << endl;
  return 0;
}
