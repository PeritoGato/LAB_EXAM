#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to compute the Euclidean distance between two points
double calculateDistance(pair<int, int> point1, pair<int, int> point2) {
    int x1 = point1.first, y1 = point1.second;
    int x2 = point2.first, y2 = point2.second;
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to compute the sum of the first N natural numbers
int sumOfNaturalNumbers(int N) {
    return N * (N + 1) / 2;
}

int main() {
    int N;
    cout << "Enter the number of delivery points: ";
    cin >> N;

    // Vector to store the coordinates of the delivery points
    vector<pair<int, int>> points(N);

    cout << "Enter the coordinates (x y) of the delivery points:\n";
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    // Calculate the total distance traveled
    double totalDistance = 0.0;
    for (int i = 1; i < N; i++) {
        totalDistance += calculateDistance(points[i - 1], points[i]);
    }

    // Calculate the sum of the first N natural numbers
    int sumNatural = sumOfNaturalNumbers(N);

    // Output results
    cout << "\nTotal distance traveled: " << totalDistance << endl;
    cout << "Sum of the first " << N << " natural numbers: " << sumNatural << endl;

    return 0;
}
