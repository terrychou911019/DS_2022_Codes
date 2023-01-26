#include <iostream>

typedef long long ll;

using namespace std;

typedef struct _Node
{
    ll data;
    struct _Node* next;
}
Node;

Node* newNode(ll data)
{
    Node* n = new Node;
    n->data = data;
    n->next = nullptr;
    return n;
}

int main()
{
    int M;
    cin >> M;
    while (M--)
    {
        int N, K;
        cin >> N >> K;
        if (N == 0)
        {
            cout << "\n";
            continue;
        }
        Node* head = newNode(0); // virtual head
        Node* tail = head;
        int n = N;

        // make the chain
        while (n--)
        {   
            ll num;
            cin >> num;
            Node* nd = newNode(num);
            tail->next = nd;
            tail = nd; 
        }

        int times = N / K; // reverse how many times
        Node* cur = head->next;
        while (times--)
        {   
            Node* prev = nullptr;
            int k = K; 
            Node* rhead = newNode(0);

            // reverse how many Nodes
            while (k--)
            {   
                Node* r = prev;
                prev = cur;
                cur = cur->next;
                prev->next = r;
            }
            rhead->next = prev;
            Node* c = rhead->next;

            // print
            while (c)
            {
                cout << c->data << " ";
                c = c->next;
            }
            
            // delete Nodes
            while (rhead)
            {
                Node* del = rhead;
                rhead = rhead->next;
                delete del;
            }
        }

        // print the remains n < K
        while (cur)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "\n";  
    }
    return 0;
}