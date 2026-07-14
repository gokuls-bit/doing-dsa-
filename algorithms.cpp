Yes. If you want **important C++ DSA algorithms in long copy-paste format, roughly 100 lines per algorithm**, the best way is to keep each algorithm as a **separate standalone C++ program** containing:

* Includes and namespace
* Helper functions
* Main algorithm
* Example input
* Output printing
* Time and space complexity comments
* Detailed inline explanation

Below is **Part 1: Core Array and Searching Algorithms**. Each code block is independently copy-pasteable.

## 1. Bubble Sort — Full C++ Program

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    BUBBLE SORT
    ============================================================

    Bubble Sort repeatedly compares adjacent elements.

    If two adjacent elements are in the wrong order,
    they are swapped.

    After every complete pass, the largest remaining element
    moves to its correct position at the end.

    Example:

        Input:
            5 1 4 2 8

        Pass 1:
            1 4 2 5 8

        Pass 2:
            1 2 4 5 8

    Time Complexity:
        Best Case:    O(n)       with optimization
        Average Case: O(n^2)
        Worst Case:   O(n^2)

    Space Complexity:
        O(1)

    Stable:
        Yes

    In-place:
        Yes
*/


void printArray(const vector<int>& nums) {

    cout << "[ ";

    for (int number : nums) {
        cout << number << " ";
    }

    cout << "]" << endl;
}


void bubbleSort(vector<int>& nums) {

    int n = nums.size();

    /*
        We need at most n - 1 passes.

        After every pass, one element reaches
        its final sorted position.
    */

    for (int pass = 0; pass < n - 1; pass++) {

        bool swapped = false;

        /*
            The last 'pass' elements are already sorted.

            Therefore:

                j < n - pass - 1
        */

        for (int j = 0; j < n - pass - 1; j++) {

            /*
                Compare adjacent elements.
            */

            if (nums[j] > nums[j + 1]) {

                swap(nums[j], nums[j + 1]);

                swapped = true;
            }
        }

        /*
            If no swaps occurred during this entire pass,
            the array is already sorted.

            This optimization improves the best case
            from O(n^2) to O(n).
        */

        if (!swapped) {
            break;
        }
    }
}


int main() {

    vector<int> nums = {
        64,
        34,
        25,
        12,
        22,
        11,
        90
    };


    cout << "Original Array:" << endl;

    printArray(nums);


    bubbleSort(nums);


    cout << endl;

    cout << "Sorted Array:" << endl;

    printArray(nums);


    return 0;
}
```

## 2. Selection Sort — Full C++ Program

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    SELECTION SORT
    ============================================================

    Selection Sort divides the array into two parts:

        1. Sorted portion
        2. Unsorted portion

    During every iteration, we find the smallest element
    from the unsorted portion and place it at the beginning.

    Example:

        Input:
            64 25 12 22 11

        Find minimum = 11

            11 25 12 22 64

        Find next minimum = 12

            11 12 25 22 64

    Time Complexity:
        Best Case:    O(n^2)
        Average Case: O(n^2)
        Worst Case:   O(n^2)

    Space Complexity:
        O(1)

    Stable:
        Normally No

    In-place:
        Yes
*/


void printArray(const vector<int>& nums) {

    cout << "[ ";

    for (int value : nums) {
        cout << value << " ";
    }

    cout << "]" << endl;
}


void selectionSort(vector<int>& nums) {

    int n = nums.size();


    /*
        Move the boundary of the unsorted array
        one position forward after every iteration.
    */

    for (int i = 0; i < n - 1; i++) {

        /*
            Assume the current element is minimum.
        */

        int minimumIndex = i;


        /*
            Search for a smaller element.
        */

        for (int j = i + 1; j < n; j++) {

            if (nums[j] < nums[minimumIndex]) {

                minimumIndex = j;
            }
        }


        /*
            Place the minimum element at index i.
        */

        if (minimumIndex != i) {

            swap(
                nums[i],
                nums[minimumIndex]
            );
        }
    }
}


int main() {

    vector<int> nums = {
        64,
        25,
        12,
        22,
        11
    };


    cout << "Before Selection Sort:" << endl;

    printArray(nums);


    selectionSort(nums);


    cout << endl;

    cout << "After Selection Sort:" << endl;

    printArray(nums);


    return 0;
}
```

