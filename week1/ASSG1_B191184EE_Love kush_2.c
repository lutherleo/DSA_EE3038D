/*Write a program to implement a Stack S using an array A of size n. The stack must support the functions:
isEmpty, Push, Pop and isFull. Modify the isFull and/or PUSH functions to support the following functionality:
If S is full when the PUSH function is called, allocate a new array B of size 2n, copy all the elements of A into B,
make A point to the array B, deallocate the old array A, and finally perform the PUSH operation on the new array A.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int top, n;
    int *A;
} *stack;

int stackEmpty(stack);
int stackFull(stack);
int push(stack, int);
int pop(stack);

int main()
{
    stack S;
    char c;
    int x, n;
    scanf("%d", &S->n);
    S->top = -1;
    S->A = (int*)malloc(S->n*sizeof(int));
    do
    {
        scanf("%c", &c);
        switch (c)
        {
        case 'i':
            scanf("%d", &x);
            push(S, x);
            break;
        case 'd':
            printf("%d\n", pop(S));
            break;
        case 'e':
            printf("%d\n", stackEmpty(S));
        }
    } while (c!='t');
    return 0;
}

int stackEmpty(stack S)
{
    if(S->top==-1)
        return -1;
    return 1;
}

int stackFull(stack S)
{
    if(S->top==S->n-1)
        return 1;
    return 0;
}

int push(stack S, int k)
{
    if(!stackFull(S))
        return S->A[++S->top] = k;
    else{
        printf("1 \n");
        S->A = (int*)realloc(S->A, 2*S->n);
        return S->A[++S->top] = k;
    }

    return -1;
}

int pop(stack S)
{
    if(stackEmpty(S)!=-1)
        return S->A[S->top--];
    return -1;
}