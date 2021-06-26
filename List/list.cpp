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
Node *ReverseList(Node *&head);
Node *ReverseKNodes(Node *&head, int k);
void MakeCycle(Node *&head, int value);
bool DetectCycle(Node *&head);                         // Floyd's Algorithm
void RemoveCycle(Node *&head);                         // Floyd's Algorithm Continue



int main(void)
{
    Node *head = NULL;
    InsertAtHead(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    InsertAtTail(head, 6);
    
    MakeCycle(head, 3);
    cout << DetectCycle(head) << endl;

    RemoveCycle(head);
    cout << DetectCycle(head) << endl;
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


Node *ReverseList(Node *&head)
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
    return previous;
}


Node *ReverseKNodes(Node *&head, int k)
{
    Node *previous = NULL;
    Node *current = head;
    Node *next;

    int counter = 0;
    while (current && counter < k)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
        counter++;
    }

    if (next)
        head->next = ReverseKNodes(next, k);
    
    return previous;
}


void MakeCycle(Node *&head, int value)
{
    Node *temp = head;
    Node *cycleNode;

    while (temp->next)
    {
        if (temp->data == value)
            cycleNode = temp;
        
        temp = temp->next;
    }
    temp->next = cycleNode;
}


bool DetectCycle(Node *&head)
{
    Node *fast = head, *slow = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
            return true;
    }
    return false;
}


void RemoveCycle(Node *&head)
{
    Node *fast = head, *slow = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    while (slow != fast);
    
    fast = head;
    while (fast->next != slow->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}