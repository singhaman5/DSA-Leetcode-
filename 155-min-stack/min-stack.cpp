class MinStack {
public:
    // Method - 3: Best solution for this question -> T.C = O(1), S.C. = O(1);
    stack<long long> st;
    long long min;
    MinStack() {
        min = LLONG_MAX;
    }
    
    void push(int val) { // O(1)
        long long x = (long long)val;
        if(st.size()==0){
            st.push(x);
            min = x;
        }
        else if(x>=min) st.push(x);
        else{ // val < min
            st.push(2*x-min);
            min = x;
        }
    }
    
    void pop() { // O(1)
        if(st.top() < min){ // st.top<min : A fake value is present;
                // before popping, make sure to retrieve the old min;
            long long oldMin = 2 * min -st.top();
            min = oldMin;
        }
        st.pop();
    }
    int top() { // O(1)
        if(st.top() < min) return min;
        else return st.top();
    }
    
    int getMin() { // O(1)
        return min;
    }
};