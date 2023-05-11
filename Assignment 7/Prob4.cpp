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

const int M=1e9+7;
const int maxn=1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

struct Node{
    int data;
    Node *next;
    Node *prev;
};


class InputRestrictedDeque{
    private:
        Node *head, *tail;
    public:
        InputRestrictedDeque(){
            head = NULL;
            tail = NULL;
        }
        bool isEmpty(){
            return head==NULL;
        }
        void insertRear(int num){
            Node *tmp = new Node;
            tmp->data=num;
            tmp->next=NULL;
            if(head==NULL){
                head = tail = tmp;
                tmp->prev=NULL;
            }
            else{
                tail->next=tmp;
                tmp->prev=tail;
                tail=tmp;
            }
        }
        void deleteFront(){
            if(isEmpty()){
                cout << "empty\n";
                return;
            }
            if(head==tail){
                delete head;
                head = tail = NULL;
            }
            else{
                Node *tmp = head;
                head=head->next;
                head->prev=NULL;
                delete tmp;
            }
        }
        int getRear(){
            if(isEmpty()){
                cout << "empty\n";
                return -1;
            }
            else return tail->data;
        }
        void print(){
            Node *curr = head;
            while(curr!=NULL){
                cout << curr->data << " ";
                curr=curr->next;
            }
            cout << "\n";
        }
};

class OutputRestrictedDeque{
    private:
        Node *head, *tail;
    public:
        OutputRestrictedDeque(){
            head = NULL;
            tail = NULL;
        }
        bool isEmpty(){
            return head==NULL;
        }
        void insertFront(int num){
            Node *tmp = new Node;
            tmp->data=num;
            tmp->prev=NULL;
            if(head==NULL){
                head = tail = tmp;
                tmp->next=NULL;
            }
            else{
                tmp->next=head;
                head->prev=tmp;
                head=tmp;
            }
        }
        void deleteRear(){
            if(isEmpty()){
                cout << "empty\n";
                return;
            }
            if(head==tail){
                delete head;
                head = tail = NULL;
            }
            else{
                Node *tmp = tail;
                tail=tail->prev;
                tail->next=NULL;
                delete tmp;
            }
        }
        int getFront(){
            if(isEmpty()){
                cout << "empty\n";
                return -1;
            }
            else return head->data;
        }
        void print(){
            Node *curr = head;
            while(curr!=NULL){
                cout << curr->data << " ";
                curr=curr->next;
            }
            cout << "\n";
        }
};

int main(){
    fast;
    indef();
    InputRestrictedDeque q1;
    OutputRestrictedDeque q2;
    q1.insertRear(5);
    q1.insertRear(4);
    q1.insertRear(7);
    q1.print();
    q1.deleteFront();
    q1.print();
    cout << q1.getRear() << "\n";
    q2.insertFront(10);
    q2.insertFront(20);
    q2.insertFront(30);
    q2.print();
    q2.deleteRear();
    q2.print();
    cout << q2.getFront() << "\n";
}
