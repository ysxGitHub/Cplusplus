#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;


class Person
{
public:
    Person(string name, double avg_score)
    {
        this->name = name;
        this->avg_score = avg_score;
    }
    void printScore()
    {
        for(int i=0; i<10; i++)
        {
            cout<<score[i]<<"  ";
        }
        cout<<endl;
    }
    double avg_score;
    int score[10];
    string name;
};


void createPerson(vector<Person>&v)
{
    string extr = "ABCDE";
    for(int i=0; i<5; i++)
    {
        string name = "palyer-";
        name += extr[i];
        Person p(name, 0);
        v.push_back(p);
    }

}

void playerScore(vector<Person>&v)
{
    for(vector<Person>::iterator vit=v.begin(); vit!=v.end(); vit++)
    {
        
        deque<int>d;
        int sum_score=0;
        for(int i=0; i<10; i++)
        {
            int score = rand()%41+60;
            d.push_back(score);
            vit->score[i] = score;
        }
        sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();
        for(deque<int>::iterator dit=d.begin(); dit!=d.end(); dit++)
        {
            sum_score+=*(dit);
        }
        vit->avg_score = (double)sum_score/d.size();
    }

}

int main(int argc, char const *argv[])
{
    vector<Person>v;
    createPerson(v);
    // for(vector<Person>::iterator vit=v.begin(); vit!=v.end(); vit++)
    // {
    //     cout<<vit->name<<endl;
    // }
    playerScore(v);

    for(vector<Person>::iterator vit=v.begin(); vit!=v.end(); vit++)
    {
        cout<<"name: "<<vit->name<<endl;
        cout<<"avg_score:  "<<vit->avg_score<<endl;
        vit->printScore();
    }
    
    return 0;
}

