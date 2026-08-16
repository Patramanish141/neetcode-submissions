class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<int> left, star;

        for(int i=0; i<n; i++){
            if(s[i] == '(') left.push(i);
            else if(s[i] == '*') star.push(i);
            else { 
                if(left.empty() && star.empty()) return false;

                if(!left.empty()){
                    left.pop();
                }
                else {
                    star.pop();
                }
            } 
        }

        //till here ')' correponding '(' or '*' is exhausted

        while(!left.empty() && !star.empty()){
            if(left.top() > star.top()) return false; //there is '(' after *....it dont have any correspoding left
            left.pop();
            star.pop();
        }

        return left.empty();
    }
};
