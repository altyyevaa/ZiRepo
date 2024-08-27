#include <fstream>
#include <iostream>
using namespace std;

void printFile(char filename[32]) {
    ifstream in_stream;
    in_stream.open(filename);

    if (!in_stream.good()) {
        // Throws an error
            in_stream.close();

        throw "\nA file by that name does not exist!";
    }

    char ch;

    cout<<endl;
    while (!in_stream.eof()) {
        cout << ch;
        ch = in_stream.get();
    }
    cout << endl;

    in_stream.close();
}

int main() {
    char filename[32];
    cout << "Filename: ";
    cin >> filename;

    try {
        // Tries to print the file
        printFile(filename);
    }
    catch (const char *msg) {
        // Runs if error is thrown
        cerr << msg << endl; //cerr is used to output errors similar to cout.

        // Uses default file to print instead
        try {
            char defaultFile[32] = "file.txt";
            printFile(defaultFile);
        }
        catch (const char *msg) {
            cerr << "Default file not found!" << endl; //cerr is used to output errors similar to cout.
        }
    }

    return 0;
}