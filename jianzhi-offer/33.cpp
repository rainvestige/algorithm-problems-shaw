#include <vector>

using namespace std;

class Solution {
public:
  bool verifyPostorder(vector<int>& postorder) {
    int n = postorder.size();
    if (n <= 1) {
      return true;
    }

    int rootVal = postorder.back();
    postorder.pop_back();

    vector<int> left, right;
    bool isRight {false};
    // Divide the BST
    for (const int item: postorder) {
      if (item > rootVal) {
        isRight = true;
      }
      if (!isRight) {
        left.push_back(item);
      } else {
        right.push_back(item);
      }
    }

    // is legal subtree
    if (isLegalBst(left, rootVal, true) && isLegalBst(right, rootVal, false)) {
      return verifyPostorder(left) && verifyPostorder(right);
    } else {
      return false;
    }
  }

  bool isLegalBst(vector<int>& tree, const int rootVal, bool isLeft) {
    bool ret {true};
    if (isLeft) {
      // all value in tree should be less than rootVal
      for (auto item: tree) {
        ret = ret && (item < rootVal);
      }
    } else {
      for (auto item: tree) {
        ret = ret && (item > rootVal);
      }
    }
    return ret;
  }

};
