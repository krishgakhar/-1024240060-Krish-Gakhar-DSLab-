// solution done on leetcode
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> student;
        queue<int> sandwich;
        for(int i=0;i<students.size();i++){
            student.push(students[i]);
            sandwich.push(sandwiches[i]);
        }

        bool breaking= false;
        int count=0;
        while(student.size()!=0 && breaking==false){
            if(student.front()==sandwich.front()){
                student.pop(); sandwich.pop();
                count=0;
            }
            else{
                student.push(student.front());
                student.pop();
                count++;
            }
            if(count==student.size()){
                breaking=true;
                return student.size();
            }

            }
        return 0;
        }
};