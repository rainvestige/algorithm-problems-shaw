#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  unordered_map<int, int> valueCountMap;
  int majorityElement(vector<int>& nums) {
    int ret;
    for (auto num: nums) {
      if (valueCountMap.find(num) == valueCountMap.end()) {
        valueCountMap.insert({num, 1});
      } else {
        ++valueCountMap[num];
      }
    }
    int halfSize = nums.size() / 2;
    for (auto keyValue: valueCountMap) {
      if (keyValue.second > halfSize) {
        ret = keyValue.first;
        break;
      }
    }
    return ret;
  }
};
