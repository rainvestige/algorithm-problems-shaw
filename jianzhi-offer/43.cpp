#include <iostream>

class Solution {
public:
  int *dp_; // Count index's one digits

  int countDigitOne(int n) {
    int ret = 0;

    CreateDP(n);

    for (int i = 1; i <= n; ++i) {
      ret += dp_[i];
    }

    delete[] dp_;
    return ret;
  }

  void CreateDP(int num) {
    dp_ = new int[num + 1];
    // Base items. [0-9]
    for (int i = 0; i < 10; ++i) {
      if (i == 1) {
        dp_[i] = 1;
      } else {
        dp_[i] = 0;
      }
    }
    for (int i = 10; i <= num; ++i) {
      dp_[i] = dp_[i / 10] + dp_[i % 10];
    }
  }

};

int main() {
  Solution A;
  std::cout << A.countDigitOne(824883294);

  return 0;
}
