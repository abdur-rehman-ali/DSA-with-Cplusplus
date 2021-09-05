#include <iostream>
using namespace std;

class stack
{
private:
    int arr[50];
    int size;
    int top;

public:
    stack();
    bool isEmpty();
    bool isFull();
    int count();
    void push(int value);
    int pop();
    int peek(int index);
    void change(int index,int value);
    void display();
};

//constructor
stack::stack()
{
        top = -1;
        size = 49;
        for (int i = 0; i <= size; i++)
        {
            arr[i] = 0;
        }
}

//For displaying elemnts in stack
void stack::display()
{

    for (int i = size; i >= 0; i--)
    {
        cout << "Value at index "<<i<<" is : "<<arr[i] << endl;
    }
}

// Check whether stack is empty or not
bool stack::isEmpty()
{
    if(top==-1)
        return true;
    else 
        return false;
}

// Check whether stack is full or not
bool stack::isFull()
{
    if(top==size)
        return true;
    else 
        return false;
}

//Give count of element in stack
int stack::count()
{
    return top+1;
}

//Will push elemnent in aray
void stack::push(int value)
{
    if (isFull())
    {
        cout<<"Stack is full ---overflow occured"<<endl<<endl;
    }
    else
    {
        top++;
        arr[top]=value;
    }
}
//Will pop element from stack
int stack::pop()
{
    if(isEmpty())
    {
        return 0;
    }
    else
    {

        int pop_value=arr[top];
        arr[top]=0;
        top--;
        return pop_value;
        
    }
}
//Return value at ith index of stack
int stack::peek(int index)
{
    if (index<=top)
    return arr[index];
    else
    return -1;
}

//Change value at given index
void stack::change(int index, int value)
{
    if (index >top)
    cout<<"ERR!!That index of stack does not exist yet"<<endl<<endl;
    else
    arr[index]=value;
}

void menu()
{
    int option,value,index;
    stack stackObj;

    do
    {
    cout<<"0)Exit()"<<endl<<endl;
    cout<<"1)Push()"<<endl<<endl;
    cout<<"2)Pop()"<<endl<<endl;
    cout<<"3)isEmpty()"<<endl<<endl;
    cout<<"4)isFull()"<<endl<<endl;
    cout<<"5)Peek()"<<endl<<endl;
    cout<<"6)Count()"<<endl<<endl;
    cout<<"7)Change()"<<endl<<endl;
    cout<<"8)Display()"<<endl<<endl;
    cout<<"9)Clear screen()"<<endl<<endl;
    cin>>option;
   
        switch(option)
        {
            case 0:
            {   
                break;
            }
            case 1:
            {   cout<<"Enter the value to push : ";
                cin>>value;
                stackObj.push(value);
                break;
            }
            case 2:
            {
                if (stackObj.pop()==0)
                     cout<<"Stack is empty - Underflow occured"<<endl<<endl;
                else
                    cout<<stackObj.pop()<<endl<<endl;
                
                break;
            }
            case 3:
            {
                if(stackObj.isEmpty())
                    cout<<"Stack is empty..."<<endl<<endl;
                else   
                    cout<<"Not empty"<<endl<<endl;
                break;
            }
            case 4:
            {
                if(stackObj.isFull())
                    cout<<"Stack is Full..."<<endl<<endl;
                else   
                    cout<<"Not Full"<<endl<<endl;
                break;
            }
            case 5:
            {
                cout<<"Enter the index to get its value ";
                cin>>index;
                if(stackObj.peek(index)==-1)
                    cout<<"Index is not created yet..."<<endl<<endl;
                else   
                    cout<<stackObj.peek(index)<<endl<<endl;
                break;
            }
            case 6:
            {
                cout<<"There are " <<stackObj.count()<<" values in stack"<<endl<<endl;
                break;
            }
            case 7:
            {
                cout<<"Enter index to change ";
                cin>>index;
                cout<<"Enter value to change ";
                cin>>value;
                stackObj.change(index,value);
                break;
            }
            case 8:
            {
                stackObj.display();
                break;
            }
            case 9:
            {
                system("cls");
                break;
            }
            default:
            {
                cout<<"Select correct option"<<endl<<endl;
            }
            cout<<endl<<endl<<endl<<endl;
        }

    }while(option!=0);



}
int main()
{
   menu();
}