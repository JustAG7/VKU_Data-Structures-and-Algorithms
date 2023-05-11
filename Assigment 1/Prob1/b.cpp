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
    int c = 1; 
    int n0 = 1; 
    int lhs = n * n - 3 * n + 1;
    int rhs = c * n;
    if(lhs >= rhs && n >= n0) {
        cout << "n^2 - 3n + 1 >= c * n với n >= " << n0 << endl;
    } else {
        cout << "n^2 - 3n + 1 < c * n với n < " << n0 << endl;
    }
    return 0;
}
