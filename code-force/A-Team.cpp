#include <iostream>

using namespace std;

int main()
{
  int numProblems;
  cin >> numProblems;

  int a, b, c;
  int numProblemsImplement = 0;
  while (numProblems--) {
    cin >> a >> b >> c;
    if (a + b + c >= 2) {
      ++numProblemsImplement; 
    }
  }
  cout << numProblemsImplement;
  return 0;
}
