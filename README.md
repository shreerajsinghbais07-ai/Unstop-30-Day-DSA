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
