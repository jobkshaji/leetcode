class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        int r=nums.size();
        for(int i=0;i<r;i++){
            if(nums[i]<0){
                neg.push_back(nums[i]*nums[i]);
            }
        }
        for(int i=0;i<r;i++){
            if(nums[i]>=0){
                pos.push_back(nums[i]*nums[i]);
            }
        }
        sort(neg.begin(),neg.end());
        int m=pos.size();
        int n=neg.size();
        vector<int>res(m+n);
        int k=0;
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(pos[i]<neg[j]){
                res[k]=pos[i];
                i++;
                k++;
            }else{
                res[k]=neg[j];
                j++;
                k++;
            }
        }
        while(i<m){
            res[k]=pos[i];
            k++;
            i++;
        }
        while(j<n){
            res[k]=neg[j];
            k++;
            j++;
        }

        return res;

    }
};