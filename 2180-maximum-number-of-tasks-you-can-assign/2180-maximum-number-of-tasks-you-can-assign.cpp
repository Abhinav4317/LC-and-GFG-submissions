class Solution {
public:
    /** 
    The solution uses three main ideas:

1. **Binary‐search on the answer**  
2. **Greedy matching with a multiset**  
3. **“Use a pill only when you really need it”**  

Here’s how it all fits together:

---

### 1. Binary‐search on the number of tasks

We know the maximum possible answer lies between 0 and `min(n, m)` (you can’t do more tasks than you have tasks or workers).  
```cpp
int left = 0, right = min(tasks.size(), workers.size());
```
We then repeatedly test a candidate answer `mid = (left + right + 1)/2`.  
- If we **can** assign `mid` tasks, we move `left = mid` (try for even more).  
- Otherwise we move `right = mid-1`.  

After the loop, `left` is the largest number of tasks that can be completed.

---

### 2. Preparing for each feasibility check

Before the binary‐search loop, we sort both arrays in **non-decreasing** order:
```cpp
sort(tasks.begin(), tasks.end());
sort(workers.begin(), workers.end());
```
Within each check for a given `mid`, we’ll only try to assign the **weakest** `mid` tasks (i.e. `tasks[0..mid-1]`) to the **strongest** `mid` workers (i.e. `workers[m-mid..m-1]`).  Intuitively, if you can’t match those, you won’t be able to match any harder subset.

We copy the strongest `mid` workers into a `multiset<int>` so we can:
- Quickly grab the current strongest available worker (`prev(end())`).  
- Quickly find the weakest worker who, **with a pill**, can still do a given task (`lower_bound( neededStrength )`).  
- Erase whichever worker we use.

```cpp
multiset<int> workersFree(workers.end() - mid, workers.end());
```

---

### 3. Greedy matching from hardest task down

We now try to assign the `mid` tasks **from largest requirement down to smallest**:
```cpp
for (int i = mid - 1; i >= 0; --i) {
    // 1) Try assigning the currently strongest worker:
    auto it = prev(workersFree.end());
    if (*it >= tasks[i]) {
        // No pill needed: assign and erase
    } else {
        // 2) Otherwise try giving a pill to the weakest
        //    worker who can handle this task after pill.
        it = workersFree.lower_bound(tasks[i] - strength);
        // if none found or we run out of pills → fail
    }
    erase(it);
}
```

- **Case A:** The strongest free worker `*it` already meets `tasks[i]`.  
  We pair them without using a pill.  
- **Case B:** Even the strongest worker is too weak.  
  We search for the **weakest** worker who, after taking a pill (`strength` boost), would be able to handle it.  
  ```cpp
  it = workersFree.lower_bound(tasks[i] - strength);
  ```
  - If we find one, we consume one pill (`usedPills++`) and assign.  
  - If we don’t—or we exceed our pill budget—then we cannot complete `mid` tasks and we break out.

If we finish the loop without running out of pills or candidates, we know **it’s possible** to assign `mid` tasks.

---

### 4. Time and space complexity

- Sorting: O(n log n + m log m).  
- Binary‐search has O(log (min(n,m))) iterations.  
- Each feasibility check uses up to `mid` iterations, each one doing at most two multiset operations (log m each).  
- Overall: 
\[
O\bigl((n + m)\log(n + m) + \log(\min(n,m)) \times \min(n,m)\log m\bigr).
\]

---

### Why it’s correct

- **Binary‐search** finds the largest feasible count efficiently instead of checking every possible `k`.  
- **Sorting + greedy** ensures you always match the hardest tasks to the strongest available workers, saving weaker workers (and pills) for easier tasks.  
- **Pill usage** is deferred until absolutely necessary and then applied to the weakest viable worker—maximizing your chance to use pills optimally.  

This combination of binary‐search and a greedy “match‐hardest‐first with minimal pill usage” check is both efficient and provably correct for maximizing the number of tasks you can complete.
    */
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int left = 0, right = min(tasks.size(), workers.size());

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        while(left < right) {
            int mid = (left + right + 1) / 2;
            int usedPills = 0;
            multiset<int> workersFree(workers.end() - mid, workers.end());

            bool canAssign = true;
            for(int i = mid - 1; i >= 0; --i) {
                auto it = prev(workersFree.end());

                if(*it < tasks[i]) {
                    it = workersFree.lower_bound(tasks[i] - strength);
                    if(it == workersFree.end()) {
                        canAssign = false;
                        break;
                    }
                    ++usedPills;
                    if(usedPills > pills) {
                        canAssign = false;
                        break;
                    }
                }
                workersFree.erase(it);
            }

            if(canAssign)
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};