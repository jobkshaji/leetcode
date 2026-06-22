class Solution {
public:
    int soilder(vector<int>&mat){
        int l=0; int h=mat.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mat[mid]==0){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<mat.size();i++){
            pq.push({soilder(mat[i]),i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};