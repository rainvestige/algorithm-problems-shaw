#include <iostream>

class solution {
public:
  int add(int a, int b) {
    int c = a ^ b;
    int u = (unsigned)(a & b) << 1;
    return (u == 0) ? c : add(c, u);
  }
};
