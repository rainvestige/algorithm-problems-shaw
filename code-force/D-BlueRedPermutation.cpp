#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pic = pair<int, char>;

void DisplayVector(vector<pic>& data)
{
  for (int i = 0; i < (int)data.size(); ++i) {
    cout << data[i].first << " " << data[i].second << endl;
  }
}

// Blue: decrease.
// Red: increase.
bool IsPermutationExist(vector<pic>& dataColor, int blueColorCount)
{
  // Divide the data by color.
  sort(dataColor.begin(), dataColor.end(), [](pic& a, pic& b) {
      return a.second < b. second;
  });
  sort(dataColor.begin(), dataColor.begin() + blueColorCount, [](pic& a, pic& b) {
      return a.first < b.first;});
  sort(dataColor.begin()+blueColorCount, dataColor.end(), [](pic& a, pic& b) {
      return a.first > b.first;});
  //DisplayVector(dataColor);

  int rangeLeft = 1;
  int rangeRight = dataColor.size();
  for (int i = 0; i < blueColorCount; ++i) { // Blue color, decrease.
    if (dataColor[i].first >= rangeLeft) {
      ++rangeLeft;
    } else {
      return false;
    }
  }
  for (int j = blueColorCount; j < (int)dataColor.size(); ++j) {
    if (dataColor[j].first <= rangeRight) {
      --rangeRight;
    } else {
      return false;
    }
  }

  if (rangeLeft < rangeRight) {
    return false;
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL);
  int numTestCases;
  cin >> numTestCases;

  int lenArray;
  int blueColorCount = 0;
  while (numTestCases--) {
    cin >> lenArray;
    vector<int> data(lenArray, 0);
    for (int i = 0; i < lenArray; ++i) {
      cin >> data[i];
    }
    vector<pair<int, char>> dataColor(lenArray);
    char color;
    blueColorCount = 0;
    for (int i = 0; i < lenArray; ++i) {
      cin >> color;
      if (color == 'B') {
        ++blueColorCount;
      }
      dataColor[i] = {data[i], color};
    }
    if (IsPermutationExist(dataColor, blueColorCount)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
