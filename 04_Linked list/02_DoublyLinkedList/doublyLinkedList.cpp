#include<iostream>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
}

class doublyLinkedList
{   
    private:
    node *head;
    

};


void menu()
{
    int option, value, data;

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
            
            
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
           


           
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
           
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
           
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
           

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