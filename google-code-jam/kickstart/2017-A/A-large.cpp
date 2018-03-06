#include <cstdio>

typedef long long llint;
llint MOD = 1000000007;
int MAX_SIZE = 1000000001;

int min(int x, int y) {
  return x < y ? x : y;
}

llint mod(llint num) {
  return ((num % MOD) + MOD) % MOD;
}

llint sum_1(llint m) {
  return mod(m * (m + 1) / 2);
}

llint sum_2(llint m) {
  llint n1 = m;
  llint n2 = m + 1;
  llint n3 = 2 * m + 1;

  if (n1 % 2 == 0) n1 /= 2; 
  else n2 /= 2;

  if (n1 % 3 == 0) n1 /= 3;
  else if(n2 % 3 == 0) n2 /= 3;
  else n3 /= 3;

  return mod(mod(n1 * n2) * n3);
}

llint sum_3(llint m) {
  llint n1 = m;
  llint n2 = m + 1;

  if (n1 % 2 == 0) n1 /= 2;
  else n2 /= 2;

  return mod(mod(n1 * n1) * mod(n2 * n2));
}

void solve() {
  llint R,C;
  scanf("%lld%lld", &R, &C);
  llint M = min(R, C);
  llint sol = 0;
  
  sol += mod(mod(-C - 1 - R - (C * R)) * M);
  sol += mod(mod(R * C + 2 * R + 2 * C + 3) * sum_1(M));
  sol += mod(mod(-R  - C - 3) * sum_2(M));
  sol += mod(sum_3(M));

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