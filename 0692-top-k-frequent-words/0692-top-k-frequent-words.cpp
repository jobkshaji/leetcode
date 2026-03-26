class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>freq;
        for(auto word:words){
            freq[word]++;
        }
        struct cmp{
            bool operator()(pair<int,string>&a , pair<int,string>&b){
                if(a.first!=b.first){
                    return a.first>b.first;
                }
                return a.second<b.second;
            }
        };
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;

        for(auto p:freq){
            pq.push({p.second,p.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};