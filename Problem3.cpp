#include <iostream>

using namespace std;

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int N, char source, char destination, char buffer) {
    if (N == 1) {
        cout << "Move package 1 from " << source << " to " << destination << endl;
        return;
    }
    // Move N-1 packages from source to buffer, using destination as buffer
    towerOfHanoi(N - 1, source, buffer, destination);
    
    // Move the Nth package from source to destination
    cout << "Move package " << N << " from " << source << " to " << destination << endl;
    
    // Move the N-1 packages from buffer to destination, using source as buffer
    towerOfHanoi(N - 1, buffer, destination, source);
}

int main() {
    int N;
    cout << "Enter the number of packages (discs): ";
    cin >> N;

    // Call the recursive Tower of Hanoi function
    towerOfHanoi(N, 'A', 'C', 'B'); // A is the source, C is the destination, B is the buffer

    // Output the total number of moves
    cout << "\nTotal number of moves required: " << (1 << N) - 1 << endl; // 2^N - 1 moves

    return 0;
}
