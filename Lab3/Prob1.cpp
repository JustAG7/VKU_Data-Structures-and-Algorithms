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

bool isOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
  switch(op) {
    case '^':
      return 3;
    case '*':
    case '/':
      return 2;
    case '+':
    case '-':
      return 1;
    default:
      return -1;
  }
}

string infixToPostfix(string s) {
  Stack stack(s.size());
  string postfix = "";

  for (char c : s) {
    if (isalnum(c)) {
      postfix += c;
    }
    else if (c == '(') {
      stack.push(c);
    }
    else if (c == ')') {
      while (!stack.isEmpty() && stack.peek() != '(') {
        postfix += stack.pop();
      }
      if (!stack.isEmpty() && stack.peek() != '(') {
        throw "Invalid s: Mismatched Parentheses";
      }
      stack.pop();
    }
    else {
      while (!stack.isEmpty() && precedence(c) <= precedence(stack.peek())) {
        postfix += stack.pop();
      }
      stack.push(c);
    }
  }

  while (!stack.isEmpty()) {
    if (stack.peek() == '(') {
      throw "Invalid s: Mismatched Parentheses";
    }
    postfix += stack.pop();
  }

  return postfix;
}

double computePostfix(string s) {
  Stack stack(s.size());

  for (char c : s) {
    if (isdigit(c)) {
      stack.push(c - '0');
    }
    else if (isOperator(c)) {
      double operand2 = stack.pop();
      double operand1 = stack.pop();

      switch(c) {
        case '+':
          stack.push(operand1 + operand2);
          break;
        case '-':
          stack.push(operand1 - operand2);
          break;
        case '*':
          stack.push(operand1 * operand2);
          break;
        case '/':
          stack.push(operand1 / operand2);
          break;
        case '^':
          stack.push(pow(operand1, operand2));
          break;
      }
    }
  }

  return stack.pop();
}

int main() {
  fast;
  indef();
  string infix = "2*(3+4)-8/2^2";
  string postfix = infixToPostfix(infix);
  cout << "Infix: " << infix << nl;
  cout << "Postfix: " << postfix << nl;
  double value = computePostfix(postfix);
  cout << "Value: " << value << nl;
}
