#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to create a 2D stack dynamic array fill with random values
/*float** random_array(int size_of_matrix)
{
    //get random val between 1-9
    srand(time(NULL));
    //initialize array
    float matrix[size_of_matrix][size_of_matrix];
    //fill array with random val
    for(int i=0;i<size_of_matrix;i++)
    {
        for (int j=0;j<size_of_matrix;j++)
        {
            matrix[i][j] = rand()%10;
        }
    }
    
    return matrix;
}*/
//function to add 2 matrices
float** matrix_addition(float m1[][], float m2[][], float res[][],int size)
{   
    float sum_matrix[size][size];
    float (*pointer)[size];
    pointer =&sum_matrix;
    for (int row=0;row<size;row++)
    {
        for (int col=0;col<size;col++)
        {
            sum_matrix[row][col] = *(*(m1+row)+col) + *(*(m2+row)+col);
        }
    }
    return sum_matrix;
}
int main()
{
    
    int size_of_matrix1;
    int size_of_matrix2;
    float **sum_matrix;
    //Matrix 1
    printf("Please enter a size (<100) for matrix 1: ");
    scanf("%d", &size_of_matrix1);
    while (size_of_matrix1 > 100)
    {
        printf("Matrix size must be less than 100!\n");
        printf("Please enter a size (<100) for matrix 1: ");
        scanf("%d", &size_of_matrix1);
    }
;
    //initialize array
    float (matrix1)[size_of_matrix1][size_of_matrix1];
    float (*pointer1)[size_of_matrix1];
    pointer1 = matrix1;
    //initialize random seed val
    srand(time(NULL));   
    //fill array with random val
    for(int i=0;i<size_of_matrix1;i++)
    {
        for (int j=0;j<size_of_matrix1;j++)
        {   
            //get random val between 1 - 9
            matrix1[i][j] = rand() % 10;
        }
    }
   for (int i=0;i<size_of_matrix1;i++)
    {
        for (int j=0;j<size_of_matrix1;j++)
        {
            printf("%f\n",matrix1[i][j]);
        }
    }
    //Matrix 2
    printf("Please enter a size (<100) for matrix 2: ");
    scanf("%d", &size_of_matrix2);
    while (size_of_matrix2 > 100)
    {
        printf("Matrix size must be less than 100!\n");
        printf("Please enter a size (<100) for matrix 2: ");
        scanf("%d", &size_of_matrix2);
    }
    //initialize array
    float matrix2[size_of_matrix2][size_of_matrix2];
    float (*pointer2)[size_of_matrix2];
    pointer2 = matrix2;

    //initialize random seed val
    srand(time(NULL));   
    //fill array with random val
    for(int i=0;i<size_of_matrix2;i++)
    {
        for (int j=0;j<size_of_matrix2;j++)
        {   
            //get random val between 1 - 9
            matrix2[i][j] = rand() % 10;
        }
    }
   for (int i=0;i<size_of_matrix2;i++)
    {
        for (int j=0;j<size_of_matrix2;j++)
        {
            printf("%f\n",matrix2[i][j]);
        }
    }

    //check for size for addition
    if (size_of_matrix1 != size_of_matrix2)
    {
        printf("Invalid operation!");
    } 
    else
    {
        sum_matrix = matrix_addition(pointer1,pointer2,size_of_matrix1);
    }
    return 0;
}