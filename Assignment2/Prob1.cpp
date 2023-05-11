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
    int num;
    struct Node *next;
};
void NONO(){
	cout << "-1\n";
}
void addfront(Node *&list){
    Node *nNode = new Node;
    cin >> nNode->num;
    nNode->next = NULL;
    if(list==NULL) list = nNode;
    else nNode->next=list;
    list = nNode;
}
void addback(Node *&list){
    Node *nNode = new Node;
    cin >> nNode->num;
    nNode->next = NULL;
    if(list==NULL) list = nNode;
    else{
        Node *curr = list;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next = nNode;
    }
}
void popfront(Node *&list){
    if(list==NULL) return NONO();
    else list = list->next;
}
void popback(Node *&list){
    if(list==NULL) return NONO();
    Node *curr = list;
    Node *prev = NULL;
    while(curr->next!=NULL){
        prev = curr;
        curr=curr->next;
    }
    if(prev == NULL) list = NULL;   
    else prev->next = NULL;
    
    delete curr;
}
int countnodes(Node *list){
    int cnt=0;
    if(list==NULL) return cnt;
    Node *curr = list;
    while(curr!=NULL){
        cnt++;
        curr=curr->next;
    }
    return cnt;
}
void print(Node *list){
    if(list==NULL) return NONO();
    Node *curr = list;
    while(curr!=NULL){
        cout << curr->num << nl;
        curr=curr->next;
    }
}
void searchVal(Node *list){
    if(list==NULL) return NONO();
    int n,cnt=1;
    cin >> n;
    bool ok = false;
    Node *curr = list;
    while(curr!=NULL){
        if(curr->num==n){
            cout << cnt << ' ';
            ok=true;
        }
        curr=curr->next;
        cnt++;
    }
    if(!ok) return NONO();
    else cout << nl;

}
void searchPos(Node *list){
    if(list==NULL) return NONO();
    int n,cnt=1;
    cin >> n;
    Node *curr = list;
    while(curr!=NULL){
        if(cnt==n){
            cout << curr->num << nl;
            return;
        }
        curr=curr->next;
        cnt++;
    }
    NONO();
}
void append(Node *&p1,Node *p2){
    if(p1==NULL && p2==NULL) return NONO();
    Node *curr = p1;
    if(p1==NULL) p1=p2;
    else{
        Node *curr = p1;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next = p2;
    }
}
Node* merge(Node* p1, Node* p2) {
    vector<int> ans;
    Node* curr = p1;
    while(curr!=NULL){
        ans.pb(curr->num);
        curr=curr->next;
    }
    curr = p2;
    while(curr!=NULL){
        ans.pb(curr->num);
        curr=curr->next;
    }
    sort(all(ans));
    Node *res = NULL;
    for(int i=0;i<ans.size();i++){
        Node *nNode = new Node;
        nNode->num = ans[i];
        nNode->next = NULL;
        if(res == NULL) {
            res = nNode;
        } else {
            Node *temp = res;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = nNode;
        }
    }
    return res;
}

void deleteAt(Node *&list) {
    if (list == NULL) return NONO();
    int pos;
    cin >> pos;
    if (pos < 1) return NONO();
    int cnt = 1;
    Node *curr = list;
    Node *prev = NULL;
    while (curr != NULL && cnt < pos) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    if (curr == NULL) return NONO();  

    if (prev == NULL) {  
        list = curr->next;
        delete curr;
    } 
    else { 
        prev->next = curr->next;
        delete curr;
    }
}
void insertAt(Node *&list){
    int pos, val;
    cin >> pos >> val;
    Node *nNode = new Node;
    nNode->num = val;
    if(pos == 1){ 
        nNode->next = list;
        list = nNode;
        return;
    }
    Node *curr = list;
    Node *prev = NULL;
    int cnt = 1;
    while(curr != NULL && cnt != pos){  
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    if(curr == NULL && cnt < pos){  
        delete nNode;  
        return NONO();
    }
    prev->next = nNode;
    nNode->next = curr;
}

int main() {
	fast;
	indef();
    Node *p = NULL;
    Node *p1 = NULL;
    Node *p2 = NULL;
    addfront(p);
    addfront(p);
    addfront(p);
    addback(p);
    addback(p);
   	print(p);
    cout << nl;
    deleteAt(p);
    insertAt(p);
    print(p);
}

