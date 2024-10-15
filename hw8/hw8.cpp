//COE_322_hw_8
//Name: Orlan Oconer 
//Eid: ojo366
//TACC username: orlan 

//Based on the problem statement there is two classes: Storage and Pascal
#include <iostream> 
#include <vector> 
#include <string> 
using namespace std; 

class Storage {
private:
    //two vectors == [x,y], this is the basis of the triangle 
    std::vector<std::vector<int>> triangle; 
public: 
    //takes the value of n and puts it in genRows 
    Storage(int n){
        genRows(n); 
    }
    void genRows(int n){
        //start the loop, this is the max size of the triangel 
        int size = triangle.size(); 
        for(int r = size; r<n; ++r){
            //starts the number of each row into 1 
            std::vector<int> row(r+1,1);
            for (int c = 1; c< r; ++c){
                row[c] = triangle[r-1][c-1] + triangle[r-1][c];
            }   
            triangle.push_back(row); 
        }
    }
    //retrieval; what this does it that it regenerates everything up until that specific row; 
    std::vector<int> getRow(int row){
        if (row>= triangle.size()){
            genRows(row +1); 
        }
        return triangle[row]; 
    }
    // checks the numbers and then calls getRow to get the number 
    int getValue (int i, int j){
        if (i < 0 || j < 0 || j>i){
            cout <<"Invalid numbers brahhh :(" << endl; 
            return -1;  // Return a default value for invalid inputs
        }
        return getRow(i)[j]; 
    }
    void printTriangle(){
        int maxRows = triangle.size(); 
        int width = 2*maxRows; 

        for (int r = 0; r < maxRows; ++r){
            //calculating how many spaces are needed to pring a symmetrical pyramid 
            int spaces = (width - (2*r+1)) / 2;
            // this creates how many spaces are between each one 
            std::string space_bars(spaces, ' ');
            cout << space_bars; 
                for (int c = 0; c <= r; ++c){  // Use <= to print all columns in the row
                    cout << triangle[r][c] << " "; 
                }
            cout << endl; 
        }
    }
};

class Pascal{
private: 
    //this stores the triangle
    Storage triangleStorage;
    //this is the current rows 
    int current_rows; 

public:
    Pascal(int n): triangleStorage(n), current_rows(n){};
    // this be the same as 
    /*
    Pascal(int n) {
    triangleStorage = Storage(n);  
    current_rows = n;              
    }*/
   int getValue(int i, int j){
    return triangleStorage.getValue(i,j); 
   }
   void print(){
    triangleStorage.printTriangle();  // No return, just call the function
   }
   void extend(int row){
    if (row>= current_rows){ 
        triangleStorage.genRows(row+1); 
        current_rows = row + 1; 
    }
   }
};

int main(){
    Pascal pascal(10);
    pascal.print(); 
    cout << "Val at (5,3):" << pascal.getValue(5,3) << endl; 
    cout << "Val at (2,1):" << pascal.getValue(2,1) << endl; 
    return 0;
}
