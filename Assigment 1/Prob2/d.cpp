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
	int n;
	cin >> n;
	int cnt4=0;
	for(int i = 1; i <= n; i *= 2)
		for(int j = 1; j <= i; j++)
			cnt4++;
	cout << cnt4;
	/*
		loop 1 contain 1 to log2(n) => O(log(n))
		each loop contain 1 to i => O(i)
		but i is 1,2,4,8,...,n => O(i)~O(n)
		=> computational complexity O(n*log(n))
	*/
}
