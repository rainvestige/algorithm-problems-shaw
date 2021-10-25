#include <iostream>
#include <vector>

using namespace std;
void DisplayVector(vector<char>& data);
int GetMaxScore(vector<char>& data, vector<char>* readyEmitBalls, int M);

int main() {

  // Prepare the input.
  int L1, L2, M;
  cin >> L1 >> L2 >> M;
  vector<char> data(L1);
  for (int i = 0; i < L1; ++i) {
    cin >> data[i];
  }
  vector<char> readyEmitBalls(L2);
  for (int i = 0; i < L2; ++i) {
    cin >> readyEmitBalls[i];
  }

  // Display the input data.
  //cout << "L1 = " << L1;
  //cout << " L2 = " << L2;
  //cout << " M = " << M << endl;
  //DisplayVector(data);
  //DisplayVector(readyEmitBalls);

  int maxScore = GetMaxScore(data, readyEmitBalls, M);
  return 0;
}

void DisplayVector(vector<char>& data) {
  for (auto& d : data) {
    cout << d << " ";
  }
  cout << endl;
}

int GetMaxScore(vector<char>& data, vector<char>& readyEmitBalls, int M) {
  int maxScore;
  vector<bool> visited(data.size(), false);
  for (int j = 0; j < (int)data.size(); ++j) {
      if (data[j] == readyEmitBalls[0]) {
        dfs(data, j, readyEmitBalls, 0, M, maxScore, visited);
      }
  }
  return maxScore;
}

void dfs(vector<char>& data, const int i, vector<char>& readyEmitBalls, int j, const int& M;
         int& maxScore, vector<bool>& visited) {
  int toLeft, toRight;
  toLeft = toRight = i;
  int leftCount = 0;
  int rightCount = 0;
  while (toLeft - 1 >= 0) {
    if (visited[toLeft-1]) {
      --toLeft;
    } else {
      if (data[toLeft-1] == data[i]) {
        ++leftCount;
        --toLeft;
      } else {
        break;
      }
    }
  }
  while (toRight + 1 < (int)data.size()) {
    if (visited[toRight+1]) {
      ++toRight;
    } else {
      if (data[toRight+1] == data[i]) {
        ++rightCount;
        ++toRight;
      } else {
        break;
      }
    }
  }

  if (leftCount + rightCount + 1 >= M) {
    maxScore += count;
    // mark visited.
    visited[i] = true;
    toLeft = toRight = i;
    while (toLeft - 1 >= 0) {
      if (visited[toLeft-1]) {
        --toLeft;
      } else {
        if (data[toLeft-1] == data[i]) {
          visited[toLeft-1] = true;
          --toLeft;
        } else {
          break;
        }
      }
    }
    while (toRight + 1 < (int)data.size()) {
      if (visited[toRight+1]) {
        ++toRight;
      } else {
        if (data[toRight+1] == data[i]) {
          visited[toRight+1] = true;
          ++toRight;
        } else {
          break;
        }
      }
    }
    if (toRight + 1 < (int)data.size()) {
      dfs(data, toRight+1, readyEmitBalls, j, 
    }
  } else {
    dfs(data,
  }
  return;
}