## 3. Insertion Sort — Full C++ Program

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    INSERTION SORT
    ============================================================

    Insertion Sort builds the sorted array one element
    at a time.

    It works similarly to arranging playing cards.

    For each element:

        1. Store the current element as key.
        2. Move larger elements one position right.
        3. Insert key into its correct position.

    Example:

        5 2 4 6 1 3

        Insert 2:
            2 5 4 6 1 3

        Insert 4:
            2 4 5 6 1 3

    Time Complexity:
        Best Case:    O(n)
        Average Case: O(n^2)
        Worst Case:   O(n^2)

    Space Complexity:
        O(1)

    Stable:
        Yes

    In-place:
        Yes
*/


void printArray(const vector<int>& nums) {

    cout << "[ ";

    for (int value : nums) {

        cout << value << " ";
    }

    cout << "]" << endl;
}


void insertionSort(vector<int>& nums) {

    int n = nums.size();


    /*
        Start from index 1 because a single element
        at index 0 is already considered sorted.
    */

    for (int i = 1; i < n; i++) {

        /*
            Current element to insert.
        */

        int key = nums[i];


        /*
            Start checking from previous position.
        */

        int j = i - 1;


        /*
            Move all elements greater than key
            one position to the right.
        */

        while (
            j >= 0 &&
            nums[j] > key
        ) {

            nums[j + 1] = nums[j];

            j--;
        }


        /*
            Insert key into correct position.
        */

        nums[j + 1] = key;
    }
}


int main() {

    vector<int> nums = {
        12,
        11,
        13,
        5,
        6
    };


    cout << "Original Array:" << endl;

    printArray(nums);


    insertionSort(nums);


    cout << endl;

    cout << "Sorted Array:" << endl;

    printArray(nums);


    return 0;
}
```

## 4. Merge Sort — Full C++ Program

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    MERGE SORT
    ============================================================

    Merge Sort uses the Divide and Conquer technique.

    Steps:

        1. Divide array into two halves.
        2. Recursively sort the left half.
        3. Recursively sort the right half.
        4. Merge both sorted halves.

    Time Complexity:
        Best Case:    O(n log n)
        Average Case: O(n log n)
        Worst Case:   O(n log n)

    Space Complexity:
        O(n)

    Stable:
        Yes
*/


void printArray(const vector<int>& nums) {

    cout << "[ ";

    for (int value : nums) {

        cout << value << " ";
    }

    cout << "]" << endl;
}


void mergeArrays(
    vector<int>& nums,
    int left,
    int middle,
    int right
) {

    int leftSize = middle - left + 1;

    int rightSize = right - middle;


    vector<int> leftArray(leftSize);

    vector<int> rightArray(rightSize);


    /*
        Copy data into temporary arrays.
    */

    for (int i = 0; i < leftSize; i++) {

        leftArray[i] = nums[left + i];
    }


    for (int j = 0; j < rightSize; j++) {

        rightArray[j] = nums[middle + 1 + j];
    }


    int i = 0;

    int j = 0;

    int k = left;


    /*
        Merge both arrays.
    */

    while (
        i < leftSize &&
        j < rightSize
    ) {

        if (leftArray[i] <= rightArray[j]) {

            nums[k] = leftArray[i];

            i++;
        }

        else {

            nums[k] = rightArray[j];

            j++;
        }

        k++;
    }


    /*
        Copy remaining left elements.
    */

    while (i < leftSize) {

        nums[k] = leftArray[i];

        i++;

        k++;
    }


    /*
        Copy remaining right elements.
    */

    while (j < rightSize) {

        nums[k] = rightArray[j];

        j++;

        k++;
    }
}


void mergeSort(
    vector<int>& nums,
    int left,
    int right
) {

    /*
        Base condition.
    */

    if (left >= right) {

        return;
    }


    int middle = left + (right - left) / 2;


    /*
        Sort left half.
    */

    mergeSort(
        nums,
        left,
        middle
    );


    /*
        Sort right half.
    */

    mergeSort(
        nums,
        middle + 1,
        right
    );


    /*
        Merge sorted halves.
    */

    mergeArrays(
        nums,
        left,
        middle,
        right
    );
}


int main() {

    vector<int> nums = {

        38,
        27,
        43,
        3,
        9,
        82,
        10
    };


    cout << "Original Array:" << endl;

    printArray(nums);


    mergeSort(
        nums,
        0,
        nums.size() - 1
    );


    cout << endl;

    cout << "Sorted Array:" << endl;

    printArray(nums);


    return 0;
}
```

## 5. Quick Sort — Full C++ Program

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    QUICK SORT
    ============================================================

    Quick Sort is a Divide and Conquer algorithm.

    Steps:

        1. Choose a pivot.
        2. Place smaller elements before pivot.
        3. Place larger elements after pivot.
        4. Recursively sort both parts.

    Time Complexity:

        Best:       O(n log n)
        Average:    O(n log n)
        Worst:      O(n^2)

    Space:

        Average recursion:
            O(log n)

    In-place:
        Yes
