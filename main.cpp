// COMSC-210 | Lab 18 | Christine Susic

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Node {
    int rating;
    string comments;
    Node *next;
};

//function prototypes
void addHeadNode(Node*&, int, string);
void addTailNode(Node*&, int, string);
void print(Node*&);
void deleteNode(Node*&);

int main() {
    Node one;
    Node *head = nullptr; //head ptr
    Node *newNode = new Node; //newNode ptr pointing to new Node
    int choiceList;
    char choiceReview;
    double average;
    
    cout << "Which linked list method should we use?" << endl;
    cout << "\t[1] New nodes are added at the head of the linked list" << endl;
    cout << "\t[2] New nodes are added at the tail of the linked list" << endl;
    
    //input data to linked list
    //review rating
    for (int i = 0; i < 2; i++) {
        cout << "Choice: ";
        cin >> choiceList;
        //if 1, nodes are added at the head
        if (choiceList == 1) {
            cout << "Enter review rating 0-5: ";
            cin >> one.rating;
            cin.ignore();
            //review comments
            cout << "Enter review comments: ";
            getline(cin, one.comments);
            addHeadNode(head, one.rating, one.comments);
        }
        else if (choiceList == 2) {
            //if 2, nodes are added at the tail
            cout << "Enter review rating 0-5: ";
            cin >> one.rating;
            cin.ignore();
             //review comments
            cout << "Enter review comments: ";
            getline(cin, one.comments);
            addTailNode(head, one.rating, one.comments);
        }
        else {
            cout << "Invalid entry. Please enter 1 or 2." << endl;
            continue;
        }
        //another review?
        cout << "Enter another review? Y/N: ";
        cin >> choiceReview;
        if (choiceReview == 'Y' || choiceReview == 'y') {
            continue;
        }
        else if (choiceReview == 'N' || choiceReview == 'n') {
            break;
        }
        else {
            cout << "Invalid entry. Please try again." << endl;
            continue;
        }
    };
    
    //output data
    cout << "Outputting all reviews: " << endl;
    for (int i = 0; i < 4; i++) {
        cout << "\t> Review #" << i + 1 << ": ";
    }
    print(head);
    //calculate average
    average = (one.rating)/2;
    cout << "\t> Average: " << average << endl;
    
    deleteNode(head);
    
    return 0;
}

void addHeadNode(Node*&head, int val1, string val2) {
    //adding a node to the head
    Node *newNode = new Node; //newNode ptr pointing to new Node
    if (!head) { //if list is empty
        head = newNode; //newNode becomes the head
        newNode->next = nullptr; //newNode next points to nullptr
        newNode->rating = val1; //add some value into new Node
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

void print(Node*&head) {
    Node* current = head;
    while (current) {
        cout << current->rating;
        cout << ": ";
        cout << current->comments;
        current = current->next;
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
