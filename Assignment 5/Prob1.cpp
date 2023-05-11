#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        DoublyLinkedList() {
            head = NULL;
            tail = NULL;
        }
        
        void pfront(int value) {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = head;
            newNode->prev = NULL;
            if (head != NULL) {
                head->prev = newNode;
            } else {
                tail = newNode;
            }
            head = newNode;
        }
        
        void pback(int value) {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = NULL;
            newNode->prev = tail;
            if (tail != NULL) {
                tail->next = newNode;
            } else {
                head = newNode;
            }
            tail = newNode;
        }
        
        void delfront() {
            if (head == NULL) {
                cout << "Empty.\n";
            } else {
                Node* temp = head;
                head = head->next;
                if (head != NULL) {
                    head->prev = NULL;
                } else {
                    tail = NULL;
                }
                delete temp;
            }
        }
        
        void delback() {
            if (tail == NULL) {
                cout << "Empty.\n";
            } else {
                Node* temp = tail;
                tail = tail->prev;
                if (tail != NULL) {
                    tail->next = NULL;
                } else {
                    head = NULL;
                }
                delete temp;
            }
        }
        
        void printList() {
            if (head == NULL) {
                cout << "Empty.\n";
            } else {
                Node* temp = head;
                while (temp != NULL) {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
        
        int count() {
            int count = 0;
            Node* temp = head;
            while (temp != NULL) {
                count++;
                temp = temp->next;
            }
            return count;
        }
        
        bool searchVal(int value) {
            Node* temp = head;
            while (temp != NULL) {
                if (temp->data == value) {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
        
        int searchPos(int pos) {
            int count = 1;
            Node* temp = head;
            while (temp != NULL && count < pos) {
                temp = temp->next;
                count++;
            }
            if (temp != NULL && count == pos) {
                return temp->data;
            } else {
                cout << "Invalid pos\n";
                return -1;
            }
        }
        void deleteAtPos(int pos) {
            Node* temp = head;
            int count = 1;
            while (temp != NULL && count < pos) {
                temp = temp->next;
                count++;
            }
            if (temp == NULL) {
                cout << "Invalid pos\n";
                return;
            }
            if (temp == head) {
                head = temp->next;
                if (head != NULL) {
                    head->prev = NULL;
                } else {
                    tail = NULL;
                }
            } else if (temp == tail) {
                tail = temp->prev;
                tail->next = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            delete temp;
        }

        void insertAtPos(int pos, int value) {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->prev = NULL;
            newNode->next = NULL;
            Node* temp = head;
            int count = 1;
            while (temp != NULL && count < pos) {
                temp = temp->next;
                count++;
            }
            if (temp == NULL && count != pos) {
                cout << "Invalid pos\n";
                delete newNode;
                return;
            }
            if (temp == head) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else if (temp == NULL) {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            } else {
                newNode->prev = temp->prev;
                newNode->next = temp;
                temp->prev->next = newNode;
                temp->prev = newNode;
            }
        }
};

int main() {
	fast;
	//indef();
    DoublyLinkedList s;
    s.pback(7);
    s.pfront(5);
    s.insertAtPos(2,8);
    s.deleteAtPos(2);
    s.printList();
}

