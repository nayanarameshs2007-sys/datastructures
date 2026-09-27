#include <stdio.h>

int comparisons = 0;
int majorOperations = 0;

void merge(int A[], int n, int B[], int m, int result[]) {

    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {

        comparisons++;

        if (A[i] <= B[j])
            result[k++] = A[i++];
        else
            result[k++] = B[j++];

        majorOperations++;
    }

    while (i < n) {
        result[k++] = A[i++];
        majorOperations++;
    }

    while (j < m) {
        result[k++] = B[j++];
        majorOperations++;
    }
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\n");
}

int main() {

    int L1[] = {10, 30, 50, 70};
    int L2[] = {20, 40, 60, 80};
    int L3[] = {15, 35, 55, 75};

    int temp[8];
    int result[12];

    printf("PAIRWISE MERGING\n");
    printf("-----------------------------\n");

    /* Merge L1 and L2 */
    merge(L1, 4, L2, 4, temp);

    printf("\nAfter merging L1 and L2:\n");
    printArray(temp, 8);

    /* Merge result with L3 */
    merge(temp, 8, L3, 4, result);

    printf("\nFinal merged list:\n");
    printArray(result, 12);

    printf("\nNumber of comparisons: %d\n", comparisons);
    printf("Major operations: %d\n", majorOperations);

    return 0;
}