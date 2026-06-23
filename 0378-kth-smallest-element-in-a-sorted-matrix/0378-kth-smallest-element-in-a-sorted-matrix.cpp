class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        priority_queue<int>pq;
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                pq.push(matrix[r][c]);
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};