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
struct Student{
	char name[30];
	char classroom[10];
	float mMath;
	float mPhysical;
};
void add(Student **&students, int &n){
	Student *s = new Student;
	cin.ignore();
	cin.getline(s->name, 30);
	cin.getline(s->classroom, 10);
	cin >> s->mMath;
	cin >> s->mPhysical;
	Student **tmp = new Student*[n+1];
	for(Student **p = students, **q = tmp; p != students+n; p++,q++) {
        *q = *p;
    }
    tmp[n] = s;
    delete[] students;
    students=tmp;
    n++;
}

int findName(Student **&students,int n){
	char sName[30];
	cin.ignore();
	cin.getline(sName,30);
	for(Student **p =students;p<students+n;p++){
		if(strcmp((*p)->name,sName)==0){
			return p-students+1;
		}
	}
	return -1;
}
void FandEname(Student **&students, int n){
	char sName[30];
	cin.ignore();
	cin.getline(sName,30);
	for(Student **p=students;p<students+n;p++){
		if(strcmp((*p)->name,sName)==0){
			char nClass[10];
			cin.getline(nClass,10);
			strcpy((*p)->classroom,nClass);
		}
	}
}
int main(){
	fast;
	//indef();
	int n;
	cin >> n;
	Student **students = new Student*[n];
	for(Student **p=students; p<students+n;p++){
		*p= new Student;
		cin.ignore();
		cin.getline((*p)->name, 30);
		cin.getline((*p)->classroom, 10);
		cin >> (*p)->mMath;
		cin >> (*p)->mPhysical;

	}
	
	add(students,n);
	findName(students,n);
	FandEname(students,n);
	for(Student **p=students; p<students+n;p++){
		cout << (*p)->name << ' ' << (*p)->classroom << ' ' << (*p)->mMath << ' ' << (*p)->mPhysical << nl;
	}
	

}
