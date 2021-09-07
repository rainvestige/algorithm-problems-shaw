#include <vector>
#include <string>
#include <algorithm>
#include <iostream>


using namespace std;

class Solution {
public:
  vector<string> charVec;

  vector<string> permutation(string s) {
    vector<string> ret;
    if (s == "") {
      return ret;
    }

    SplitStrIntoChar(s);
    string tmp{""};
    vector<bool> visited(charVec.size(), false);
    for (unsigned int i = 0; i < charVec.size(); ++i) {
      DFS(charVec, i, ret, tmp, visited);
    }
    std::sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    return ret;
  }


  void DFS(vector<string>& strVec, int index, vector<string>& ret, string tmp,
           vector<bool> visited) {
    //
    if (visited[index]) {
      return;
    }
    // mark current index visited
    visited[index] = true;
    tmp += strVec[index];
    // terminate condition: all visited
    if (std::count(visited.begin(), visited.end(), false) == 0) {
      ret.push_back(tmp);
      return;
    }

    for (unsigned int i = 0; i < strVec.size(); ++i) {
      DFS(strVec, i, ret, tmp, visited);
    }
  }

  void SplitStrIntoChar(string& s) {
    for (auto ch: s) {
      charVec.push_back(string{ch});
    }
  }
};

class Solution1 {
public:
  vector<string> charVec;

  vector<string> permutation(string s) {
    vector<string> ret;
    if (s == "") {
      return ret;
    }

    SplitStrIntoChar(s);
    string tmp{""};
    for (const auto ch: charVec) {
      DFS(charVec, ch, ret, tmp);
    }
    return ret;
  }

  void DFS(vector<string>& strVec, string ch, vector<string>& ret, string tmp) {
    tmp += ch;
    // terminate condition
    if (strVec.size() == 1) {
      ret.push_back(tmp);
      return;
    }

    vector<string> remainedCharVec(charVec);
    // exclude self
    auto it = find(remainedCharVec.begin(), remainedCharVec.end(), ch);
    if (it != remainedCharVec.end()) {
      remainedCharVec.erase(it);
    }

    for (auto item: remainedCharVec) {
      DFS(remainedCharVec, item,  ret, tmp);
    }
  }

  void SplitStrIntoChar(string& s) {
    for (auto ch: s) {
      charVec.push_back(string{ch});
    }
  }
};
