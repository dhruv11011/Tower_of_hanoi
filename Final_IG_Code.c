#include <stdio.h> //For Basic Input Output Processes
#include <math.h> //For Mathematical Manupulations
#include <string.h> //For String Manupulations
#include <stdlib.h> //For Dynamic Memory Allocation
#include <windows.h> //For Manupulating Terminal

int count_steps = 0, disks;
struct stack //Creating Stack
{
    int size;
    int top;
    int *arr;
} A, B, C; //Declaring Global Variables

int isFull(struct stack *ptr) // Creating Function And Returning Value For Furthur Use
{
    if (ptr->top == (ptr->size) - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct stack *ptr) // Creating Function And Returning Value For Furthur Use
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//hi i am dhruv

void push(struct stack *ptr, int val) //For Pushing Value On The Stack
{
    if (isFull(ptr))
    {
        printf("---Stack Overflow---\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack *ptr) //For Poping Out Of The Stack
{
    if (isEmpty(ptr))
    {
        return 0;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->arr[ptr->top] = 0;
        ptr->top--;
        return val;
    }
}

void Initializing_Tower_Of_Hanoi(); //Function For Initializing Some Tower Values
void run(); //For Running The Game
void Printing_Line_By_Line(struct stack *A, struct stack *B, struct stack *C); //Function For Printing Each Line Of Game
void Printing_Base(); //Function For Printing The Base
void HanoiTower(int n, char source, char dest, char aux);//For Optimized Steps

int main()
{
    system("@cls||clear"); //For Clearing The Terminal
    char ch;
    printf("How Many Disks Do You Want? : ");
    scanf("%d", &disks); //How Many Disks Do U Want In The Game.

    Initializing_Tower_Of_Hanoi();
    run();
    printf("\nYou Took %d Steps.\n", count_steps);
    printf("Do You Want To See The Optimized Steps(Y/N): ");
    scanf(" %c", &ch);
    if (ch == 'Y')
    {
        printf("The Optimized Steps To Complete The Game Are: \n");
        HanoiTower(disks, 'A', 'C', 'B'); // A, B, C Three Tower
    }
    else
    {
        printf("Thank You For Playing The Game");
    }

    return 0;
}

void Initializing_Tower_Of_Hanoi()
{
    A.size = disks;
    B.size = disks;
    C.size = disks;

    // For Initializing The Top Value
    A.top = -1;
    B.top = -1;
    C.top = -1;

    A.arr = (int *)malloc(A.size * sizeof(int));
    B.arr = (int *)malloc(B.size * sizeof(int));
    C.arr = (int *)malloc(C.size * sizeof(int));

    for (int i = disks; i > 0; i--)
    {
        push(&A, i);
    }
}

void run()
{
    system("@cls||clear");
    char tower_start;
    char tower_end;
    Printing_Line_By_Line(&A, &B, &C);
    Printing_Base();

    while (!isFull(&C))
    {
        printf("\nFrom Which Tower Would You Like To Move A Disk?(A/B/C): ");
        scanf(" %c", &tower_start);

        if (tower_start == 'A')
        {
            if (isEmpty(&A))
            {
                printf("\nInvalid Choice Since The Tower Is Empty\n");
                continue;
            }
            else
            {
                printf("\nTo Which Tower Would You Like To Move A Disk?(B/C): ");
                scanf(" %c", &tower_end);
                if (tower_end == 'B')
                {
                    if (B.arr[B.top] > A.arr[A.top] || B.top == -1)
                    {
                        B.top++;
                        B.arr[B.top] = pop(&A);
                        run();
                    }
                    else
                    {
                        printf("\nInvalid Choice,A Disk With Higher Priority Cannot Be Kept On Disk With Lower Priority\n");
                        continue;
                    }
                }
                else if (tower_end == 'C')
                {
                    if (C.arr[C.top] > A.arr[A.top] || C.top == -1)
                    {
                        C.top++;
                        C.arr[C.top] = pop(&A);
                        run();
                    }
                    else
                    {
                        printf("\nInvalid Choice,A Disk With Higher Priority Cannot Be Kept On Disk With Lower Priority\n");
                        continue;
                    }
                }
                else
                {
                    count_steps--;
                    run();
                }
            }
        }
        else if (tower_start == 'B')
        {
            if (isEmpty(&B))
            {
                printf("\nInvalid Choice Since The Tower Is Empty\n");
                continue;
            }
            else
            {
                printf("\nTo Which Tower Would You Like To Move A Disk?(A/C): ");
                scanf(" %c", &tower_end);
                if (tower_end == 'A')
                {
                    if (A.arr[A.top] > B.arr[B.top] || A.top == -1)
                    {
                        A.top++;
                        A.arr[A.top] = pop(&B);
                        run();
                    }
                    else
                    {
                        printf("\nInvalid Choice,A Disk With Higher Priority Cannot Be Kept On Disk With Lower Priority\n");
                        continue;
                    }
                }
                else if (tower_end == 'C')
                {
                    if (C.arr[C.top] > B.arr[B.top] || C.top == -1)
                    {
                        C.top++;
                        C.arr[C.top] = pop(&B);
                        run();
                    }
                    else
                    {
                        printf("\nInvalid Choice,A Disk With Higher Priority Cannot Be Kept On Disk With Lower Priority\n");
                        continue;
                    }
                }
                else
                {
                    count_steps--;
                    run();
                }
            }
        }
        else if (tower_start == 'C')
        {
            if (isEmpty(&C))
            {
                printf("\nInvalid Choice Since The Tower Is Empty\n");
                continue;
            }
            else
            {
                printf("\nTo Which Tower Would You Like To Move A Disk?(A/B): ");
                scanf(" %c", &tower_end);
            }
            if (tower_end == 'A')
            {
                if (A.arr[A.top] > C.arr[C.top] || A.top == -1)
                {
                    A.top++;
                    A.arr[A.top] = pop(&C);
                    run();
                }
                else
                {
                    printf("\nInvalid Choice,A Disk With Higher Priority Cannot Be Kept On Disk With Lower Priority\n");
                    continue;
                }
            }
            else if (tower_end == 'B')
            {
                if (B.arr[B.top] > C.arr[C.top] || B.top == -1)
                {
                    B.top++;
                    B.arr[B.top] = pop(&C);
                    run();
                }
                else
                {
                    printf("\nInvalid Choice,A Disk With Higher Priority Cannot Be Kept On Disk With Lower Priority\n");
                    continue;
                }
            }
            else
                {
                    count_steps--;
                    run();
                }
        }
        count_steps++;
    }
}

void Printing_Base()
{
    for (int d = 0; d < 3; d++)
    {
        for (int i = 0; i < disks; i++)
        {
            printf("--");
        }
        printf("  ");
    }
}

void Printing_Line_By_Line(struct stack *A, struct stack *B, struct stack *C)
{
    int ele = disks;
    for (int lines = 0; lines < disks; lines++)
    {
        while (ele != 0)
        {
            if (A->top > -1 && A->arr[ele - 1] != 0 && A->arr[ele - 1] <= disks)
            {
                for (int i = 0; i < disks - A->arr[ele - 1]; i++)
                {
                    printf(" ");
                }
                for (int i = 0; i < A->arr[ele - 1]; i++)
                {
                    printf("00");
                }
                for (int i = 0; i < disks - A->arr[ele - 1]; i++)
                {
                    printf(" ");
                }
            }
            else
            {
                for (int i = 0; i < disks; i++)
                {
                    printf("  ");
                }
            }

            printf("  ");

            if (B->top > -1 && B->arr[ele - 1] != 0 && B->arr[ele - 1] <= disks)
            {
                for (int i = 0; i < disks - B->arr[ele - 1]; i++)
                {
                    printf(" ");
                }
                for (int i = 0; i < B->arr[ele - 1]; i++)
                {
                    printf("00");
                }
                for (int i = 0; i < disks - B->arr[ele - 1]; i++)
                {
                    printf(" ");
                }
            }
            else
            {
                for (int i = 0; i < disks; i++)
                {
                    printf("  ");
                }
            }

            printf("  ");

            if (C->top > -1 && C->arr[ele - 1] != 0 && C->arr[ele - 1] <= disks)
            {
                for (int i = 0; i < disks - C->arr[ele - 1]; i++)
                {
                    printf(" ");
                }
                for (int i = 0; i < C->arr[ele - 1]; i++)
                {
                    printf("00");
                }
                for (int i = 0; i < disks - C->arr[ele - 1]; i++)
                {
                    printf(" ");
                }
            }
            else
            {
                for (int i = 0; i < disks; i++)
                {
                    printf("  ");
                }
            }
            ele--;
            printf("\n");
        }
    }
}
void HanoiTower(int n, char source, char dest, char aux)
{

    if (n == 1) // n-1 disk from source to dest
    {
        printf("\nMove Disk 1 From Rod %c To Rod %c", source, dest);
        return;
    }
    HanoiTower(n - 1, source, aux, dest); // n-1 disk from source to aux
    printf("\nMove Disk %d From Rod %c To Rod %c", n, source, dest);
    HanoiTower(n - 1, aux, dest, source); // n-1 disk from aux to dest
}