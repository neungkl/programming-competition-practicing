#include <cstdio>
#include <string>
#include <map>

using namespace std;

map <int, int> M;
map <int, int> Mcount;

int positionToNumber(char* s) {
  int num = 0;
  for (int i = 0; s[i] != '\0'; s++) {
    num = num * 26 + (s[i] - 'A');
  }
  return num;
}

void numberToPosition(char* s, int n) {
  for (int i = 2; i >= 0; i--) {
    s[i] = (n % 26) + 'A';
    n /= 26;
  }  
}

int main() {
  int T; scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    int N; scanf("%d", &N);

    M.clear();
    Mcount.clear();

    for (int i = 0; i < N; i++) {
      char f[4], d[4];
      scanf("%s", f);
      scanf("%s", d);

      int from = positionToNumber(f);
      int dest = positionToNumber(d);

      Mcount[from]++;
      Mcount[dest]--;
      M[from] = dest;
    }

    int start;
    for (map<int, int>::iterator it = Mcount.begin(); it != Mcount.end(); it++) {
      if (it->second == 1) {
        start = it->first;
      }
    }

    printf("Case #%d: ", t + 1);

    while(true) {
      if (M.find(start) == M.end()) break;

      char from[4], dest[4];
      numberToPosition(from, start);
      numberToPosition(dest, M[start]);

      printf("%s-%s ", from, dest);
      start = M[start];
    }

    printf("\n");
  }
}

/*
===
2
1
SFO
DFW
4
MIA
ORD
DFW
JFK
SFO
DFW
JFK
MIA
---
Case #1: SFO-DFW
Case #2: SFO-DFW DFW-JFK JFK-MIA MIA-ORD
===
1
2
BCJ
GMZ
GMZ
HRM
---
Case #1: BCJ-GMZ GMZ-HRM
===
*/