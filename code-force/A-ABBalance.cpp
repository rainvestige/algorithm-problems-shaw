#include <iostream>
#include <vector>
#include <string>

using namespace std;

int NumOccurence(string& str, const string& substr)
{
  int lenSubstr = substr.size();
  int count{0};
  for (int i = 0; i <= (int)str.size() - lenSubstr; ++i) {
    if (str.substr(i, lenSubstr) == substr) {
      ++count;
    }
  }
  return count;
}

int DiffInNumOccurence(string& str, const string& substr1, const string& substr2)
{
  int diffCount{0};
  if (substr1.size() != substr2.size()) {
    cout << "substr1 and substr2 must have the same size" << endl;
    return -1;
  }
  int lenSubstr = substr1.size();
  for (int i = 0; i <= (int)str.size() - lenSubstr; ++i) {
    if (str.substr(i, lenSubstr) == substr1) {
      ++diffCount;
    } else if (str.substr(i, lenSubstr) == substr2) {
      --diffCount;
    }
  }
  return diffCount;
}

// diffCount: num of "ab" minus num of "ba"
void MakeStrBalance(string& str, int diffCount)
{
  int strSize = str.size();
  for (int i = 0; i < strSize; ++i) { // only change the str[i].
    if (diffCount > 0) {
      // The num of "ab" is greater than that of "ba". We should reduce the
      // occurrence of "ab", or increase the occurrence of "ba".
      if (i == 0) {
        // no need to check the i+1 bound.
        if ((str[i] == 'a' && str[i+1] == 'a') ||
            (str[i] == 'a' && str[i+1] == 'b')) {
          str[i] = 'b'; // increase the num of "ba".
          --diffCount; // update diffCount.
        }
      }
      if (i == strSize - 1) {
        if ((str[i-1] == 'a' && str[i] == 'b') ||
            (str[i-1] == 'b' && str[i] == 'b')) {
          str[i] = 'a';
          --diffCount;
        }
      }
      // 0 < i < strSize - 1. at middle.
      //if (str[i] == 'b') { // str[i] == 'a' no need to change.
      //  str[i] = 'a';
      //}

    }
    if (diffCount < 0) {
      if (i == 0) {
        // no need to check the i+1 bound.
        if ((str[i] == 'b' && str[i+1] == 'a') ||
            (str[i] == 'b' && str[i+1] == 'b')) {
          str[i] = 'a'; // increase the num of "ba".
          ++diffCount; // update diffCount.
        }
      }
      if (i == strSize - 1) {
        if ((str[i-1] == 'a' && str[i] == 'a') ||
            (str[i-1] == 'b' && str[i] == 'a')) {
          str[i] = 'b';
          ++diffCount;
        }
      }
      // at middle.
      //if (str[i] = 'a') {

      //}
    }
    if (diffCount == 0) {
      return;
    }
  }
}

int main()
{
  // Prepare the input.
  int numTestCases;
  cin >> numTestCases;
  vector<string> stringData(numTestCases);

  int diffCount = 0;
  for (int i = 0; i < numTestCases; ++i) {
    cin >> stringData[i];
    //cout << "The number of 'ab' in string" << stringData[i] << " is "
    //     << NumOccurence(stringData[i], "ab") << endl;
    //cout << "The number of 'ba' in string" << stringData[i] << " is "
    //     << NumOccurence(stringData[i], "ba") << endl;
    if ((diffCount = DiffInNumOccurence(stringData[i], "ab", "ba")) != 0) {
      //cout << "diff count: " << diffCount << endl;
      MakeStrBalance(stringData[i], diffCount);
    }
    cout << stringData[i] << endl;

  }



  return 0;
}
