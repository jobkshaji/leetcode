class Solution {
public:
    void fun(int open,int close, int n,string & tmp, vector<string>&res){
        if(open==n and close==n){
            res.push_back(tmp);
            return;
        }

        if(open<n){
            tmp.push_back('(');
            fun(open+1,close,n,tmp,res);
            tmp.pop_back();
        }

        if(close<open){
            tmp.push_back(')');
            fun(open,close+1,n,tmp,res);
            tmp.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        vector<string>ans;
        string tmp;
        fun(open,close,n,tmp,ans);
        return ans;
    }
};