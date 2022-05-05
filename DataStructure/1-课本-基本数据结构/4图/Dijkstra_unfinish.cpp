#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<cstring>

using namespace std;

template<class T, class Q>
unordered_map<Q, int> init_distance(T Graph, Q source){
    unordered_map<Q, int>distance;
    distance[source] = 0;
    for(auto g: Graph){
        if(g.first!=source){
            distance[g.first] = 1000000;
        }
    }
    return distance;
}


template<class T, class Q>
void Dijkstra(T Graph, Q source){
    
    unordered_set<Q>seen;
    unordered_map<Q, Q>parent;
    unordered_map<Q, int>distance;

    priority_queue<unordered_map<Q, int>,,>pqueue;
    unordered_map<Q, int>mymap;
    mymap[source] = 0;
    pqueue.push(mymap);

    parent[source] = '-';
    distance = init_distance(Graph, source);

    while (!pqueue.empty()){
        int dist;
        Q vertex;
        for(auto& tp: pqueue.top()){
            Q vertex = tp.first; 
            int dist = tp.second;
        }
        pqueue.pop();
        seen.insert(vertex);

        for(auto g: Graph[vertex]){
            if(seen.find(g.first)==seen.end()){
                if(dist + g.second < distance[g.first]){
                    unordered_map<Q, int>mp;
                    mp[g.first] = dist + g.second;
                    pqueue.push(mp);
                    distance[g.first] = dist + g.second;
                }
            }
        }

    }

    for(auto a: parent){
        cout<<"parent: "<<a.second<<"   child: "<<a.first<<endl;
    }    
    for(auto d: distance){
        cout<<"char: "<<d.first<<"   dist: "<<d.second<<endl;
    }  

}



int main(int argc, char const *argv[])
{
    unordered_map<char, unordered_map<char, int>>graph;
    for(int i=0; i<strlen("ABCDEF"); i++){
        unordered_map<char, int>g;
        if(i==0){
            g['B'] = 5; g['C'] = 1; 
            graph['A'] = g;
        }else if(i==1){
            g['A'] = 5; g['C'] = 2; g['D'] = 1;
            graph['B'] = g;  
        }else if(i==2){
            g['A'] = 1; g['B'] = 2; g['D'] = 4; g['E'] = 8; 
            graph['C'] = g;              
        }else if(i==3){
            g['B'] = 1; g['C'] = 4; g['E'] = 3; g['F'] = 6; 
            graph['D'] = g;  
        }else if(i==4){
            g['C'] = 8; g['D'] = 3; 
            graph['E'] = g;              
        }else{
             g['D'] = 6; 
            graph['F'] = g; 
        }
    }

    char source = 'A';
    Dijkstra(graph, source);

    return 0;
}
