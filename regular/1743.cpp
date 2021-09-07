/*
 * 存在一个由 n 个不同元素组成的整数数组 nums
 * ，但你已经记不清具体内容。好在你还记得 nums 中的每一对相邻元素。
 * 给你一个二维整数数组 adjacentPairs ，大小为 n - 1 ，其中每个 adjacentPairs[i] =
 * [ui, vi] 表示元素 ui 和 vi 在 nums 中相邻。 题目数据保证所有由元素 nums[i] 和
 * nums[i+1] 组成的相邻元素对都存在于 adjacentPairs 中，存在形式可能是 [nums[i],
 * nums[i+1]] ，也可能是 [nums[i+1], nums[i]] 。这些相邻元素对可以 按任意顺序
 * 出现。 返回 原始数组 nums 。如果存在多种解答，返回 其中任意一个 即可。
 */

#include <vector>
#include <unordered_map>
#include <deque>

using namespace std;
class Solution {
public:
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    vector<int> ret, ret2;
    std::unordered_map<int, int> numTimesMap;
    unordered_map<int, int> pairMap;
    for (auto pair: adjacentPairs) {
      bool isChanged = false; // current pair can only change once when build link relationship
      for (int i = 0; (unsigned)i < pair.size(); ++i) {
        // find head
        if(numTimesMap.find(pair[i]) == numTimesMap.end()) {
          // no find pair[i] in map, insert it
          numTimesMap.insert({pair[i], 1});
        } else {
          ++numTimesMap[pair[i]]; // now the pair[i] occurs twice
        }

        // build link
        if (pairMap.find(pair[i]) != pairMap.end()) {
          if (!isChanged) {
            isChanged = true;
            pairMap[pair[i]] = (i == 0 ? pair[1] : pair[0]);
          }
        } else {
          pairMap.insert({pair[i], i == 0 ? pair[1] : pair[0]});
        }
      }
    }

    int headValue = -1;
    int tailValue = -1;
    bool getHead = false;
    for (auto item: numTimesMap) {
      if (item.second == 1) {
        // its head or tail
        if (!getHead) {
          headValue = item.first;
          getHead = true;
        } else {
          tailValue = item.first;
          break;
        }
      }
    }

    for (int i = 0; (unsigned)i < adjacentPairs.size() + 1; ++i) {
      ret.push_back(headValue);
      if ((unsigned)i < adjacentPairs.size() - 1 &&
          headValue == pairMap[pairMap[headValue]]) {
        break;
      }
      headValue = pairMap[headValue];
    }
    for (int i = 0; (unsigned)i < adjacentPairs.size() + 1; ++i) {
      ret2.push_back(tailValue);
      if ((unsigned)i < adjacentPairs.size() - 1 &&
          tailValue == pairMap[pairMap[tailValue]]) {
        break;
      }
      tailValue = pairMap[tailValue];
    }
    return ret.size() > ret2.size() ? ret : ret2;
  }
};

class Solution2 {
public:
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    vector<int> ret, ret2;
    std::unordered_map<int, int> numTimesMap;
    unordered_map<int, int> pairMap;

    // find head and tail, only occur once
    for (auto pair: adjacentPairs) {
      for (int i = 0; (unsigned)i < pair.size(); ++i) {
        if(numTimesMap.find(pair[i]) == numTimesMap.end()) {
          // no find pair[i] in map, insert it
          numTimesMap.insert({pair[i], 1});
        } else {
          ++numTimesMap[pair[i]]; // now the pair[i] occurs twice
        }
      }
    }

    int headValue = -1;
    int tailValue = -1;
    bool getHead = false;
    for (auto item: numTimesMap) {
      if (item.second == 1) {
        // its head or tail
        if (!getHead) {
          headValue = item.first;
          getHead = true;
        } else {
          tailValue = item.first;
          break;
        }
      }
    }

