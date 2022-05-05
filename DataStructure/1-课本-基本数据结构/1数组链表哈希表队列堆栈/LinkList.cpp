#include<iostream>
using namespace std;

template <class T>
class LNode
{

public:
    T data;
    LNode<T> *Next;

};

template <class T>
class LinkList
{
public:

    LinkList(int n)
    {
        this->m_Len = n;
        this->m_Point = 0;
        
        this->head = new LNode<T>;
        this->head->data = (T)0;
        this->head->Next = NULL;

        LNode<T>* start = new LNode<T>;
        start->data = (T)0;
        start->Next = NULL;

        this->head->Next = start;
        // LNode<T>* temp = start;
        
        for(int i =0; i<n-1; i++)
        {
            LNode<T>* p = new LNode<T>;
            p->data = T(0);
            p->Next = NULL;

            start->Next = p;
            start = p;
        }

    }
    ~LinkList()
    {
        if(0==this->m_Len)
        {
            delete this->head;
            this->head = NULL;
            return;
        }
        LNode<T> *p = head->Next;
        delete this->head;
        this->head = NULL;
        while(p!=NULL)
        {
            LNode<T>*temp = p->Next;
            delete p;
            p = temp;
        }
        delete p;
        this->m_Len=0;
    }

    int size() const
    {
        return this->m_Point;
    }
    int capacity() const
    {
        return this->m_Len;
    }

    void for_each()
    {
        LNode<T> *p=this->head->Next;
        for (int i=0; i<this->m_Point; i++)
        {
            cout<<p->data<<" ";
            p = p->Next;
        }
        p=NULL;
        cout<<endl;
    }

    LNode<T>* find_node(int index)
    {
        LNode<T>* temp = new LNode<T>;
        if(index>this->m_Point)
        {
            // return temp;
            temp->data = (T)0;
            temp->Next = NULL;
        }
        else
        {
            temp = head;
            while (index--)
            {
                temp = temp->Next;
            }
        }


        return temp;        
    }

    int find(T var)
    {
        LNode<T>* temp = head->Next;
        int i=0;
        while (i<this->m_Point && var!=temp->data)
        {
            temp=temp->Next;
            i++;
        }
        if (i>=this->m_Point)
        {
            return -1;
        }
        else
        {
            return i;
        }
        temp=NULL;
    }

    void insert(T var, int index)
    {
        if(index>this->m_Len+1 || index<0)
        {
            return;
        }
        else if (index==this->m_Len+1)
        {
            LNode<T>* temp = this->head->Next;
            while (temp->Next!=NULL)
            {
                temp=temp->Next;
            }
            temp->Next = new LNode<T>;
            temp->Next->Next = NULL;
            temp->Next->data = var;
            this->m_Len++;
            this->m_Point++;
        }
        else
        {
            LNode<T>* pre = this->find_node(index);
            LNode<T>* cur = new LNode<T>;
            cur->data = var;
            cur->Next = pre->Next;
            pre->Next = cur;
            pre = cur = NULL;
            this->m_Len++;
            this->m_Point++;

            // if(this->m_Len!=this->m_Point)
            // {
            //     LNode<T>* p = this->head->Next;
            //     while (p->Next->Next!=NULL)
            //     {
            //         p=p->Next;
            //     }
            //     delete p->Next;
            //     p->Next=NULL;
            //     p = NULL;
            // }
        }
        
        
    }

    void del(int index)
    {
        if(index>this->m_Len||index<0)
        {
            return;
        }
        LNode<T>* pre = this->find_node(index);
        LNode<T>* cur =pre->Next;
        pre->Next = cur->Next;
        delete cur;
        cur=pre=NULL;
        this->m_Len--;
        this->m_Point--;
    }

    void push_back(T var)
    {
        if(this->m_Point<this->m_Len)
        {
            LNode<T>* p = this->head->Next;
            for(int i=0; i<this->m_Point; i++)
            {
                p = p->Next;
            }
            p->data = var;
            this->m_Point++;
        }
    }
    void push_head(T var)
    {
        if(this->m_Point<this->m_Len)
        {
            
            LNode<T>* temp = new LNode<T>;
            temp->data = var;
            temp->Next = this->head->Next;
            this->head->Next = temp;

            LNode<T>* p = this->head->Next;
            while (p->Next->Next!=NULL)
            {
                p=p->Next;
            }
            delete p->Next;
            p->Next=NULL;
            p = NULL;
            this->m_Point++;
        }
    }
    void pop_head()
    {
        if(this->m_Point>0)
        {
            LNode<T>* p = this->head->Next;
            this->head->Next = p->Next;
            delete p;
            p=NULL;

            LNode<T>* temp = this->head->Next;
            while (temp->Next!=NULL)
            {
                temp=temp->Next;
            }
            temp->Next = new LNode<T>;
            temp->Next->Next = NULL;
            temp->Next->data = (T)0;

            this->m_Point--;
        }

    }
    void pop_back()
    {
       if(this->m_Point>0)
       {
            this->m_Point--;
       }
    }

    void revese()
    {
        LNode<T>* pre = this->head;
        LNode<T>* cur = pre->Next;
        LNode<T>* next = cur->Next;
        for(int i=0; i<this->m_Point-2; i++)
        {
            pre = cur;
            cur = next; 
            next = next->Next;
            cur->Next = pre;
        }
        next->Next = cur;
        head->Next = next;
        pre=cur=next=NULL; 
    }

private:
    int m_Len;
    int m_Point;
    LNode<T>* head;
};

int main(int argc, char const *argv[])
{

    LinkList<int> l1(7);

    l1.push_back(2);
    l1.push_back(1);
    l1.push_back(3);
    l1.push_back(1);
    l1.for_each();
    cout << l1.size() <<":"<<l1.capacity()<<endl;

    l1.push_head(1);
    l1.push_head(4);
    l1.push_head(5);
    l1.for_each();
    cout << l1.size() <<":"<<l1.capacity()<<endl;

    cout<<"find: "<<l1.find(2)<<endl;
    l1.insert(20, 8);
    l1.insert(30, 9);
    l1.insert(40, 7);
    l1.for_each();
    cout << l1.size() <<":"<<l1.capacity()<<endl;


    l1.pop_head();
    l1.pop_head();
    l1.pop_head();
    l1.for_each();
    cout << l1.size() <<":"<<l1.capacity()<<endl;

    l1.pop_back();
    l1.pop_back();
    l1.pop_back();
    l1.for_each();
    cout << l1.size() <<":"<<l1.capacity()<<endl;

    l1.insert(10, 4);
    l1.insert(5, 0);
    l1.insert(12, 2);
    l1.for_each();
    cout << l1.size() <<":"<<l1.capacity()<<endl;

    l1.del(0);
    l1.del(0);
    l1.del(4);
    l1.del(3);
    l1.for_each();
    cout << l1.size() <<":"<<l1.capacity()<<endl;

    l1.revese();
    l1.for_each();
    cout << l1.size() <<":"<<l1.capacity()<<endl;

    return 0;
}
