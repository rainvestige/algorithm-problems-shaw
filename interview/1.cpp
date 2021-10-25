#include <iostream>

using namespace std;

int DivideByEveryDigit(int n) {
  int ret{0};
  int base = 10;
  // Get every digit.
  int origin = n;
  int digit;
  while (n / base != 0) {
    digit = n % base;
    if (digit != 0 && origin % digit == 0) {
      ++ret;
    }
    n /= base;
  }
  if (n != 0 && origin % n == 0) {
    ++ret;
  }
  return ret;
}

int main() {
  int n;
  cin >> n;

  cout << DivideByEveryDigit(n);
  return 0;
}
