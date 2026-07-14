Yes. To make your **C++ DSA algorithm collection genuinely complete**, add more than the original 30. A strong collection should contain around **60–70 important algorithms and patterns**, with each one written as a separate copy-pasteable C++ program.

Below is an expanded roadmap. After that, I've added more full-length algorithms in the same format.

## Complete C++ DSA Algorithm Collection

1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
5. Quick Sort
6. Heap Sort
7. Counting Sort
8. Binary Search
9. Lower Bound
10. Upper Bound
11. Binary Search on Answer
12. Two Pointers
13. Sliding Window — Fixed Size
14. Sliding Window — Variable Size
15. Prefix Sum
16. Difference Array
17. Kadane's Algorithm
18. Boyer-Moore Majority Vote
19. Dutch National Flag Algorithm
20. Hash Map Frequency Counting
21. Stack
22. Monotonic Stack
23. Queue
24. Deque
25. BFS
26. DFS
27. Flood Fill
28. Number of Connected Components
29. Cycle Detection in Undirected Graph
30. Cycle Detection in Directed Graph
31. Linked List Reversal
32. Floyd's Cycle Detection
33. Find Middle of Linked List
34. Merge Two Sorted Linked Lists
35. Binary Tree Preorder
36. Binary Tree Inorder
37. Binary Tree Postorder
38. Level Order Traversal
39. Tree Diameter
40. Lowest Common Ancestor
41. BST Search and Insert
42. Backtracking — Subsets
43. Backtracking — Permutations
44. Combination Sum
45. N-Queens
46. Dynamic Programming — Fibonacci
47. Climbing Stairs
48. House Robber
49. 0/1 Knapsack
50. Coin Change
51. Longest Common Subsequence
52. Longest Increasing Subsequence
53. Edit Distance
54. Grid DP
55. Heap / Priority Queue
56. Dijkstra's Algorithm
57. Bellman-Ford Algorithm
58. Floyd-Warshall Algorithm
59. Union-Find / DSU
60. Kruskal's MST
61. Prim's MST
62. Topological Sort — Kahn's Algorithm
63. Topological Sort — DFS
64. Trie
65. KMP String Matching
66. Rabin-Karp
67. Sieve of Eratosthenes
68. GCD and LCM
69. Fast Exponentiation
70. Bit Manipulation

Here are more full-length copy-paste programs.

## 7. Heap Sort — Full C++ Program

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    HEAP SORT
    ============================================================

    Heap Sort uses a Binary Heap data structure.

    Main steps:

        1. Convert the array into a Max Heap.
        2. The largest element is now at index 0.
        3. Swap it with the last unsorted element.
        4. Reduce the heap size.
        5. Restore the Max Heap property.
        6. Repeat until the array is sorted.

    Time Complexity:

        Build Heap: O(n)

        Sorting:
            O(n log n)

        Overall:
            O(n log n)

    Space Complexity:

        O(log n) recursive stack

        Can be considered O(1) auxiliary space
        with iterative heapify.

    Stable:

        No

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


void heapify(
    vector<int>& nums,
    int heapSize,
    int root
) {

    /*
        Assume root is largest.
    */

    int largest = root;


    /*
        Calculate child indices.
    */

    int leftChild = 2 * root + 1;

    int rightChild = 2 * root + 2;


    /*
        Check whether left child is larger.
    */

    if (
        leftChild < heapSize &&
        nums[leftChild] > nums[largest]
    ) {

        largest = leftChild;
    }


    /*
        Check whether right child is larger.
    */

    if (
        rightChild < heapSize &&
        nums[rightChild] > nums[largest]
    ) {

        largest = rightChild;
    }


    /*
        If root isn't largest,
        swap and recursively heapify.
    */

    if (largest != root) {

        swap(
            nums[root],
            nums[largest]
        );


        heapify(
            nums,
            heapSize,
            largest
        );
    }
}


void heapSort(vector<int>& nums) {

    int n = nums.size();


    /*
        STEP 1:

        Build Max Heap.

        Last non-leaf node:

            n / 2 - 1
    */

    for (
        int i = n / 2 - 1;
        i >= 0;
        i--
    ) {

        heapify(
            nums,
            n,
            i
        );
    }


    /*
        STEP 2:

        Extract largest elements one by one.
    */

    for (
        int end = n - 1;
        end > 0;
        end--
    ) {

        /*
            Largest element is at index 0.

            Move it to the end.
        */

        swap(
            nums[0],
            nums[end]
        );


        /*
            Restore heap property for
            remaining unsorted portion.
        */

        heapify(
            nums,
            end,
            0
        );
    }
}


