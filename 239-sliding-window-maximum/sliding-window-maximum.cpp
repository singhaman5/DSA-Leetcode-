class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        int ngi[n];
        stack<int> st;
        ngi[n-1] = n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && arr[st.top()]<=arr[i]) st.pop();
            if(st.size()==0) ngi[i] = n;
            else ngi[i] = st.top();
            st.push(i);
        }
        vector<int> ans;
        for(int i=0;i<n-k+1;i++){
            int mx = arr[i]; // starting of window se
            int j = i;
            while(j < i+k){ // means if nge is inside window
                mx = arr[j];
                j = ngi[j];
            }
            ans.push_back(mx); 
        }
        return ans;
    }
};