#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBr(string s){
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%'){
            st.push(ch);
        }
        else{
            // ch is ) or lowercase letter 
            if(ch == ')'){
                bool is_redundant = true;

                while(st.top() != '('){
                    char top = st.top();

                    if(top == '(' || top == '+' || top == '-' || top == '*' || top == '/' || top == '%'){
                        is_redundant = false;
                    }
                    st.pop();
                }

                if(is_redundant){
                    return true;
                }
                st.pop();
            }
        }
    }

    return false;

}

int main(){
    string s = "((((+)+)+))";
    bool is_red;

    is_red = findRedundantBr(s);

    if(is_red)
        cout<<"yes";
    else
        cout<<"No";
}