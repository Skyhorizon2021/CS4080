#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int array[10];
int main()
{
    for (int i = 0;i<10;i++)
    {
        array[i] = rand();
    }
    for (int j = 0;j<10;j++)
    {
        printf("%d\n",array[j]);
    }


return 0;
}