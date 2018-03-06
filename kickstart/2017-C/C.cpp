#include <cstdio>
#include <cstring>

#define MAX_Q 55

int dp[2][MAX_Q][MAX_Q][MAX_Q];
char p[3][MAX_Q];
int score[2];
int N, Q;

int solve() {
  dp[0][0][0][0] = 1;
  for (int q = 0; q < Q; q++) {
    memset(dp[(q + 1) % 2], 0, sizeof(dp[(q + 1) % 2]));
    for (int i = 0; i <= Q; i++) {
      for (int j = 0; j <= Q; j++) {
        for (int k = 0; k <= Q; k++) {
          if (dp[q % 2][i][j][k]) {
            int s[3] = {0};
            if (p[0][q] == 'T') s[0] = 1;
            if (p[1][q] == 'T') s[1] = 1;
            if (p[2][q] == 'T') s[2] = 1;
            dp[(q + 1) % 2][i][j][k] = 1;
            dp[(q + 1) % 2][i + s[0]][j + s[1]][k + s[2]] = 1;
            dp[(q + 1) % 2][i + !s[0]][j + !s[1]][k + !s[2]] = 1;
          }
        }
      }
    }
  }

  for (int k = Q; k >= 0; k--) {
    if (dp[Q % 2][score[0]][score[1]][k]) return k;
  }

  return 0;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d%d", &N, &Q);
    scanf("%s", p[0]);
    if (N == 1) strcpy(p[1], p[0]);
    else scanf("%s", p[1]);
    scanf("%s", p[2]);
    scanf("%d", &score[0]);
    if (N == 1) score[1] = score[0];
    else scanf("%d", &score[1]);

    memset(dp, 0, sizeof(dp));

    printf("Case #%d: %d\n", t + 1, solve());
  }
}

/*
===
3
1 2
TF
FF
1
1 3
TTT
TTF
0
2 3
TTF
FTF
TTT
1 2
---
Case #1: 2
Case #2: 1
Case #3: 2
===
*/