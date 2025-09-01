# Exercise Sheet 2

## Question2.1

### a)

 $3n^2+5n-2=\Theta(n^2)$

$\text{let } c_1=1,c_2=5,n_0=3,$

$0\leq c_1n^2 \leq 3n^2+5n-2 \leq c_2n^2  \text{, for all } n \geq n_0 $

### b)

 $42=\Theta(1)$

$\text{let } c_1=1,c_2=43,n_0=1,$

$0 \leq c_1 \leq 42 \leq c_2  \text{, for all } n \geq n_0 $

### c)

 $4n^2·(1+\log n)-2n^2=\Theta(n^2·\log n)$

$\text{let } c_1=4,c_2=6,n_0=10,$

$0\leq c_1n^2·\log n \leq 4n^2·(1+\log n)-2n^2 \leq c_2n^2·\log n  \text{, for all } n \geq n_0 $



## Question2.2

### (a)

| $f(n)$    | $g(n)$           | $O$  | $o$  | $\Omega$ | $\omega$ | $\Theta$ |
| --------- | ---------------- | ---- | ---- | -------- | -------- | -------- |
| $\log n$  | $\sqrt n$        | yes  | yes  | no       | no       | no       |
| $n$       | $\sqrt n$        | no   | no   | yes      | yes      | no       |
| $n$       | $n\log n$        | yes  | yes  | no       | no       | no       |
| $n^2$     | $n^2+(\log n)^3$ | yes  | no   | yes      | no       | yes      |
| $2^n$     | $n^3$            | no   | no   | yes      | yes      | no       |
| $2^{n/2}$ | $2^n$            | yes  | yes  | no       | no       | no       |
| $log_2 n$ | $log_{10} n$     | yes  | no   | yes      | no       | yes      |



## Question2.3

### ALGORITHM A

Line 1 is executed once and line 4 to line 6 are executed $n(n-2)$ times for each.

So the numbers of foos is $1+n(n-2)·3=3n^2-6n+1=\Theta(n^2)$

As $c_1n^2 \leq 3n^2-6n+1 \leq c_2 n^2  \text{ for all }n \geq n_0 \text{ when choosing, say, }n_0=12,c_1=1/2,c_2=3$.

### ALGORITHM B

Line 1 is executed once, line 3 is executed $n$ times, and line 5 to line 6 are executed $[\frac{n}{2}]$times for each.

So the numbers of foos is $1+n+2[\frac{n}{2}]=\Theta(n)$

As $c_1n \leq  1+n+2[\frac{n}{2}] \leq c_2n \text{ for all }n \geq n_0 \text{ when choosing, say, }n_0=2,c_1=1,c_2=4$.

### ALGORITHM C

Line 1 is executed once, line 4 is executed $1+2+···+n=(1+n)n/2$ times, line 5 is executed $n$ times, line 6 is executed once.

So the numbers of foos is $1+n(n+1)/2+n+1=\frac{1}{2}n^2+\frac{3}{2}n+2=\Theta(n^2)$

As $c_1n^2 \leq \frac{1}{2}n^2+\frac{3}{2}n+2 \leq c_2 n^2  \text{ for all }n \geq n_0 \text{ when choosing, say, }n_0=3,c_1=1/2,c_2=2$.



## Question 2.4

### 1.

**True**,because $O(\sqrt n) \subseteq O(n)$.

### 2.

**False**, for example $n$ is in $o(n^2)$, but $n+n=2n$ is not in $\omega(n)$.

### 3.

**True**, because $O(n) \subseteq O(n\log n)$, so $3n\log n+O(n)=\Theta(n log n)$.

### **Explain:**

Because $O$ notation represents an upper bound instead of a lower bound, while the phrase "at least" refers to a lower bound, which contradicts to the purpose of $O$. The meaningful statement should be,"The running time of Algorithm A is at most $O(n^2)$".

##  Question 2.5

Line 1 is executed $n+1$ times, line 2 is executed $n(n+1)$ times, Line 3 is executed $n^2$ times, line 4 is executed $n^2(n+1)$ times, line 5 is executed $n^3$ times, line 6 is executed once.

$c_1(n+1)+c_2n(n+1)+c_3n^2+c_4n^2(n+1)+c_5n^3+c_6=\Theta(n^3)$

