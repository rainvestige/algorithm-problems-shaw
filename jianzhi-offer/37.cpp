#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
  const string SEP {","};
  const string NULL_NODE {"#"};
  unordered_map<long long ,int> indexValueMap;
  // BFS
  void BFS(TreeNode* root, string& ret) {
    queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
      auto frontNode = queue.front();
      queue.pop();
      if (frontNode) {
        // Process the ret string
        ret += to_string(root->val);
        ret += SEP;
        // update queue, first left, then right.
        queue.push(frontNode->left);
        queue.push(frontNode->right);
      } else {
        ret += NULL_NODE;
        ret += SEP;
      }
    }
  }

  void GetIndexValueMap(TreeNode* root, long long index = 0) {
    if (root) {
      indexValueMap.insert({index, root->val});
      if (root->left) {
        GetIndexValueMap(root->left, 2 * index + 1);
      }
      if (root->right) {
        GetIndexValueMap(root->right, 2 * index + 2);
      }
    }
    return;
  }

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    GetIndexValueMap(root);
    string ret{""};
    if (!root) {
      return ret;
    }
    BFS(root, ret);
    return ret;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data == "") {
      return NULL;
    }
    return DeserializeFromMap();
  }

  TreeNode* DeserializeFromMap(long long index = 0) {
    TreeNode* ret{nullptr};
    if (indexValueMap.find(index) != indexValueMap.end()) {
      TreeNode *root = new TreeNode(indexValueMap[index]);
      root->left = DeserializeFromMap(index * 2 + 1);
      root->right = DeserializeFromMap(index * 2 + 2);
      ret = root;
    }
    return ret;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
