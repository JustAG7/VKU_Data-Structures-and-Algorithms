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
    char* arr;
    int top;
    int capacity;

  public:
    Stack(int size) {
      arr = new char[size];
      capacity = size;
      top = -1;
    }

    ~Stack() {
      delete[] arr;
    }

    void push(char c) {
      if (isFull()) {
        throw "Stack Overflow";
      }
      arr[++top] = c;
    }

    char pop() {
      if (isEmpty()) {
        throw "Stack Underflow";
      }
      return arr[top--];
    }

    char peek() {
      if (isEmpty()) {
        throw "Stack Underflow";
      }
      return arr[top];
    }

    bool isEmpty() {
      return top == -1;
    }

    bool isFull() {
      return top == capacity - 1;
    }
};

bool isMatchingPair(char opening, char closing) {
  if (opening == '(' && closing == ')') {
    return true;
  }
  else if (opening == '[' && closing == ']') {
    return true;
  }
  else if (opening == '{' && closing == '}') {
    return true;
  }
  else {
    return false;
  }
}

bool isBalanced(string s) {
  Stack stack(s.size());

  for (char c : s) {
    if (c == '(' || c == '[' || c == '{') {
      stack.push(c);
    }
    else if (c == ')' || c == ']' || c == '}') {
      if (stack.isEmpty() || !isMatchingPair(stack.peek(), c)) {
        return false;
      }
      else {
        stack.pop();
      }
    }
  }

  return stack.isEmpty();
}

int main() {
  indef();
  fast;
  string s = "{A + (B - C)}";
  if (isBalanced(s)) cout << "Balanced." << nl;
  else cout << "The s is not balanced." << nl;
  
}
