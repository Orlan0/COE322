//COE_322_hw_8
//Name: Orlan Oconer & Dominic Nguyen
//Eid: ojo366 & dhn454
//TACC username: orlan & dnguyen_3002 

//Based on the problem statement there is two classes: Storage and Pascal


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Storage {
private:
    // One vector to store Pascal's triangle in 1D form
    std::vector<int> triangle;

    // Helper function to calculate the index in a 1D array for the (i, j) element
    int index(int i, int j) {
        return (i * (i + 1)) / 2 + j;  
    }

public:
    // Takes the value of n and puts it in genRows
    Storage(int n){
        genRows(n);
    }

    void genRows(int n){
        // Resize the vector to fit the entire Pascal's triangle up to row n
        int totalSize = (n * (n + 1)) / 2;
        if (triangle.size() < totalSize) {
            triangle.resize(totalSize, 1);  // Set all initial values to 1
        }

        for(int r = 2; r < n; ++r){  // Start from row 2 because row 0 and row 1 are already correct
            for (int c = 1; c < r; ++c){
                // Access elements using the index function and calculate values
                triangle[index(r, c)] = triangle[index(r - 1, c - 1)] + triangle[index(r - 1, c)];
            }
        }
    }

    // Retrieval; regenerates everything up until that specific row
    std::vector<int> getRow(int row){
        int totalSize = (row * (row + 1)) / 2;
        if (totalSize >= triangle.size()){
            genRows(row + 1);
        }
        std::vector<int> result(row + 1);
        for (int i = 0; i <= row; ++i) {
            result[i] = triangle[index(row, i)];
        }
        return result;
    }

    // Checks the numbers and then calls getRow to get the number
    int getValue (int i, int j){
        if (i < 0 || j < 0 || j > i){
            cout <<"Invalid numbers brahhh :(" << endl;
            return -1;  // Return a default value for invalid inputs
        }
        return triangle[index(i, j)];
    }

    void printTriangle(){
        int maxRows = 0;
        while ((maxRows * (maxRows + 1)) / 2 <= triangle.size()) {
            ++maxRows;
        }
        int width = 2 * maxRows;

        for (int r = 0; r < maxRows-1; ++r){
            // Calculating how many spaces are needed to print a symmetrical pyramid
            int spaces = (width - (2 * r + 1)) / 2;
            // This creates how many spaces are between each one
            std::string space_bars(spaces, ' ');
            cout << space_bars;
            for (int c = 0; c <= r; ++c){  // Use <= to print all columns in the row
                cout << triangle[index(r, c)] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Storage storage(10);
    
    storage.printTriangle();

    cout << "Val at (5,3): " << storage.getValue(5, 3) << endl;
    cout << "Val at (2,1): " << storage.getValue(2, 1) << endl;

    return 0;
}
