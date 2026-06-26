class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>>worker;
        for(int i=0;i<wage.size();i++){
            worker.push_back({(double)wage[i]/quality[i],quality[i]});
        }
        sort(worker.begin(),worker.end());
        priority_queue<int>pq;
        double ans=DBL_MAX;
        int quali=0;
        for(auto x:worker){
            double ratio=x.first;
            quali+=x.second;
            pq.push(x.second);
            if(pq.size()>k){
                int p =pq.top();
                pq.pop();
                quali-=p;
            }
            if (pq.size()==k){
                double current=ratio * quali;
                ans=min(current,ans);
            }
        }
        return ans;
    }
};