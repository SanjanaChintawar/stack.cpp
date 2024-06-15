// insert an element in the bottom of the given full stack
#include<iostream>
#include<stack>
using namespace std;

void pushAtBottom(stack<int>& s, int x) {
    //base case
    if(s.empty()) {
        s.push(x);
        return ;
    }
    
    int num = s.top();
    s.pop();
    
    //recursive call
    pushAtBottom(s, x);
    
    s.push(num);
}

int main(){
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    int x = 5;

    pushAtBottom(s,x);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    
}