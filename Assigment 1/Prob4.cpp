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
int Min(int a[], int n){
	int i, min;
	min = a[0];
	for(i = 1; i < n; i++)
		if (a[i] < min)
			min = a[i];
	return min;
}
int main(){
	indef();
	fast;
	int n,cnt=0;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	cout << Min(a,n);
	/*
		each time the function is called
		the function will loop from 1 to n to check every element
		=> time complexity O(n)
	*/
}
