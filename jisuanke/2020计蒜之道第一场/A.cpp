#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

// 五子棋，黑色棋子先手
vector<string> ve;
char next_step;

int tran(int x, int y) {
  int cnt = 0, nx = x, ny = y - 1;
  while (ny >= 0 && ve[nx][ny] == next_step) {
    cnt++;
    ny--;
  }
  ny = y + 1;
  while (ny < 25 && ve[nx][ny] == next_step) {
    cnt++;
    ny++;
  }
  if (cnt >= 4)
    return 1;
  else
    return 0;
}

bool vertical(int x, int y) {
  int cnt = 0, nx = x - 1, ny = y;
  while (nx >= 0 && ve[nx][ny] == next_step) {
    cnt++;
    nx--;
  }
  nx = x + 1;
  while (nx < 25 && ve[nx][ny] == next_step) {
    cnt++;
    nx++;
  }
  if (cnt >= 4)
    return 1;
  else
    return 0;
}

bool MainDiagonal(int x, int y) {
  int cnt = 0, nx = x - 1, ny = y - 1;
  while (nx >= 0 && ny >= 0 && ve[nx][ny] == next_step) {
    cnt++;
    nx--;
    ny--;
  }
  nx = x + 1, ny = y + 1;
  while (nx < 25 && ny < 25 && ve[nx][ny] == next_step) {
    cnt++;
    nx++;
    ny++;
  }
  if (cnt >= 4)
    return 1;
  else
    return 0;
}

bool SubDiagonal(int x, int y) {
  int cnt = 0, nx = x - 1, ny = y + 1;
  while (nx >= 0 && ny < 25 && ve[nx][ny] == next_step) {
    cnt++;
    nx--;
    ny++;
  }
  nx = x + 1, ny = y - 1;
  while (nx < 25 && ny >= 0 && ve[nx][ny] == next_step) {
    cnt++;
    nx++;
    ny--;
  }
  if (cnt >= 4)
    return 1;
  else
    return 0;
}

int main(int argc, char const *argv[]) {
  int n;
  string s;
  for (int i = 0; i < 25; i++) {
    cin >> s;
    ve.push_back(s);
  }
  int white = 0, black = 0;
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 25; j++) {
      if (ve[i][j] == 'o') {
        white++;
      }
      if (ve[i][j] == 'x') {
        black++;
      }
    }
  }
  if (white == black) {
    next_step = 'x';
  } else {
    next_step = 'o';
  }
  vector<pair<int, int> > ans;
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 25; j++) {
      if (ve[i][j] == '.') {
        if (tran(i, j) || vertical(i, j) || MainDiagonal(i, j) ||
            SubDiagonal(i, j)) {
          ans.push_back(make_pair(i, j));
        }
      }
    }
  }
  if (ans.size() == 0) {
    cout << "tie" << endl;
    return 0;
  } else {
    for (int i = 0; i < (int)ans.size(); i++) {
      cout << ans[i].first << " " << ans[i].second << endl;
    }
  }
  return 0;
}
