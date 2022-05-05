#include<iostream>
#include<list>
using namespace std;

class Staff;

// 抽象的发布者
class Notice{
public:
    list<Staff*> StaffList;
    void attach(Staff* s1){
        StaffList.push_back(s1);
    }
    void detach(Staff* s2){
        StaffList.remove(s2);
    }
    void notify();
    virtual string company_info()=0;
    virtual ~Notice(){}
};


// 抽象的订阅者
class Observer{
public:
    virtual void update(Notice&notice)=0;

    virtual ~Observer(){}

};


class StaffNotice: public Notice
{
public:
    string m_S;
    StaffNotice(string S):m_S(S){};

    virtual string company_info(){
        return m_S;
    }
    void company_info(string S){
        m_S = S;

    }
};


class Staff: public Observer
{
public:
    string Sinfo;
    virtual void update(Notice& notice){
        Sinfo = notice.company_info();
    }

};


void Notice::notify(){
    auto itr = StaffList.begin();
    for(itr; itr!=StaffList.end(); itr++){
        (*(itr))->update(*this);
    }
}

int main(int argc, char const *argv[])
{
    StaffNotice notice("887766");
    Staff s1;
    Staff s2;
    notice.attach(&s1);
    notice.attach(&s2);

    notice.company_info("6666");
    
    cout<<s1.Sinfo<<endl;
    cout<<s2.Sinfo<<endl;
    return 0;
}



