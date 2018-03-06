#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef long long llint;

llint dp[2005][2005];

llint min(llint x, llint y) {
  return x < y ? x : y;
}

llint arrive(llint x, llint S, llint F, llint D) {
  if (x < S) return S + D;
  llint mul  = (x - S) / F + (((x - S) % F) != 0);
  return S + mul * F + D;
}

llint fill(llint bfill, llint value) {
  if (bfill == -1) return value;
  return min(bfill, value);
}

int main() {
  int TC;
  scanf("%d",&TC);
  for(int tc=1; tc<=TC; tc++) {
    memset(dp, -1, sizeof(dp));
    llint S[2005], F[2005], D[2005];

    llint N, Ts, Tf;
    scanf("%lld %lld %lld", &N, &Ts, &Tf);
    for(int i=1; i<N; i++) {
      scanf("%lld%lld%lld", S+i, F+i, D+i);
    }

    dp[0][0] = 0;
    for(int i=1; i<N; i++) {
      for(int j=0; j<i; j++) {
        llint Tbf = dp[i-1][j];

        llint Tnonpick = arrive(Tbf, S[i], F[i], D[i]);
        llint Tpick = arrive(Tbf + Ts, S[i], F[i], D[i]);

        dp[i][j+1] = fill(dp[i][j+1], Tpick);
        dp[i][j] = fill(dp[i][j], Tnonpick);
      }
    }

    int answer = -1;
    for(int j=N; j>=0; j--) {
      if(dp[N-1][j] == -1) continue;
      if(dp[N-1][j] <= Tf) {
        answer = j;
        break;
      }
    }

    if (answer == -1) {
      printf("Case #%d: IMPOSSIBLE\n", tc);
    } else {
      printf("Case #%d: %d\n", tc,  answer);
    }
  }
}

/*
===
4
4 3 12
3 2 1
6 2 2
1 3 2
3 2 30
1 2 27
3 2 1
4 1 11
2 1 2
4 1 5
8 2 2
5 10 5000
14 27 31
27 11 44
30 8 20
2000 4000 3
---
Case #1: 2
Case #2: 0
Case #3: IMPOSSIBLE
Case #4: 4
===
*/