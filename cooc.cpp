#include <bits/stdc++.h>
#define MAX 4

using namespace std;

// Defines algorithms for getting coocurrence entries for different
// directions.
// TODO: Split up into separate functions.
int get_entry(int **a, int n, int y, int x) {
  int i, j, cnt = 0, tmp = 0;
  switch (k) 
    case 0: {
      // 0 degree direction.
      for (i=0; i < n; ++i) {
        for (j=0; j < n-1; ++j) {
          cnt += (a[i][j] == y && a[i][j+1] == x);
          cnt += (a[i][j] == x && a[i][j+1] == y);
        }
      }
      break;
    }
    case 1: {
      // 45 degree direction.
      for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
          cnt += (a[i][j] == y && a[i-1][j+1] == x);
          cnt += (a[i][j] == x && a[i-1][j+1] == y);
        }
      }
      break;
    }
    case 2: {
      // 90 degree direction.
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
          cnt += (a[j][i] == y && a[j+1][i] == x);
          cnt += (a[j][i] == x && a[j+1][i] == y);
        }
      }
      break;
    }
    case 3: {
      // 135 degree direction.
      for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
          cnt += (a[i][j] == y && a[i-1][j-1] == x);
          cnt += (a[i][j] == x && a[i-1][j-1] == y);
        }
      }
      break;
    }
}

int main() {
  // m - number of intensities.
  // n - dimension of image.
  int m, n, i, j, lvl, curr;
  cin >> m >> n;
  int a[n][n];
  int b[MAX][m][m];
  for (i=0; i<n; ++i) {
    for (j=0; j<n; ++j) { 
      cin >> a[i][j];
    }
  }
  
  for (k=0; k<MAX; ++k) {
    for (i=0; i<m; ++i) {
      for (j=0; j<m; ++j) {
        b[k][i][j] = get_entry(a, m, k, i, j);
      }
    }
  }

  cout << "done" << endl;
}
