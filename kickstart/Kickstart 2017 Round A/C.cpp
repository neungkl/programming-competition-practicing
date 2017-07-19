#include <cstdio>
#define SIZE 2005

const int inf = 1000000000;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int N;
int x[SIZE];
int y[SIZE];
int z[SIZE];
int r[SIZE];

int maxx, maxy, maxz;
int minx, miny, minz;

int cover_axis(int x1_s, int x1_e, int x2_s, int x2_e, int P[]) {
  for(int i=0; i<N; i++) {
    if(
      (x1_s <= P[i] - r[i] && P[i] + r[i] <= x1_e) ||
      (x2_s <= P[i] - r[i] && P[i] + r[i] <= x2_e)
    ) {
      continue;
    }
    return false;
  }
  return true;
}

int cover(int radius) {
  int pass = 0;
  pass += cover_axis(minx, minx + radius, maxx - radius, maxx, x);
  pass += cover_axis(miny, miny + radius, maxy - radius, maxy, y);
  pass += cover_axis(minz, minz + radius, maxz - radius, maxz, z);
  return pass == 3;
}

void solve() {
  scanf("%d", &N);

  maxx = maxy = maxz = -inf;
  minx = miny = minz = inf;

  for(int i=0; i<N; i++) {
    scanf("%d%d%d%d", x+i, y+i, z+i, r+i);

    maxx = max(maxx, x[i] + r[i]);
    minx = min(minx, x[i] - r[i]);
    maxy = max(maxy, y[i] + r[i]);
    miny = min(miny, y[i] - r[i]);
    maxz = max(maxz, z[i] + r[i]);
    minz = min(minz, z[i] - r[i]);
  }

  int rs = 0;
  int re = inf;

  while (rs <= re) {
    int rc = (rs + re) / 2;
    
    if(cover(rc)) {
      re = rc - 1;
    } else {
      rs = rc + 1;
    }
  }
  printf("%d\n", rs);
}

int main() {
  int T;
  scanf("%d", &T);
  for(int t=1; t<=T; t++) {
    printf("Case #%d: ", t);
    solve();
  }
}

/*
===
3
3
1 1 1 1
2 2 2 1
4 4 4 1
3
1 1 1 2
2 3 4 1
5 6 7 1
3
1 1 1 1
1 1 1 1
9 9 9 1
---
Case #1: 3
Case #2: 5
Case #3: 2
===
*/