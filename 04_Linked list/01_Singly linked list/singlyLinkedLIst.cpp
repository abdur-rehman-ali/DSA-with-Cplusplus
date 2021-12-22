#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class singlyLinkedList
{
private:
    node *head;

public:
    singlyLinkedList()
    {
        head = NULL;
    }

    bool valueExist(int value);
    void append(node *newNode);
    void prepend(node *newNode);
    void update(int data, int value);
    void deleteValue(int value);
    void display();
};

//This function will check whether search value exist in list or not
bool singlyLinkedList::valueExist(int value)
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

//This fucntion will add value at end of linked list
void singlyLinkedList::append(node *newNode)
{
    //If linked list is empty then this condition will be true
    if (head == NULL)
    {
        head = newNode;
        cout << "Value added at head of the linked list" << endl;
        ;
    }
    else
    {
        //Made temporary pointer for traversal of list
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Value added by traversing the linked list" << endl;
    }
}

//This fucntion will add value at start of linked list
void singlyLinkedList::prepend(node *newNode)
{
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        cout << "Value added at head" << endl;
    }
}

//This fucntion will update the value
void singlyLinkedList::update(int data, int value)
{
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
    }
    else
    {
        if (valueExist(data))
        {

            node *temp = head;
            while (temp != NULL)
            {
                if (temp->data == data)
                {
                    temp->data = value;
                    cout << "value updated" << endl;
                    return;
                }
                temp = temp->next;
            }
        }
        else
        {
            cout << "Value does not exist" << endl;
        }
    }
}

//This function will delete the value
void singlyLinkedList::deleteValue(int value)
{
    if (head == NULL)
    {
        cout << "List is empty...." << endl;
    }
    else
    {
        if (valueExist(value))
        {
            if (head->data == value)
            {
                head = head->next;
                cout << "Head value deleted..." << endl;
            }
            else
            {
                node *prevPtr = head;
                node *temp = head->next;
                while (temp != NULL)
                {
                    if (temp->data == value)
                    {
                        prevPtr->next = temp->next;
                        cout << "Value deleted..." << endl;
                        break;
                    }
                    prevPtr = prevPtr->next;
                    temp = temp->next;
                }
            }
        }
        else
        {
            cout << "Value does not exist..." << endl;
        }
    }
}

//This function will display all the values in the list
void singlyLinkedList::display()
{
    if (head == NULL)
    {
        cout << "Linked list is empty...." << endl;
    }
    else
    {
        //Made temporary pointer for traversal of list
        node *temp = head;
        while (temp != NULL)
        {
            cout << " " << temp->data << "-->";
            temp = temp->next;
        }
        cout << endl;
    }
}

void menu()
{
    int option, value, data;

    singlyLinkedList singlyLinkedListObj;

    do
    {
        cout << "0)Exit()" << endl
             << endl;
        cout << "1)Append()" << endl
             << endl;
        cout << "2)Prepend()" << endl
             << endl;
        cout << "3)Update()" << endl
             << endl;
        cout << "4)Delete()" << endl
             << endl;
        cout << "5)Display()" << endl
             << endl;
        cout << "6)Clear screen()" << endl
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

            singlyLinkedListObj.append(newNode);
            
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


            singlyLinkedListObj.prepend(newNode);
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            cout << "Enter the which value you want to update" << endl;
            cin >> data;
            cout << "Enter the updated value " << endl;
            cin >> value;
            singlyLinkedListObj.update(data, value);

            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            cout << "Enter the which value you want to delete" << endl;
            cin >> value;
            singlyLinkedListObj.deleteValue(value);

            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            singlyLinkedListObj.display();

            system("pause");
            system("cls");
            break;
        }
        case 6:
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