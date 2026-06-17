class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string res="";
        while(!st.empty()){
            int c=st.top();
            res.push_back(c);
            st.pop();
        }
        reverse(res.begin(),res.end());
        int i=0;
        while(i<res.size() && res[i]=='0'){
            i++;
        }
        res=res.substr(i);
        return res.empty() ? "0":res;
    }
};