#include <iostream>
#include <vector>
using namespace std;

int N = 9;
struct meet
{
	int begin, end, value;
};

void solve(int n, meet *meet)
{
	if ( n == 1 )
		cout << meet[1].value;
	int i, j;
	int prev[N]={0};

    vector<int>* taskDo = new vector<int>[N];

	for(i = 2; i < N; i++)
		for(j = i - 1; j >= 1; j-- )
			if(meet[i].begin >= meet[j].end)
			{
				prev[i] = j;
				break;
			}
	int opt[N]={0};
	for(i = 1; i < N; i++)
	{
		if(prev[i] == 0){
			// opt[i] = max(meet[i].value, opt[i-1]);
            if(meet[i].value>opt[i-1]){
                opt[i] = meet[i].value;
                taskDo[i].push_back(i);
            }else{
                opt[i] = opt[i-1];
                taskDo[i]=taskDo[i-1];
            }
        }
		else{
			// opt[i] = max((meet[i].value + opt[prev[i]]), opt[i-1]);
            if((meet[i].value + opt[prev[i]])>opt[i-1]){
                opt[i] = meet[i].value + opt[prev[i]];
                taskDo[i]=taskDo[prev[i]];
                taskDo[i].push_back(i);
            }else{
                opt[i] =opt[i-1];
                taskDo[i]=taskDo[i-1];
            }
        }

	}

    for(int t=1; t<N; t++){
        cout<<"Tasks: ";
        while (!taskDo[t].empty()){
            cout<<taskDo[t].back()<<"  ";
            taskDo[t].pop_back();
        } 
        cout<<"\ttotal value: "<<opt[t];
        cout<<endl;
    }
    
    delete[] taskDo;
}

int main()
{
	meet mm[9] = { 0,0,0, 1,4,5, 3,5,1, 0,6,8, 4,7,4,
			3,8,6, 5,9,3, 6,10,2, 8,11,4 };
	solve(9,mm);

    return 0;
}