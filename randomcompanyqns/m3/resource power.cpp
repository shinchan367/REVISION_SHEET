#include <iostream>
using namespace std;

int Resource(int A, int B, int C) {
    // Find the maximum number of mixed groups (one of each type)
    int mixedGroups = min({A, B, C});
    
    // Remove used resources
    A -= mixedGroups;
    B -= mixedGroups;
    C -= mixedGroups;
    
    // Find the maximum number of same-type groups
    int sameTypeGroups = (A / 3) + (B / 3) + (C / 3);
    
    // Return total maximum valid groups
    return mixedGroups + sameTypeGroups;
}

int main() {
    int A, B, C;
    cout << "Enter values for A, B, and C: ";
    cin >> A >> B >> C;
    
    cout << "Maximum valid resource systems: " << Resource(A, B, C) << endl;
    
    return 0;
}
