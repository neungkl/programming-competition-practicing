Kickstart Round A 2017
====

Task reference: [https://code.google.com/codejam/contest/8284486/dashboard](https://code.google.com/codejam/contest/8284486/dashboard)

## Note

### A. Square Counting

This problem is can be reduced down into small pieces of abstraction.

Try to imagine only a square with N * N dots. How many possible reactangle that can fit in that square. Count only the square which larger than (N - 1) * (N - 1) size (so that means rotated squares are count as well)

For example if square size is 4 * 4, the amount of fitted squares is 3
```
5 * 5 = 4
6 * 6 = 5
...
N * N = N - 1
```

So, just count amount number of square in different size from 1 to min(R, C) and summarize it all.

```
for(m: 1...min(R,C))
    answer += (R - m + 1) * (C - m + 1) * (m - 1)
```

But this alogithm taks `O(N)` which is too slow for large data.

Another approach is multiple arimetric expression shown in above formular, reduce three brackets group into single group that each value combines with plus sign (ex. `(A + B) * (C + D) = AC + AD + BC + BD`)

After you complete it. Apply the summation rules to reduced formular.
[https://brilliant.org/wiki/sum-of-n-n2-or-n3/](https://brilliant.org/wiki/sum-of-n-n2-or-n3/)

And this algorithm can run with `O(1)`

### B. Pattern Overlap

I think this task is easy than A in term of mathematical knowledge. 

If you can write with recursive approach then everything is solved. The hard part is you must think of edge case that can cause program bugs. Try to imagine multiple cases.

```
*1111*
2222***3333

n*
n

*n
1234n
```

Use your imagination.

After you write down your code and already tested on the edge cases.
Add some memorization and your algorithm can be run on `O(N * N)` where N is maximum length of both string.