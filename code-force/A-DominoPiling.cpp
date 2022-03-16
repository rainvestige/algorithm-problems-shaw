#include <iostream>

using std::cin, std::cout;


int max_domino_piles(int rect_m, int rect_n, int pile_size)
{
  int max_piles{-1};

  // If rectangular `m` or `n` is even.
  if (rect_m % pile_size == 0 || rect_n % pile_size == 0) {
    return rect_m * rect_n / pile_size;
  }
  // `rect_m` and `n` are both odd.
  // Get the mininum value. Use `rect_m` to store the min value.
  int tmp{-1};
  if (rect_m > rect_n) {
    tmp = rect_m;
    rect_m = rect_n;
    rect_n = tmp;
  }

  if (rect_m == 1) {
    return (rect_n - 1) / 2;
  } else {
    return (rect_m - 1) * rect_n / 2 + (rect_n - 1) / 2;
  }
}

int main()
{
  int m{-1};
  int n{-1};

  cin >> m >> n;
  cout << max_domino_piles(m, n, 2);
  return 0;
}
