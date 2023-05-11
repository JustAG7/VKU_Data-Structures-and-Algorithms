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
	int sum=0;
	cin >> n;
	int a[n][n];
	int b[n][n]={1};
	int c[n][n]={1};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			sum = 0;
			for(int k = 0; k < n; k++){
				cnt++;
				sum = sum + b[i][k] * c[k][j];
			}
			a[i][j] = sum;
		}
	}
	cout << cnt;
	/*
		loop 1 contain 0 to n-1 => O(n)
		loop 2 contain 0 to n-1 => O(n)
		loop 3 contain O to n-1 => O(n)
		=> computational complexity O(n^3)
	*/
}
