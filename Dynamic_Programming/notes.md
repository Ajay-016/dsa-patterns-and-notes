# Dynamic Programming — Master Notes

## 1. What DP Actually Is (My Understanding After ~50 Problems)
- DP = recursion with memory (memoization) OR stable bottom-up iteration (tabulation).
- Most DP problems reduce to **state + transition**.
- When brute force becomes exponential, DP converts it into polynomial time.
- DP is NOT about formula memorization; it's about recognizing patterns.
- Every DP problem comes from ~7 fundamental archetypes.

---

## 2. When To Use DP (My Triggers)
I now immediately consider DP when:
- The problem asks **min / max / count / true-false**.
- There’s a clear notion of **choices** → take / skip / include / exclude.
- Two sequences or indices interact (strings, arrays, knapsack).
- There is obvious subproblem overlap.
- There is an exponential recursion that can be compressed.

DP keywords:
- “number of ways”
- “minimum operations”
- “longest…”
- “partition…”
- “take or not take”
- “subsequence”

---

## 3. DP Patterns (Categorized From Everything I Solved)

### 🔹 1. 1D DP (Climbing stairs, House robber, Cost minimization)
- State depends only on previous few values (`dp[i-1], dp[i-2]`).
- Typical transition:  
  `dp[i] = max(dp[i-1], dp[i-2] + value)`  
  or  
  `dp[i] = dp[i-1] + dp[i-2]`

### 🔹 2. 2D Grid DP (Unique paths, Min path sum)
- `dp[i][j]` → value based on top & left.
- Transition:  
  `dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]`

### 🔹 3. Subsequence DP (LCS, LIS, Knapsack, Edit Distance)
- Base pattern: **take / not take**.
- Knapsack template:  
  `dp[i][w] = max(take, skip)`
- LCS template:  
  `dp[i][j] = 1 + dp[i-1][j-1]` or `max(dp[i-1][j], dp[i][j-1])`

### 🔹 4. String DP (Palindrome, Insertions, Deletions)
- Mirror of LCS logic.
- Often solved with 2D DP based on substring boundaries.

### 🔹 5. Partition DP
- Very knapsack-like.
- Often:  
  `can we split array into two subsets with equal sum?`

### 🔹 6. Grid + Path Constraints DP
- Frog jumps  
- Max path sums  
- Path counting with limits  

### 🔹 7. DP on Trees (Advanced)
- DFS that returns combined values.
- Example: max path on tree returns pair {include, best}.

---

## 4. Templates That Cover 90% of Problems

### **Memoization Template**
```cpp
int solve(int i, int j, vector<vector<int>>& dp) {
    if (base case) return ...;

    if (dp[i][j] != -1) return dp[i][j];

    int take = ...
    int not_take = ...

    return dp[i][j] = max(take, not_take);
}