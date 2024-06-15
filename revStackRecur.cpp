#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int n){
    if(s.empty()){
        s.push(n);
        return ;
    }
    int num = s.top();
    s.pop();

    insertAtBottom(s, n);

    s.push(num);
}

void reverseStack(stack<int> &s){
    if(s.empty()){
        return ;
    }

    int num = s.top();
    s.pop();

    // recursive call
    reverseStack(s);

    insertAtBottom(s,num);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverseStack(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}