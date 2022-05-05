#include<iostream>
using namespace std;

template<class T>
class LinearList
{

public:
    LinearList()
    {
        this->m_data = NULL;
        this->m_Last = -1;
        this->m_Point = 0;
    }
    LinearList(int size)
    {
        this->m_data = new T[size];
        this->m_Last = size;
        this->m_Point = 0;
    }

    ~LinearList()
    {
        if(this->m_data!=NULL)
        {
            delete [] this->m_data;
            this->m_data = NULL;
        }
        this->m_Last = -1;
        this->m_Point = 0;
    }

    int size() const
    {
        return this->m_Point;
    }
    int capacity() const
    {
        return this->m_Last;
    }

    void push_back(T val)
    {
        if(this->m_Point<this->m_Last)
        {
            this->m_data[this->m_Point]=val;
            this->m_Point++;
        }
    }
    void push_head(T val)
    {
        if(this->m_Point<this->m_Last)
        {
            for(int i=this->m_Point; i>0; i--)
            {
                this->m_data[i] = this->m_data[i-1];
            }
            this->m_data[0]=val;
            this->m_Point++;
        }
    }

    int find(T var)
    {
        int i=0;
        while (i<this->m_Point&&var!=this->m_data[i])
        {
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
    }

    void for_each()
    {
        for(int i=0; i<this->m_Point; i++)
        {
            cout<<this->m_data[i]<<" ";
        }
        cout<<endl;
    }

    void resize(int size)
    {
        T* temp_data = new T[size];
        if(size>=this->m_Last)
        {
            for(int i=0; i<this->m_Last; i++)
            {
                temp_data[i] = this->m_data[i];
            }
        }
        else
        {
            for(int i=0; i<size; i++)
            {
                temp_data[i] = this->m_data[i];
                this->m_Point = size-1;
            }
        }
        delete[] this->m_data;
        this->m_data = temp_data;
        this->m_Last = size;
    }

    void insert(T var, int index)
    {
        if(index<0||index>=this->m_Last)
        {
            return;
        }
        if(this->m_Point<this->m_Last)
        {
            if(index==0)
            {
                this->push_head(var);
            }
            else if(index==this->m_Point)
            {
                this->push_back(var);
            }
            else
            {
                for(int j=this->m_Point; j>=index; j--)
                {
                    this->m_data[j+1] = this->m_data[j]; 
                }
                this->m_data[index] = var;
                this->m_Point++;
            }
        }
    }

    void del(int index)
    {
        if(index<0||index>=this->m_Last)
        {
            return;
        }
        for(int i=index+1; i<=this->m_Point; i++)
        {
            this->m_data[i-1] = this->m_data[i];
        }
        this->m_Point--;
    }

    void clear()
    {
        // delete[] this->m_data;
        this->m_Point = 0;
    }

    void pop_back()
    {
        this->m_Point--;
    }
    
    void pop_head()
    {
        for(int i=0; i<this->m_Point; i++)
        {
            this->m_data[i] = this->m_data[i+1];
        }
        this->m_Point--;
    }

    T operator[](int index)
    {
        return this->m_data[index];
    }


private:
    T* m_data;
    int m_Last;
    int m_Point;
};


int main(int argc, char const *argv[])
{
    LinearList<int> l1(5);
    LinearList<int> l2(5);

    for(int i=1; i<6; i++)
    {
        l1.push_back(i*2);
        l2.push_head(i*3);
    }
    
    l1.for_each();
    l2.for_each();

    cout<<l1[3]<<endl;

    cout<<l1.find(4)<<endl;

    l1.resize(7);
    l1.push_head(20);
    l1.for_each();
    cout<<l1.size()<<endl;
    cout<<l1.capacity()<<endl;

    l1.insert(30,5);
    l1.for_each();
    cout<<l1.size()<<endl;

    l1.del(2);
    l1.for_each();
    cout<<l1.size()<<endl;

    l1.pop_back();
    l1.for_each();
    cout<<l1.size()<<endl;

    l1.pop_head();
    l1.for_each();
    cout<<l1.size()<<endl;
  


    l1.clear();
    l1.for_each();
    cout<<l1.size()<<endl;

    // LinearList<char> l3(5);

    // l3.push_back('b');
    // l3.push_back('c');
    // l3.push_back('a');
    // l3.push_back('d');
    // l3.push_back('e');
    // cout<<l3.find('a')<<endl;
    // l3.for_each();

    return 0;
}
