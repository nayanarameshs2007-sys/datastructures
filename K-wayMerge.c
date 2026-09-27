#include <stdio.h>

#define K 3
#define N 4

typedef struct {
    int value;
    int listIndex;
    int elementIndex;
} HeapNode;

HeapNode heap[K];
int heapSize = 0;
int comparisons = 0;
int heapOperations = 0;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void printHeap() {
    printf("Heap: ");
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i].value);
    }
    printf("\n");
}

void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        comparisons++;
        if (heap[parent].value <= heap[index].value)
            break;

        swap(&heap[parent], &heap[index]);
        heapOperations++;
        index = parent;
    }
}

void heapifyDown(int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heapSize) {
            comparisons++;
            if (heap[left].value < heap[smallest].value)
                smallest = left;
        }

        if (right < heapSize) {
            comparisons++;
            if (heap[right].value < heap[smallest].value)
                smallest = right;
        }

        if (smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);
        heapOperations++;
        index = smallest;
    }
}

void insert(HeapNode node) {
    heap[heapSize] = node;
    heapSize++;
    heapifyUp(heapSize - 1);
}

HeapNode deleteMin() {
    HeapNode minNode = heap[0];

    heap[0] = heap[heapSize - 1];
    heapSize--;

    if (heapSize > 0)
        heapifyDown(0);

    return minNode;
}

int main() {

    int lists[K][N] = {
        {10, 30, 50, 70},
        {20, 40, 60, 80},
        {15, 35, 55, 75}
    };

    int result[K * N];
    int resultIndex = 0;

    printf("K-WAY MERGE USING MIN HEAP\n");
    printf("--------------------------------\n");

    /* Insert first element of each list */
    for (int i = 0; i < K; i++) {
        HeapNode node;
        node.value = lists[i][0];
        node.listIndex = i;
        node.elementIndex = 0;

        insert(node);
    }

    printf("\nInitial heap:\n");
    printHeap();

    while (heapSize > 0) {

        HeapNode minNode = deleteMin();

        result[resultIndex++] = minNode.value;

        printf("\nRemoved: %d\n", minNode.value);

        /* Insert next element from the same list */
        if (minNode.elementIndex + 1 < N) {

            HeapNode nextNode;

            nextNode.listIndex = minNode.listIndex;
            nextNode.elementIndex = minNode.elementIndex + 1;
            nextNode.value =
                lists[nextNode.listIndex][nextNode.elementIndex];

            insert(nextNode);
        }

        printHeap();
    }

    printf("\nMerged List:\n");

    for (int i = 0; i < resultIndex; i++)
        printf("%d ", result[i]);

    printf("\n");

    printf("\nNumber of comparisons: %d\n", comparisons);
    printf("Heap operations (swaps): %d\n", heapOperations);

    return 0;
}