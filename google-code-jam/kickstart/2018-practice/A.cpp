#include <cstdio>

int a[5005];
int b[5005];

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; t++)
  {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
      scanf("%d%d", a + i, b + i);
    }

    int P;
    scanf("%d", &P);

    printf("Case #%d: ", t + 1);

    for (int i = 0; i < P; i++)
    {
      int q;
      scanf("%d", &q);
      int count = 0;
      for (int j = 0; j < N; j++)
      {
        if (a[j] <= q && q <= b[j])
          count++;
      }

      printf("%d ", count);
    }

    printf("\n");
  }
}

/*
===
2
4
15 25 30 35 45 50 10 20
2
15
25

10
10 15 5 12 40 55 1 10 25 35 45 50 20 28 27 35 15 40 4 5
3
5
10
27
---
Case #1: 2 1
Case #2: 3 3 4
===
*/