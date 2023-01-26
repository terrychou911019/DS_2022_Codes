#include <iostream>

using namespace std;

template <class T>
class mystack
{
public:
    // Constructer
    mystack(int stackCapacity = 10);

    // Check if the stack is empty
    bool empty() const;

    // Return the top element
    T& top() const;

    // Insert a new element at top
    void push(const T& element);

    // Delete one element from top
    void pop();

    // Return the number of elements
    int size() const;
private:
    T* stack;
    int top_idx; // init. value = -1
    int capacity;
};

template<class T>
mystack<T>::mystack(int stackCapacity)
{
    if(stackCapacity < 1)
        throw "stackCapacity must be > 0.";

    stack = new T[stackCapacity];
    top_idx = -1;
    capacity = stackCapacity;
}

template<class T>
bool mystack<T>::empty() const
{
    return (top_idx == -1);
}

template<class T>
T& mystack<T>::top() const
{
    if(empty())
        throw "Stack is empty. No top element.";

    return stack[top_idx];
}

template<class T>
void mystack<T>::push(const T& element)
{   // Add element to stack
    if(top_idx == capacity - 1){
        // resize
        T* tmp = stack;
        stack = new T[2 * capacity];
        for(int i = 0 ; i <= top_idx ; i++){
            stack[i] = tmp[i];
        }
        delete [] tmp;
        capacity *= 2;
    }
    stack[++top_idx] = element;
}

template<class T>
void mystack<T>::pop()
{   // Delete top element from stack
    if(empty())
        throw "Stack is empty. Cannot pop.";

    stack[top_idx--].~T();
}

template<class T>
int mystack<T>::size() const
{
    return top_idx + 1;
}

mystack<int> sk;
int GPU[10000005];

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int i = 0;
    int price;
    while (cin >> price)
    {
        GPU[i] = price;
        i = i + 1;
    }
    
    sk.push(0);
    cout << "1 ";
    for (int j = 1 ; j < i ; j++)
    {   
        while (!sk.empty() && GPU[sk.top()] >= GPU[j]) 
            sk.pop();

        if (sk.empty())
            cout << j + 1;
        else 
            cout << j - sk.top();
        cout << " ";

        sk.push(j);
    }
    cout << "\n";
    return 0;
}