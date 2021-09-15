#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;

};


class singlyLinkedList
{
    private:
    node*head;
    public:

    singlyLinkedList()
    {
        head=NULL;
    }

    void append(node* newNode);
    void prepend(node* newNode);
    void display();
};

//This fucntion will add value at end of linked list
void singlyLinkedList:: append(node* newNode)
{
    //If linked list is empty then this condition will be true
    if(head==NULL)
    {
        head=newNode;
        cout<<"Value added at head of the linked list";
    }
    else
    {
        //Made temporary pointer for traversal of list
        node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        cout<<"Value added by traversing the linked list";
    }
}


//This fucntion will add value at start of linked list
void singlyLinkedList::prepend(node* newNode)
{
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        node *temp=head;
        newNode->next=temp;
        head=newNode;
        cout<<"Value added at head"<<endl;

    }
}


//This function will display all the values in the list
void singlyLinkedList:: display()
{
    if (head==NULL)
    {
        cout <<"Linked list is empty";
    }
    else
    {
        //Made temporary pointer for traversal of list
        node *temp=head;
        while(temp!=NULL)
        {
            cout<<" "<<temp->data<<"-->";
            temp=temp->next;
        }
    }
}


void menu()
{
    int option,value;
   
    singlyLinkedList singlyLinkedListObj;

    do
    {
    cout<<"0)Exit()"<<endl<<endl;
    cout<<"1)Append()"<<endl<<endl;
    cout<<"2)Prepend()"<<endl<<endl;
    cout<<"3)Update()"<<endl<<endl;
    cout<<"4)Delete()"<<endl<<endl;
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
            {   
                cout<<"Enter the value to append"<<endl;
                cin>>value;
                node* newNode = new node();
                newNode->data=value;
                newNode->next=NULL;

                singlyLinkedListObj.append(newNode);
                break;
            }
            case 2:
            {
                cout<<"Enter the value to prepend"<<endl;
                cin>>value;
                node* newNode = new node();
                newNode->data=value;
                newNode->next=NULL;

                singlyLinkedListObj.prepend(newNode);
                break;
                
                break;
            }
            case 3:
            {
               
                break;
            }
            case 4:
            {
                
                break;
            }
            case 5:
            {
                singlyLinkedListObj.display();
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