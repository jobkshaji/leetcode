class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        stack<int>st;
        while(n>0){
            int curr=n%10;
            while(curr==0){
                n=n/10;
                curr=n%10;
            }
            sum+=curr;
            st.push(curr);
            n=n/10;
        }
        long long temp=0;
        while(!st.empty()){
            int val=st.top();
            temp=temp*10+val;
            st.pop();
        }
        return temp*sum;
    }
};