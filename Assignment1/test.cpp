#include <iostream>
#include <cmath>

using namespace std;

class Matrix 
{
private:
    int row;
    int col;

public:
    void setRow(int Row) {
        row = Row;
    }
    int getRow()
    {
        return row;
    }
    //function to print matrix
    void print_matrix()
    {
        cout << "Row - " << row;
        cout << "Column - " << col;

    }
    //Matrix constructor function
    Matrix(int Row, int Col)
    {
        row = Row;
        col = Col;
        
    }
};



int main()
{
    Matrix m1 = Matrix(2,2);
    m1.
}