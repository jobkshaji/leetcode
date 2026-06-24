class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1];
        });
        int d=0;
        priority_queue<int>pq;
        for(auto i:courses){
            d+=i[0];
            pq.push(i[0]);
            if(d>i[1]){
                d-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};