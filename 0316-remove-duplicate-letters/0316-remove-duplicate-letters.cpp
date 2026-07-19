class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>freq(26);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']=i;
        }
        vector<bool>visit(26,false);
        string st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(visit[ch-'a']) continue;
            while(!st.empty()&& st.back()>ch && freq[st.back()-'a']>i){
                visit[st.back()-'a']=false;
                st.pop_back();
            }
            st.push_back(ch);
            visit[ch-'a']=true;
        }
        return st;
    }
};