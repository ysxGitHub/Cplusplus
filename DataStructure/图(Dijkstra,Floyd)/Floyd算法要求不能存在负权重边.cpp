/*

*/

#include<iostream>
#include<vector>

using namespace std;

class Floyd{
private:
    // 记录节点之间最短的距离
    vector<vector<int>>dist;
    // 记录节点之间的连接点
    vector<vector<int>>path;
    // 节点个数
    int Nv;
public:

    // 这里的graph是邻居矩阵
    Floyd(vector<vector<int>>graph){
        Nv = graph.size();
        dist.resize(Nv, vector<int>(Nv));
        path.resize(Nv, vector<int>(Nv, -1));
        for(int i=0; i<Nv; i++){
            for(int j=0; j<Nv; j++){
                dist[i][j] = graph[i][j];
            }
        }
        for (int k=0; k<Nv; k++){
            for(int i=0; i<Nv; i++){
                for(int j=0; j<Nv; j++){
                    int new_dist = dist[i][k]+dist[k][j];
                    if(new_dist<dist[i][j]){
                        dist[i][j] = new_dist;
                        path[i][j] = k;
                    }
                }
            }
        }
    }

    void FindMin(){
        int Number;
        int MinDist = INT32_MAX;
        for (int i=0; i<Nv; i++){
            int MaxDist = 0;
            // 寻找i到j的最大路径
            for (int j=0; j<Nv; j++){
                if (MaxDist<dist[i][j]&&dist[i][j]!=0){
                    MaxDist = dist[i][j];
                }
            }
            // 多行中的最大最小值
            if (MinDist>MaxDist){
                MinDist = MaxDist;
                Number = i;
            }
        }
        cout<<"Num: "<<Number<<" MinDist: "<<MinDist<<endl;
    }

    printPath() {
        // cout << "各个顶点对的最短路径：" << endl;
        int temp = 0;
        for (int row = 0; row < Nv; row++) {
            for (int col = row + 1; col < Nv; col++) {
                cout << "v" << to_string(row + 1) << "--" << "v" << to_string(col+1) << " weight: "
                    << dist[row][col] << " path: " << " v" << to_string(row + 1);
                temp = path[row][col];
                //循环输出途径的每条路径。
                while (temp != col) {
                    cout << "-->" << "v" << to_string(temp + 1);
                    temp = path[temp][col];
                }
                cout << "-->" << "v" << to_string(col + 1) << endl;
            }
            cout << endl;
        }
    }

};


int main(int argc, char const *argv[])
{
    
    return 0;
}
