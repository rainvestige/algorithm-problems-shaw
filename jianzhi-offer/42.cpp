#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  void FindMaxIterators(vector<int>& nums, vector<vector<int>::iterator>& maxIts,
      vector<int>::iterator& maxIt) {
    for (auto it = nums.begin(); it != nums.end(); ++it) {
      if (*it == *maxIt) {
        maxIts.push_back(it);
      }
    }
  }

  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums.back();
    }
    if (nums.size() == 2) {
      return max({nums[0], nums[1], nums[0] + nums[1]});
    }

    vector<vector<int>::iterator> maxIts;
    vector<int>::iterator maxIt = max_element(nums.begin(), nums.end());
    FindMaxIterators(nums, maxIts, maxIt);

    int preMaxSum = numeric_limits<int>::min();
    int curMaxSum = 0;
    for (auto maxIt: maxIts) {
      // right max sum
      int curRightSum = 0;
      int maxRightSum = 0; // must be positive
      for (auto it = maxIt + 1; it < nums.end(); ++it) {
        curRightSum += *it;
        if (curRightSum > maxRightSum) {
          maxRightSum = curRightSum;
        }
      }
      int curLeftSum = 0;
      int maxLeftSum = 0;
      for (auto it = maxIt - 1; it >= nums.begin(); --it) {
        curLeftSum += *it;
        if (curLeftSum > maxLeftSum) {
          maxLeftSum = curLeftSum;
        }
      }
      curMaxSum = *maxIt + maxLeftSum + maxRightSum;

      if (curMaxSum > preMaxSum) {
        preMaxSum = curMaxSum;
      }
    }
    return preMaxSum;
  }
};

class Solution1 {
public:

  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    // First element.
    vector<int> dp((int)nums.size(), 0);
    dp[0] = nums[0];
    int maxSum = dp[0];
    for (unsigned i = 1; i < nums.size(); ++i) {
      dp[i] = max(nums[i], dp[i-1] + nums[i]);
      if (dp[i] > maxSum) {
        maxSum = dp[i];
      }
    }
    return maxSum;
  }
};
