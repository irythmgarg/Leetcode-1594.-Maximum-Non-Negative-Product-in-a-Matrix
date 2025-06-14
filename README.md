# Leetcode-1594.-Maximum-Non-Negative-Product-in-a-Matrix
# Leetcode 1594 - Maximum Non-Negative Product in a Matrix

## Problem Statement

You are given a 2D grid of integers. Starting from the top-left corner, you can only move either **down** or **right** at any point in time. Your goal is to reach the bottom-right corner of the grid. Along the way, you multiply all the numbers you visit.

Return the **maximum non-negative product** modulo $10^9 + 7$. If the maximum product is negative, return **-1**.

---

## Example

**Input:**

```cpp
[[1, -2, 1],
 [1, -2, 1],
 [3, -4, 1]]
```

**Output:**

```cpp
8
```

---

## Approach 1: Recursive with Min/Max Tracking

### Description:

* A recursive function `hlo(i, j)` is used to calculate both the **minimum** and **maximum** product paths from cell `(i,j)` to the destination `(m-1,n-1)`.
* At each step, the function explores both downward and rightward directions.
* Since multiplying a negative value can turn a min into a max and vice versa, both min and max values are tracked.

### Time Complexity:

* **Exponential** in the worst case due to overlapping subproblems: $O(2^{m+n})$

### Space Complexity:

* **O(m+n)** — recursion stack depth.

### Pros:

* Easy to understand

### Cons:

* Very slow for large matrices due to repeated calculations.

---

## Approach 2: Dynamic Programming (Tabulation)

### Description:

* We use a DP table `dp[i][j]` that stores a pair `{minProduct, maxProduct}` at each cell.
* At each cell, we consider all 4 paths from top and left (min and max values), multiply with the current cell's value, and store the new min and max.
* This avoids recomputation and guarantees efficiency.

### Time Complexity:

* **O(m \* n)** — we process each cell once.

### Space Complexity:

* **O(m \* n)** — for the DP table.

### Pros:

* Efficient and optimal
* Handles negatives correctly by maintaining both min and max

### Cons:

* Slightly more complex to implement compared to standard DP

---

## Final Note

If the max product at the bottom-right cell is negative, we return -1. Otherwise, we return the product modulo $10^9 + 7$.

---

## Author

**Ridham Garg**
B.Tech Computer Engineering
Thapar University, Patiala
Roll No: 102203014
