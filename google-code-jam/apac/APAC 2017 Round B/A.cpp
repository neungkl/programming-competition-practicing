#include <cstdio>

typedef long long LL;

int min(int a, int b) { return a < b ? a : b; }

void solve()
{
  LL L, R;
  scanf("%lld%lld", &L, &R);
  LL C = min(L,R);

  printf("%lld\n", C * (C + 1) / 2);
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++)
  {
    printf("Case #%d: ", t);
    solve();
  }
}