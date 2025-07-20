class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for(int i=0; i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stack.push_back(s[i]);
            }
            else if(s[i]==')' || s[i]=='}' || s[i]==']'){
                char temp = 0;
                if(s[i]==')'){
                    temp='(';
                }
                else if(s[i]=='}'){
                    temp='{';
                }
                else if(s[i]==']'){
                    temp='[';
                }
                if(stack.empty()){
                    return false;
                }
                if(stack[stack.size()-1]==temp){
                    stack.pop_back();
                }
                else{
                    return false;
                }
            }
        }
    if(stack.empty()){
        return true;
    }
    return false;
    }
   
};