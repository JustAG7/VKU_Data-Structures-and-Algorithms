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
    char data;
    Node *next;
    Node(char data = '\0'){
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

        void push(char data){
            Node *nNode = new Node(data);
            nNode->next=this->list;
            this->list=nNode;
        }

        bool empty(){
            return this->list == NULL;
        }

        char pop(){
            if(empty()){
                throw "empty stack";
            }
            Node *tmp = this->list;
            this->list=this->list->next;
            char pop_char = tmp->data;
            delete tmp;
            return pop_char;
        }

        char peek(){
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

        int compute(){
            if(empty()){
                throw "empty stack";
            }

            int num = 0, result = 0;
            char op = '+';

            while(!empty()){
                char c = pop();
                if(isdigit(c)){
                    num = num * 10 + (c - '0');
                }
                else if(c == '+' || c == '-'){
                    if(op == '+'){
                        result += num;
                    }
                    else if(op == '-'){
                        result -= num;
                    }
                    op = c;
                    num = 0;
                }
                else{
                    throw "Invalid operator";
                }
            }

            if(op == '+'){
                result += num;
            }
            else if(op == '-'){
                result -= num;
            }

            return result;
        }
};

int main(){
	fast;
    Stack s;
    s.push('3');
    s.push('+');
    s.push('5');
    s.print(); 
    cout << s.compute() << nl;
}
