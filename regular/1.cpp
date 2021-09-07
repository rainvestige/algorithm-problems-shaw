/*
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值
 * target  的那 两个 整数，并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 你可以按任意顺序返回答案。
*/
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ret;
    int j;
    for (int i = 0; static_cast<unsigned>(i) < nums.size() - 1; ++i) {
      j = FindRemained(nums, i+1, target - nums[i]);
      if (j != -1) {
        ret.push_back(i);
        ret.push_back(j);
      }
    }
    return ret;
  }

  int FindRemained(vector<int>& nums, int startIndex, int target) {
    for (int i = startIndex; static_cast<unsigned>(i) < nums.size(); ++i) {
      if (nums[i] == target) {
        return i;
      }
    }
    return -1;
  }
};



class Solution2 {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ret;
    unordered_map<int, int> valueIndexMap;
    for (int i = 0; (unsigned)i < nums.size(); ++i) {
      if (valueIndexMap.find(target-nums[i]) != valueIndexMap.end()) {
        ret = vector<int> {i, valueIndexMap[i]};
        break;
      } else {
        valueIndexMap.insert({nums[i], i});
      }
    }
    return ret;
  }
};
