#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class singelLinkedList {
    Node* head;
public:
    singelLinkedList(){
        head = NULL;
    }

    void insertBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        Node* temp;
        if(head == NULL){
            head = newNode;
            temp = newNode;
        } else {
            temp = head;
            while (temp != NULL) {
                if(temp->next == NULL) {
                    temp->next = newNode;
                    temp = newNode;
                }
                temp = temp->next;
            }
        }
    }

    void deleteHeadNode() {
        Node* temp = head;
        if(temp->next != NULL) {
            head = temp->next;
            delete temp;
            cout << "First node is deleted" << endl;
        }
    }

    void deleteEndNode() {
        if(head != NULL) {
            if(head->next == NULL) {
                head = NULL;
            } else {
                Node* temp = head;
                while(temp->next->next != NULL) {
                    temp = temp->next;
                }
                Node* lastNode = temp->next;
                temp->next = NULL;
                free(lastNode);
               
            }
        }

    };

    void deleteNodeByValue(int value) {
        if(head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Head is deleted" << endl;
        } else {
            Node *temp = head;
            while (temp->next != NULL) {
                if (temp->next->data == value) {
                    temp->next = temp->next->next;
                    cout << "Value in linked-list is deleted" << endl;
                    return;
                }
                temp = temp->next;
            }
        }
    }

    void displaySLL(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<endl;
            cout<<"Memory location of data" << &temp->data<<endl;
            cout<< &temp->next->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};




int main() {

    singelLinkedList sLLObject;
    
    sLLObject.insertBeginning(60);
    sLLObject.insertBeginning(70);
    sLLObject.insertBeginning(80);
    sLLObject.displaySLL();


    sLLObject.insertEnd(50);
    sLLObject.displaySLL();

    sLLObject.deleteEndNode();
    sLLObject.displaySLL();



    return 0;
}
