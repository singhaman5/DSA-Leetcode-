class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(students[i]);
        }
        int i = 0; // To traverse the sandwiches array
        int count = 0;
        while(q.size()>0 && count!=q.size()){
            if(q.front()==sandwiches[i]){
                count = 0; // VIMP
                q.pop();
                i++; 
            }
            else{
                q.push(q.front());
                q.pop();
                count++; // VIMP
            }
        }
        return q.size();
    }
};