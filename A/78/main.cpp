#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1 << 30)

struct Cell {
  char value;
  bool is_deleted;

  Cell(char value, bool is_deleted = false): value(value), is_deleted(is_deleted) {};
};

int w = 5;
int h;
vector<vector<Cell>> table;

void find() {
  rep(i, h) {
    rep(j, w) {
      char target = table[i][j].value;
      if (target == '.') continue;

      // 十字チェック
      bool all_deleted = true;
      vector<Cell*> cell_list;
      cell_list.push_back(&table[i][j]);
      for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
          if (k == -1 && l == -1) continue;
          if (k == -1 && l == 1) continue;
          if (k == 1 && l == 1) continue;
          if (k == 1 && l == -1) continue;
          if (k == 0 && l == 0) continue;

          int y, x;
          y = i + k;
          x = j + l;

          if (y < 0 || y >= h || x < 0 || x >= w) continue;


          if (table[y][x].value != target) {
            all_deleted = false;
            break;
          }

          cell_list.push_back(&table[y][x]);
        }
        if (!all_deleted) {
          cell_list.clear();
          break;
        }
      }

      rep (i, cell_list.size()) {
        cell_list[i]->is_deleted = true;
      }
      cell_list.clear();
    }
  }
}

int main() {
  cin >> h;
  table.resize(h);

  rep(i, h) {
    rep(j, w) {
      char value;
      cin >> value;
      table[i].push_back({value});
    }
  }


  bool is_changed = false;
  while(true) {
    // 探索
    find();

    // 消す
    rep(i, h) {
      rep(j, w) {
        if (table[i][j].is_deleted) {
          table[i][j].value = '.';
          table[i][j].is_deleted = false;
          is_changed = true;
        }
      }
    }

    if (!is_changed) {
      // 変化なし
      rep(i, h) {
        rep(j, w) {
          cout << table[i][j].value;
        }
        cout << endl;
      }

      break;
    } else {
      is_changed = false;
      // 落とす
      for (int i = h-2; i >= 0; i--) {
        rep(j, w) {
          if (table[i][j].value == '.') continue;

          int y = i;
          while(true) {
            if (y+1 > h - 1) { break; }
            if (table[y+1][j].value != '.') { break; }

            y++;
          }

          if (y != i) swap(table[i][j], table[y][j]);
        }
      }
    }
  }

  return 0;
}