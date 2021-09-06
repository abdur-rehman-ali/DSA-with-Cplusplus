#include<iostream>
using namespace std;

class queue{
    private:
    int arr[10];
    int size;
    int front;
    int back;

    public:
    queue();
    bool isFull();
    bool isEmpty();
    void enqueue(int val);
    int dequeue();
    void display();
};
queue::queue()
{
    size=10;
    front=-1;
    back=-1;
    for (int i = 0; i < size; i++)
    {
        arr[i]=0;
    }
}
bool queue::isEmpty()
{
    if (front==-1 && back==-1)
    return true;
    else 
    return false;
}
bool queue::isFull()
{
    if (back==size-1)
    return true;
    else
    return false;
}
void queue::enqueue(int val)
{
    if (isFull())
    {
        cout<<"Queue is full"<<endl;
    }
    else if (back==-1 && front==-1)
    {
        front=0;
        back=0;
        arr[back]=val;
    }
    else
    {
        back++;
        arr[back]=val;
    }
}
int queue::dequeue()
{
    int ret_value=0;
    if (isEmpty())
    {
        return ret_value;
    }
    else if (front==back)
    {
        cout<<"Else if executred"<<endl<<endl;
        ret_value=arr[front];
        arr[front]=0;
        back=-1;
        front=-1;
        cout<<"Front"<<ret_value<<endl<<endl;
        return ret_value;
    }
    else
    {
        ret_value=arr[front];
        arr[front]=0;
        front++;
        return ret_value;
    }
}

void queue::display()
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }
    
}
void menu()
{
    int option,value,dequeue_value;
    queue queueObj;

    do
    {
    cout<<"0)Exit()"<<endl<<endl;
    cout<<"1)Enqueue()"<<endl<<endl;
    cout<<"2)Dequeue()"<<endl<<endl;
    cout<<"3)isEmpty()"<<endl<<endl;
    cout<<"4)isFull()"<<endl<<endl;
    cout<<"5)Display()"<<endl<<endl;
    cout<<"6)Clear screen()"<<endl<<endl;
    cin>>option;
   
        switch(option)
        {
            case 0:
            {   
                break;
            }
            case 1:
            {   cout<<"Enter the value to enqueue : ";
                cin>>value;
                queueObj.enqueue(value);
                break;
            }
            case 2:
            {
                dequeue_value=queueObj.dequeue();
                if (dequeue_value==0)
                {
                  cout<<"Queue is empty - Underflow occured"<<endl<<endl;
                }
                else
                 {  
                      cout<<"Dequeued value : "<<dequeue_value<<endl<<endl;
                 }
                
                break;
            }
            case 3:
            {
                if(queueObj.isEmpty())
                    cout<<"Queue is empty..."<<endl<<endl;
                else   
                    cout<<"Not empty..."<<endl<<endl;
                break;
            }
            case 4:
            {
                if(queueObj.isFull())
                    cout<<"Queue is Full..."<<endl<<endl;
                else   
                    cout<<"Not Full"<<endl<<endl;
                break;
            }
            case 5:
            {
                queueObj.display();
                break;
            }
            case 6:
            {
                system("cls");
                break;
            }
            default:
            {
                cout<<"Select correct option"<<endl<<endl;
            }
            
        }

}while(option!=0);



}
int main()
{
   menu();
   return 0;
}