int main() {

    vector<int> nums = {

        12,
        11,
        13,
        5,
        6,
        7
    };


    cout << "Original Array:" << endl;

    printArray(nums);


    heapSort(nums);


    cout << endl;

    cout << "Sorted Array:" << endl;

    printArray(nums);


    return 0;
}
```

## 8. Two Pointers — Pair Sum

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    TWO POINTERS
    ============================================================

    Problem:

        Given an array and a target,
        determine whether two elements have
        a sum equal to the target.

    Approach:

        1. Sort the array.
        2. Place one pointer at the beginning.
        3. Place another pointer at the end.

        If:

            nums[left] + nums[right] == target
                Answer found.

            Sum < target
                Move left forward.

            Sum > target
                Move right backward.

    Time Complexity:

        Sorting:
            O(n log n)

        Two-pointer scan:
            O(n)

        Overall:
            O(n log n)

    Space Complexity:

        Depends on sorting implementation.
*/


void printArray(const vector<int>& nums) {

    cout << "[ ";

    for (int number : nums) {

        cout << number << " ";
    }

    cout << "]" << endl;
}


bool findPairWithSum(
    vector<int> nums,
    int target
) {

    /*
        Sort first.
    */

    sort(
        nums.begin(),
        nums.end()
    );


    int left = 0;

    int right = nums.size() - 1;


    while (left < right) {

        long long currentSum =
            (long long) nums[left] +
            nums[right];


        /*
            Pair found.
        */

        if (currentSum == target) {

            cout << endl;

            cout << "Pair found: "
                 << nums[left]
                 << " + "
                 << nums[right]
                 << " = "
                 << target
                 << endl;

            return true;
        }


        /*
            Need larger sum.
        */

        if (currentSum < target) {

            left++;
        }


        /*
            Need smaller sum.
        */

        else {

            right--;
        }
    }


    return false;
}


int main() {

    vector<int> nums = {

        10,
        20,
        35,
        50,
        75,
        80
    };


    int target = 70;


    cout << "Original Array:" << endl;

    printArray(nums);


    cout << endl;

    cout << "Target = "
         << target
         << endl;


    bool result =
        findPairWithSum(
            nums,
            target
        );


    if (!result) {

        cout << "No valid pair found."
             << endl;
    }


    return 0;
}
```

## 9. Sliding Window — Fixed Size

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    FIXED-SIZE SLIDING WINDOW
    ============================================================

    Problem:

        Find the maximum sum among all
        contiguous subarrays of exactly size k.

    Brute Force:

        Calculate every window independently.

        Time:
            O(n * k)

    Sliding Window:

        Calculate the first window once.

        When moving forward:

            Add new element.
            Remove old element.

        Time:
            O(n)

    Example:

        nums = [2, 1, 5, 1, 3, 2]

        k = 3

        Windows:

            [2,1,5] = 8
            [1,5,1] = 7
            [5,1,3] = 9
            [1,3,2] = 6

        Answer:

            9
*/


long long maximumWindowSum(
    const vector<int>& nums,
    int k
) {

    int n = nums.size();


    /*
        Invalid window size.
    */

    if (
        k <= 0 ||
        k > n
    ) {

        return -1;
    }


    long long windowSum = 0;


    /*
        Build first window.
    */

    for (int i = 0; i < k; i++) {

        windowSum += nums[i];
    }


    long long maximumSum =
        windowSum;


    /*
        Slide window.
    */

    for (
        int right = k;
        right < n;
        right++
    ) {

        /*
            Add new right element.
        */

        windowSum += nums[right];


        /*
            Remove element leaving window.
        */

        windowSum -= nums[right - k];


        /*
            Update maximum.
        */

        maximumSum = max(
            maximumSum,
            windowSum
        );
    }


    return maximumSum;
}


