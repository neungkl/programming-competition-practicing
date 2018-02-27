#include <cstdio>

typedef long long llint;

int calc(llint K, llint N, llint lenN) {
  // printf("%lld %lld %lld\n", N, K, lenN);
  
  if (N == 1) return 0;

  llint half = lenN / 2;
  if (K == half) return 0;

  if (K < half) {
    return calc(K, N - 1, half);
  } else {
    return !calc(lenN - K - 1, N - 1, half);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    llint K; scanf("%lld", &K);
    llint N = 0;
    llint lenN = 0;

    while (lenN < K) {
      lenN = 2 * lenN + 1;
      N++;
    }
    K--;

    printf("Case #%d: %d\n", t + 1, calc(K, N, lenN));
  }
}

/*
===
4
1
2
3
10
---
Case #1: 0
Case #2: 0
Case #3: 1
Case #4: 0
===
11
1
2
3
4
5
6
7
8
9
10
11
---
Case #1: 0
Case #2: 0
Case #3: 1
Case #4: 0
Case #5: 0
Case #6: 1
Case #7: 1
Case #8: 0
Case #9: 0
Case #10: 0
Case #11: 1
===
*/