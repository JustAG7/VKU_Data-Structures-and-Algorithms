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

struct Node {
  int data;
  int priority;
  Node* next;
};

class PriorityQueue {
 private:
  Node* front;
  Node* rear;

 public:
  PriorityQueue() {
    front = NULL;
    rear = NULL;
  }

  void push(int data, int priority) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (front == NULL || priority < front->priority) {
      newNode->next = front;
      front = newNode;
    } else {
      Node* current = front;
      while (current->next != NULL && current->next->priority <= priority) {
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
    }

    if (rear == NULL) {
      rear = front;
    }
  }

  void pop() {
    if (front == NULL) {
      cout << "Priority queue is empty" << nl;
      return;
    }
    Node* temp = front;
    front = front->next;
    delete temp;
  }

  void print() {
    if (front == NULL) {
      throw "empty";
      return;
    }
    cout << "PQ: ";
    Node* current = front;
    while (current != NULL) {
      cout << current->data <<  " ";
      current = current->next;
    }
    cout << nl;
  }
};

int main() {
  fast;
  indef();
  PriorityQueue pq;
  pq.push(3, 1);
  pq.push(5, 3);
  pq.push(1, 1);
  pq.push(4, 2);

  pq.print();

  pq.pop();
  pq.pop();

  pq.print();

}

//if you want to have a pq with reversed sorted elements
/*
struct Node{
   int data;
   Node *next;
};

class PriorityQueue {
private:
    Node* head;
public:
    PriorityQueue() {
        head = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr || value > head->data) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != nullptr && curr->next->data >= value) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }

    void pop() {
        if (head == nullptr) {
            cout << "PQ is empty!" << nl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void print() {
        Node* curr = head;
        cout << "PQ: ";
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << nl;
    }
};
int main() {
  fast;
  indef();
  PriorityQueue pq;
  pq.push(10);
  pq.push(20);
  pq.push(30);
  pq.print();
  pq.pop();
  pq.print();
}
*/