#include <iostream>
#include <string>

#define maxstack 4

using namespace std;

struct stack
{
    int data[maxstack];
    int count;
};

stack grades;

void initialize(stack *s)
{
    s->count = 0;
}

bool isEmpty(stack *s) {
    if (s->count == 0) {
        return true;
    }

    return false;
}

bool isMax(stack *s)
{
    if (s->count == maxstack)
    {
        return true;
    }

    return false;
}

void push(int grade, stack *s)
{
    if (isMax(s))
    {
        cout << "The grade is already full!" << endl;
    }
    else
    {
        s->data[s->count] = grade;
        ++(s->count);

        cout << "PUSH: " << grade << endl;
    }
}

void pop(stack *s, int *idx) {
    if (isEmpty(s)) {
        cout << "The grade is empty!" << endl;
    } else {
        --(s->count);
        *idx = s->data[s->count];
        s->data[s->count] = 0;
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

    cout << "==================\n\n";

    int x;

    initialize(&grades);


    while (!isMax(&grades)) {
        int grade;

        cout << "Input grade: ";
        cin >> grade;
        
        push(grade, &grades);
    }

    print(&grades);

    pop(&grades, &x);

    cout << "POP: The selected grade is " << x << endl;

    cout << "\n\n==================\n";

    return 0;
}