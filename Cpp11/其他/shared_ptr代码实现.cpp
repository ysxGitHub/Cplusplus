/*

*/
#include <iostream>
#include <memory>
using namespace std;

template<typename T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = NULL):_ptr(ptr), _pcount(new int(1))
	{}

	SharedPtr(const SharedPtr& s):_ptr(s._ptr), _pcount(s._pcount){
		(*_pcount)++;
	}

	SharedPtr<T>& operator=(const SharedPtr& s){
		if (this != &s)
		{
			if (this->_pcount&&--(*(this->_pcount)) == 0)
			{
				delete this->_ptr;
				delete this->_pcount;
			}
			_ptr = s._ptr;
			_pcount = s._pcount;
			(*_pcount)++;
		}
		return *this;
	}
	SharedPtr<T>& operator=(T* value){
        if (this->_pcount&&--(*(this->_pcount)) == 0)
        {
            delete this->_ptr;
            delete this->_pcount;
        }
        _ptr = value;
        _pcount = new int(1);
		return *this;
	}
	T& operator*()
	{
		return *(this->_ptr);
	}
	T* operator->()
	{
		return this->_ptr;
	}
	~SharedPtr()
	{
		--(*(this->_pcount));
		if (*(this->_pcount) == 0)
		{
			delete _ptr;
			_ptr = NULL;
			delete _pcount;
			_pcount = NULL;
		}
	}
    int use_count()const{
        return *this->_pcount;
    }
private:
	T* _ptr;
	int* _pcount;//指向引用计数的指针
};


int main(int argc, char const *argv[])
{
    int a=10, b=20;
    SharedPtr<int>ptr1 = &a;
    SharedPtr<int>ptr2 = ptr1;
    // SharedPtr<int>ptr3 = ptr1;
    cout<<ptr1.use_count()<<endl;
    cout<<ptr2.use_count()<<endl;

    ptr1 = ptr2;
    cout<<ptr1.use_count()<<endl;
    ptr1 = &b;
    cout<<ptr1.use_count()<<endl;
    cout<<ptr2.use_count()<<endl;

    // shared_ptr<int> p4(new int(1));
    return 0;
}
