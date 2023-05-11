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
};

class CircularLinkedList {
    private:
        Node* tail;
    public:
        CircularLinkedList() {
            tail = NULL;
        }
        
        void pfront(int value) {
            Node* newNode = new Node;
            newNode->data = value;
            if (tail == NULL) {
                tail = newNode;
                tail->next = tail;
            } else {
                newNode->next = tail->next;
                tail->next = newNode;
            }
        }
        
        void pback(int value) {
            Node* newNode = new Node;
            newNode->data = value;
            if (tail == NULL) {
                tail = newNode;
                tail->next = tail;
            } else {
                newNode->next = tail->next;
                tail->next = newNode;
                tail = newNode;
            }
        }
        
        void delfront() {
            if (tail == NULL) {
                cout << "Empty\n";
            } else if (tail == tail->next) {
                Node* temp = tail;
                tail = NULL;
                delete temp;
            } else {
                Node* temp = tail->next;
                tail->next = temp->next;
                delete temp;
            }
        }
        
        void delback() {
            if (tail == NULL) {
                cout << "Empty\n";
            } else if (tail == tail->next) {
                Node* temp = tail;
                tail = NULL;
                delete temp;
            } else {
                Node* temp = tail;
                while (temp->next != tail) {
                    temp = temp->next;
                }
                temp->next = tail->next;
                delete tail;
                tail = temp;
            }
        }
        
        void printList() {
            if (tail == NULL) {
                cout << "Empty\n";
            } else {
                Node* temp = tail->next;
                do {
                    cout << temp->data << " ";
                    temp = temp->next;
                } while (temp != tail->next);
                cout << endl;
            }
        }
};
int main() {
	fast;
	indef();
    CircularLinkedList s;
    s.pback(6);
    s.pback(5);
    s.pfront(1);
    s.pfront(9);
    s.printList();
    s.delfront();
    s.delback();
    s.printList();
}

