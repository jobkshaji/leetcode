class Solution {
public:
    bool fun(unordered_map<char,int>& m , unordered_map<char,int>& r){
        for(auto i : r) {
            char c= i.first;
            int fneed=i.second;
            int fhave=m[c];
            if(fhave < fneed) return false;
        }
        return true;
    }
    bool canConstruct(string r, string m) {
        unordered_map<char,int>have;
        unordered_map<char,int>need;
        for(int i=0;i<m.size();i++){
            have[m[i]]++;
        }
        for(int i=0;i<r.size();i++){
            need[r[i]]++;
        }
        return fun(have,need);
    }
};