#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> aset;

    // Inserting elements into the set
    aset.insert(10);
    aset.insert(20);
    aset.insert(30);

    // Attempting to insert a duplicate element
    aset.insert(20);  // This will have no effect since 20 is already in the set

    // Displaying the set elements
    cout << "Set elements: ";
    for (int elem : aset) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
