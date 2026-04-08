class Solution {
public:
    int leastInterval(vector<char>& tasks, int z) {
        int n=tasks.size();
        unordered_map<char,int>freq;
        unordered_map<char,int>free;
        for(int i=0;i<n;i++){
            freq[tasks[i]]++;
            free[tasks[i]]=1;
        }
        priority_queue<pair<int,char>>pq;
        for(auto i:freq){
            pq.push({i.second,i.first});
        }
        int seat=1;
        while(!pq.empty()){
            vector<pair<int,char>>stored;
            while(!pq.empty()){
                pair<int,char>p=pq.top();
                pq.pop();
                int freq=p.first;
                char child=p.second;
                if(free[child]<=seat){
                    if(p.first>1){
                        pq.push({p.first-1,p.second});
                        free[p.second]=seat+z+1;
                    }
                    break;
                }else{
                    stored.push_back(p);
                }
            }
            for(int i=0;i<stored.size();i++){
                pq.push(stored[i]);
            }
            seat++;
        }
        return seat-1;
    }
};