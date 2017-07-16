#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
  int TC;
  scanf("%d",&TC);
  for(int tc=1; tc<=TC; tc++) {
    char in[100][100];
    int N; scanf("%d", &N);
    for(int i=0; i<N; i++) {
      scanf("%s", in[i]);
    }

    int n_block = 0;

    while(true) {
      bool has_block = false;
      for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
          for(int k=0; k<N; k++) {
            for(int l=0; l<N; l++) {
              if(i == k || l == j) continue;
              if(
                in[i][j] == 'X' &&
                in[i][l] == 'X' &&
                in[k][j] == 'X' &&
                in[k][l] == 'X'
              ) {
                for(int cc=0; cc<N; cc++) {
                  in[i][cc] = in[k][cc] = in[cc][j] = in[cc][l] = '.';
                }
                has_block = true;
                n_block++;
              }
            }
          }
        }
      }
      if(!has_block) break;
    }
    
    int x_left = 0;

    for(int i=0; i<N; i++) {
      for(int j=0; j<N; j++) x_left += (in[i][j] == 'X');
    }

    bool correct = false;
    if(n_block == (N / 2) && x_left == 1) correct = true;
    
    printf("Case #%d: %s\n", tc, correct ? "POSSIBLE" : "IMPOSSIBLE");
  }
}

/*
===
3
3
..X
XX.
XX.
3
...
XXX
XX.
5
X.X..
.X..X
X.X..
...X.
.X..X
---
Case #1: POSSIBLE
Case #2: IMPOSSIBLE
Case #3: POSSIBLE
===
*/