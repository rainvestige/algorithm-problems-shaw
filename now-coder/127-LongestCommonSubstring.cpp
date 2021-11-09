#include <iostream>
#include <vector>
#include <string>

using namespace std;

string LCS(string& str1, string& str2)
{
  int endPos{0};
  int lcsLength{0};
  vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));
  for (int i = 0; i < (int)str1.size(); ++i) {
    for (int j = 0; j < (int)str2.size(); ++j) {
      if (str1[i] != str2[j]) {
        dp[i+1][j+1] = 0;
        continue;
      }
      dp[i+1][j+1] = dp[i][j] + 1;
      if (dp[i+1][j+1] > lcsLength) {
        lcsLength = dp[i+1][j+1];
        endPos = i;
      }
    }
  }
  return str1.substr(endPos-lcsLength+1, lcsLength);
}

int main()
{
  string str1{"1AB2345CD"};
  string str2{"12345EF"};
  cin >> str1 >> str2;
  cout << "The longest common substring of " << str1 << " and " << str2
       << " is " << LCS(str1, str2) << endl;
  return 0;
}
