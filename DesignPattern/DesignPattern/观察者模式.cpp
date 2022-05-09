#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Observer{
public:
    virtual void Update(int) = 0;
};

class Subject{
public:
    virtual void Attach(Observer *) = 0;
    virtual void Detach(Observer *) = 0;
    virtual void Notify() = 0;
};

class ConcreteObserver : public Observer{
public:
    ConcreteObserver(Subject *pSubject) : m_pSubject(pSubject){};
    void Update(int value){
        cout << "接收到信息通知:" << value << endl;
    }
private:
    Subject *m_pSubject;
};

class ConcreteSubject : public Subject{
public:
    void Attach(Observer *pObserver);
    void Detach(Observer *pObserver);
    void Notify();
    void SetState(int state){
        m_iState = state;
    }

    int GetState(){
        return m_iState;
    }
private:
    std::list<Observer *> m_ObserverList;
    int m_iState;
};

void ConcreteSubject::Attach(Observer *pObserver){
    m_ObserverList.push_back(pObserver);
}

void ConcreteSubject::Detach(Observer *pObserver){
    m_ObserverList.remove(pObserver);
}

void ConcreteSubject::Notify(){
    std::list<Observer *>::iterator it = m_ObserverList.begin();
    while (it != m_ObserverList.end()){
        (*it)->Update(m_iState);
        ++it;
    }
}