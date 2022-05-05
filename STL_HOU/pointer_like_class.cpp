
template<class T>
class share_ptr
{
public:
    T& operator*() const
    {
        return *this->px;
    }
    T* operator->() const
    {
        return this->px;
    }
    share_ptr(T* p): px(p){}
private:
    T* px;
    long* pn;

};

