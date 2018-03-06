#include <cstdio>

typedef long long llint;
int MOD = 1000000007;
int MAX_SIZE = 1000000001;

int min(int x, int y) {
  return x < y ? x : y;
}

void solve() {
  llint R,C;
  scanf("%lld%lld", &R, &C);
  llint M = min(R, C);
  llint sol = 0;
  for(llint m=2; m<=M; m++) {
    sol += (R - m + 1) * (C - m + 1) * (m - 1);
    sol %= MOD;
  }
  printf("%lld", sol % MOD);
}

int main() {
  int T;
  scanf("%d", &T);
  for(int i=1; i<=T; i++) {
    printf("Case #%d: ", i);
    solve();
    printf("\n");
  }
}

/*
===
4
2 4
3 4
4 4
1000 500
---
Case #1: 3
Case #2: 10
Case #3: 20
Case #4: 624937395
===
*/