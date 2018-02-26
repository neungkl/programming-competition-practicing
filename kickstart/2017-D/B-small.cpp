#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>

long long A[205];
long long B[205];
long long r[205];
long long s[205];
long long x[205];
long long y[205];
long long mtx[205][205];

using namespace std;

priority_queue<long long> result;
vector<long long> final_result;

int main() {
  int TC;
  scanf("%d",&TC);
  for(int tc=1; tc<=TC; tc++) {
    
    int N, K, A1, B1, C, D, E1, E2, F;
    while(!result.empty()) {
      result.pop();
    }
    final_result.clear();

    scanf("%d%d%d%d%d%d%d%d%d", &N, &K, &A1, &B1, &C, &D, &E1, &E2, &F);

    for(int i=1; i<=N; i++) {
      if(i == 1) {
        A[i] = x[i] = A1;
        B[i] = y[i] = B1;
        r[i] = 0;
        s[i] = 0;
      } else {
        x[i] = (C * x[i-1] + D * y[i-1] + E1) % F;
        y[i] = (D * x[i-1] + C * y[i-1] + E2) % F;

        r[i] = (C * r[i-1] + D * s[i-1] + E1) % 2;
        s[i] = (D * r[i-1] + C * s[i-1] + E2) % 2;

        A[i] = r[i] % 2 == 0 ? x[i] : -x[i];
        B[i] = s[i] % 2 == 0 ? y[i] : -y[i];
      }
    }

    for(int i=1; i<=N; i++) {
      for(int j=1; j<=N; j++) {
        mtx[i][j] = A[i] * B[j];
      }
    }

    for(int i=1; i<=N; i++) {
      for(int j=1; j<=N; j++) {
        mtx[i][j] = mtx[i][j] + mtx[i-1][j] + mtx[i][j-1] - mtx[i-1][j-1];
      }
    }

    int exceed = false;
    for(int i=1; i<=N; i++) {
      for(int j=i; j<=N; j++) {
        for(int k=1; k<=N; k++) {
          for(int l=k; l<=N; l++) {
            long long sum = mtx[j][l] - mtx[i-1][l] - mtx[j][k-1] + mtx[i-1][k-1];
            if (exceed) {
              long long min = -result.top();
              if(sum < min) continue;
              result.push(-sum);
              result.pop();
            } else {
              if (result.size() > K) exceed = true;
              result.push(-sum);
            } 
          }
        }
      }
    }

    while(!result.empty()) {
      long long t = result.top();
      final_result.push_back(-t);
      result.pop();
    }

    printf("Case #%d: %lld\n", tc, final_result[final_result.size() - K]);
  }
}

/*
===
6
2 3 1 1 1 1 1 1 5
2 2 1 1 1 1 1 1 5
2 1 1 1 1 1 1 1 5
1 1 2 2 2 2 2 2 5
2 3 1 2 2 1 1 1 5
9 8 7 6 5 4 3 2 1
---
Case #1: 6
Case #2: 6
Case #3: 9
Case #4: 4
Case #5: 1
Case #6: 42
===
*/