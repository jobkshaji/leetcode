class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>free_server;
        priority_queue<tuple<long long ,int,int>,vector<tuple<long long,int,int>>,greater<tuple<long long,int,int>>>busy;
        vector<int>ans;
        for(int i=0;i<servers.size();i++){
            free_server.push({servers[i],i});
        }
        for(long long time=0;time<tasks.size();time++){
            while(!busy.empty()){
                auto[finish,wgt,idx]=busy.top();
                if(finish>time) break;
                busy.pop();
                free_server.push({wgt,idx});
            }
            if(free_server.empty()){
                auto[finish,wgt,idx]=busy.top();
                busy.pop();
                busy.push({finish+tasks[time],wgt,idx});
                ans.push_back(idx);
            }else{
                pair<int,int>p=free_server.top();
                free_server.pop();
                busy.push({time+tasks[time],p.first,p.second});
                ans.push_back(p.second);
            }
        }
        return ans;
    }
};