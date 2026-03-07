// COMSC-210 | Lab 18 | Christine Susic

#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 7;

class Node {
    public:
    int rating;
    string comments;
    Node *next;
};

//function prototypes
void addHeadNode(int, string);
void addTailNode(int, string);
void printRating();
void printComments();

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
        cout << "Enter review rating 0-5: " << endl;
        if (choiceList == 1) {
            //if 1, nodes are added at the head
            while (cin >> one.rating) {
                addHeadNode(one.rating);
            }
        }
        else if (choiceList == 2) {
            //if 2, nodes are added at the tail
            while (cin >> one.rating) {
                addTailNode(one.rating);
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
            while (cin >> one.comments) {
                addHeadNode(one.comments);
            }
        }
        else if (choiceList == 2) {
            //if 2, nodes are added at the tail
            while (cin >> one.comments) {
                addTailNode(one.comments);
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
    }
  
    //output data
    cout << "Outputting all reviews: " << endl;
    for (int i = 0; i < 4; i++) {
        cout << "> Review #" << i + 1 << ": ";
        cout << printRating() << ": ";
        cout << printComments() << endl;
    }
    //calculate average
    cout << "Average: " << average << endl;
    
    return 0;
}

void addHeadNode(int val, string comments) {
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

void addTailNode(int val, string comments) {
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

void printComments() {
    Node *head = nullptr; //head ptr
    Node *temp = head; //temp node pointing to head
    while (temp) {
        cout << temp->comments << " ";
        temp = temp->next;
    }
};

