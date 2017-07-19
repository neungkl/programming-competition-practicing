#include <cstdio>
#include <cstring>
#define SIZE 2005

char A[SIZE];
char B[SIZE];

int dp[SIZE][SIZE];
int size_a, size_b;

bool run(int ax, int bx) {
  if (ax >= size_a) return 0;
  if (bx >= size_b) return 0;

  if (dp[ax][bx] != -1) return dp[ax][bx];

  if(A[ax] == '*') {
    int result = 0;
    for(int i=0, c=0; c<=4; i++) {
      result |= run(ax + 1, bx + i);
      c += B[bx + i] != '*';
      if (result) break;
    }
    return dp[ax][bx] = result;
  } else if(B[bx] == '*') {
    int result = 0;
    for(int i=0, c=0; c<=4; i++) {
      result |= run(ax + i, bx + 1);
      c += A[ax + i] != '*';
      if (result) break;
    }
    return dp[ax][bx] = result;
  } else {
    return dp[ax][bx] = (A[ax] == B[bx] ? run(ax + 1, bx + 1) : false);
  }
}

void solve() {
  scanf("%s%s", A, B);
  memset(dp, -1, sizeof(dp));

  size_a = strlen(A);
  size_b = strlen(B);
  dp[size_a][size_b] = 1;
  A[size_a++] = '#';
  B[size_b++] = '#';

  int result = run(0, 0);
  printf("%s", result ? "TRUE" : "FALSE");
}

int main() {
  int T;
  scanf("%d",&T);
  for(int t=1; t<=T; t++) {
    printf("Case #%d: ", t);
    solve();
    printf("\n");
  }
}

/*
===
4
****
It
Shakes*e
S*speare
Shakes*e
*peare
n*
n
---
Case #1: TRUE
Case #2: TRUE
Case #3: FALSE
Case #4: TRUE
===
*/
