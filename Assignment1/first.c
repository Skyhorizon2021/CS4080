//Name: Loc nguyen
//Program Purpose:
//Use stack dynamic 2D array with limit of size 100x100
//Have functions to do operations of addition, subtraction, and multiplication 
#include <stdio.h>
#include <stdlib.h>

//fucntion to get elements from user
void getELements(int row, int col,float matrix[row][col])
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%f",&matrix[i][j]);
        }
    }
}
//function to add 2 matrices
void add_matrix(int row, int col, float matrix1[row][col], float matrix2[row][col], float sum_matrix[row][col])
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];   
        }
    }
}

//function to subtract 2 matrices
void sub_matrix(int row, int col, float matrix1[row][col], float matrix2[row][col], float diff_matrix[row][col])
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            diff_matrix[i][j] = matrix1[i][j] - matrix2[i][j];   
        }
    }
}

//function to multiply 2 matrices
void mul_matrix(int row1, int col1_row2, int col2, float matrix1[row1][col1_row2], float matrix2[col1_row2][col2], float product_matrix[row1][col2])
{
    float value;
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col2;j++)
        {
            for(int k=0; k<col1_row2; k++)
            {
                value += matrix1[i][k] * matrix2[k][j];
                product_matrix[i][j] = value;
            }
        value = 0;
        }
        
    }
}
//function to print menu
void print_menu()
{
    //menu & operation selection
    printf("\n----- Select an operation -----\n(1) Addition\n(2) Subtraction\n(3) Multiplication\n(4) Enter two new matrices\n(5) Exit");
    printf("\nEnter your choice: ");
}

//function to print matrix
void print_matrix(int row, int col, float matrix[row][col])
{
    printf("\nOutput Matrix:\n");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("\t%f", matrix[i][j]);
        }
        printf("\n");
    }
}

//main function
int main()
{
    //initialize matrix 1
    int m1_rows, m1_cols;
    
    printf("Enter rows and columns of matrix 1: ");
    scanf("%d %d", &m1_rows, &m1_cols);
    float m1[m1_rows][m1_cols];

    //Enter elements in matrix 1
    printf("Enter elements of matrix 1:\n");
    getELements(m1_rows,m1_cols,m1);
    

    //initilize matrix 2
    int m2_rows,m2_cols;

    printf("Enter rows and columns of matrix 2: ");
    scanf("%d %d", &m2_rows, &m2_cols);
    float m2[m2_rows][m2_cols];

    //Enter elements in matrix 2
    printf("Enter elements of matrix 2:\n");
    getELements(m2_rows,m2_cols,m2);


    //menu & operation selection
    print_menu();
    int choice;
    scanf("%d",&choice);
    
    //loop until choice = 5
    while(choice != 5)
    {
        //Addition
        if(choice == 1)
        {
            //check matrices size
            if ((m1_rows == m2_rows) && (m1_cols == m2_cols))
            {
                float sum_matrix[m1_rows][m1_cols];
                add_matrix(m1_rows,m1_cols,m1,m2,sum_matrix);
                print_matrix(m1_rows,m1_cols,sum_matrix);
            }
            else
            {
                printf("\nInvalid addition operation based on matrix size!\n");
            }
            
        }
        
        //Subtraction
        else if(choice == 2)
        {
            if ((m1_rows == m2_rows) && (m1_cols == m2_cols))
            {
                float diff_matrix[m1_rows][m1_cols];
                sub_matrix(m1_rows,m1_cols,m1,m2,diff_matrix);
                print_matrix(m1_rows,m1_cols,diff_matrix);    
            }
            else
            {
                printf("\nInvalid subtraction operation based on matrix size!\n");
            }
            
        }
        
        //Multiplication
        else if(choice == 3)
        {
            if (m1_cols == m2_rows)
            {
                float product_matrix[m1_rows][m2_cols];
                mul_matrix(m1_rows,m2_rows,m2_cols,m1,m2,product_matrix);
                print_matrix(m1_rows,m2_cols,product_matrix);
            }
            else
            {
                printf("\nInvalid multiplication operation based on matrix size!\n");
            }
        }
        
        //Enter 2 new matrices
        else if(choice == 4)
        {
            //initilize matrix 1
            printf("Enter rows and columns of matrix 1: ");
            scanf("%d %d", &m1_rows, &m1_cols);
            float m1[m1_rows][m1_cols];

            //Enter elements in matrix 1
            printf("Enter elements of matrix 1:\n");
            getELements(m1_rows,m1_cols,m1);
            

            //initilize matrix 2
            printf("Enter rows and columns of matrix 2: ");
            scanf("%d %d", &m2_rows, &m2_cols);
            float m2[m2_rows][m2_cols];

            //Enter elements in matrix 2
            printf("Enter elements of matrix 2:\n");
            getELements(m2_rows,m2_cols,m2);

            
        }
        //menu & operation selection
        print_menu();
        scanf("%d",&choice);    
    }
    if(choice==5)
    {
        printf("Program Terminated!");
    }
    return 0; 
}   