#include <iostream>
using namespace std;

struct node
{

    int key;
    int data;
    node *next;
};

class stack
{

private:
    node *top;
    int count;

public:
    stack()
    {
        top = NULL;
        count = 0;
    }

    bool keyExist(int key);
    bool isEmpty();
    int valueCount();
    void push(node *newNode); // Prepend value in stack
    node *pop();              // Remove value from head
    node *peek();
    void display();
};

bool stack::isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    return false;
}

bool stack::keyExist(int key)
{
    node *temp = top;

    while (temp != NULL)
    {
        if (temp->key == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int stack::valueCount()
{
    return count;
}

void stack::push(node *newNode)
{
    if (top == NULL)
    {
        top = newNode;
        cout << "Congrats!!! Value pushed..." << endl;
        count++;
    }
    else
    {
        newNode->next = top;
        top = newNode; //Point top to newNode
        cout << "Congrats!!! Value pushed..." << endl;
        count++;
    }
}

node *stack::pop()
{
    node *temp = top;
    top = top->next;

    return temp;
}
node *stack::peek()
{
    return top;
}

void stack::display()
{
    if (isEmpty())
    {
        cout << "Stack is empty ... " << endl;
    }
    else
    {
        node *temp = top;
        while (temp != NULL)
        {
            cout << "(" << temp->key << " , " << temp->data << ")" << endl;
            temp = temp->next;
        }
    }
}

void menu()
{
    int option, value, key;
    stack stackObj;

    do
    {
        cout << "0)Exit()" << endl
             << endl;
        cout << "1)Push()" << endl
             << endl;
        cout << "2)Pop()" << endl
             << endl;
        cout << "3)isEmpty()" << endl
             << endl;
        cout << "4)Peek(Display top element of stack)" << endl
             << endl;
        cout << "5)Count()" << endl
             << endl;
        cout << "6)Display()" << endl
             << endl;
        cout << "7)Clear screen()" << endl
             << endl;
        cin >> option;

        switch (option)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            cout << "Enter the key: ";
            cin >> key;
            if (stackObj.keyExist(key))
            {
                cout << "User with this key already exist...\nTry with another key" << endl;
            }
            else
            {
                cout << "Enter the value: ";
                cin >> value;
                node *newNode = new node();
                newNode->key = key;
                newNode->data = value;
                newNode->next = NULL;
                stackObj.push(newNode);
            }

            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            if (stackObj.isEmpty())
            {
                cout << "No value in stack..." << endl;
            }
            else
            {
                node *newNode = new node();
                newNode = stackObj.pop();
                cout << "(" << newNode->key << " , " << newNode->data << ")" << endl;
            }

            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            if (stackObj.isEmpty())
            {
                cout << "Empty..." << endl;
            }
            else
            {
                cout << "Stack is not empty..." << endl;
            }
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {

            if (stackObj.isEmpty())
            {
                cout << "No value in stack..." << endl;
            }
            else
            {
                node *newNode = new node();
                newNode = stackObj.peek();
                cout << "(" << newNode->key << " , " << newNode->data << ")" << endl;
            }

            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            cout << "There are " << stackObj.valueCount() << "values in stack" << endl;

            system("pause");
            system("cls");
            break;
        }
        case 6:
        {
            stackObj.display();

            system("pause");
            system("cls");
            break;
        }
        case 7:
        {
            system("cls");
            break;
        }
        default:
        {
            cout << "Select correct option" << endl
                 << endl;
        }
            cout << endl
                 << endl
                 << endl
                 << endl;
        }

    } while (option != 0);
}
int main()
{
    menu();
}