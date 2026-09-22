# Unstop 30-Day DSA Challenge

Welcome to my 30-Day Data Structures and Algorithms (DSA) coding challenge repository. I am using this space to track my daily progress, log my code, and document key logic and "Aha!" moments as I build consistency and improve my problem-solving skills.

## Challenge Log

**Day 1: Assembly Line**
* **Topic:** Arrays & Binary Search
* **Learning:** Used a modified Binary Search (finding the lower bound) in a sorted array to efficiently find the exact insertion index for a new element, reducing time complexity compared to a linear search. Avoided infinite loops by correctly managing `left < right` boundary conditions.

**Day 2: Double Array**
* **Topic:** Arrays & Fast Sorting
* **Learning:** Used C's built-in `qsort()` function to achieve O(N log N) time complexity, preventing Time Limit Exceeded (TLE) errors on large datasets (up to N = 10^6). Created a new dynamically allocated array of size `2 * n` and efficiently mapped the sorted elements to both `result[i]` and `result[i + n]`.

**Day 3: Bouquet of Flowers**
* **Topic:** Arrays & Two Pointers
* **Learning:** Implemented the Two-Pointer technique on a sorted array to find a specific target sum efficiently. By placing pointers at the start and end and adjusting them based on whether the current sum was too high or too low, I reduced the time complexity from O(N^2) down to an optimal O(N).

*Day 4: Clean the Record (Remove Duplicates)*
* *Topic:* Singly Linked Lists
* *Learning:* Mastered pointer manipulation by traversing a sorted linked list to remove duplicate nodes. Learned to bypass a node by re-routing the pointer (current->next = current->next->next) and used free() to properly manage memory and prevent memory leaks in C.

**Day 5: Kth Character**
* **Topic:** Strings & O(1) Optimization
* **Learning:** Solved a string manipulation problem without actually manipulating the string. Recognized that finding the k-th character of a reversed string simply requires calculating its original index using `n - k`. This reduced the time and space complexity from O(N) to O(1).

**Day 6: Triangle Game**
* **Topic:** Math & Pascal's Triangle
* **Learning:** Optimized an apparent O(N^2) pattern generation problem down to O(N) by applying combinatorial math (`nCr`). Mastered handling intermediate integer overflow by correctly utilizing 64-bit `long long` data types for large sequential multiplications.

**Day 7: Happy Number**
* **Topic:** Math & Floyd's Cycle Detection
* **Learning:** Successfully stepped up to a Medium-level problem. Adapted the Two-Pointer technique into the Tortoise and Hare algorithm to detect infinite cycles. Built a helper function to isolate the digit-squaring math, keeping the main pointer logic clean and readable.

**Day 8: Escape Plan**
* **Topic:** Linked Lists & Linear Time Sorting
* **Learning:** Successfully combined linked list traversal with an optimal O(N) Counting Sort by analyzing the problem constraints. Avoided the overhead of converting the list to an array for `qsort` by tallying frequencies and overwriting the node values directly in place.

**Day 9: Choose Your Syllabus**
* **Topic:** Sorting & Two Pointers
* **Learning:** Mastered the technique of using sorted arrays and synchronized pointers to drop algorithm time complexity from O(N^2) to O(N log N). Handled large data summations using `long long` accumulators to prevent silent overflow errors during large test cases.

**Day 10: Backspace String Compare**
* **Topic:** Strings & Stack Simulation
* **Learning:** Mastered in-place string modification using a read/write pointer system to simulate stack operations (push/pop). Achieved O(N) time complexity and O(1) space complexity by resolving the backspace logic directly within the original memory blocks before comparing the final results.

**Day 11: The Excavation Ledger**
* **Topic:** Prefix Sums & Hash/Frequency Arrays
* **Learning:** Implemented an O(N) algorithmic optimization to count contiguous subarrays divisible by a target integer. Successfully handled negative number modulo arithmetic in C and protected against massive output combinations using 64-bit integer accumulators.

**Day 12: Alice Cleans Her Home**
* **Topic:** Arrays & In-Place Two Pointers
* **Learning:** Successfully adapted the Two-Pointer read/write technique to an integer array to solve the classic "Move Zeroes" problem. Maintained O(N) time complexity and optimal O(1) space complexity by shifting non-zero elements to the front and backfilling the remainder with zeros.

