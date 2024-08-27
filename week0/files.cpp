#include <cstdlib>  // for the exit function
#include <fstream>  // for I/O member functions
#include <iostream> // for cout
using namespace std; // To avoid writing std:: before standard library components

int main() 
{
    // Declare variables for file names and file streams
    char in_file_name[16], // Arrays to store filenames (max 15 chars + null terminator)
        out_file_name[16]; 
    ifstream in_stream; // Input file stream object
    ofstream out_stream;// Output file stream object

    // Prompt the user for input and output file names
    cout << "This program will sum three numbers taken from an input\n"
         << "file and write the sum to an output file." << endl;
    cout << "Enter the input file name (maximum of 15 characters):\n";
    cin >> in_file_name;
    cout << "\nEnter the output file name (maximum of 15 characters):\n";
    cin >> out_file_name;
    cout << endl;

    // Condensed input and output file opening and checking.
    in_stream.open(in_file_name);
    out_stream.open(out_file_name);

    if (in_stream.fail() || out_stream.fail()) {
        cout << "Input or output file opening failed.\n";
        exit(1); // Terminate the program with an error code
    }

    // Declare variables to store numbers and their sum
    double firstn, secondn, thirdn, sum = 0.0;

    // Read the first three numbers from the input file
    cout << "Reading numbers from the file " << in_file_name << endl;
    in_stream >> firstn >> secondn >> thirdn;
    sum = firstn + secondn + thirdn;

    // The following set of lines will write to the screen
    cout << "The sum of the first 3 numbers from " << in_file_name << " is "
         << sum << endl;

    cout << "Placing the sum into the file " << out_file_name << endl;

    // The following set of lines will write to the output file
    out_stream << "The sum of the first 3 numbers from " << in_file_name
               << " is " << sum << endl;

    // Close the file streams
    in_stream.close();
    out_stream.close();

    cout << "End of Program." << endl;

    return 0;
}