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
	for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int result = 4*i*i + 7*j + 1;
            cout << result << " ";
        }
        cout << nl;
    }
    // 4n2 + 7n + 1 < 4n^2 + 7n^2  + 1n^2 = 12n^2 , with n=1.
    //=> O(n^2)
}
