#include <iostream>

#define maxstack 4

using namespace std;

struct stack
{
    int data[maxstack];
    int count;
};

stack a;

void initial(stack *s)
{
    s->count = 0;
}

bool isFull(stack *s)
{
    if (s->count == maxstack)
    {
        return true;
    }

    return false;
}

void push(int val, stack *s)
{
    if (isFull(s))
    {
        cout << "The data already full!" << endl;
    }
    else
    {
        s->data[s->count] = val;
        ++(s->count);
    }
}

void print(stack *s)
{
    for (int i = 0; i < maxstack; i++)
    {
        cout << s->data[i] << endl;
    }
}

int main()
{
    a.count = 0;

    initial(&a);

    push(5, &a);
    push(10, &a);
    push(15, &a);
    push(20, &a);
    push(25, &a);
    print(&a);

    return 0;
}