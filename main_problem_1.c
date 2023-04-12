#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int readParam();
int readParam()
{
    int stupid;
    printf("Please input an integer 0 through 9 or -1 to quit: ");
    scanf("%d", &stupid);
    return stupid;
}
void fctrl(int num);
void fctrl(int num)
{

    int product = 1;
    printf("*****");
    for(int i = num; i > 1; i--) {
        printf("********");
    }
    printf("\n");
    printf("* %d! = ", num);
    for(int i = num; i > 1; i--)
    {
        product *= i;
        printf("%d * ", i);
    }
    printf("1 = %d *\n", product);
    printf("*****");
    for(int i = num; i > 1; i--) {
        printf("********");
    }
    printf("\n");
}
int main()
{
    int param;
    while((param = readParam()) != -1)
    {
        if(param >= 0 && param <= 9)
        {
            fctrl(param);
        }
        else
        {
            printf("Invalid entry\n");
        }
    }
    return(0);
}