#include <iostream>
#include <cmath>

using namespace std;

class Matrix 
{
private:
    int row;
    int col;
    float** new_matrix;

public:

    float** getMatrix()
    {
        return new_matrix;
    }
    //function to print matrix
    void print_matrix()
    {
        cout << "\nOutput Matrix:\n";
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                cout << "\t" << *(*(new_matrix+i)+j);
            }
            cout << "\n";
        }
    }
    void getElements()
    {
    float value;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin >> value;
            *(*(new_matrix+i)+j) = value;
        }
    }
    };   
    //matrix constructor
    Matrix(int inputRow, int inputCol)
    {
        row = inputRow;
        col = inputCol;
        //dynamic allocation for matrix
        new_matrix = new float*[row];
        for (int i = 0; i < row; i++)
        {
            *(new_matrix+i) = new float[col];
        }
    }
    //overloaded operator function to add 2 matrices
    Matrix operator +(Matrix a_matrix)
    {   
        Matrix sum_matrix = Matrix(row,col);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                *(*(sumMatrix+i)+j) += *(*(another_matrix+i)+j);
            }
        }
        return sumMatrix;

    }

};

//function to print menu
void print_menu()
{
    cout << "\n----- Select an operation -----\n(1) Addition\n(2) Subtraction\n(3) Multiplication\n(4) Enter two new matrices\n(5) Exit" << endl;
    cout << "Enter your choice: ";
}
int main()
{
    // //initialize matrix 1
    int m1_rows, m1_cols;
    cout << "Enter rows and columns of matrix 1: ";
    cin >> m1_rows >> m1_cols;

    //dynamic allocation for matrix 1
    Matrix m1 = Matrix(m1_rows,m1_cols);
    
    //Enter elements in matrix 1
    printf("Enter elements of matrix 1:\n");
    m1.getElements();

    //initialize matrix 2
    int m2_rows, m2_cols;
    cout << "Enter rows and columns of matrix 2: ";
    cin >> m2_rows >> m2_cols;

    //dynamic allocation for matrix 2
    Matrix m2 = Matrix(m2_rows,m2_cols);

    //Enter elements in matrix 2
    printf("Enter elements of matrix 2:\n");
    m2.getElements();
    
    //menu & operation selection
    print_menu();
    int choice;
    cin >> choice;

    //loop until choice = 5
    while(choice != 5)
    {
        //Addition
        if(choice == 1)
        {
            //check matrices size
            if ((m1_rows == m2_rows) && (m1_cols == m2_cols))
            {
                //dynamic allocation for sum matrix
                Matrix sumMatrix = Matrix(m1_rows,m1_cols);
                sumMatrix = m1.getMatrix() + m2.getMatrix();
                // sum_matrix.print_matrix();
            }
            else
            {
                printf("\nInvalid addition operation based on matrix size!\n");
            }
        }
    }
    return 0;
}