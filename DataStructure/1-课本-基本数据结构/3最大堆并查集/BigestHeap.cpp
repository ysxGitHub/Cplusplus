#include<iostream>
using namespace std;
#define MaxData 10000

template<typename T>
class MaxHeap
{

public:
    MaxHeap()
    {
        elements = NULL;
        m_size=0;
        capacity=0;
    }
    MaxHeap(int maxsize): capacity(maxsize)
    {
        m_size = 0;
        elements = new T[maxsize+1];
        // 哨兵
        elements[0] = MaxData;
    }
    ~MaxHeap()
    {
        delete[] elements;
        m_size=0;
        capacity=0;
    }
    void CreateHeap()
    {
        for(int i=m_size/2; i>0; i--)
        {
            PrecDown(i);
        }
    }
    bool Insert(T val)
    {
        if(capacity!=0)
        {
            int i;
            if(m_size==capacity)
            {
                return false;
            }
            // 指向堆的最后面
            i = ++m_size;
            // 当父节点的值小于要插入的值时
            for(; elements[i/2]<val; i/=2)
            {
                // 将父节点的值下移
                elements[i] = elements[i/2];
            }
            // 将要插入的值放入移动后的空位
            elements[i] = val;
            return true;
        }
        else{return false;}

    }
    // 从最大堆中删除最大节点
    bool Delete()
    {
        if(capacity!=0)
        {
            int parent, child;

            // 取出根节点
            T maxitem = elements[1];
            // 得到最大堆最后一个元素, 并将size-1;
            T temp = elements[m_size--];
            // 判断父节点是否有左儿子, 如果有进行循环（从根节点进行）
            for(parent=1; parent*2<=m_size; parent=child)
            {
                // child指向左儿子
                child = parent*2;
                if((child!=m_size)&& // 判断是否有右儿子
                (elements[child]<elements[child+1])) // 判断右儿子的值是否大于左儿子
                {
                    child++;
                }
                if(temp>=elements[child]) // 如果最后的值大于等于
                {break;}
                else
                {
                    elements[parent] = elements[child];
                }
            }
            elements[parent] = temp;
            return true;
        }
        else
        {
            return false;
        }
    }
    void set_Date(T* data)
    {
        elements = data;
    }
    void set_Size(int size)
    {
        if(size<capacity)
        {
            m_size = size;
        }
    }
    int get_Size() const
    {
        return m_size;
    }

    T get_Data(int i) const
    {
        if(i<=m_size)
        {
            return elements[i];
        }
        else
        {
            return elements[0];
        }
    }
    
private:
    T* elements;
    int m_size;
    int capacity;

    void PrecDown(int p)
    {
        int parent, child;

        // 取出根节点
        T item = elements[p];
        // 判断父节点是否有左儿子, 如果有进行循环（从根节点进行）
        for(parent=p; parent*2<=m_size; parent=child)
        {
            // child指向左儿子
            child = parent*2;
            if((child!=m_size)&& // 判断是否有右儿子
            (elements[child]<elements[child+1])) // 判断右儿子的值是否大于左儿子
            {
                child++;
            }
            if(item>=elements[child]) // 找到合适的位置了
            {break;}
            else
            {
                elements[parent] = elements[child];
            }
        }
        elements[parent] = item;
    }

};



int main(int argc, char const *argv[])
{
    MaxHeap<int> heap(20);
    int num1[11] = {MaxData,1,2,3,4,5,6,7,8,9,10};
    heap.set_Date(num1);
    heap.set_Size(10);
    heap.CreateHeap();
    for(int i=1;i<=heap.get_Size();i++)
    {
        cout<<heap.get_Data(i)<<" ";
    }
    cout<<endl;

    heap.Delete();
    for(int i=1;i<=heap.get_Size();i++)
    {
        cout<<heap.get_Data(i)<<" ";
    }
    cout<<endl;    

    heap.Insert(0);
    for(int i=1;i<=heap.get_Size();i++)
    {
        cout<<heap.get_Data(i)<<" ";
    }
    cout<<endl;   

    return 0;
}


