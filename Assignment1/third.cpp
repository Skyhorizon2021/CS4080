/*
Name: Loc Nguyen
Program Purpose: Add, subtract, multiply 2 matrices using pointer to pointer and new
*/
#include <iostream>
#include <cmath>
#include <random>
#include <time.h>
#include <chrono>
using namespace std;

typedef chrono::high_resolution_clock Clock;
//fucntion to get random float
float randomFloat()
{
    
    return ((float)(rand()%100)) / (float)(rand()%100+1);
}
class Matrix 
{
private:
    int row;
    int col;
    float** new_matrix;

public:
    int getRow()
    {
        return row;
    }
    int getCol()
    {
        return col;
    }
    float** getPointerMatrix()
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
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            //cin >> value;
            float value = randomFloat();
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
    Matrix operator +(Matrix& a_matrix)
    {   
        Matrix sumMatrix = Matrix(row,col);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                *(*(sumMatrix.getPointerMatrix()+i)+j) = (*(*(new_matrix+i)+j));
                *(*(sumMatrix.getPointerMatrix()+i)+j) = *(*(sumMatrix.getPointerMatrix()+i)+j) + (*(*(a_matrix.getPointerMatrix()+i)+j));
            }
        }
        return sumMatrix;
    };
    //overloaded operator function to subtract 2 matrices
    Matrix operator -(Matrix& a_matrix)
    {   
        Matrix diffMatrix = Matrix(row,col);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                *(*(diffMatrix.getPointerMatrix()+i)+j) = (*(*(new_matrix+i)+j));
                *(*(diffMatrix.getPointerMatrix()+i)+j) = *(*(diffMatrix.getPointerMatrix()+i)+j) - (*(*(a_matrix.getPointerMatrix()+i)+j));
            }
        }
        return diffMatrix;
    }
    //overloaded operator function to multiply 2 matrices
    Matrix operator *(Matrix& a_matrix)
    {   
        Matrix productMatrix = Matrix(row,a_matrix.getCol());
        float value = 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<a_matrix.getCol();j++)
            {
                for(int k = 0;k<col;k++)
                {
                    value += (*(*(new_matrix+i)+k)) * (*(*(a_matrix.getPointerMatrix()+k)+j));
                    (*(*(productMatrix.getPointerMatrix()+i)+j)) = value;
                }
                value = 0;
            }
        }
        return productMatrix;
    }

}; //end of class definition

//function to print menu
void print_menu()
{
    cout << "\n----- Select an operation -----\n(1) Addition\n(2) Subtraction\n(3) Multiplication\n(4) Enter two new matrices\n(5) Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    srand(time(0));
    int size_limit = 100;
    //initialize matrix 1
    int m1_rows, m1_cols;
    cout << "Enter rows and columns of matrix 1: ";
    cin >> m1_rows >> m1_cols;
    //set matrix size limit
    while((m1_rows > size_limit) || (m1_cols >size_limit))
    {   
        printf("Matrix size limit exceed 100x100!\n");
        printf("Enter rows and columns of matrix 1: ");
        cin >> m1_rows >> m1_cols;
    }

    //dynamic allocation for matrix 1
    Matrix m1 = Matrix(m1_rows,m1_cols);
    
    //Enter elements in matrix 1
    //printf("Enter elements of matrix 1:\n");
    m1.getElements();
    //m1.print_matrix();

    //initialize matrix 2
    int m2_rows, m2_cols;
    cout << "Enter rows and columns of matrix 2: ";
    cin >> m2_rows >> m2_cols;
    //set matrix size limit
    while((m2_rows > size_limit) || (m2_cols > size_limit))
    {   
        printf("Matrix size limit exceed 100x100!\n");
        printf("Enter rows and columns of matrix 2: ");
        cin >> m2_rows >> m2_cols;
    }
    //dynamic allocation for matrix 2
    Matrix m2 = Matrix(m2_rows,m2_cols);

    //Enter elements in matrix 2
    //printf("Enter elements of matrix 2:\n");
    m2.getElements();
    //m2.print_matrix();
    
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
                sumMatrix = m1 + m2;
                sumMatrix.print_matrix();
            }
            else
            {
                printf("\nInvalid addition operation based on matrix size!\n");
            }
        }
        //Subtraction
        if(choice == 2)
        {
            //check matrices size
            if ((m1_rows == m2_rows) && (m1_cols == m2_cols))
            {
                //dynamic allocation for difference matrix
                Matrix diffMatrix = Matrix(m1_rows,m1_cols);
                diffMatrix = m1 - m2;
                diffMatrix.print_matrix();
            }
            else
            {
                printf("\nInvalid addition operation based on matrix size!\n");
            }
        }
        //Multiplication
        else if(choice == 3)
        {
            if (m1_cols == m2_rows)
            {
                //dynamic allocation for product matrix
                Matrix productMatrix = Matrix(m1_rows,m2_cols);
                //time measure
                auto start = Clock::now();
                productMatrix = m1 * m2;
                auto end = Clock::now();
                productMatrix.print_matrix();
                
                cout << "Execution time(ns): " << chrono::duration_cast<chrono::nanoseconds>(end-start).count()<<endl;
            }
            else
            {
                printf("\nInvalid multiplication operation based on matrix size!\n");                
            }
        }
        //Enter 2 new matrices
        else if(choice == 4)
        {
            srand(time(0));
            cout << "Enter rows and columns of matrix 1: ";
            cin >> m1_rows >> m1_cols;
            //set matrix size limit
            while((m1_rows > size_limit) || (m1_cols >size_limit))
            {   
                cout << ("Matrix size limit exceed 100x100!\n");
                cout << ("Enter rows and columns of matrix 1: ");
                cin >> m1_rows >> m1_cols;
            }

            //dynamic allocation for matrix 1
            Matrix m1 = Matrix(m1_rows,m1_cols);
            
            //Enter elements in matrix 1
            //printf("Enter elements of matrix 1:\n");
            m1.getElements();
            //m1.print_matrix();

            //initialize matrix 2
            int m2_rows, m2_cols;
            cout << "Enter rows and columns of matrix 2: ";
            cin >> m2_rows >> m2_cols;
            //set matrix size limit
            while((m2_rows > size_limit) || (m2_cols > size_limit))
            {   
                cout << ("Matrix size limit exceed 100x100!\n");
                cout << ("Enter rows and columns of matrix 2: ");
                cin >> m2_rows >> m2_cols;
                
            }
            //dynamic allocation for matrix 2
            Matrix m2 = Matrix(m2_rows,m2_cols);

            //Enter elements in matrix 2
            //printf("Enter elements of matrix 2:\n");
            m2.getElements();
            //m2.print_matrix();
        }
        //menu & operation selection
        print_menu();
        cin >> choice;
    }
    if(choice == 5)
    {
        cout << "Program Terminated!";
    }
    return 0;
}