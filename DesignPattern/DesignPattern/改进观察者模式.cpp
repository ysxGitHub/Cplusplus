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


// 参数包 Targs...
template <typename Type>
void print(Type x) {
    std::cout << x << ", 233333" << std::endl;
}

template <typename Type, typename... Targs>
void print(Type x, Targs... args) {
    std::cout << x << std::endl;
    print(args...);
}

int main1() {
    print('1', 1.5, "Hello World");
    return 0;
}

// 实现 tuple
template <typename ... Tail> class Tuple;

template<> class Tuple<> {};

template <typename Value, typename ... Tail>
class Tuple<Value, Tail ...> : Tuple<Tail ...> {
    Value Val;
public:
    Tuple() {}
    Tuple(Value value, Tail ... tail) : Val(value), Tuple<Tail ...>(tail ...) {}
    Value value() {
        return Val;
    }
    Tuple<Tail ...> next() {
        return *this; // 直接返回了父类对象
    }
};

int main() {
    Tuple<char, double, std::string> tuple('1', 1.5, "Hello World");
    std::cout << tuple.value() << std::endl;
    std::cout << tuple.next().value() << std::endl;
    std::cout << tuple.next().next().value() << std::endl;
    return 0;
}

