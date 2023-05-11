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


class Stack {
private:
    char arr[maxn];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char c) {
        if (top == maxn - 1) {
            throw "overflow!";
            return;
        }
        top++;
        arr[top] = c;
    }

    char pop() {
        if (top == -1) {
            throw "underflow!";
            return '\0';
        }
        char c = arr[top];
        top--;
        return c;
    }

    bool isEmpty() {
        return top == -1;
    }
};

void rvStack(string& str) {
    Stack stack;
    for (char c : str) {
        stack.push(c);
    }
    for (int i = 0; i < str.length(); i++) {
        str[i] = stack.pop();
    }
}

void rvRecursion(string& str, int start, int end) {
    if (start >= end) {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    rvRecursion(str, start+1, end-1);
}

int main() {
    fast;
    indef();
    string str = "hello";
    rvStack(str);
    cout << str << nl;
    string s = "hello";
    rvRecursion(s, 0, s.length()-1);
    cout << str << nl;
}
