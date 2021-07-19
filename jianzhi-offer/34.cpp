#include <vector>

using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<vector<int>> pathSum(TreeNode* root, int target) {
    vector<vector<int>> ret;
    if (root == nullptr) {
      return ret;
    }
    vector<int> tmpVec;
    int tmpSum = 0;
    dfs(root, target, ret, tmpSum, tmpVec);
    return ret;
  }

  void dfs(TreeNode *node, const int target, vector<vector<int>> &ret,
           int tmpSum, vector<int> tmpVec) {
    tmpSum += node->val; // update path sum
    tmpVec.push_back(node->val);
    int savedSum{tmpSum};
    vector<int> savedVec{tmpVec};
    // terminate condition
    if (node->left == nullptr && node->right == nullptr) {
      if (tmpSum == target) {
        ret.emplace_back(tmpVec);
      }
      return;
    }
    if (node->left != nullptr) {
      dfs(node->left, target, ret, tmpSum, tmpVec);
    }
    if (node->right != nullptr) {
      dfs(node->right, target, ret, savedSum, savedVec);
    }
  }
};
