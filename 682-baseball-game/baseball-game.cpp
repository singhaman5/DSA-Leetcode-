class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int> st;
        for(int i=0;i<op.size();i++){
            if(op[i]=="C"){
                st.pop();
            }
            else if(op[i]=="D"){
                st.push(2*st.top());
            }
            else if(op[i]=="+"){
                int last = st.top();
                st.pop();
                int secondLast = st.top();
                st.push(last);
                st.push(last+secondLast);
            }
            else{
                st.push(stoi(op[i])); // stoi handles + and - numbers
            }
        }
        int sum = 0;
        while(st.size()>0){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};