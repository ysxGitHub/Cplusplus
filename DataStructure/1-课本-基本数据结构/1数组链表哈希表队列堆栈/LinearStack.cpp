#include<iostream>
// #include<stack>
using namespace std;

template<class T>
class StackLinear
{

public:
    StackLinear()
    {
        this->m_top = -1;
        this->MaxSize = 0;
        this->data = NULL;
    }
    StackLinear(int size)
    {
        this->m_top = -1;
        this->MaxSize = size;
        this->data = new T[size];

    }
    ~StackLinear()
    {
        delete [] this->data;
        this->data = NULL;
        this->m_top = -1;
        this->MaxSize = 0;
    }
    bool empty() const
    {
        if(this->m_top == -1){return true;}
        else{return false;}
    }
    void push(T var)
    {
        if(this->m_top == this->MaxSize-1)
        {
            return ;
        }
        else
        {
            this->data[++this->m_top] = var;
        }
    }
    void pop()
    {
        this->m_top--;
    }
    int size() const
    {
        return this->m_top+1;
    }
    T top() const
    {
        return this->data[this->m_top];
    }

private:
    int m_top;
    int MaxSize;
    T *data;
};

template<class T>
class Node
{
public:
    T data;
    Node<T>* next_node;
};
template<class T>
class StackLink
{

public:
    StackLink()
    {
        this->head = NULL;
        this->m_top = -1;
        this->Maxsize = 0;
    }
    StackLink(int size)
    {
        this->head = new Node<T>;
        this->head->data = (T)0;
        this->head->next_node = NULL;
        this->m_top = -1;
        this->Maxsize = size;
    }
    ~StackLink()
    {
        if(0==this->Maxsize)
        {
            delete this->head;
            this->head = NULL;
            return;
        }
        Node<T> *p = head->next_node;
        delete this->head;
        this->head = NULL;
        while(p!=NULL)
        {
            Node<T>*temp = p->next_node;
            delete p;
            p = temp;
        }
        delete p;
        this->Maxsize=0;
    }
    bool empty() const
    {
        if(this->m_top == -1){return true;}
        else{return false;}
    }
    void push(T var)
    {
        if(this->m_top == this->Maxsize-1)
        {
            return ;
        }
        else
        {
            Node<T>* new_node = new Node<T>;
            new_node->data = var;
            new_node->next_node = this->head->next_node;
            this->head->next_node = new_node;
            this->m_top++;
        }
    }
    void pop()
    {
        Node<T>* temp = this->head->next_node;
        this->head->next_node = temp->next_node;
        delete temp;
        this->m_top--;
    }
    int size() const
    {
        return this->m_top+1;
    }
    T top() const
    {
        return this->head->next_node->data;
    }

private:
    Node<T>* head;
    int Maxsize;
    int m_top;
};


int main(int argc, char const *argv[])
{
    StackLinear<int>s1(5);
    cout<<s1.empty()<<endl;
    s1.push(5);
    s1.push(6);
    cout<<s1.size()<<endl;
    cout<<s1.top()<<endl;
    s1.pop();
    cout<<s1.top()<<endl;

    StackLink<int>s2(5);
    cout<<s2.empty()<<endl;
    s2.push(2);
    s2.push(3);
    cout<<s2.size()<<endl;
    cout<<s2.top()<<endl;
    s2.pop();
    cout<<s2.top()<<endl;

    return 0;
}

