/*************************************************************************
 * File Name:    3_2_3.cc
 * Author:       hongchunxiao
 * Mail:         hongchunxiao@360.cn
 * Created  Time: 2015/12/19 15:20:49 (Saturday December)
 * Modified Time: 2015/12/19 15:20:49 (Saturday December)
 * 
 * Description: 矩阵链相乘
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;
static const int kMaxSize = 1000;
static int m[kMaxSize][kMaxSize];
static int s[kMaxSize][kMaxSize];
static int p[kMaxSize + 1];

static int MatriChain(int *p, int n) {
  for (int i = 0; i < n; i++) {
    m[i][i] = 0;
  }

  for (int r = 2; r <= n; r++) {//链长
    for (int i = 0; i <= n - r; i++) {
      int j = i + r - 1;
      m[i][j] = m[i+1][j] + p[i] * p[i+1] * p[j+1]; // p[i],p[i+1]分别表示第i个矩阵的行和列
      s[i][j] = i;
      for (int k = i+1; k <= j-1; k++) {
        int temp = m[i][k] + m[k+1][j] + p[i] * p[k+1] * p[j+1];
        if (temp < m[i][j]) {
          m[i][j] = temp;
          s[i][j] = k;
        }
      }
    }
  }
  return m[0][n-1];
}

static void Display(int k, int i, int j) {
  if (i == j) {
    cout << "A" << i;
  } else {
    cout << "(";
    Display(s[i][k], i, k);
    cout << "*";
    Display(s[k+1][j], k+1, j);
    cout << ")";
  }
}

int main() {  
  int num;
  cin >> num;  
  cout << "相乘矩阵的个数: " << num << endl; 
  cout << "矩阵的行数与列数: ";  
  for (int i = 0; i <= num; i++) {
    cin >> p[i];
    cout << p[i] << " "; 
  }
  cout << endl;

  int minvalue = MatriChain(p, num);

  cout << "实现矩阵相乘最少的标量积为: " << minvalue << endl;
  Display(s[0][num-1], 0, num-1);
  cout << endl;
  return 0;  
}
