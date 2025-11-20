

















#include <stdio.h>

int add(int a, int b)
{
    int temp = 0;      // unused variable -> should be flagged
    return a + b;
}


int main(void)
{
    int x = 10;
    int y = 20;
    int result = add(x, y);

    
    printf("Sum of %d and %d is %d\n", x, y, result);
    // missing return 0;  -> should be flagged

}

