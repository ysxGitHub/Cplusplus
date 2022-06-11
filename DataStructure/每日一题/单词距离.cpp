/*
有个内含单词的超大文本文件，给定任意两个不同的单词，找出在这个文件中这两个单词的最短距离(相隔单词数)。如果寻找过程在这个文件中会重复多次，而每次寻找的单词不同，你能对此优化吗?
*/

int findClosest(vector<string>& words, string word1, string word2) {
    int ans = 100000, start=-100000, end=100000;
    for(int i=0; i<words.size(); ++i){
        if(words[i]==word1){
            start = i;
        }
        if(words[i]==word2){
            end = i;
        }
        ans = min(ans, abs(end-start));
    }
    return ans;
}