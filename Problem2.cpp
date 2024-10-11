#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Bubble Sort Function
void bubbleSort(vector<int>& times) {
    int n = times.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (times[j] > times[j + 1]) {
                swap(times[j], times[j + 1]);
            }
        }
    }
}

// Merge Sort Helper Functions
void merge(vector<int>& times, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = times[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = times[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            times[k] = L[i];
            i++;
        } else {
            times[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        times[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        times[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& times, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(times, left, mid);
        mergeSort(times, mid + 1, right);

        merge(times, left, mid, right);
    }
}

int main() {
    int N;
    cout << "Enter the number of delivery times: ";
    cin >> N;

    vector<int> deliveryTimes(N);
    cout << "Enter the delivery times in minutes:\n";
    for (int i = 0; i < N; i++) {
        cin >> deliveryTimes[i];
    }

    // Bubble Sort
    vector<int> bubbleSortedTimes = deliveryTimes;
    auto start = high_resolution_clock::now();
    bubbleSort(bubbleSortedTimes);
    auto end = high_resolution_clock::now();
    auto bubbleDuration = duration_cast<microseconds>(end - start);
    
    // Output Bubble Sort result
    cout << "\nBubble Sort - Sorted times:\n";
    for (int time : bubbleSortedTimes) {
        cout << time << " ";
    }
    cout << "\nBubble Sort Time: " << bubbleDuration.count() << " microseconds\n";

    // Merge Sort
    vector<int> mergeSortedTimes = deliveryTimes;
    start = high_resolution_clock::now();
    mergeSort(mergeSortedTimes, 0, N - 1);
    end = high_resolution_clock::now();
    auto mergeDuration = duration_cast<microseconds>(end - start);

    // Output Merge Sort result
    cout << "\nMerge Sort - Sorted times:\n";
    for (int time : mergeSortedTimes) {
        cout << time << " ";
    }
    cout << "\nMerge Sort Time: " << mergeDuration.count() << " microseconds\n";

    // Time Complexity Explanation
    cout << "\nTime Complexity Analysis:\n";
    cout << "Bubble Sort: O(N^2) - Inefficient for large datasets due to its nested loops.\n";
    cout << "Merge Sort: O(N log N) - More efficient for larger datasets due to its divide-and-conquer approach.\n";

    return 0;
}
