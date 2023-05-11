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

int ign = 0;
struct Student{
	string name;
	int day,month,year;
	float mathMark,physicMark,languageMark;
};
struct ListNode{
	Student st;
	ListNode *nextNode;
};
ListNode *create(int n){
	ListNode *list = NULL;
	ListNode *curr = NULL;
	if(ign) {cin.ignore();ign=0;}
	for(int i=0;i<n;i++){
		ListNode *nNode = new ListNode;
		cin.ignore();	
		getline(cin,nNode->st.name);
		cin >> nNode->st.day;
		cin >> nNode->st.month;
		cin >> nNode->st.year;
		cin >> nNode->st.mathMark;
		cin >> nNode->st.physicMark;
		cin >> nNode->st.languageMark;
		nNode->nextNode=NULL;
		if(list==NULL){
			list = nNode;
			curr = nNode;
		}
		else{
			curr->nextNode=nNode;
			curr = nNode;
		}
	}
	return list;
}
void printList(ListNode *list,int n){
	ListNode* curr = list;
	while(curr!=NULL){
		cout << curr->st.name << nl;
		cout << curr->st.day << "/" << curr->st.month << "/" << curr->st.year << nl;
		cout << curr->st.mathMark << ' ' << curr->st.physicMark << ' ' << curr->st.languageMark << nl;
		curr=curr->nextNode;
	}
}

void add(ListNode *&list,int &n){
	ListNode *nNode = new ListNode;
	if(ign) {cin.ignore();ign=0;}
	n++;
	getline(cin,nNode->st.name);
	cin >> nNode->st.day;
	cin >> nNode->st.month;
	cin >> nNode->st.year;
	cin >> nNode->st.mathMark;
	cin >> nNode->st.physicMark;
	cin >> nNode->st.languageMark;
	nNode->nextNode=NULL;
	if(list==NULL){
		list = nNode;
	}
	else{
		ListNode *curr = list;
		while(curr->nextNode!=NULL) {
			curr=curr->nextNode;
		}
		curr->nextNode=nNode;
	}
	ign=1;
}
int cYear(ListNode *list){
	int year;
	int cnt=0;
	cin >> year;
	ign=1;
	ListNode *curr = list;
	while(curr!=NULL){
		if(curr->st.year==year) cnt++;
		curr=curr->nextNode;
	}
	return cnt;
}
int cName(ListNode *list){
	string sName;
	if(ign) {cin.ignore();ign=0;}
	getline(cin,sName);
	ListNode *curr = list;
	int cnt = 1;
	while(curr!=NULL){
		if(curr->st.name==sName) return cnt;
		cnt++;
		curr = curr->nextNode;
	}
	return -1;
}
void maxAvg(ListNode *list){
	double Avg=0;
	if(list==NULL) {cout << "-1\n"; return;}
	ListNode *curr = list;
	ListNode *ans = NULL;
	while(curr!=NULL){
		double avg = (curr->st.mathMark + curr->st.physicMark + curr->st.languageMark)/3.0;
		if(avg>Avg){
			ans = curr;
			Avg=avg;
		}
		curr= curr->nextNode;
	}
	cout << "Highest avg student: \n";
	cout << ans->st.name << nl;
	cout << ans->st.day << "/" << ans->st.month << "/" << ans->st.year << nl;
	cout << ans->st.mathMark << ' ' << ans->st.physicMark << ' ' << ans->st.languageMark << nl;
	cout << "Avg: " << Avg << nl;
}
void delByName(ListNode *&list, int &n){
	string sName;
	if(ign) {cin.ignore();ign=0;}	
	getline(cin,sName);
	ListNode *curr = list;
	ListNode *prev = NULL;
	while(curr!=NULL){
		if(curr->st.name==sName){
			if(prev==NULL){
				list = curr->nextNode;
			}
			else{
				prev->nextNode=curr->nextNode;
			}
			delete curr;
			n--;
			return;
		}
		prev = curr;
		curr = curr->nextNode;
	}
	cout << "-1\n";
}
void printListLessthan5(ListNode *list){
	ListNode *curr = list;
	if(list==NULL) {cout << "-1\n"; return;}
	else cout << "List of student having math Mark less than 5:\n";
	while(curr!=NULL){
		if(curr->st.mathMark<5){
			cout << curr->st.name << nl;
			cout << curr->st.day << "/" << curr->st.month << "/" << curr->st.year << nl;
			cout << curr->st.mathMark << ' ' << curr->st.physicMark << ' ' << curr->st.languageMark << nl;
		}
		curr=curr->nextNode;
	}
}
void KhOnGeM(){
	cout << "-1\n";
}
void printToFile(ListNode *list){
	if(list == NULL) return KhOnGeM();
	ofstream file("StudentList.txt");
	ListNode *curr = list;
	while(curr!=NULL){
		file << curr->st.name << nl;
		file << curr->st.day << "/" << curr->st.month << "/" << curr->st.year << nl;
		file << curr->st.mathMark << ' ' << curr->st.physicMark << ' ' << curr->st.languageMark << nl;
		curr=curr->nextNode;
	}
	file.close();
}
int main(){
	//indef();
	fast;
	int n;
	cin >> n;
	ListNode *list = create(n);

	//delByName(list,n);
	printToFile(list);
	printList(list,n);
}
