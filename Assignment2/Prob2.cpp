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


void indef(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
class Node {
public:
    int num;
    Node* next;
};

class Set {
private:
    Node* head; 
public:
    Set() {
        head = NULL;
    }
    bool isset() {
        Node* curr = head;
        while (curr != NULL) {
            Node* tmp = curr->next;
            while (tmp != NULL) {
                if (tmp->num == curr->num) {
                    return false;
                }
                tmp = tmp->next;
            }
            curr = curr->next;
        }
        return true;
    }

    bool subset(Set s2) {
        Node* curr = head;
        while (curr != NULL) {
            Node* tmp = s2.head;
            bool found = false;
            while (tmp != NULL) {
                if (tmp->num == curr->num) {
                    found = true;
                    break;
                }
                tmp = tmp->next;
            }
            if (!found) {
                return false;
            }
            curr = curr->next;
        }
        return true;
    }

    Set union_set(Set s2) {
        Set res;
        Node* curr = head;
        while (curr != NULL) {
            res.insert(curr->num);
            curr = curr->next;
        }
        curr = s2.head;
        while (curr != NULL) {
            res.insert(curr->num);
            curr = curr->next;
        }
        return res;
    }

    Set intersection(Set s2) {
        Set res;
        Node* curr = head;
        while (curr != NULL) {
            Node* tmp = s2.head;
            while (tmp != NULL) {
                if (tmp->num == curr->num) {
                    res.insert(curr->num);
                    break;
                }
                tmp = tmp->next;
            }
            curr = curr->next;
        }
        return res;
    }


    void insert(int x) {
        if (head == NULL) {
            head = new Node();
            head->num = x;
            head->next = NULL;
        }
        else {
            Node* curr = head;
            while (curr->next != NULL) {
                if (curr->num == x) {
                    return; 
                }
                curr = curr->next;
            }
            if (curr->num != x) {
                Node* tmp = new Node();
                tmp->num = x;
                tmp->next = NULL;
                curr->next = tmp;
            }
        }
    }

    void print() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->num << " ";
            curr = curr->next;
        }
        cout << nl;
    }
};

int main() {
    fast;
    indef();
    Set s1,s2;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s2.insert(5);
    s2.insert(2);
    s2.insert(6);
    s2.insert(1);
    Set s3 = s1.intersection(s2);
    s3.print();
}