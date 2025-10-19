#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int d){
        data = d;
        next = nullptr;
    }
};

class LinkedList{
private:
    Node* head;

public:
    LinkedList(): head(nullptr){}

    // Append a new node at the end
    void Append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;                 // seting first node
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next; // now go to last
        temp->next = newNode;                 // linking at tail
    }

    // now inserting a node at the front (the head)
    void InsertNodeToHead(int val){
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode; //updating head
}

    // Here lets insert a node after the first node (value == key)
    void InsertNode(int key, int val){
        Node* temp = head;
        // find our key
        while (temp && temp->data != key) temp = temp->next;

        if(!temp){
            cout << "Node with value " << key << " not found!" << endl;
            return;
        }
        // insert after temp node
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // insert a tails node at the end of list
    void InsertNodeToTail(int val){
        Node *newNode = new Node(val);

        if (!head) {
         cout << "The list is empty." << endl; 
            head = newNode;
            return;
        }

        Node* last = head;
        while (last->next) last = last->next;
        last->next = newNode;
    }

    // anything with a vallue of d must be deleted
    void DeleteNode(int d){
        if (!head) {
            cout << "Node with value " << d << " not found!" << endl;
            return;
        }

        // delete head
        if (head->data == d) {
            Node* toDel = head;
            head = head->next;
            delete toDel;
            return;
        }

        // lets find the predecessor of node to delete
        Node *temp = head;
        while (temp->next && temp->next->data != d) temp = temp->next;

        if (temp->next == nullptr) {
            cout << "Node with value " << d << " not found!" << endl;
            return;
        }

        Node* toDel = temp->next;
        temp->next = toDel->next;
        delete toDel;
    }

    // Display
    void Display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedList emptyList;
    emptyList.InsertNodeToTail(10);
    cout << "The linked list after inserting 10 to the tail: ";
    emptyList.Display();

    emptyList.InsertNodeToTail(20);
    cout << "The linked list after inserting 20 to the tail: ";
    emptyList.Display();
    cout << "" << endl;

    int listArray[] = {1, 3, 5, 7, 9};

    LinkedList lkList;

    for (int x : listArray) lkList.Append(x);

    cout << "The created linked List: ";
    lkList.Display();
    cout << "" << endl;

    lkList.InsertNodeToHead(0);
    cout << "The linked list after adding 0: ";
    lkList.Display();
    cout << "" << endl;

    lkList.InsertNode(5, 6);
    cout << "The linked list after adding 6: ";
    lkList.Display();
    cout << "" << endl;

    lkList.DeleteNode(0);
    cout << "The linked list after deleting 0: ";
    lkList.Display();
    cout << "" << endl;

    lkList.DeleteNode(10);
    cout << "The linked list after deleting 10: ";
    lkList.Display();
    cout << "" << endl;

    lkList.DeleteNode(7);
    cout << "The linked list after deleting 7: ";
    lkList.Display();

    return 0;
}
