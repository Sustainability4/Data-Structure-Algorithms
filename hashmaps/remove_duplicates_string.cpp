#include<unordered_map>
#include<cstring>
#include <iostream>
#include <string>
using namespace std;

string uniqueChar(string str) {
	// Write your code here
    unordered_map<char,int> ourmap;
    string ans;
    
    for(int i = 0; i<str.size(); i++){
        if(ourmap[str[i]] > 0){
            continue;
        }
        ourmap[str[i]] = 1;
        ans = ans +str[i];
    }
    
    return ans;
    
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
