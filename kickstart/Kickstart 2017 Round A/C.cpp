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

int is_circle_inside(int x_s, int x_e, int p, int p_r) {
  return x_s <= p - p_r && p + p_r <= x_e;
}

int cover_box(int x1, int x2, int y1, int y2, int z1, int z2, int rd) {
  for(int i=0; i<N; i++) {
    if(
      (
        is_circle_inside(x1, x1 + rd, x[i], r[i]) &&
        is_circle_inside(y1, y1 + rd, y[i], r[i]) &&
        is_circle_inside(z1, z1 + rd, z[i], r[i])
      ) ||
      (
        is_circle_inside(x2, x2 + rd, x[i], r[i]) &&
        is_circle_inside(y2, y2 + rd, y[i], r[i]) &&
        is_circle_inside(z2, z2 + rd, z[i], r[i])
      )
    ) {
      continue;
    }
    return false;
  }
  return true;
}

int cover(int radius) {
  return
    cover_box(minx, maxx - radius, miny, maxy - radius, minz, maxz - radius, radius) ||
    cover_box(minx, maxx - radius, maxy - radius, miny, minz, maxz - radius, radius) ||
    cover_box(maxx - radius, minx, miny, maxy - radius, minz, maxz - radius, radius) ||
    cover_box(maxx - radius, minx, maxy - radius, miny, minz, maxz - radius, radius);
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