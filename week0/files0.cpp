// Illustrates output formatting instructions.
// Read all the numbers in the file rawdata.dat and write the numbers
// to the screen and to the file neat.dat in a neatly formatted way.

#include <cstdlib>  // for the exit function
#include <fstream>  // for I/O member functions
#include <iomanip>  // for the setw function
#include <iostream> // for cout
using namespace std;
void make_neat(
    ifstream &messy_file,
    ofstream &neat_file,
    int number_after_decimalpoint,
    int field_width);

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("rawdata.txt");
    if (fin.fail()) { // oops the file did not exist for reading?
        cout << "Input file opening failed." << endl;
        exit(1);
    }

    fout.open("neat.txt");
    if (fout.fail()) { // oops the output file open failed!
        cout << "Output file opening failed.\n";
        exit(1);
    }
    make_neat(fin, fout, 5, 12);

    fin.close();
    fout.close();
    cout << "End of program." << endl;
    return 0;
}
// Uses iostreams, streams to the screen, and iomanip:
void make_neat(
    ifstream &messy_file,
    ofstream &neat_file,
    int number_after_decimalpoint,
    int field_width) {
    // set the format for the neater output file.
    neat_file.setf(ios::fixed);
    neat_file.setf(ios::showpoint);
    neat_file.setf(ios::showpos);
    neat_file.precision(number_after_decimalpoint);
    // set the format for the output to the screen too.
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);
    cout.precision(number_after_decimalpoint);
    double next;
    while (messy_file >> next) { // while there is still stuff to read
        cout << setw(field_width) << next << endl;
        neat_file << setw(field_width) << next << endl;
    }
}

// Code by Jan Pearce