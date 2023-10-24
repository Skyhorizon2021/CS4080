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
//function to print all float elements in 2D array
int main()
{
    
    int size_of_matrix;
    
    //Matrix 1
    printf("Please enter a size (<100) for matrix 1: ");
    scanf("%d", &size_of_matrix);
    while (size_of_matrix > 100)
    {
        printf("Matrix size must be less than 100!\n");
        printf("Please enter a size (<100) for matrix 1: ");
        scanf("%d", &size_of_matrix);
    }
;
    //initialize array
    float matrix1[size_of_matrix][size_of_matrix];
    //initialize random seed val
    srand(time(NULL));   
    //fill array with random val
    for(int i=0;i<size_of_matrix;i++)
    {
        for (int j=0;j<size_of_matrix;j++)
        {   
            //get random val between 1 - 9
            matrix1[i][j] = rand() % 10;
        }
    }
   for (int i=0;i<size_of_matrix;i++)
    {
        for (int j=0;j<size_of_matrix;j++)
        {
            printf("%f\n",matrix1[i][j]);
        }
    }
    
    //Matrix 2
    printf("Please enter a size (<100) for matrix 2: ");
    scanf("%d", &size_of_matrix);
    while (size_of_matrix > 100)
    {
        printf("Matrix size must be less than 100!\n");
        printf("Please enter a size (<100) for matrix 2: ");
        scanf("%d", &size_of_matrix);
    }
    //initialize array
    float matrix2[size_of_matrix][size_of_matrix];
    //initialize random seed val
    srand(time(NULL));   
    //fill array with random val
    for(int i=0;i<size_of_matrix;i++)
    {
        for (int j=0;j<size_of_matrix;j++)
        {   
            //get random val between 1 - 9
            matrix2[i][j] = rand() % 10;
        }
    }
   for (int i=0;i<size_of_matrix;i++)
    {
        for (int j=0;j<size_of_matrix;j++)
        {
            printf("%f\n",matrix2[i][j]);
        }
    }

    return 0;
}