**Day 13: Tom And Jerry**
* **Topic:** Arrays & Descending Sorting
* **Learning:** Mastered custom comparator functions in C's `qsort` to manipulate array ordering. Solved the Kth largest element problem with `O(N log N)` time complexity and `O(1)` space complexity by sorting the array in descending order and directly targeting the `k - 1` index.

**Day 14: Measurement of Array**
* **Topic:** Arrays & Modulo Mathematics
* **Learning:** Circled back to conquer a skipped Medium problem. Bypassed O(N log N) simulation constraints by mathematically reducing the original index sums to an O(1) formula and utilizing an O(N) Frequency Array to determine sorted index positions. Applied rigorous Modulo 10^9+7 distribution to secure large data calculations.

**Day 15: Design Hashmap**
* **Topic:** Data Structure Engineering (Hashing & Chaining)
* **Learning:** Engineered a functional Hash Map from the ground up to handle data collisions. Implemented an array of Linked Lists (Chaining) to safely manage Insert, Get, and Delete operations in **O(1)** average time complexity, successfully avoiding reliance on pre-built libraries.

**Day 16: Too Many Books**
* **Topic:** Dynamic Programming & Binary Search
* **Learning:** Mastered the Longest Increasing Subsequence (LIS) pattern. Successfully bypassed standard O(N^2) limitations by integrating a Binary Search approach over a dynamic "tails" array, dropping the time complexity to a highly optimal O(N log N).

**Day 17: Tree Bias**
* **Topic:** Trees & Breadth-First Search (BFS)
* **Learning:** Implemented an $O(N)$ iterative BFS traversal with dynamic adjacency lists in C to aggregate node depths and prevent recursion stack overflows.

**Day 18: Congenial Node**
* **Topic:** Graph Theory & Star Graph Invariants
* **Learning:** Identified the central node of a star tree in $O(1)$ time complexity by inspecting node overlap across initial edge pairs, bypassing unnecessary adjacency graph building.

*Day 19: Mocha's Alien Dictionary*
* *Topic:* Dynamic Programming & String Processing
* *Learning:* Implemented 1D DP string segmentation in $O(|S| \cdot N)$ complexity with precomputed string lengths and strncmp matching in C.

**Day 20: Shortest Path to School**
* **Topic:** 2D Dynamic Programming (Grid Optimization)
* **Learning:** Solved the Minimum Path Sum problem on an $N \times M$ matrix in $O(N \cdot M)$ time complexity using dynamic state transitions in C.

**Day 21: Cricket Match Score**
* **Topic:** Greedy Algorithms & Array Reachability
* **Learning:** Implemented an $O(N)$ time and $O(1)$ auxiliary space greedy reachability algorithm to determine target score feasibility in C.

**Day 22: Signal Peaks at Mission Control**
* **Topic:** Monotonic Queue & Sliding Window
* **Learning:** Computed maximum values across overlapping continuous cycles of size $k$ in $O(n)$ time complexity using a monotonic deque.

**Day 23: The Museum Ticket Budget**
* **Topic:** Two Pointers & Sliding Window
* **Learning:** Computed the maximum affordable contiguous subarray within budget limit $B$ in $O(N)$ time complexity using dynamic sliding window boundaries.

**Day 24: Track Team Pace Window**
* **Topic:** Dual Monotonic Deques & Sliding Window
* **Learning:** Computed the longest contiguous subsegment satisfying a peak-to-trough range limit $L$ in $O(N)$ time complexity using dynamic minimum and maximum tracking queues.

**Day 25: The Robotics Assembly Kit**
* **Topic:** Sliding Window & Dynamic Frequency Counting
* **Learning:** Solved the variable-length minimum window substring problem with multi-frequency character constraints in $O(N)$ time complexity using dynamic two-pointer boundary adjustments.

**Day 26: The Kharantep Relic Ledger**
* **Topic:** DSU & Small-to-Large Merging
* **Learning:** Engineered dynamic property resolution across expanding graph components. Leveraged a tailored Union-Find hierarchy mapped to min-max sorting heaps, ensuring rapid extraction while capping set-consolidation thresholds at an efficient $O(N \log^2 N)$ boundary.
