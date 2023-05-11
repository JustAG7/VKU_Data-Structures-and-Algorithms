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
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a % b);
}
ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
}
int main(){
	fast;
	//indef();
	ll a,b;
	cin >> a >> b;
	cout << gcd(a,b) << ' ' << lcm(a,b);

}
