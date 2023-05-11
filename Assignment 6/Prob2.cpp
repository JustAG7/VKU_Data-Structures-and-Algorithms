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
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class Stack{
    private:
        Node *list;

    public:
        Stack(){
            this->list=NULL;
        }

        void push(int data){
            Node *nNode = new Node(data);
            nNode->next=this->list;
            this->list=nNode;
        }

        bool empty(){
            return this->list == NULL;
        }

        int pop(){
            if(empty()){
                throw "empty stack";
            }
            Node *tmp = this->list;
            this->list=this->list->next;
            int pop_int = tmp->data;
            delete tmp;
            return pop_int;
        }

        int peek(){
            if(empty()){
                throw "empty stack";
            }
            return this->list->data;
        }

        void print(){
            Node *curr = this->list;
            while(curr!=NULL){
                cout << curr->data;
                curr=curr->next;
            }
            cout << '\n';
        }
        Stack(int num){
            while(num>0){
                if(num&1) push(1);
                else push(0);
                num/=2;
            }
        }
};

int main(){
	fast;
    
    Stack s = Stack(8);
    s.print();

    Stack m = Stack(12);
    m.print();

}
