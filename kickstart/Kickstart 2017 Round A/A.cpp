#include <cstdio>

typedef long long llint;
int MOD = 1000000007;

int min(int x, int y) {
  return x < y ? x : y;
}

void solve() {
  llint R,C;
  scanf("%lld%lld", &R, &C);
  llint M = min(R, C);
  llint sol = 0;
  for(llint m=2; m<=M; m++) {
    sol += 
  }
  printf("%lld", sol % MOD)
}

int main() {
  int T;
  scanf("%d", &T);
  for(int i=1; i<=T; i++) {
    printf("Case #%d: ", i);
    solve();
  }
}