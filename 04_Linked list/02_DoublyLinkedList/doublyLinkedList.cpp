#include <iostream>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

class DoublyLinkedList
{
private:
    node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    bool valueExist(int value);
    void append(node *newNode);
    void prepend(node *newNode);
    void insertNodeAfter(int value, node *newNode);
    void update(int old, int newValue);
    void deleteValue(int value);
    void displayInReverse();
    void display();
};

bool DoublyLinkedList::valueExist(int value)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return false;
    }
    else
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
}

void DoublyLinkedList::append(node *newNode)
{
    if (head == NULL)
    {
        head = newNode;
        cout << "Value added at head" << endl;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        cout << "Value added after traversing" << endl;
    }
}

void DoublyLinkedList::prepend(node *newNode)
{
    if (head == NULL)
    {
        head = newNode;
        cout << "List was empty \n Value added at head..." << endl;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        cout << "Value added at head" << endl;
    }
}

void DoublyLinkedList::insertNodeAfter(int value, node *newNode)
{

    node *slow=head;
    node* fast=head->next;

    while(fast!=NULL)
    {

        if(slow->data==value)
        {
            slow->next=newNode;
            newNode->prev=slow;
            newNode->next=fast;
            fast->prev=newNode;
            cout<<"Value added..."<<endl;
            return;
        }
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=newNode;
    cout<<"Value added at tail..."<<endl;

}

void DoublyLinkedList::update(int old, int newValue)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == old)
        {
            temp->data = newValue;
            cout << "Value updated..." << endl;
            break;
        }

        temp = temp->next;
    }
}

void DoublyLinkedList::deleteValue(int value)
{
    if (head->data == value)
    {
        head = head->next;
        cout << "Value deleted from head..." << endl;
    }
    else
    {
        node *slow = head;
        node *fast = head->next;

        while (fast->next != NULL)
        {
            if (fast->data == value)
            {
                slow->next = fast->next;
                fast->next->prev = slow;
                cout << "Value deleted..." << endl;
                return;
            }

            slow = slow->next;
            fast = fast->next;
        }
        if (fast->data == value)
        {
            slow->next = NULL;
            cout << "Value deleted from tail..." << endl;
        }
    }
}

void DoublyLinkedList::displayInReverse()
{

    if (head == NULL)
    {
        cout << "List is currently empty..." << endl;
        return;
    }

    node *temp = head;

    //This loop will traverse though end and then we start printing element in reverse order
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    //Loop below will print the list in reverse order
    while (temp != NULL)
    {
        cout << " " << temp->data << "-->";
        temp = temp->prev;
    }
}

void DoublyLinkedList::display()
{
    if (head == NULL)
    {
        cout << "List is currently empty..." << endl;
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << " " << temp->data << "-->";
        temp = temp->next;
    }
    cout << endl;
}

void menu()
{
    int option, value, data;

    DoublyLinkedList DoublyLinkedListObj;

    do
    {
        cout << "0)Exit()" << endl
             << endl;
        cout << "1)Append()" << endl
             << endl;
        cout << "2)Prepend()" << endl
             << endl;
        cout << "3)Insert node after()" << endl
             << endl;
        cout << "4)Update()" << endl
             << endl;
        cout << "5)Delete()" << endl
             << endl;
        cout << "6)DisplayInRevers()" << endl
             << endl;
        cout << "7)Display()" << endl
             << endl;
        cout << "8)Clear screen()" << endl
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
            cout << "Enter the value to append" << endl;
            cin >> value;
            node *newNode = new node();
            newNode->data = value;
            newNode->next = NULL;
            newNode->prev = NULL;
            DoublyLinkedListObj.append(newNode);

            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            cout << "Enter the value to prepend" << endl;
            cin >> value;
            node *newNode = new node();
            newNode->data = value;
            newNode->next = NULL;
            newNode->prev = NULL;

            DoublyLinkedListObj.prepend(newNode);
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            cout << "Enter the value after which you want to add node" << endl;
            cin >> value;
            if (DoublyLinkedListObj.valueExist(value))
            {
                cout << "Enter value to insert ...";
                cin >> data;
                node *newNode = new node();
                newNode->data = data;
                newNode->next = NULL;
                newNode->prev = NULL;

                DoublyLinkedListObj.insertNodeAfter(value,newNode);
            }
            else
            {
                cout << "Value does not exist..." << endl;
            }

            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            cout << "Enter the which value you want to update" << endl;
            cin >> data;
            if (DoublyLinkedListObj.valueExist(data))
            {
                cout << "Enter the updated value " << endl;
                cin >> value;
                DoublyLinkedListObj.update(data, value);
            }
            else
            {
                cout << "That value does not exixt..." << endl;
            }

            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            cout << "Enter the which value you want to delete" << endl;
            cin >> value;
            if (DoublyLinkedListObj.valueExist(value))
            {
                DoublyLinkedListObj.deleteValue(value);
            }
            else
            {
                cout << "Value does not exist..." << endl;
            }

            system("pause");
            system("cls");
            break;
        }
        case 6:
        {
            DoublyLinkedListObj.displayInReverse();

            system("pause");
            system("cls");
            break;
        }
        case 7:
        {
            DoublyLinkedListObj.display();

            system("pause");
            system("cls");
            break;
        }
        case 8:
        {
            system("cls");
            break;
        }
        default:
        {
            cout << "Select correct option" << endl
                 << endl;
        }
        }

    } while (option != 0);
}

int main()
{
    menu();
    return 0;
}