int main() {

    vector<int> nums = {

        2,
        1,
        5,
        1,
        3,
        2
    };


    int k = 3;


    long long answer =
        maximumWindowSum(
            nums,
            k
        );


    cout << "Maximum sum of a subarray "
         << "of size "
         << k
         << " is: "
         << answer
         << endl;


    return 0;
}
```

## 10. Prefix Sum — Range Query

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    PREFIX SUM
    ============================================================

    Prefix Sum allows fast range-sum queries.

    Given:

        nums = [2, 4, 6, 8, 10]

    Build:

        prefix[0] = 0
        prefix[1] = 2
        prefix[2] = 6
        prefix[3] = 12
        prefix[4] = 20
        prefix[5] = 30

    To calculate sum from index l to r:

        prefix[r + 1] - prefix[l]

    Example:

        l = 1
        r = 3

        nums[1..3] = [4,6,8]

        sum = 18

    Complexity:

        Build:
            O(n)

        Each query:
            O(1)

        Space:
            O(n)
*/


vector<long long> buildPrefixSum(
    const vector<int>& nums
) {

    int n = nums.size();


    vector<long long> prefix(
        n + 1,
        0
    );


    for (int i = 0; i < n; i++) {

        prefix[i + 1] =
            prefix[i] + nums[i];
    }


    return prefix;
}


long long rangeSum(
    const vector<long long>& prefix,
    int left,
    int right
) {

    return
        prefix[right + 1] -
        prefix[left];
}


int main() {

    vector<int> nums = {

        2,
        4,
        6,
        8,
        10
    };


    /*
        Build prefix array once.
    */

    vector<long long> prefix =
        buildPrefixSum(nums);


    /*
        Example queries.
    */

    vector<pair<int, int>> queries = {

        {0, 2},
        {1, 3},
        {2, 4},
        {0, 4}
    };


    for (auto query : queries) {

        int left = query.first;

        int right = query.second;


        long long answer =
            rangeSum(
                prefix,
                left,
                right
            );


        cout << "Sum from index "
             << left
             << " to "
             << right
             << " = "
             << answer
             << endl;
    }


    return 0;
}
```

## 11. Kadane's Algorithm — Maximum Subarray

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    KADANE'S ALGORITHM
    ============================================================

    Problem:

        Find the maximum possible sum of
        a contiguous subarray.

    Core decision:

        At every index, either:

            1. Start a new subarray here.

        OR

            2. Extend the previous subarray.

    Formula:

        currentSum =
            max(
                nums[i],
                currentSum + nums[i]
            )

    Then:

        maximumSum =
            max(
                maximumSum,
                currentSum
            )

    Example:

        nums =
            [-2,1,-3,4,-1,2,1,-5,4]

        Best subarray:

            [4,-1,2,1]

        Sum:

            6

    Time Complexity:

        O(n)

    Space Complexity:

        O(1)
*/


long long maximumSubarraySum(
    const vector<int>& nums
) {

    if (nums.empty()) {

        return 0;
    }


    long long currentSum =
        nums[0];


    long long maximumSum =
        nums[0];


    for (
        int i = 1;
        i < nums.size();
        i++
    ) {

        /*
            Decide whether to:

                Start fresh at nums[i]

            OR

                Extend previous subarray.
        */

        currentSum = max(
            (long long) nums[i],

            currentSum + nums[i]
        );


        /*
            Update global maximum.
        */

        maximumSum = max(
            maximumSum,
            currentSum
        );
    }


    return maximumSum;
}


int main() {

    vector<int> nums = {

        -2,
        1,
        -3,
        4,
        -1,
        2,
        1,
        -5,
        4
    };


    long long answer =
        maximumSubarraySum(nums);


    cout << "Maximum Subarray Sum = "
         << answer
         << endl;


    return 0;
}
```

## 12. Boyer-Moore Majority Vote Algorithm

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    BOYER-MOORE MAJORITY VOTE ALGORITHM
    ============================================================

    Problem:

        Find an element occurring more than n / 2 times.

    Core idea:

        Maintain:

            candidate
            count

        If count becomes 0:

            Choose current element as candidate.

        If current element equals candidate:

            Increment count.

        Otherwise:

            Decrement count.

    Why it works:

        Every different element cancels one occurrence
        of the majority element.

        Since the majority appears more than n / 2 times,
        it cannot be completely cancelled.

    Time Complexity:

        O(n)

    Space Complexity:

        O(1)
*/


int findMajorityCandidate(
    const vector<int>& nums
) {

    int candidate = 0;

    int count = 0;


    for (int number : nums) {

        /*
            Select new candidate.
        */

        if (count == 0) {

            candidate = number;
        }


        /*
            Vote.
        */

        if (number == candidate) {

            count++;
        }

        else {

            count--;
        }
    }


    return candidate;
}


int majorityElement(
    const vector<int>& nums
) {

    if (nums.empty()) {

        return -1;
    }


    int candidate =
        findMajorityCandidate(nums);


    /*
        Verification step.

        Necessary if the problem doesn't guarantee
        that a majority element exists.
    */

    int frequency = 0;


    for (int number : nums) {

        if (number == candidate) {

            frequency++;
        }
    }


    if (
        frequency >
        nums.size() / 2
    ) {

        return candidate;
    }


    return -1;
}


int main() {

    vector<int> nums = {

        2,
        2,
        1,
        1,
        1,
        2,
        2
    };


    int answer =
        majorityElement(nums);


    if (answer == -1) {

        cout << "No majority element exists."
             << endl;
    }

    else {

        cout << "Majority Element = "
             << answer
             << endl;
    }


    return 0;
}
```

