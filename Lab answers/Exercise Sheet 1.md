# Exercise Sheet 1

## Q1.1

| 24   | 5    | 6    | 23   | 42   | 45   | 2    | 1    | 8    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |

| 1    | 5    | 6    | 23   | 42   | 45   | 2    | 24   | 8    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |

| 1    | 2    | 6    | 23   | 42   | 45   | 5    | 24   | 8    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |

| 1    | 2    | 5    | 23   | 42   | 45   | 6    | 24   | 8    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |

| 1    | 2    | 5    | 6    | 42   | 45   | 23   | 24   | 8    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |

| 1    | 2    | 5    | 6    | 8    | 45   | 23   | 24   | 42   |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |

| 1    | 2    | 5    | 6    | 8    | 23   | 45   | 24   | 42   |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |

| 1    | 2    | 5    | 6    | 8    | 23   | 24   | 45   | 42   |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |

| 1    | 2    | 5    | 6    | 8    | 23   | 24   | 42   | 45   |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |

## Q1.2

The prove of the correctness of SELECTIONSORT:

**loop invariant**: At the start of each iteration of the for loop of lines 1-6, the subarray A'[1...j-1] consists of all the smallest j-1 numbers from the array A[1...n], and the subarray A'[1...j-1] is in sorted order.

**Initialization**: When j=1, the subarray is empty, it is in sorted order（trivial）, thus the loop invariant is true at initialization.

Maintenance: If the loop invariant is true after i iterations, we can get a subarray A'[1...i] consists of all the smallest i numbers from the array A[1...n], and the subarray A'[1...i] is in sorted order. Then at the i+1 iteration, we will get the smallest element amongst those not sorted yet(A'[i+1...n]), and swaps it with the first number in the unsorted part of the array. In this way we can get the sorted subarray A'[1...i+1], which contains the i+1 smallest numbers. Therefore, by the end of the iteration the loop invariant still holds for step i+1.

**Termination**: The algorithm terminates when j=n-1, subarray A'[1...n-1] has been sorted and A[n] is larger than any number in A'[1...n-1]. Therefore the A[1...n] is sorted and the loop invariant still holds.

## Q1.3

(We think "n = A.length" also takes time 1.)

The best-case running time of SELECTIONSORT:

We assume the sequence is already sorted in ascending order.

$1+n+(n-1)+(n+n-1+...+1)+(n-1+n-2+...+1)+(n-1)=n^2+3n-1$

The worst-case running time of SELECTIONSORT:

We assume the sequence is sorted in descending order.

$1+n+(n-1)+(n+n-1+...+1)+(n-1+n-2+...+1)+(n-1)=n^2+3n-1$



Then we compare it to INTERSECRIONSORT,

The best-case running time of INTERSECRIONSORT:

We assume the sequence is already sorted in ascending order.

$n+(n-1)+(n-1)+(n-1)+0+0+(n-1)=5n-4$

The worst-case running time of INTERSECRIONSORT:

We assume the sequence is sorted in descending order.

$n+(n-1)+(n-1)+(2+3+...+n)+(1+2+...+n-1)+(1+2+...n-1)+(n-1)=\frac{3n^2}{2}+\frac{7n}{2}-4$



**When n is extremely large**, we find that, SELECTIONSORT has better worst-case running time than INTERSECRIONSORT; however, INTERSECRIONSORT has better best-case running time than SELECTIONSORT. The running time of SELECTIONSORT is much more steady, while the running time of INTERSECRIONSORT depends much on its case.