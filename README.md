# K-Way Merge and Pairwise Merge

## Problem Statement

A financial system receives three already sorted transaction lists:

L1 = 10, 30, 50, 70

L2 = 20, 40, 60, 80

L3 = 15, 35, 55, 75

The objective is to merge the sorted lists using:

1. K-Way Merge using Min Heap
2. Pairwise Merge

and compare their performance.

---
## Source Code

## Files Included

- k_way_merge.c
- pairwise_merge.c

---

## Execution Results

### K-Way Merge

### Important Heap States During K-Way Merge

The three sorted lists are:

L1 = 10, 30, 50, 70
L2 = 20, 40, 60, 80
L3 = 15, 35, 55, 75

The first element from each list is inserted into the Min Heap.

**Initial Heap:**

```text
       10
      /  \
    20    15
```

Array representation: `[10, 20, 15]`

The minimum element is removed from the heap and the next element from the same list is inserted.

| Step    | Operation            | Heap State   |
| ------- | -------------------- | ------------ |
| Initial | Insert 10, 20, 15    | [10, 20, 15] |
| 1       | Remove 10, insert 30 | [15, 20, 30] |
| 2       | Remove 15, insert 35 | [20, 30, 35] |
| 3       | Remove 20, insert 40 | [30, 35, 40] |
| 4       | Remove 30, insert 50 | [35, 40, 50] |
| 5       | Remove 35, insert 55 | [40, 50, 55] |
| 6       | Remove 40, insert 60 | [50, 55, 60] |
| 7       | Remove 50, insert 70 | [55, 60, 70] |
| 8       | Remove 55, insert 75 | [60, 70, 75] |
| 9       | Remove 60, insert 80 | [70, 75, 80] |
| 10      | Remove 70            | [75, 80]     |
| 11      | Remove 75            | [80]         |
| 12      | Remove 80            | []           |

Some important heap states can also be represented as:

**After Step 1:**

```text
       15
      /  \
    20    30
```

**After Step 4:**

```text
       35
      /  \
    40    50
```

**After Step 8:**

```text
       60
      /  \
    70    75
```

**After Step 9:**

```text
       70
      /  \
    75    80
```

The elements removed from the Min Heap in order are:

```text
10, 15, 20, 30, 35, 40, 50, 55, 60, 70, 75, 80
```

Therefore, the final merged sorted list is:

```text
10, 15, 20, 30, 35, 40, 50, 55, 60, 70, 75, 80
```

The heap contains at most one element from each sorted list. Therefore, the maximum heap size is **k = 3** for this example.


Comparisons: 21

### Pairwise Merge

### Pairwise Merging

In pairwise merging, two sorted lists are merged at a time. The result is then merged with the next sorted list.

Given:

```text
L1 = 10, 30, 50, 70
L2 = 20, 40, 60, 80
L3 = 15, 35, 55, 75
```

### Step 1: Merge L1 and L2

```text
L1 = 10, 30, 50, 70
L2 = 20, 40, 60, 80
```

The elements are compared one by one:

```text
10 < 20  → 10
30 > 20  → 20
30 < 40  → 30
50 > 40  → 40
50 < 60  → 50
70 > 60  → 60
70 < 80  → 70
```

The remaining element is:

```text
80
```

Therefore,

```text
L1 + L2 = 10, 20, 30, 40, 50, 60, 70, 80
```

### Step 2: Merge the Result with L3

Now merge:

```text
Result = 10, 20, 30, 40, 50, 60, 70, 80
L3     = 15, 35, 55, 75
```

The comparisons are:

```text
10 < 15  → 10
20 > 15  → 15
20 < 35  → 20
30 < 35  → 30
40 > 35  → 35
40 < 55  → 40
50 < 55  → 50
60 > 55  → 55
60 < 75  → 60
70 < 75  → 70
80 > 75  → 75
```

The remaining element is:

```text
80
```

Therefore, the final merged list is:

```text
10, 15, 20, 30, 35, 40, 50, 55, 60, 70, 75, 80
```

### Pairwise Merging Summary

| Step | Lists Merged | Result                                         |
| ---- | ------------ | ---------------------------------------------- |
| 1    | L1 + L2      | 10, 20, 30, 40, 50, 60, 70, 80                 |
| 2    | Result + L3  | 10, 15, 20, 30, 35, 40, 50, 55, 60, 70, 75, 80 |

The final sorted list obtained using pairwise merging is:

10, 15, 20, 30, 35, 40, 50, 55, 60, 70, 75, 80


Comparisons: 18

---

## Complexity Analysis

| Method | Time Complexity | Space Complexity |
|----------|----------|----------|
| K-Way Merge | O(n log k) | O(k) |
| Pairwise Merge | O(nk) | O(n) |

---
## Comparison Table
Parameter            K-Way Merge      Pairwise Merge
---------------------------------------------------
Heap Size            3                N/A
Comparisons          21               18
Time Complexity      O(n log k)       O(nk)
Space Complexity     O(k)             O(n)

## Conclusion
Both K-way merging using a Min Heap and pairwise merging successfully merge the three sorted transaction lists into a single sorted list. Pairwise merging is simpler to implement and works efficiently for a small number of lists. The Min Heap approach maintains at most one active element from each list and performs merging in O(n log k) time with O(k) auxiliary heap space. As the number of sorted files increases, the Min Heap K-way merge is more scalable because it efficiently selects the smallest element among all active lists without repeatedly merging large intermediate lists. Therefore, K-way merging using a Min Heap is a suitable approach for applications involving a large number of sorted files.
