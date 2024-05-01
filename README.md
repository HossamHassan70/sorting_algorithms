0x1B. C - Sorting algorithms & Big O Project

# Big O: Demystifying the Efficiency Code

##### Big O notation describes an algorithm’s efficiency as the data size (n) grows. It doesn’t care about exact numbers, but the overall trend of operations as n increases. Here’s a crash course on common Big O complexities:

* O(1): Constant time, independent of n (think array access).
* O(log n): Logarithmic time, operations grow slowly with n (think binary search).
* O(n): Linear time, operations increase proportionally to n (think iterating through an array).
* O(n log n): Log-linear time, efficient for large datasets (think merge sort, quicksort).
* O(n²): Quadratic time, operations grow quadratically with n (think bubble sort, insertion sort).

# Sorting Showdown: Big O in Action

##### Compare some popular sorting algorithms:

* Bubble Sort: O(n²) — Simple but slow, compares adjacent elements repeatedly, swapping if needed.
* Insertion Sort: O(n²) — Similar to bubble sort, but inserts each element into its correct position.
* Selection Sort: O(n²) — Finds the minimum element, swaps it with the first, repeats.
* Merge Sort: O(n log n) — Divides the list, sorts sub-lists recursively, merges them efficiently.
* Quick Sort: O(n log n) — Chooses a pivot element, partitions around it, sorts sub-lists recursively.
* Heap Sort: O(n log n) — Builds a heap, extracts elements in sorted order.
