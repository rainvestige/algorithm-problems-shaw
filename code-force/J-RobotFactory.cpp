#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  unordered_map<int, vector<char>> numDirectionMap = {
    {0, {'u', 'r', 'd', 'l'}},
    {1, {'u', 'r', 'd'}},
    {2, {'u', 'r', 'l'}},
    {3, {'u', 'r'}},
    {4, {'u', 'd', 'l'}},
    {5, {'u', 'd'}},
    {6, {'u', 'l'}},
    {7, {'u'}},
    {8, {'r', 'd', 'l'}},
    {9, {'r', 'd'}},
    {10, {'r', 'l'}},
    {11, {'r'}},
    {12, {'d', 'l'}},
    {13, {'d'}},
    {14, {'l'}},
    {15, {}},
  };

  int numRows;
  int numCols;
public:
  Solution(int nRows, int nCols): numRows(nRows), numCols(nCols)
  {
    //cout << "The num of rows: " << numRows << endl;
    //cout << "The num of cols: " << numCols << endl;
  }

  void DisplayVector(vector<int>& v)
  {
    for (const auto& it : v) {
      cout << it << " ";
    }
    cout << endl;
  }

  void GetOrderedRoomSize(vector<vector<int>>& tiles)
  {
    vector<int> result;
    int size = 0;
    vector<vector<int>> visited(numRows, vector<int>(numCols, 0));
    for (int i = 0; i < numRows; ++i) {
      for (int j = 0; j < numCols; ++j) {
        if (visited[i][j] == 0) { // -1 means the tiles[i][j] has been visited.
          size = 0;
          dfs(tiles, size, i, j, visited);
          result.push_back(size);
        }
      }
    }
    sort(result.begin(), result.end(), greater<int>());
    DisplayVector(result);
  }

  void dfs(vector<vector<int>>& tiles, int& size, int i, int j,
      vector<vector<int>>& visited)
  {
    if (i < 0 || i >= numRows || j < 0 || j >= numCols || visited[i][j] == 1) {
      return;
    }
    ++size; // current tiles visited.
    visited[i][j] = 1;
    for (auto& direct : numDirectionMap[tiles[i][j]]) {
      switch (direct) {
        case 'u':
          dfs(tiles, size, i-1, j, visited);
          break;
        case 'r':
          dfs(tiles, size, i, j+1, visited);
          break;
        case 'd':
          dfs(tiles, size, i+1, j, visited);
          break;
        case 'l':
          dfs(tiles, size, i, j-1, visited);
          break;
        default:
          cout << "Something error happen!" << endl;
          break;
      }
    }
  }


};

int main()
{
  int N,M;
  cin >> N >> M;
  vector<vector<int>> tiles(N, vector<int>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> tiles[i][j];
      //cout << tiles[i][j] << " ";
    }
    //cout << endl;
  }

  Solution s(N, M);
  s.GetOrderedRoomSize(tiles);
  return 0;
}
