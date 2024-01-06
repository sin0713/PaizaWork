#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1 << 30)

void printFrame(string &str) {
  int cnt = (int)str.size() + 2;
  rep(i, cnt) {
    cout << "+";
  }
}

int main() {
  string s;
  cin >> s;

  printFrame(s);
  cout << endl;
  cout << "+" << s << "+" << endl;;
  printFrame(s);
  cout << endl;

  return 0;
}