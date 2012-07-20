// bratner_hanoi.cpp : Defines the entry point for the console application.
#include <stdio.h>
void hanoi(int amnt, char p1, char p2, char pezer){
    if (amnt == 0)
        return;
    hanoi(amnt - 1, p1, pezer, p2);
    printf("MOVE %c to %c\n", p1, p2);
    hanoi(amnt - 1, pezer, p1, p2);
}
int main(int argc, char * argv[])
{
    hanoi(5,'A','B','C');
    return 0;
}