    // reorder the orgin vector
    vector<bool> visited(adjacentPairs.size(), false);
    for (int i = 0; (unsigned)i < adjacentPairs.size() / 2 + 1; ++i) {
      for (int j = 0; (unsigned)j < adjacentPairs.size(); ++j) {
        if (!visited[j]) {
          // head
          if (adjacentPairs[j][0] == headValue) { // no need reorder this pair
            ret.push_back(headValue);
            headValue = adjacentPairs[j][1];
            visited[j] = true;
          } else if (adjacentPairs[j][1] == headValue) { // reorder, swap
            ret.push_back(headValue);
            headValue = adjacentPairs[j][0];
            visited[j] = true;
          }
          // tail
          if (adjacentPairs[j][1] == tailValue) { // no need reorder this pair
            ret2.push_back(tailValue);
            tailValue = adjacentPairs[j][0];
            visited[j] = true;
          } else if (adjacentPairs[j][0] == tailValue) { // reorder, swap
            ret2.push_back(tailValue);
            tailValue = adjacentPairs[j][1];
            visited[j] = true;
          }
        }
        continue;

        }
    }

    for (auto it = ret2.crbegin(); it != ret2.crend(); ++it) {
      ret.push_back(*it);
    }
    return ret;
  }
};

class Solution3 {
public:
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    vector<int> ret, ret2;
    std::unordered_map<int, int> numTimesMap;
    unordered_map<int, int> pairMap;

    unordered_map<int, deque<int>&> headDequeMap;
    unordered_map<int, deque<int>&> tailDequeMap;

    // find head and tail, only occur once
    for (auto pair: adjacentPairs) {
      for (int i = 0; (unsigned)i < pair.size(); ++i) {


        if(numTimesMap.find(pair[i]) == numTimesMap.end()) {
          // no find pair[i] in map, insert it
          numTimesMap.insert({pair[i], 1});
        } else {
          ++numTimesMap[pair[i]]; // now the pair[i] occurs twice
        }

        if (headDequeMap.find(pair[i]) != headDequeMap.end()) {
          auto newHeadValue = i == 0 ? pair[1] : pair[0];
          headDequeMap[pair[i]].push_front(newHeadValue);
          headDequeMap.insert({newHeadValue, headDequeMap[pair[i]]});
          headDequeMap.erase(pair[i]);
          break;
        }
        if (tailDequeMap.find(pair[i]) != tailDequeMap.end()) {
          auto newTailValue = i == 0 ? pair[1] : pair[0];
          tailDequeMap[pair[i]].push_back(newTailValue);
          tailDequeMap.insert({newTailValue, tailDequeMap[pair[i]]});
          tailDequeMap.erase(pair[i]);
          break;
        }
        if (i == 0) {
          deque<int> tmp;
          tmp.push_front(pair[i]);
          tmp.push_back(pair[i+1]);
          headDequeMap.insert({pair[0], tmp});
          tailDequeMap.insert({pair[1], tmp});
          break;
        }
      }
    }
  }

    int headValue = -1;
    int tailValue = -1;
    bool getHead = false;
    for (auto item: numTimesMap) {
      if (item.second == 1) {
        // its head or tail
        if (!getHead) {
          headValue = item.first;
          getHead = true;
        } else {
          tailValue = item.first;
          break;
        }
      }
    }

    // reorder the orgin vector
    vector<bool> visited(adjacentPairs.size(), false);
    for (int i = 0; (unsigned)i < adjacentPairs.size() / 2 + 1; ++i) {
      for (int j = 0; (unsigned)j < adjacentPairs.size(); ++j) {
        if (!visited[j]) {
          // head
          if (adjacentPairs[j][0] == headValue) { // no need reorder this pair
            ret.push_back(headValue);
            headValue = adjacentPairs[j][1];
            visited[j] = true;
          } else if (adjacentPairs[j][1] == headValue) { // reorder, swap
            ret.push_back(headValue);
            headValue = adjacentPairs[j][0];
            visited[j] = true;
          }
          // tail
          if (adjacentPairs[j][1] == tailValue) { // no need reorder this pair
            ret2.push_back(tailValue);
            tailValue = adjacentPairs[j][0];
            visited[j] = true;
          } else if (adjacentPairs[j][0] == tailValue) { // reorder, swap
            ret2.push_back(tailValue);
            tailValue = adjacentPairs[j][1];
            visited[j] = true;
          }
        }
        continue;

        }
    }

    for (auto it = ret2.crbegin(); it != ret2.crend(); ++it) {
      ret.push_back(*it);
    }
    return ret;
  }
};
