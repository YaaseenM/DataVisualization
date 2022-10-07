#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace std;

int main() {
    /* Overall flow of the program:
   Get some input for the title
   Get some input for column header #1
   Get some input for column header #2

   Until the user types "-1":
   Get input for a string
   Validate input
   If valid...
      Split
      Validate second half of input
      If also valid...
         Store separate pieces

   Print out data in table format

   Print out data in chart format
   */

    /* Type code here. */
    // Receive Title for Graph
    cout << "Enter a title for the data:" << endl;
    string title;
    getline(cin, title);
    cout << "You entered: " << title << endl;

    // Naming Columns
    cout << "Enter the column 1 header:" << endl;
    string column1;
    getline(cin, column1);
    cout << "You entered: " << column1 << endl;

    cout << "Enter the column 2 header:" << endl;
    string column2;
    getline(cin, column2);
    cout << "You entered: " << column2 << endl;

    // Get info each entry for each column
    bool exit = true;
    vector<string> names;
    vector<int> nums;
    while (exit) {
        // All try, throw, and catch are used to make sure the input is proper
        try {
            cout << "Enter a data point (-1 to stop input):" << endl;
            string lineInput;
            string nameInput;
            string numInputString;
            int numInput;

            getline(cin, lineInput);
            istringstream iss(lineInput);

            // Check commas
            int commaCount = 0;
            for (unsigned int i = 0; i < lineInput.length(); i++) {
                if (lineInput[i] == ',') {
                    commaCount++;
                }
            }
            if (commaCount == 0) {
                if (lineInput == "-1") {
                    exit = true;
                    break;
                }
                throw runtime_error("Error: No comma in string.");
            }
            if (commaCount > 1) {
                throw runtime_error("Error: Too many commas in input.");
            }
            getline(iss, nameInput, ',');
            getline(iss, numInputString);

            // Check if the numInputString can be turned into an int
            try {
                numInput = stoi(numInputString);
                cout << "Data string: " << nameInput << endl;
                cout << "Data integer: " << numInput << endl;
                names.push_back(nameInput);
                nums.push_back(numInput);
            } catch (...) {
                cout << "Error: Comma not followed by an integer." << endl;
            }
        } catch (runtime_error &excpt) {
            cout << excpt.what() << endl;
        }
    }
    cout << endl;

    // Create the graph in a neat format
    cout << setw(33) << title << endl;
    cout << column1 << setw(20 - (column1.size() - 1));
    cout << "|";
    cout << setw(23) << column2 << endl;
    for (int i = 0; i < 44; i++) {
        cout << "-";
    }
    cout << endl;

    // Create a number of asterisks based on the number given next to the name entry with
    for (unsigned int i = 0; i < names.size(); i++) {
        cout << names[i] << setw(20 - (names[i].size() - 1));
        cout << "|";
        cout << setw(23) << nums[i] << endl;
    }
    cout << endl;
    for (unsigned int i = 0; i < names.size(); i++) {
        cout << setw(20) << names[i];
        cout << " ";
        for (int j = 0; j < nums[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}