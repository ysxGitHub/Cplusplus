/*
堆是一个完全二叉树
堆顶最小/最大

push: 进入堆尾，向上调整左右子树，不断与父节点比较，将最小/最大的提上去

pop: 1.交换堆顶和堆尾
    2.把堆尾干掉
    3.从堆顶出发，向下调整左右子树，不断与左右子节点比较，将最小/最大的提上去，

*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
#define p (root>>1)
#define lc (root<<1)
#define rc (lc|1)

template<class T>
class minHeap{
private:
    vector<T>V;
    int _size;
public:    
    int size() const {
        return _size;
    }
    minHeap(){
        _size = 0;
        V.emplace_back(T());
    }
    void push(const T a){
        ++_size;
        V.emplace_back(a);
        int root = _size;
        while(p&&V[root]<V[p]){
            swap(V[root], V[p]);
            root = p;
        }
    }
    void pop() {
        int root = 1;
        swap(V[root], V[_size]);
        --_size;
        V.pop_back();
        while(lc<=_size){
            int now = lc;
            if(rc<=_size&&V[now]>V[rc]){
                now = rc;
            }
            if(V[now]<V[root]){
                swap(V[root], V[now]);
            }
            root = lc;
        }
    }
    T top() const{
        return V[1];
    }

    void showheap() const {
        for(int i=1; i<=_size; i++){
            cout<<V[i]<<"  ";
        }
        cout<<endl;
    }

};

void heapify(vector<int>&v, int root, int size){
    while(lc<=size){
        int now = lc;
        if(rc<=size&&v[now]>v[rc]){
            now = rc;
        }
        if(v[now]<v[root]){
            swap(v[root], v[now]);
        }
        root = lc;
    }
}

void bulti_heap(vector<int>&arr){
    int root = arr.size()-1;
    for(int i=p; i>=1; i--){
        heapify(arr, i, root);
    }
}

void heap_sort(vector<int>&arr){
    bulti_heap(arr);
    for(int i = arr.size()-1; i>=1; i--){
        swap(arr[1], arr[i]);
        // 注意下一次调整的时i-1，i已经调整好了
        heapify(arr, 1, i-1);
    }
}

int main(int argc, char const *argv[])
{
    minHeap<int>mheap;
    vector<int>nums = {5,1,4,2,6,8,7,9,3,0};
    for(auto&n: nums){
        mheap.push(n);
    }
    mheap.showheap();
    cout<<mheap.top()<<endl;
    mheap.pop();
    cout<<mheap.top()<<endl;
    mheap.pop();
    cout<<mheap.top()<<endl;
    // cout<<mheap.size()<<endl;
    nums = {-1,5,1,4,2,6,8,7,9,3,0}; // 前面加一个填充值
    heap_sort(nums);
    for(auto&n: nums){
        cout<<n<<" ";
    }    
    
    // make_heap(), sort_heap() 用sort_heap前先用make_heap

    int myints[] = {10,20,30,5,15};
    vector<int> v(myints,myints+5);

    make_heap (v.begin(),v.end());
    cout << "initial max heap   : " << v.front() << '\n';

    pop_heap (v.begin(),v.end()); v.pop_back();
    cout << "max heap after pop : " << v.front() << '\n';

    v.push_back(99); push_heap (v.begin(),v.end());
    cout << "max heap after push: " << v.front() << '\n';

    sort_heap (v.begin(),v.end());

    cout << "final sorted range :";
    for (unsigned i=0; i<v.size(); i++)
        cout << ' ' << v[i];

    // priority_queue<int, vector<int>, greater<int>> maxpq;

    return 0;
}