## 13. Dutch National Flag Algorithm

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    DUTCH NATIONAL FLAG ALGORITHM
    ============================================================

    Problem:

        Sort an array containing only:

            0
            1
            2

    Example:

        Input:
            [2,0,2,1,1,0]

        Output:
            [0,0,1,1,2,2]

    We maintain three pointers:

        low
        mid
        high

    Regions:

        [0 ... low-1]
            Contains only 0s.

        [low ... mid-1]
            Contains only 1s.

        [mid ... high]
            Unknown.

        [high+1 ... n-1]
            Contains only 2s.

    Time Complexity:

        O(n)

    Space Complexity:

        O(1)
*/


void sortColors(vector<int>& nums) {

    int low = 0;

    int mid = 0;

    int high = nums.size() - 1;


    while (mid <= high) {

        /*
            Current value is 0.

            Move it to beginning.
        */

        if (nums[mid] == 0) {

            swap(
                nums[low],
                nums[mid]
            );

            low++;

            mid++;
        }


        /*
            Current value is 1.

            Already in correct middle region.
        */

        else if (nums[mid] == 1) {

            mid++;
        }


        /*
            Current value is 2.

            Move it to end.

            Do NOT increment mid because the
            swapped value from high hasn't been
            processed yet.
        */

        else {

            swap(
                nums[mid],
                nums[high]
            );

            high--;
        }
    }
}


void printArray(
    const vector<int>& nums
) {

    cout << "[ ";

    for (int number : nums) {

        cout << number << " ";
    }

    cout << "]" << endl;
}


int main() {

    vector<int> nums = {

        2,
        0,
        2,
        1,
        1,
        0
    };


    cout << "Before:" << endl;

    printArray(nums);


    sortColors(nums);


    cout << endl;

    cout << "After:" << endl;

    printArray(nums);


    return 0;
}
```

## 14. Monotonic Stack — Next Greater Element

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    ============================================================
    MONOTONIC STACK
    ============================================================

    Problem:

        For every element, find the first greater
        element appearing to its right.

    Example:

        nums =
            [2, 1, 2, 4, 3]

        Answer:
            [4, 2, 4, -1, -1]

    We maintain a stack of indices whose next
    greater element hasn't been found yet.

    When nums[i] is greater than the element
    represented by the stack top:

        nums[i] is the answer for that index.

    Time Complexity:

        O(n)

    Why O(n)?

        Every index is:

            Pushed once.
            Popped at most once.

    Space Complexity:

        O(n)
*/


vector<int> nextGreaterElement(
    const vector<int>& nums
) {

    int n = nums.size();


    vector<int> answer(
        n,
        -1
    );


    stack<int> indices;


    for (int i = 0; i < n; i++) {

        /*
            Resolve all smaller elements
            waiting in the stack.
        */

        while (
            !indices.empty() &&
            nums[i] >
            nums[indices.top()]
        ) {

            int index =
                indices.top();

            indices.pop();


            answer[index] =
                nums[i];
        }


        /*
            Current index now waits for
            its next greater element.
        */

        indices.push(i);
    }


    return answer;
}


void printArray(
    const vector<int>& nums
) {

    cout << "[ ";

    for (int number : nums) {

        cout << number << " ";
    }

    cout << "]" << endl;
}


int main() {

    vector<int> nums = {

        2,
        1,
        2,
        4,
        3
    };


    vector<int> answer =
        nextGreaterElement(nums);


    cout << "Input:" << endl;

    printArray(nums);


    cout << endl;

    cout << "Next Greater Elements:" << endl;

    printArray(answer);


    return 0;
}
```

For your goal, I would build the complete collection in this sequence: **arrays and searching first, then linked lists and stacks, then trees and graphs, then dynamic programming and advanced algorithms**. The next highest-value additions are **variable-size sliding window, difference arrays, BFS, DFS, linked-list reversal, Floyd cycle detection, tree traversals, backtracking, 0/1 knapsack, LCS, LIS, Dijkstra, DSU, topological sort, Trie, KMP, sieve, and fast exponentiation**.

