class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(char ch : expression){
            if(ch == ',' ) continue;

            if(ch != ')'){
                st.push(ch);
            }
            else{
                vector<char> vals;

                while(st.top() != '('){
                    vals.push_back(st.top());
                    st.pop();
                }
                st.pop(); // remove '('

                char op = st.top(); 
                st.pop();

                if(op == '|'){
                    bool res = false;
                    for(char v : vals){
                        if(v == 't') res = true;
                    }
                    st.push(res ? 't' : 'f');
                }
                else if(op == '&'){
                    bool res = true;
                    for(char v : vals){
                        if(v == 'f') res = false;
                    }
                    st.push(res ? 't' : 'f');
                }
                else{ // '^' or '!'
                    bool res = (vals[0] == 'f');
                    st.push(res ? 't' : 'f');
                }
            }
        }
        return st.top() == 't';
    }
};