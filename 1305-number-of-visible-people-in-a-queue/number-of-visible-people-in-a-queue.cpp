class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,0);
        stack<int> st;
        st.push(arr[n-1]);
        arr[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            int count = 0;
            // Pop with count
            while(st.size()>0 && arr[i]>st.top()){
                st.pop();
                count++;
            }
            if(st.size()!=0) count++;
            ans[i] = count;
            // Push
            st.push(arr[i]);
        }
        return ans;
    }
};