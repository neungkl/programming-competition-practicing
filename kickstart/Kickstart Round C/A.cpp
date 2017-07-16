#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
  int TC;
  scanf("%d",&TC);
  for(int tc=1; tc<=TC; tc++) {
    char enc[100];
    char out[100];

    memset(out, '-', sizeof(out));
    scanf("%s", enc);
    int size = strlen(enc);

    for(int i=1; i<size; i+=2) {
      if(i == 1) out[i] = enc[0];
      else {
        out[i] = (enc[i-1] - out[i-2] + 26) % 26 + 'A';
      }
    }

    for(int i=size-1; i>=0; i-=2) {
      if(i == size-1) out[i-1] = enc[i];
      else {
        out[i-1] = (enc[i] - out[i+1] + 26) % 26 + 'A';
      }
    }

    bool answer = true;
    for(int i=0; i<size; i++) {
      if(out[i] == '-') {
        answer = false;
      }
    }

    out[size] = '\0';

    printf("Case #%d: %s\n", tc, answer ? out : "AMBIGUOUS");
  }
}

/*
===
3
OMDU
BCB
AOAAAN
---
Case #1: SOUP
Case #2: AMBIGUOUS
Case #3: BANANA
===
*/