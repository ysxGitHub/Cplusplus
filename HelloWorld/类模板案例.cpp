#include <iostream>
using namespace std;

template <class T>
class MyArray
{
public:
    MyArray(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        this->arr = new T[this->capacity];
        cout << "constructing funcation" << endl;
    }
    MyArray(const MyArray &myArr)
    {
        this->size = myArr.size;
        this->capacity = myArr.capacity;
        // if(this->arr!=NULL)
        // {
        //     delete []  this->arr;
        //     this->arr = NULL;
        // }
        this->arr = new T[this->capacity];
        for (int i = 0; i < this->size; i++)
        {
            this->arr[i] = myArr.arr[i];
        }
        cout << "copy constructing funcation" << endl;
    }

    MyArray &operator=(const MyArray &myArr)
    {
        if (this->arr != NULL)
        {
            delete[] this->arr;
            this->arr = NULL;
            this->capacity = 0;
            this->size = 0;
        }
        this->size = myArr.size;
        this->capacity = myArr.capacity;
        this->arr = new T[this->capacity];
        for (int i = 0; i < this->size; i++)
        {
            this->arr[i] = myArr.arr[i];
        }
        cout << "operator=" << endl;
        return *this;
    }

    ~MyArray()
    {
        if (this->arr != NULL)
        {
            delete[] this->arr;
            this->arr = NULL;
            cout << "disconstructing funcation" << endl;
        }
    }
    void append(const T num)
    {
        if (this->size == this->capacity)
        {
            return;
        }
        else
        {
            this->arr[this->size] = num;
            this->size++;
        }
    }
    void del_tail()
    {
        if (this->size == 0)
        {
            return;
        }
        else
        {
            this->size--;
        }
    }
    T &operator[](int index)
    {
        // cout<<"size: "<<this->size<<endl;
        if (index < 0 && index >= this->size)
        {
            throw "index out";
        }
        else
        {
            return this->arr[index];
        }
    }
    int ArrSize()
    {
        return this->size;
    }
    int ArrCap()
    {
        return this->capacity;
    }

private:
    T *arr = NULL;
    int size;
    int capacity;
};

class Person
{
public:
    Person()
    {
    }
    Person(int age, string name)
    {
        this->age = age;
        this->name = name;
    }
    // void PrintP()
    // {
    //     cout<<this->name<<"\t"<<this->age<<endl;
    // }

    int age;
    string name;
};

ostream &operator<<(ostream &cout, Person &p)
{
    cout << "name: " << p.name << "\t age: " << p.age;
    return cout;
}

int main(int argc, char const *argv[])
{
    MyArray<int> arr1(5);
    MyArray<int> arr2(arr1);

    arr1.append(10);
    arr1.append(20);
    arr1.append(30);
    cout << "arr1 size: " << arr1.ArrSize() << endl;
    cout << "arr1[2]: " << arr1[2] << endl;

    arr2 = arr1;
    cout << "arr2 size: " << arr2.ArrSize() << endl;
    cout << "arr2[1]: " << arr2[1] << endl;

    arr1.del_tail();
    cout << "arr1 size: " << arr1.ArrSize() << endl;
    arr1.del_tail();
    cout << "arr1 size: " << arr1.ArrSize() << endl;
    // cout<<"arr1[2]: "<<arr1[2]<<endl;

    MyArray<Person> arr3(5);
    MyArray<Person> arr4(arr3);
    Person p1(12, "zhangsan");
    Person p2(10, "lisi");
    Person p3(14, "wangwu");

    arr3.append(p1);
    arr3.append(p2);
    arr3.append(p3);
    cout << arr3[0] << endl;
    cout << arr3[2] << endl;
    cout << "arr3 size: " << arr3.ArrSize() << endl;
    arr4 = arr3;
    cout << "arr4 size: " << arr4.ArrSize() << endl;
    cout << arr4[2] << endl;

    arr4.del_tail();
    cout << "arr4 size: " << arr4.ArrSize() << endl;
    arr4.del_tail();
    cout << "arr4 size: " << arr4.ArrSize() << endl;

    return 0;
}
