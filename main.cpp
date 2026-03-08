// COMSC-210 | Lab 18 | Christine Susic

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int SIZE = 7;

class Node {
    public:
    int rating;
    string comments;
    Node *next;
};

//function prototypes
void addHeadNodeRating(Node*&, int);
void addHeadNodeComments(Node*&, string);
void addTailNodeRating(Node*&, int);
void addTailNodeComments(Node*&, string);
void printRating();
void printComments();
void deleteNode();

int main() {
    Node one; //Node object
    Node *head = nullptr; //head ptr
    Node *newNode = new Node; //newNode ptr pointing to new Node
    int choiceList;
    char choiceReview;
    double average;
    
    cout << "Which linked list method should we use?" << endl;
    cout << "[1] New nodes are added at the head of the linked list" << endl;
    cout << "[2] New nodes are added at the tail of the linked list" << endl;
    cin >> choiceList;
    
    //input data to linked list
    //review rating
    for (int i = 0; i < 4; i++) {
        //if 1, nodes are added at the head
        if (choiceList == 1) {
            cout << "Enter review rating 0-5: " << endl;
            cin >> one.rating;
             //review comments
            cout << "Enter review comments: " << endl;
            cin >> one.comments;
            addHeadNodeRating(head, one.rating);
            addHeadNodeComments(head, one.comments);
        }
        else if (choiceList == 2) {
            //if 2, nodes are added at the tail
            cout << "Enter review rating 0-5: " << endl;
            cin >> one.rating;
             //review comments
            cout << "Enter review comments: " << endl;
            cin >> one.comments;
            addTailNodeRating(head, one.rating);
            addTailNodeComments(head, one.comments);
        }
        else {
            cout << "Invalid entry. Please enter 1 or 2.";
        }
    
        //another review?
        cout << "Enter another review? Y/N: " << endl;
        cin >> choiceReview;
        if (choiceReview == 'Y') {
            continue;
        }
        else break; 
    }
  
    //output data
    cout << "Outputting all reviews: " << endl;
    for (int i = 0; i < 4; i++) {
        cout << "> Review #" << i + 1 << ": ";
        printRating();
        cout << ": ";
        printComments();
        cout << endl;
    }
    //calculate average
    cout << "Average: " << average << endl;
    
    deleteNode();
    
    return 0;
}

void addHeadNodeRating(Node*&head, int val) {
    //adding a node to the head
    Node *newNode = new Node; //newNode ptr pointing to new Node
    if (!head) { //if list is empty
        head = newNode; //head points to whatever newNode points at
        newNode->next = nullptr; //newNode next points to nullptr
        newNode->rating = val; //add some value into new Node
    }
    else { //if list is not empty
        newNode->next = head;
        newNode->rating = val;
        head = newNode;
    }
};

void addHeadNodeComments(Node*&head, string val) {
    //adding a node to the head
    Node *newNode = new Node; //newNode ptr pointing to new Node
    if (!head) { //if list is empty
        head = newNode; //head points to whatever newNode points at
        newNode->next = nullptr; //newNode next points to nullptr
        newNode->comments = val; //add some value into new Node
    }
    else { //if list is not empty
        newNode->next = head;
        newNode->comments = val;
        head = newNode;
    }
};

void addTailNodeRating(Node*&head, int val) {
    //adding a node to the tail
    Node *tailNode = nullptr; //tail ptr
    Node *newNode = new Node; //newNode ptr pointing to new Node
    newNode->next = nullptr; //newNode next points to nullptr
    newNode->rating = val; //add some value into new Node
    if (!head) { //if list is empty
        head = newNode; //newNode becomes the head
    }
    else { //if list is not empty
        tailNode = head; //tailNode becomes the head
        while (tailNode->next) { //loops through the linked list
            tailNode = tailNode->next;
        }
        tailNode->next = newNode; //newNode becomes the tail
    }
};

void addTailNodeComments(Node*&head, string val) {
    //adding a node to the tail
    Node *tailNode = nullptr; //tail ptr
    Node *newNode = new Node; //newNode ptr pointing to new Node
    newNode->next = nullptr; //newNode next points to nullptr
    newNode->comments = val; //add some value into new Node
    if (!head) { //if list is empty
        head = newNode; //newNode becomes the head
    }
    else { //if list is not empty
        tailNode = head; //tailNode becomes the head
        while (tailNode->next) { //loops through the linked list
            tailNode = tailNode->next;
        }
        tailNode->next = newNode; //newNode becomes the tail
    }
};

void deleteNode() {
    Node *current = head;
    //deleting a linked list
    while (current) {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void printRating() {
    Node *head = nullptr; //head ptr
    Node *temp = head; //temp node pointing to head
    while (temp) {
        cout << temp->rating << " ";
        temp = temp->next;
    }
};

void printComments() {
    Node *head = nullptr; //head ptr
    Node *temp = head; //temp node pointing to head
    while (temp) {
        cout << temp->comments << " ";
        temp = temp->next;
    }
};