*/


void printArray(const vector<int>& nums) {

    cout << "[ ";

    for (int value : nums) {

        cout << value << " ";
    }

    cout << "]" << endl;
}


int partitionArray(
    vector<int>& nums,
    int low,
    int high
) {

    /*
        Choose last element as pivot.
    */

    int pivot = nums[high];


    /*
        i represents boundary of elements
        smaller than or equal to pivot.
    */

    int i = low - 1;


    for (int j = low; j < high; j++) {

        if (nums[j] <= pivot) {

            i++;

            swap(
                nums[i],
                nums[j]
            );
        }
    }


    /*
        Put pivot into correct position.
    */

    swap(
        nums[i + 1],
        nums[high]
    );


    return i + 1;
}


void quickSort(
    vector<int>& nums,
    int low,
    int high
) {

    /*
        Base condition.
    */

    if (low >= high) {

        return;
    }


    /*
        Partition array.
    */

    int pivotIndex = partitionArray(
        nums,
        low,
        high
    );


    /*
        Sort elements before pivot.
    */

    quickSort(
        nums,
        low,
        pivotIndex - 1
    );


    /*
        Sort elements after pivot.
    */

    quickSort(
        nums,
        pivotIndex + 1,
        high
    );
}


int main() {

    vector<int> nums = {

        10,
        7,
        8,
        9,
        1,
        5
    };


    cout << "Before Quick Sort:" << endl;

    printArray(nums);


    quickSort(
        nums,
        0,
        nums.size() - 1
    );


    cout << endl;

    cout << "After Quick Sort:" << endl;

    printArray(nums);


    return 0;
}
```

## 6. Binary Search — Full C++ Program

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    BINARY SEARCH
    ============================================================

    Binary Search works only on a sorted array.

    At every step:

        1. Find middle element.
        2. If middle == target, return index.
        3. If target > middle, search right half.
        4. Otherwise search left half.

    Time Complexity:

        O(log n)

    Space Complexity:

        O(1)

    Requirement:

        Array must be sorted.
*/


void printArray(const vector<int>& nums) {

    cout << "[ ";

    for (int value : nums) {

        cout << value << " ";
    }

    cout << "]" << endl;
}


int binarySearch(
    const vector<int>& nums,
    int target
) {

    int left = 0;

    int right = nums.size() - 1;


    while (left <= right) {

        /*
            Overflow-safe middle calculation.
        */

        int middle =
            left + (right - left) / 2;


        /*
            Target found.
        */

        if (nums[middle] == target) {

            return middle;
        }


        /*
            Search right half.
        */

        if (nums[middle] < target) {

            left = middle + 1;
        }


        /*
            Search left half.
        */

        else {

            right = middle - 1;
        }
    }


    /*
        Target doesn't exist.
    */

    return -1;
}


int main() {

    vector<int> nums = {

        2,
        5,
        8,
        12,
        16,
        23,
        38,
        56,
        72,
        91
    };


    int target = 23;


    cout << "Array:" << endl;

    printArray(nums);


    cout << endl;

    cout << "Target: "
         << target
         << endl;


    int result = binarySearch(
        nums,
        target
    );


    if (result != -1) {

        cout << "Target found at index: "
             << result
             << endl;
    }

    else {

        cout << "Target not found."
             << endl;
    }


    return 0;
}
```

## The complete set I recommend

For a full **C++ DSA algorithm notebook**, I'd organize it into these 30 standalone algorithms:

1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
5. Quick Sort
6. Binary Search
7. Two Pointers
8. Sliding Window
9. Prefix Sum
10. Kadane's Algorithm
11. Hash Map Frequency Counting
12. Stack
13. Monotonic Stack
14. Queue and BFS
15. DFS
16. Linked List Reversal
17. Floyd's Cycle Detection
18. Binary Tree DFS Traversals
19. Binary Tree Level Order BFS
20. Backtracking
21. Dynamic Programming
22. 0/1 Knapsack
23. Longest Common Subsequence
24. Longest Increasing Subsequence
25. Heap / Priority Queue
26. Dijkstra's Algorithm
27. Union-Find / DSU
28. Topological Sort
29. Kruskal's MST
30. Bit Manipulation

For interview preparation, prioritize **Binary Search, Two Pointers, Sliding Window, Prefix Sum, Hash Map, Stack, BFS, DFS, Trees, Backtracking, DP, Heap, DSU, Dijkstra, and Topological Sort**. These give you much more value than spending too much time on elementary sorts like Bubble, Selection, and Insertion Sort.
