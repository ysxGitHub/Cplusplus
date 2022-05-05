#include<iostream>
#include<vector>

using namespace std;

// 利用arr建树
void build_tree(vector<int>& arr, vector<int>& tree, int root, int start, int end){
    if(start==end){
        tree[root] = arr[start];
        return;
    }else{
        int mid = (end - start)/2 + start;
        int root_left = root*2 + 1;
        int root_right = root*2 + 2;
        build_tree(arr, tree, root_left, start, mid);
        build_tree(arr, tree, root_right, mid+1, end);
        tree[root] = tree[root_left] + tree[root_right];
    }
}

// 更新arr[index]的数值
void update_tree(vector<int>& arr, vector<int>& tree, int root, int start, int end, int index, int value){
    if(start==end){
        tree[root] = value;
        arr[index] = value;
        return;
    }
    else{
        int mid = (end - start)/2 + start;
        int root_left = root*2 + 1;
        int root_right = root*2 + 2;   
        if(index>=start&&index<=mid){
            update_tree(arr, tree, root_left, start, mid, index, value);
        }else{
            update_tree(arr, tree, root_right, mid+1, end, index, value);
        }
        tree[root] = tree[root_left] + tree[root_right];
    }
}

int query_tree(vector<int>& arr, vector<int>& tree, int root, int start, int end, int l, int r){
    if(r<start||l>end){
        /*
        [l, r] < [start, end]
        or [start, end] < [l, r]
        */
        return 0;
    }
    else if((l<=start&&end<=r)||start==end){
        /*
        [start, end]属于[l, r]
        */ 
        return tree[root];
    }
    else{
        int mid = (end - start)/2 + start;
        int root_left = root*2 + 1;
        int root_right = root*2 + 2;   

        int sum_left = query_tree(arr, tree, root_left, start, mid, l, r);
        int sum_right = query_tree(arr, tree, root_right, mid+1, end, l, r);
        return sum_left + sum_right;
    }
}


void Segment_Tree(){

}



int main(int argc, char const *argv[])
{
    vector<int>arr = {1,3,5,7,9,11};
    
    vector<int>tree;
    tree.assign(20, 0);

    build_tree(arr, tree, 0, 0, arr.size()-1);

    for(auto& t: tree){
        cout<<t<<" ";
    }
    cout<<endl;
    update_tree(arr, tree, 0, 0, arr.size()-1, 4, 6);

    for(auto& a: arr){
        cout<<a<<" ";
    }
    cout<<endl;
    for(auto& t: tree){
        cout<<t<<" ";
    }
    cout<<endl;

    cout<<query_tree(arr, tree, 0, 0, arr.size()-1, 0, arr.size()-1);

    return 0;
}

