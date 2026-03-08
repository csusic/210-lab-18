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
void addHeadNode(Node*&, int, string);
void addTailNode(Node*&, int, string);
void printNode();
void deleteNode(Node*&);

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
    cout << "Choice: ";
    cin >> choiceList;
    
    //input data to linked list
    //review rating
    do {
        //if 1, nodes are added at the head
        if (choiceList == 1) {
            cout << "Enter review rating 0-5: ";
            cin >> one.rating;
             //review comments
            cout << "Enter review comments: ";
            cin >> one.comments;
            addHeadNode(head, one.rating, one.comments);
        }
        else if (choiceList == 2) {
            //if 2, nodes are added at the tail
            cout << "Enter review rating 0-5: ";
            cin >> one.rating;
             //review comments
            cout << "Enter review comments: ";
            cin >> one.comments;
            addTailNode(head, one.rating, one.comments);
        }
        else {
            cout << "Invalid entry. Please enter 1 or 2.";
        }

        //another review?
        cout << "Enter another review? Y/N: ";
        cin >> choiceReview;
    } while (choiceReview == 'Y' || choiceReview == 'y');
  
    //output data
    cout << "Outputting all reviews: " << endl;
    for (int i = 0; i < 4; i++) {
        cout << "\t> Review #" << i + 1 << ": " << one.rating;
        cout << ": " << one.comments;
        cout << endl;
    }
    //calculate average
    cout << "\t>Average: " << average << endl;
    
    deleteNode(head);
    
    return 0;
}

void addHeadNode(Node*&head, int val1, string val2) {
    //adding a node to the head
    Node *newNode = new Node; //newNode ptr pointing to new Node
    if (!head) { //if list is empty
        head = newNode; //head points to whatever newNode points at
        newNode->next = nullptr; //newNode next points to nullptr
        newNode->rating = val1; //add some value into new Node
        head = newNode; //head points to whatever newNode points at
        newNode->next = nullptr; //newNode next points to nullptr
        newNode->comments = val2; //add some value into new Node
    }
    else { //if list is not empty
        newNode->next = head;
        newNode->rating = val1;
        head = newNode;
        newNode->next = head;
        newNode->comments = val2;
        head = newNode;
    }
};

void addTailNode(Node*&head, int val1, string val2) {
    //adding a node to the tail
    Node *tailNode = nullptr; //tail ptr
    Node *newNode = new Node; //newNode ptr pointing to new Node
    newNode->next = nullptr; //newNode next points to nullptr
    newNode->rating = val1; //add some value into new Node
    newNode->next = nullptr; //newNode next points to nullptr
    newNode->comments = val2; //add some value into new Node
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
    Node* temp = head; // Initialize temp pointer to the head
    cout << "List contents: ";
    
    // Traverse the list until temp becomes NULL
    while (temp != nullptr) {
        cout << temp->rating << " "; // Print the data
        temp = temp->next;         // Move to the next node
    }
    cout << endl; // Print a newline at the end
};

void printComments() {
    Node *head = nullptr; //head ptr
    Node *temp = head; //temp node pointing to head
    while (temp) {
        cout << temp->comments << " ";
        temp = temp->next;
    }
};

void deleteNode(Node*&head) {
    Node *current = head;
    //deleting a linked list
    while (current) {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}
