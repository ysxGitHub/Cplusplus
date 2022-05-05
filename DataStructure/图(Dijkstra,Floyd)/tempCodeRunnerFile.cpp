    int n = passingFees.size();
    vector<vector<pair<int, int>>>graph(n);
    for(auto e: edges){
        graph[e[0]].emplace_back(e[1], e[2]);
        graph[e[1]].emplace_back(e[0], e[2]);
    }
    vector<int>allfree(n, INT32_MAX), alltime(n, INT32_MAX);
    priority_queue<vector<int>, vector<vector<int>>, cmp>pq;
    alltime[0] = 0, allfree[0] = passingFees[0];
    pq.push({0, 0, passingFees[0]});

    while(!pq.empty()){
        auto cur = pq.top();
        int curNode = cur[0], curTime = cur[1], curFree = cur[2];
        
        if(curNode==n-1) return curFree;

        for(auto next: graph[curNode]){
            int nextNode = next.first, nextTime = next.second + curTime, 
                nextFree = curFree + passingFees[curNode];
            
            if(nextTime > maxTime){
                continue;
            }
            else if(nextTime<alltime[nextNode]){
                alltime[nextNode] = nextTime;
                allfree[nextNode] = nextFree;
                pq.emplace(nextNode, nextTime, nextFree);
            }
            else if(nextFree<allfree[nextNode]){
                alltime[nextNode] = nextTime;
                allfree[nextNode] = nextFree;
                pq.emplace(nextNode, nextTime, nextFree);
            }

        }
    }

    return-1;