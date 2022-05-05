#include<iostream>
using namespace std;


template<class T>
class QueueLinear
{

public:
    QueueLinear()
    {

        this->MaxSize = 0;
        this->data = NULL;
        this->m_front = 0;
        this->m_rear = 0;
    }
    QueueLinear(int size)
    {

        this->MaxSize = size;
        this->data = new T[size+1];
        this->m_front = 0;
        this->m_rear = 0;
    }
    ~QueueLinear()
    {
        delete [] this->data;
        this->data = NULL;
        this->MaxSize = 0;
        this->m_front = 0;
        this->m_rear = 0;
    }
    bool empty() const
    {
        if(this->m_rear==this->m_front)
        {return true;}
        else
        {return false;}
    }
    void push(T var)
    {
        if((this->m_rear+1)%this->MaxSize==this->m_front)
        {
            return;
        }
        this->m_rear = (this->m_rear+1)%this->MaxSize;
        this->data[this->m_rear] = var;
    }
    void pop()
    {
        if(this->m_front==this->m_rear)
        {
            return;
        }
        this->m_front = (this->m_front+1)%this->MaxSize;
    }
    T back()
    {
        return this->data[this->m_rear];
    }
    T front()
    {
        return this->data[this->m_front+1];
    }
    int size()
    {
        return this->m_rear-this->m_front;
    }

private:
    int m_rear;
    int m_front;
    int MaxSize;
    T *data;

};

template<class T>
class Node
{
public:
    T data;
    Node<T>* Next;
};
template<class T>
class QueueLink
{
public:
    QueueLink()
    {
        this->head = NULL;
        this->rear = NULL;
        this->m_size = 0;
    }
    QueueLink(int size)
    {
        this->head = new Node<T>;
        this->head->data = (T)0;
        this->head->Next =NULL;
        this->rear = this->head;
        this->MaxSize = size;
        this->m_size = 0;
    }
    ~QueueLink()
    {
        if(0==this->MaxSize)
        {
            delete this->head;
            this->head = NULL;
            this->rear = NULL;
            return;
        }
        Node<T> *p = head->Next;
        delete this->head;
        this->head = NULL;
        while(p!=NULL)
        {
            Node<T>*temp = p->Next;
            delete p;
            p = temp;
        }
        delete p;
        this->rear = NULL;
        this->MaxSize=0;
    }
    int size() const
    {
        return this->m_size;
    }
    bool empty() const
    {
        if(this->m_size==0)
        {return true;}
        else
        {return false;}
    }
    void push(T var)
    {
        if(this->m_size+1==this->MaxSize)
        {return;}
        Node<T>* temp = new Node<T>;
        temp->data = var;
        temp->Next = NULL;
        this->rear->Next = temp;
        this->rear = temp;
        this->m_size++;
    }
    void pop()
    {
        if(this->head->Next==NULL)
        {return;}
        if(this->head->Next==this->rear)
        {
            delete this->rear;
            this->rear = this->head;
            this->m_size = 0;
        }
        else
        {
            Node<T> *temp = this->head->Next;
            this->head->Next = temp->Next;
            delete temp;
            this->m_size--;
        }
    }
    T back()
    {
        return this->rear->data;
    }
    T front()
    {
        return this->head->Next->data;
    }

private:
    Node<T>* head;
    Node<T>* rear;
    int MaxSize;
    int m_size;
};

int main(int argc, char const *argv[])
{

    QueueLinear<int>q1(5);
    cout<<q1.empty()<<endl;
    q1.push(20);
    q1.push(30);
    q1.push(40);
    cout<<q1.size()<<endl;
    cout<<q1.front()<<endl;
    cout<<q1.back()<<endl;
    q1.pop();
    q1.pop();
    cout<<q1.size()<<endl;

    QueueLink<int>q2(5);
    cout<<q2.empty()<<endl;
    q2.push(50);
    q2.push(60);
    q2.push(70);
    cout<<q2.size()<<endl;
    cout<<q2.front()<<endl;
    cout<<q2.back()<<endl;
    q2.pop();
    q2.pop();
    cout<<q2.size()<<endl;
    return 0;
}

