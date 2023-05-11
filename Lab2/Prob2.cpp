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
#include <iostream>

using namespace std;

struct Node {
    int num;
    int coeff;
    struct Node *next;
};
void NONO(){
	cout << "-1\n";
}
void add(struct Node *&list){
	struct Node *newNode = new Node;
	cin >> newNode->num;
    cin >> newNode->coeff;
    list = newNode;
	
}
void addition(struct Node *&list){
	if(list==NULL) return NONO();
	struct Node *temp = list;
    bool found = false;
    struct Node *nNode = new Node;
    cin >> nNode->num;
    cin >> nNode->coeff;
    while (temp != NULL) {
        if (temp->num == nNode->num) {
            temp->coeff += nNode->coeff;
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        
        nNode->next = NULL;

        if (list == NULL) {
            list = nNode;
        } 

        else {
            temp = list;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = nNode;
        }
    }
}
void subtract(struct Node *list){
    if(list==NULL) return NONO();
    struct Node *temp = list;
    bool found = false;
    struct Node *nNode = new Node;
    cin >> nNode->num;
    cin >> nNode->coeff;
    nNode->coeff*=-1;
    while(temp!=NULL){
        if(temp->num==nNode->num){
            temp->coeff+=nNode->coeff;
            found = true;
            break;
        }
        temp = temp->next;
    }
    if(!found){
        nNode->next=NULL;
        if(list==NULL){
            list = nNode;
        }
        else{
            temp = list;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = nNode;
        }
    }
}
void printList(struct Node *list) {
    struct Node *curr = list;
    while (curr != NULL) {
        cout << curr->coeff << "x^" << curr->num;
        if(curr->next!=NULL){
        	cout << "+";    	
        }
        curr=curr->next;
    }
}

int main() {
	fast;
	indef();
    struct Node *list = NULL;
   	add(list);
   	addition(list);
    subtract(list);
   	printList(list);
}

