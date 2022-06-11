/*

*/
#include <iostream>
#include <map>

class NonCopyable{
protected:
    NonCopyable()=default;
    ~NonCopyable()=default;
    NonCopyable(const NonCopyable &)=delete;
    NonCopyable & operator =(const NonCopyable &) = delete;
};

template <typename Func>
class Event:NonCopyable{
public:
    Event()=default;
    ~Event()=delete;
    //注册观察者,支持右值引用
    int Attach(Func && f){
        return Assign(f);
    }
     //注册观察者,支持左值引用
    int Attach(Func & f){
        return Assign(f);
    }
    //移除观察者
    void Deatach(int iKey){
        m_mapOberserve.erase(iKey);
    }
    //通知接口
    template <typename... Args>
    void Notify(Args&&... args){
        for(auto& it:m_mapOberserve)
        {
            it.second(std::forward<Args>(args)...);
        }
    }
private:
    template <typename F>
    int Assign(F && f){
        int k = m_iObersevre++;
        m_mapOberserve.emplace(k,std::forward<F>(f));
        return k;
    }

    int m_iObersevre = 0;
    std::map<int,Func> m_mapOberserve;
};

