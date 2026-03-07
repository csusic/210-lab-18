// COMSC-210 | Lab 18 | Christine Susic

#include <iostream>
#include <iomanip>
using namespace std;

const int W1 = 8;

struct Node {
    int rating;
    string comments;
    Node *next;
};

//function prototypes
fillNode();

int main() {
    int choiceList;
    char choiceReview;
    
    cout << "Which linked list method should we use?" << endl;
    cout << "[1] New nodes are added at the head of the linked list" << endl;
    cout << "[2] New nodes are added at the tail of the linked list" << endl;
    cin >> choiceList;
    
    for (int i = 0; i < 4; i++) {
        cout << "Enter review rating 0-5: " << endl;
        cin >> rating;
        cout << "Enter review comments: " << endl;
        cin >> comments;
        cout << "Enter another review? Y/N: " << endl;
        cin >> choiceReview;
        if (choiceReview = 'Y' OR 'y') {
            continue
        }
        else break; 
    }
    
    //new nodes at head 
    
    //new nodes at tail
    
    cin >> rating;
    cin >> comments;
    
    //traverse linked list
  
    //output data
    
    return 0;
}

fillNode() {
    Node n;
    
}
