class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& num) {
        vector<vector<int>>res;
        sort(num.begin(),num.end());
        int start1=num[0][0];
        int end1=num[0][1];
        for(int i=1;i<num.size();i++){
            int start2=num[i][0];
            int end2=num[i][1];
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
};