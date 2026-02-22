#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<char>> calcpal1(const string &s) {
  int n = s.size();
  vector<vector<char>> pal;
  pal.assign(n, vector<char>(n, 0));

  // 从短到长/或从后往前都行，这里用 i 递减保证 pal[i+1][j-1] 已算出
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i; j < n; ++j) {
      if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1])) {
        pal[i][j] = 1;
      }
    }
  }
  return pal;
}

vector<vector<char>> calcpal2(const string &s) {
  int n = s.size();
  vector<vector<char>> pal;
  pal.assign(n, vector<char>(n, 0));
  for (int L = 1; L <= n; ++L) {
    for (int i = 0; i + L - 1 < n; ++i) {
      int j = i + L - 1;
      if (s[i] == s[j] && (L <= 2 || pal[i + 1][j - 1])) {
        pal[i][j] = 1;
      }
    }
  }
  return pal;
}

void expand(const string &s, vector<vector<char>> &pal, int l, int r) {
  int n = s.size();
  while (l >= 0 && r < n && s[l] == s[r]) {
    pal[l][r] = 1;
    --l;
    ++r;
  }
}

vector<vector<char>> calcpal3(const string &s) {
  int n = s.size();
  vector<vector<char>> pal;

  pal.assign(n, vector<char>(n, 0));
  for (int c = 0; c < n; ++c) {
    expand(s, pal, c, c);     // 奇数长度回文
    expand(s, pal, c, c + 1); // 偶数长度回文
  }
  return pal;
}

char ispal(int i, int j, vector<vector<char>> &memo, const string &s) {
  char &res = memo[i][j];
  if (i >= j)
    return res = 1;
  if (res != 2)
    return res;
  if (s[i] != s[j])
    return res = 0;
  return res = ispal(i + 1, j - 1, memo, s);
}

vector<vector<char>> calcpal4(const string &s) {
  int n = s.size();
  vector<vector<char>> pal(n, vector<char>(n, 2));
  // 可以实现懒计算
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ispal(i, j, pal, s);
    }
  }
  return pal;
}

void printPal(const vector<vector<char>> &pal) {
  int n = pal.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << (int)pal[i][j] << " "; // 转int打印，避免char的ASCII问题
    }
    cout << endl; // 每行结束换行
  }
  cout << endl; // 不同数组间空一行分隔
}

int main() {
  string str = "aaabbbcccbbaa";
  auto pal1 = calcpal1(str);
  auto pal2 = calcpal2(str);
  auto pal3 = calcpal3(str);
  auto pal4 = calcpal4(str);
  bool a = pal1 == pal2;
  cout << a << endl;

  bool b = pal2 == pal3;
  bool c = pal3 == pal4;
  cout << b << endl;
  cout << c << endl;

  printPal(pal1);
  printPal(pal2);
  printPal(pal3);
  printPal(pal4);
  return 0;
}
