/*
Name: Loc Nguyen
Program Purpose: Add, subtract, multiply 2 matrices using pointer to pointer and malloc
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//function to get or generate random value of elements
void getELements(int row, int col,float ***matrix)
{
    
    float random = (rand() % 100) +1;
    //float value;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            //scanf("%f",&value);
            //*(*(*matrix+i)+j) = value;
            //printf("%f",*(*(*matrix+i)+j));
            *(*(*matrix+i)+j) = random;
            random = (rand() % 100)+1;
        }
    }
}
//fucntion to print matrix
void print_matrix(int row, int col, float **matrix)

{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("\t%f", matrix[i][j]);
        }
        printf("\n");
    }
}
//function to add 2 matrices
void add_matrix(int row, int col, float **matrix1, float **matrix2, float **sum_matrix)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            *(*(sum_matrix+i)+j) = *(*(matrix1+i)+j) + *(*(matrix2+i)+j);   
        }
    }
}
//function to subtract 2 matrices
void sub_matrix(int row, int col, float **matrix1, float **matrix2, float **sum_matrix)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            *(*(sum_matrix+i)+j) = *(*(matrix1+i)+j) - *(*(matrix2+i)+j);   
        }
    }
}
//function to multiply 2 matrices
void mul_matrix(int row1, int col1_row2, int col2, float **matrix1, float **matrix2, float **product_matrix)
{
    float value;
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col2;j++)
        {
            for(int k=0; k<col1_row2; k++)
            {
                value += (*(*(matrix1+i))+k) * (*(*(matrix2+k))+j);
                //value += matrix1[i][k] * matrix2[k][j];
                *(*(product_matrix+i)+j) = value;
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

int main()
{
    int size_limit = 100;
    srand(time(NULL));
    struct timespec res;
    long start,end;
    //initialize matrix 1
    int m1_rows, m1_cols;
    printf("Enter rows and columns of matrix 1: ");
    scanf("%d %d", &m1_rows, &m1_cols);
    //set matrix size limit
    while((m1_rows > size_limit) || (m1_cols > size_limit))
    {   
        printf("Matrix size limit exceed 100x100!\n");
        printf("Enter rows and columns of matrix 1: ");
        scanf("%d %d", &m1_rows, &m1_cols);
    }
    //dynamic allocation for matrix 1
    float **m1 = (float**)malloc(m1_rows * sizeof(float*));
    for(int i=0; i<m1_rows; i++)
    {
        *(m1+i) = (float*)malloc(m1_cols * sizeof(float));   
    }

    //Enter elements in matrix 1
    //printf("Enter elements of matrix 1:\n");
    getELements(m1_rows,m1_cols,&m1);
    //printf("\nMatrix 1:\n");
    //print_matrix(m1_rows,m1_cols,m1);
    
    //initialize matrix 2
    int m2_rows, m2_cols;
    printf("Enter rows and columns of matrix 2: ");
    scanf("%d %d", &m2_rows, &m2_cols);
    //set matrix size limit      
    while((m2_rows > size_limit) || (m2_cols > size_limit))
    {   
        printf("Matrix size limit exceed 100x100!\n");
        printf("Enter rows and columns of matrix 2: ");
        scanf("%d %d", &m2_rows, &m2_cols);
    }
    //dynamic allocation for matrix 2
    float** m2 = (float**)malloc(m2_rows * sizeof(float*));
    for(int i=0; i<m2_rows; i++)
    {
        *(m2+i) = (float*)malloc(m2_cols * sizeof(float));     
    }

    //Enter elements in matrix 2
    //printf("Enter elements of matrix 2:\n");
    getELements(m2_rows,m2_cols,&m2);
    //printf("\nMatrix 2:\n");
    //print_matrix(m2_rows,m2_cols,m2);
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
                //dynamic allocation for sum matrix
                float **sum_matrix = (float**)malloc(m1_rows * sizeof(float*));
                for(int i=0; i<m1_rows; i++)
                {
                    *(sum_matrix+i) = (float*)malloc(m1_cols * sizeof(float));   
                }
                add_matrix(m1_rows,m1_cols,m1,m2,sum_matrix);
                printf("\nOutput Matrix:\n");
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
            //check matrices size
            if ((m1_rows == m2_rows) && (m1_cols == m2_cols))
            {
                //dynamic allocation for diff matrix
                float **diff_matrix = (float**)malloc(m1_rows * sizeof(float*));
                for(int i=0; i<m1_rows;i++)
                {
                    *(diff_matrix+i) = (float*)malloc(m1_cols * sizeof(float));
                }
                printf("\nOutput Matrix:\n");
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
                //dynamic allocation for product matrix
                float **product_matrix = (float**)malloc(m1_rows * sizeof(float*));
                for(int i=0;i<m1_rows;i++)
                {
                    *(product_matrix+i) = (float*)malloc(m2_cols * sizeof(float));
                }
                // clock_t timeStart, timeEnd;
                // double executionTime;
                // timeStart = clock();
                clock_gettime(CLOCK_REALTIME,&res);
                start = res.tv_nsec;
                mul_matrix(m1_rows,m2_rows,m2_cols,m1,m2,product_matrix);
                clock_gettime(CLOCK_REALTIME,&res);
                end = res.tv_nsec;
                // timeEnd = clock();
                // executionTime = ((double)(timeEnd - timeStart)) / CLOCKS_PER_SEC;
                //printf("\nOutput Matrix:\n");
                //print_matrix(m1_rows,m2_cols,product_matrix);
                printf("Execution time(ns): %lu",end-start);
            }
            else
            {
                printf("\nInvalid multiplication operation based on matrix size!\n");                
            }
        }
        
        //Enter 2 new matrices
        else if(choice == 4)
        {
            //initialize matrix 1
            printf("Enter rows and columns of matrix 1: ");
            scanf("%d %d", &m1_rows, &m1_cols);
            //set matrix size limit
            while((m1_rows > size_limit) || (m1_cols > size_limit))
            {   
                printf("Matrix size limit exceed 100x100!\n");
                printf("Enter rows and columns of matrix 1: ");
                scanf("%d %d", &m1_rows, &m1_cols);
            }
            //dynamic allocation for matrix 1
            float **m1 = (float**)malloc(m1_rows * sizeof(float*));
            for(int i=0; i<m1_rows; i++)
            {
                *(m1+i) = (float*)malloc(m1_cols * sizeof(float));   
            }

            //Enter elements in matrix 1
            //printf("Enter elements of matrix 1:\n");
            getELements(m1_rows,m1_cols,&m1);
            // printf("\nMatrix 1:\n");
            // print_matrix(m1_rows,m1_cols,m1);
            
            //initialize matrix 2
            printf("Enter rows and columns of matrix 2: ");
            scanf("%d %d", &m2_rows, &m2_cols);
            //set matrix size limit      
            while((m2_rows > size_limit) || (m2_cols > size_limit))
            {   
                printf("Matrix size limit exceed 100x100!\n");
                printf("Enter rows and columns of matrix 2: ");
                scanf("%d %d", &m2_rows, &m2_cols);
            }
            //dynamic allocation for matrix 2
            float** m2 = (float**)malloc(m2_rows * sizeof(float*));
            for(int i=0; i<m2_rows; i++)
            {
                *(m2+i) = (float*)malloc(m2_cols * sizeof(float));     
            }

            //Enter elements in matrix 2
            // printf("Enter elements of matrix 2:\n");
            getELements(m2_rows,m2_cols,&m2);
            // printf("\nMatrix 2:\n");
            // print_matrix(m2_rows,m2_cols,m2);
            
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