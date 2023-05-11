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
};

class Queue{
    private:
        Node *head;
        Node *tail;
    public:
        Queue(){
            head = NULL;
            tail = NULL;
        }
        bool isEmpty(){
            return head==NULL;
        }
        void push(int num){
            Node *tmp = new Node;
            tmp->data=num;
            tmp->next=NULL;
            if(head==NULL){
                head = tail = tmp;
            }
            else{
                tail->next=tmp;
                tail=tmp;
            }
        }
        void pop(){
            if(isEmpty()){
                cout << "empty\n";
                return;
            }
            if(head->next==NULL){
                delete head;
                head = NULL;
                return;
            }
            Node *tmp = head;
            head=head->next;
            delete tmp;
        }
        int front(){
            if(isEmpty()){
                cout << "empty\n";
            }
            else return head->data;
        }
        void print(){
            Node *curr = head;
            while(curr!=NULL){
                cout << curr->data << nl;
                curr=curr->next;
            }
        }

};
int main(){
	fast;
    indef();

    Queue q;
    q.push(5);
    q.push(4);
    q.push(7);

    cout << q.front() << nl;
        q.pop();
    q.print();
}
