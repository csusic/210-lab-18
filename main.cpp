// COMSC-210 | Lab 18 | Christine Susic

#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 7;

struct Node {
    int rating;
    string comments;
    Node *next;
};

//function prototypes
void addHeadNode();
void addTailNode();
void printRating();
void printComments();

int main() {
    int choiceList;
    char choiceReview;
    double average;
    
    cout << "Which linked list method should we use?" << endl;
    cout << "[1] New nodes are added at the head of the linked list" << endl;
    cout << "[2] New nodes are added at the tail of the linked list" << endl;
    cin >> choiceList;
    
    //input data to linked list
    //review rating
    cout << "Enter review rating 0-5: " << endl;
    if (choiceList == 1) {
        //if 1, nodes are added at the head
        while (cin >> rating) {
            addHeadNode(head, rating);
        }
    }
    else if (choiceList == 2) {
        //if 2, nodes are added at the tail
         while (cin >> rating) {
            addTailNode(head, rating);
        }
    }
    else {
        cout << "Invalid entry. Please enter 1 or 2."
    }
    
    //input data to linked list
    //review comments
    cout << "Enter review comments: " << endl;
    if (choiceList == 1) {
        //if 1, nodes are added at the head
        while (cin >> comments) {
            addHeadNode(head, comments);
        }
    }
    else if (choiceList == 2) {
        //if 2, nodes are added at the tail
         while (cin >> comments) {
            addTailNode(head, comments);
        }
    }
    else {
        cout << "Invalid entry. Please enter 1 or 2."
    }
    
    //another review?
    cout << "Enter another review? Y/N: " << endl;
    cin >> choiceReview;
    if (choiceReview == 'Y' OR 'y') {
        continue
    }
    else break; 
  
    //output data
    cout << "Outputting all reviews: " << endl;
    for (int i = 0; i < 4; i++) {
        cout << "> Review #" << i + 1 << ": ";
        cout << printRating() << ": ";
        cout << printReview() << endl;
    }
    //calculate average
    cout << "Average: " << average << endl;
    
    return 0;
}

void addHeadNode() {
    //adding a node to the head
    Node *head = nullptr; //head ptr
    Node *newNode = new Node; //newNode ptr pointing to new Node
    if (!head) { //if list is empty
        head = newNode; //head points to whatever newNode points at
        newNode->next = nullptr; //newNode next points to nullptr
        newNode->value = val; //add some value into new Node
    }
    else { //if list is not empty
        newNode->next = head;
        newNode->value = val;
        head = newNode;
    }
};

void addTailNode() {
    //adding a node to the tail
    Node *head = nullptr; //head ptr
    Node *tailNode = nullptr; //tail ptr
    Node *newNode = new Node; //newNode ptr pointing to new Node
    newNode->next = nullptr; //newNode next points to nullptr
    newNode->value = val; //add some value into new Node
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

void printRating() {
    Node *head = nullptr; //head ptr
    Node *temp = head; //temp node pointing to head
    while (temp) {
        cout << temp->rating << " ";
        temp = temp->next;
    }
};

void printReview() {
    Node *head = nullptr; //head ptr
    Node *temp = head; //temp node pointing to head
    while (temp) {
        cout << temp->review << " ";
        temp = temp->next;
    }
};

