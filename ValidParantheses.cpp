#include<iostream>
using namespace std;

class Valid{
    bool isValid(String str){
        stack<char> st;
        for(int i=0; i<str.length(); i++){
            if(str[i] == '(' || str[i] == '{' || str[i] == '['){// opening brackets
                st.push(str[i]);
            }
            else{ //closing brackets
                if(st.empty()) return false;
                if((st.top() == '(' && str[i] == ')') ||
                (st.top() == '{' && str[i] == '}') ||
                (st.top() == '[' && str[i] == ']')){
                    st.pop();
                }
                else{ // not matchingj 
                    return false;
                }
            }
        }
        return st.empty();
    }
}