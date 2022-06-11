
#include <iostream>
#include <atomic>
// using namespace std;

#define SAFE_DELETE(p) if (p) { delete p; p = nullptr; }

// 计数
class KRefCount
{
public:
    KRefCount() : m_nCount(0){}

public:
    // 对这个引用计数进行锁定并ADD 1
    unsigned AddRef(){ return ++m_nCount; }
    // 对这个引用计数进行锁定并SUB 1
    unsigned Release(){ return --m_nCount; }
    unsigned UseCount(){ return m_nCount; }
    void Reset(){ m_nCount = 0; }

private:
    std::atomic_uint32_t m_nCount;
};

template <typename T>
class SmartPtr
{
public:
    SmartPtr(void)
        : m_pData(NULL)
    {
        m_pReference = new KRefCount();
        m_pReference->AddRef();
    }

    SmartPtr(T* pValue)
        : m_pData(pValue)
    {
        m_pReference = new KRefCount();
        m_pReference->AddRef();
    }

    SmartPtr(const SmartPtr<T>& sp)
        : m_pData(sp.m_pData)
        , m_pReference(sp.m_pReference)
    {
        m_pReference->AddRef();
    }

    ~SmartPtr(void)
    {
        if (m_pReference && m_pReference->Release() == 0)
        {
            SAFE_DELETE(m_pData);
            SAFE_DELETE(m_pReference);
        }
    }

    inline T& operator*()
    {
        return *m_pData;
    }

    inline T* operator->()
    {
        return m_pData;
    }

    SmartPtr<T>& operator=(const SmartPtr<T>& sp)
    {
        std::cout<<"====\n";
        if (this != &sp)
        {
            if (m_pReference && m_pReference->Release() == 0)
            {
                SAFE_DELETE(m_pData);
                SAFE_DELETE(m_pReference);
            }

            m_pData = sp.m_pData;
            m_pReference = sp.m_pReference;
            m_pReference->AddRef();
        }

        return *this;
    }

    SmartPtr<T>& operator=(T* pValue)
    {
        std::cout<<"==\n";
        if (m_pReference && m_pReference->Release() == 0)
        {
            SAFE_DELETE(m_pData);
            SAFE_DELETE(m_pReference);
        }

        m_pData = pValue;
        m_pReference = new KRefCount;
        m_pReference->AddRef();
        return *this;
    }

    T* Get()
    {
        T* ptr = NULL;
        ptr = m_pData;

        return ptr;
    }

    void Attach(T* pObject)
    {
        if (m_pReference->Release() == 0)
        {
            SAFE_DELETE(m_pData);
            SAFE_DELETE(m_pReference);
        }

        m_pData = pObject;
        m_pReference = new KRefCount;
        m_pReference->AddRef();
    }

    T* Detach()
    {
        T* ptr = NULL;

        if (m_pData)
        {
            ptr = m_pData;
            m_pData = NULL;
            m_pReference->Reset();
        }
        return ptr;
    }

    unsigned int use_count() const
    {
        return m_pReference->UseCount();
    }

private:
    KRefCount* m_pReference;
    T* m_pData;
};

class CTest
{
public:
    CTest(int b) : a(b) {}
private:
    int a;
};

/*
    智能指针使用引用计数实现时，就是最好的使用代理模式的例子。在上面的例子中，SmartPtr就是一个代理类，而T* m_pData才是实际的数据。SmartPtr代理实际的数据，去实现了指针的行为，添加了引用计数，从而实现了智能指针。
*/

int main()
{

    SmartPtr<CTest> pSmartPtr1(new CTest(10));
    SmartPtr<CTest> pSmartPtr2(new CTest(20));
    std::cout<<pSmartPtr1.use_count()<<std::endl;
    std::cout<<pSmartPtr2.use_count()<<std::endl;
    pSmartPtr1 = pSmartPtr2;
    std::cout<<pSmartPtr1.use_count()<<std::endl;
    std::cout<<pSmartPtr2.use_count()<<std::endl;

    // 检验赋值操作符的重载
    int a = 10, b = 20;
    SmartPtr<int> pSmartPtr3(&a);
    SmartPtr<int> pSmartPtr4 = pSmartPtr3;
    SmartPtr<int> pSmartPtr5 = pSmartPtr3;
    std::cout<<pSmartPtr3.use_count()<<std::endl;
    pSmartPtr3 = &b;
    std::cout<<pSmartPtr3.use_count()<<std::endl;
}