class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<long long>freq(mx+1,0);
        for(int x:nums){
            freq[x]++;
        }
        vector<long long>exact(mx+1,0);
        for(int g=mx;g>=1;g--){
            long long cnt=0;;
            for(int mul=g;mul<=mx;mul+=g){
                cnt+=freq[mul];
            }
            exact[g]=cnt*(cnt-1)/2;
            for(int mul=2*g;mul<=mx;mul+=g){
                exact[g]-=exact[mul];
            }
        }
        vector<long long>prefix(mx+1,0);
        for(int i=1;i<=mx;i++){
            prefix[i]=prefix[i-1]+exact[i];
        }
        vector<int>ans;
        for(auto q:queries){
            int g=upper_bound(prefix.begin(),prefix.end(),q)-prefix.begin();
            ans.push_back(g);
        }
        return ans;
    }
};