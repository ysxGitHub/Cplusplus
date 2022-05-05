/*
如果通过交换T1中(某些)节点的左右子节点可以将T1转换为T2，那么T1和T2这两棵树就是同构的。
例如，图1中的两个树是同构的，因为如果交换A、B和G的子节点，而不是其他节点，那么它们是相同的。
给出一个多项式时间算法来判断两棵树是否同构。
*/

#include<iostream>
using namespace std;

class TreeNode
{

public:
    int Maxsize;
    int *Left;
    int *Right; 
    char *Element;
    TreeNode(int size)
    {
        this->Maxsize = size;
        this->Element = new char[this->Maxsize];
        this->Left = new int[this->Maxsize];
        this->Right = new int[this->Maxsize];
    }
    ~TreeNode()
    {
        delete[] this->Element;
        this->Element = NULL;
        delete[] this->Left;
        this->Left = NULL;
        delete[] this->Right;
        this->Right = NULL;
    }
};

int BuildTree(TreeNode& tree, int node_num)
{
    int root=0;
    int* check = new int[node_num];

    for(int i=0; i<node_num; i++)
    {
        check[i]=0;
    }
    for(int i=0; i<node_num; i++)
    {
        // cout<<"please input node"<<i+1<<"-Element"<<": ";
        // cin>>tree.Element[i];
        // cout<<"please input node"<<i+1<<"-Left"<<": ";
        // cin>>tree.Left[i];
        // cout<<"please input node"<<i+1<<"-Right"<<": ";
        // cin>>tree.Right[i];

        // 判断左子树是否为空，不为空时将左子树的标志位置为1
        if(tree.Left[i] != -1)
        {
            check[tree.Left[i]]=1;
        }
        // 判断右子树是否为空，不为空时将右子树的标志位置为1
        if(tree.Right[i] != -1)
        {
            check[tree.Right[i]]=1;
        }
    }

    for(root; root<node_num; root++)
    {
        if(check[root]==0)
        {
            break;
        }
    }
    delete[] check;

    return root;
}

int Isomorphic(int R1, int R2, TreeNode& T1, TreeNode& T2)
{
    // 两个树都是空
    if((R1==-1)&&(R2==-1)){return 1;}
    // 两个树左边右边为空与非空时
    if(((R1==-1)&&(R2!=-1))||(R2==-1)&&(R1!=-1)){return 0;}
    // 两棵树的值不相等
    if(T1.Element[R1] != T2.Element[R2]){return 0;}
    // 两棵树的左子树都为空时，递归判断右子树
    if((T1.Left[R1]==-1)&&(T2.Left[R2]==-1))
    {
        return Isomorphic(T1.Right[R1], T2.Right[R2], T1, T2);
    }
    // 判断左值是否相等
    if(((T1.Left[R1]!=-1)&&(T2.Left[R2]!=-1))&&((T1.Element[T1.Left[R1]])==(T2.Element[T2.Left[R2]])))
    {
        return (Isomorphic(T1.Left[R1], T2.Left[R2], T1, T2)&&Isomorphic(T1.Right[R1], T2.Right[R2], T1, T2));
    }
    else
    {
        return (Isomorphic(T1.Left[R1], T2.Right[R2], T1, T2)&&Isomorphic(T1.Right[R1], T2.Left[R2], T1, T2));
    }
}

int main(int argc, char const *argv[])
{
    TreeNode T1(9);
    TreeNode T2(9);
    char str1[] = "ABCDEGFH";
    int num_left1[] = {1, 3, 5, -1, 6, 7, -1, -1};
    int num_right1[] = {2, 4, -1, -1, -1, -1, -1, -1};

    char str2[] = "GBFAHCDE";
    int num_left2[] = {-1, 7, -1, 5, -1, 0, -1, 2};
    int num_right2[] = {4, 6, -1, 1, -1, -1, -1, -1};

    for(int i=0; i<8; i++)
    {
        T1.Element[i]=str1[i];
        T2.Element[i]=str2[i];

        T1.Left[i] = num_left1[i];
        T1.Right[i] = num_right1[i];

        T2.Left[i] = num_left2[i];
        T2.Right[i] = num_right2[i];
    }

    int root1 = BuildTree(T1, 8);
    int root2 = BuildTree(T2, 8);
    cout<<root1<<" "<<root2<<endl;
    // for(int i=0; i<8; i++)
    // {
    //     cout<<T1.Element[i]<<" "<<T1.Left[i]<<" "<<T1.Right[i]<<endl;
    //     cout<<T2.Element[i]<<" "<<T2.Left[i]<<" "<<T2.Right[i]<<endl;
    // }
    cout<<Isomorphic(root1, root2, T1, T2);
    return 0;
}

