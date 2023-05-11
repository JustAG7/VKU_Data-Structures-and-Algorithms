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

    /*
    log(2n + k) = log(2(n + k/2))
            = log(2) + log(n + k/2)
            <= log(2) + log(n + n)
            = log(4n)
            = 2 log(n) + log(4)
            = O(log(n))

    log(2n + k) = log(2(n/2 + k/2))
                = log(n + k/2)
                >= log(n)
                = Ω(log(n))
    */
	indef();
	fast;
	int k = 1; 
    int n0 = 1; 
    double c1 = 0.5; 
    double c2 = 2; 

    // Kiểm tra cho n = 1, 2, 3, ..., 10
    for (int n = n0; n <= 10; n++) {
        double lhs = log2(2*n + k);
        double rhs1 = c1 * log2(n);
        double rhs2 = c2 * log2(n);
        if (lhs >= rhs1 && lhs <= rhs2) {
            cout << "log(2n + k) = Theta(log(n)) voi n = " << n << endl;
        } else {
            cout << "log(2n + k) khong bang Theta(log(n)) voi n = " << n << endl;
        }
    }
}
