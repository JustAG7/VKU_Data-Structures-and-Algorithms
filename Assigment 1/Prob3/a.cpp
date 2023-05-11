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

int main(){
	indef();
	fast;
	int n,cnt=0;
	cin >> n;
	int a[n][n];
	int b[n][n]={1};
	int c[n][n]={0};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = b[i][j] + c[i][j];
			cout << a[i][j] << ' ';
			cnt++;
		}
		cout << nl;
	}
	cout << cnt;
	/*
		loop 1 contain 1 to n O(n)
		each loop contain 1 to n again O(n)
		=> computational complexity O(n^2)
	*/
}
