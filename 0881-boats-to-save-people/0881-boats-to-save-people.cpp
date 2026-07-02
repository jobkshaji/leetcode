class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int boat=0;
        int l=0;
        int h=people.size()-1;
        while(l<=h){
            if(people[l]+people[h]<=limit){
                boat++;
                l++;
                h--;
            }else{
                boat++;
                h--;
            }
        }
        return boat;
    }
};