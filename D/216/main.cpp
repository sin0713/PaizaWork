#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1 << 30)

int main() {
  int a, b;
  cin >> a >> b;

  int res = 500 - a - b;
  cout << res << endl;

  return 0;
}