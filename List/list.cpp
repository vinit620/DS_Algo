#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

void InsertAtTail(Node *&head, int val);
void InsertAtHead(Node *&head, int val);
void DeleteNode(Node *&head, int val);
void DisplayList(Node *head);
bool Search(Node *head, int key);
void ReverseList(Node *&head);


int main(void)
{
    Node *head = NULL;
    InsertAtHead(head, 10);
    InsertAtTail(head, 20);
    InsertAtTail(head, 30);
    InsertAtHead(head, 40);
    InsertAtHead(head, 50);
    DisplayList(head);
    // DeleteNode(head, 50);
    // DeleteNode(head, 30);
    // DeleteNode(head, 10);
    // DisplayList(head);
    ReverseList(head);
    DisplayList(head);

    return 0;
}


void InsertAtTail(Node *&head, int val)
{
    Node *n = new Node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = n;
}


void InsertAtHead(Node *&head, int val)
{
    Node *n = new Node(val);
    n->next = head;
    head = n;
}


void DeleteNode(Node *&head, int val)
{
    // No Element
    if (head == NULL)
    {
        cout << "Empty list";
        return;
    }

    Node *temp = head;

    // Only One element or val at head
    if (head->data == val)
    {
        head = temp->next;
        delete temp;
        return;
    }

    // Element present at places other than head
    while (temp->next->data != val && temp)
        temp = temp->next;
    
    if (temp)
    {
        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
}


void DisplayList(Node *head)
{
    if (head == NULL)
    {
        cout << endl << "Empty List" << endl;
        return;
    }

    cout << endl << "List contains: ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


bool Search(Node *head, int key)
{
    while (head != NULL)
    {
        if (head->data == key)
            return true;
        head = head->next;
    }
    return false;
}


void ReverseList(Node *&head)
{
    Node *previous = NULL;
    Node *current = head;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}