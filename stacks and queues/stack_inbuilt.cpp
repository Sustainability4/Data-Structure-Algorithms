#include <iostream>
using namespace std;
// This is the inbuilt stack file
#include<stack>
int main() {
    // push function remains the same as we have created using a template file 
    stack<int> s1; 
    s1.push(10);
    s1.push(50);
    //Pop function will do the job but it does not have any return type and hence
    // will not return anything 
    s1.pop();
    // This function cout<<s1.pop()<<endl; is invalid

    // top function will behave extactly the same 
    cout<< s1.top()<< endl;

    // size function is also the same 
    cout << s1.size() << endl;

    // IsEmpty function is the same with return type boolean but its 
    // call is different 

    cout << s1.empty() << endl;

}
