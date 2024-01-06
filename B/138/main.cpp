#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1 << 30)

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> table(h);
  rep(i, h) {
    cin >> table[i]; 
  }

  int res = 0;
  rep(i, h) {
    rep(j, w) {
      if (table[i][j] == '#') continue;
      if (i == 0 || i == h-1) continue;
      if (j == 0 || j == w-1) continue;

      // 周りを探索
      bool isDornut = true;
      rep(k, 3) {
        rep(l, 3) {
          if (k == 1 && l == 1) continue;

          if (table[i+k-1][j+l-1] == '.') {
            isDornut = false;
            break;
          }
        }
        if (!isDornut) break;
      }

      if (isDornut) res++;
    }
  }

  cout << res << endl;

  return 0;
}