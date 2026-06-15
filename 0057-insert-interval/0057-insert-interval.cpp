class Solution {
public:
    vector<vector<int>>merge(vector<vector<int>>& ans){
        sort(ans.begin(),ans.end());
        vector<vector<int>>res;
        int start1=ans[0][0];
        int end1=ans[0][1];
        for(int i=1;i<ans.size();i++){
            int start2=ans[i][0];
            int end2=ans[i][1];
            if(end1>=start2){
                start1=start1;
                end1=max(end1,end2);
            }else{
                res.push_back({start1,end1});
                start1=start2;
                end1=end2;
            }
        }
        res.push_back({start1,end1});
        return res;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int start=newInterval[0];
        int flag=false;
        for(int i=0;i<intervals.size();i++){
            int check=intervals[i][0];
            if(flag==false && check>=start){
                ans.push_back({newInterval});
                flag=true;
            }
            ans.push_back({intervals[i]});
        }
        if(flag==false){
            ans.push_back(newInterval);
        }
        return merge(ans);
    }
};