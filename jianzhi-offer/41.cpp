#include <vector>

using namespace std;

class MedianFinder {
public:
  /** initialize your data structure here. */
  vector<int> value;
  MedianFinder() {

  }

  void addNum(int num) {
    if (value.size() == 0) {
      value.push_back(num);
    } else {
      // insert sort, insert `num` in `value`
      auto pos = FindInsertPosition(value, num);
      value.insert(value.begin() + pos, num);
    }
  }

  double findMedian() {
    auto valSize = value.size();
    if (valSize % 2 == 0) {
      return static_cast<double>(value[valSize / 2] + value[valSize / 2 - 1]) / 2.0;
    } else {
      return value[valSize / 2];
    }
  }

  int FindInsertPosition(vector<int>& value, int num) {
    int pos = 0;
    for (int i = 0; i < (int)value.size(); ++i) {
      if (num >= value[i]) {
        pos = i + 1;
      } else {
        break;
      }
    }
    return pos;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
