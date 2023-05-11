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


class Queue {
    private:
        int items[maxn], front, rear;

    public:
        Queue() {
            front = -1;
            rear = -1;
        }

        bool isFull() {
            if (front == 0 && rear == maxn - 1) {
                return true;
            }
            if (front == rear + 1) {
                return true;
            }
            return false;
        }

        bool isEmpty() {
            if (front == -1) {
                return true;
            }
            return false;
        }

        void enqueue(int element) {
            if (isFull()) {
                cout << "Queue is full" << endl;
            } else {
                if (front == -1) {
                    front = 0;
                }
                rear = (rear + 1) % maxn;
                items[rear] = element;
            }
        }

        void dequeue() {
            int element;
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
            } else {
                element = items[front];
                if (front == rear) {
                    front = -1;
                    rear = -1;
                } else {
                    front = (front + 1) % maxn;
                }
            }
        }

        void display() {
            int i;
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
            } else {
        
                for (i = front; i != rear; i = (i + 1) % maxn) {
                    cout << items[i] << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    fast;
    indef();
    Queue q;

    q.enqueue(5);
    q.enqueue(9);
    q.enqueue(3);
    q.enqueue(7);
    q.enqueue(6);

    q.display();
    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
}