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

If you can write with recursive method and everything will be solved. The hard part is you must think of edge case that can cause program bugs. Try to imagine multiple cases.

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

### C. Space Cubes

This problem is not hard to follow, but there are some complex idea which maybe confuse if you try this task from scratch.

Firstly, you should know the popular algorithm name [binary search](https://en.wikipedia.org/wiki/Binary_search_algorithm), we will integrate this algorithm into our solution.

The objectives of the task is just simple. Find the minimum square cube that can contains all square from given input. If you try to imagine this task inside the brain, you brain maybe exploded.

Pick paper and pencil and write everything you can imagine now. Let's with only one diemension. If I try to make the problem more easiler by given the dots with only x-axis, each dots has radius, and you try to push two boxs that can cover all dots and radius.

It is easier.

The first box put on where the boundary is equal to leftmost dot minus by radius.
And second box put on the rightmost dot plus by radius.

Now, take a step further. Imagine the same task with 2-deminsional, what's happen?

```
# Case 1
X..
...
..X

# Case 2
..X
...
X..
```

There is 2 possible cases of boxs arragement (for the case which each box alignment with the same position in some axis ex. `X..X` it can be count as case 1 or case 2).

The thing that you must handle is try to put box in case 1 and check if those box can cover all sphere, and try with case 2 as the same.

Ok, now move on to 3-dimension. Try to imagine by yourself I will only tell you that there are only 4 cases for 3-dimension, but the detail of each case, you can try draw it by yourself.

After we try to fit the boxs into the combination of different location. The next big thing is how we calculate the size of each box which is the final answer of this problem.

The answer is simply. Just try to put 2 boxs with maximum size as you can and try to decrease each box a little bit to find the perfect box which is the answer.

But with this approach is very very slow. So, use binary search to find the proper size of the boxs and your algorithm can run on `O(log_2(D) * N)` where _D_ is furthest distant between sphere boundary.