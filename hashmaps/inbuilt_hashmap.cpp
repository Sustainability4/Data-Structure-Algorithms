#include <iostream>
using namespace std;
#include<unordered_map>
#include<string>
int main() {
    unordered_map<string,int> ourmap;
    //insert elements
    pair<string, int> p("abc",1);
    ourmap.insert(p);

    // another way to insert 
    ourmap["def"]=2;

    //find or access
    //with square brackets you will not get an exception even for the keys that 
    // don't exist but with .at() function you will get an exception.
    // accessing with square brackets will insert that key with a value zero and its size 
    // will increase
    cout<<ourmap["abc"]<<endl;
    cout<<ourmap.at("abc")<<endl;

    // if we want to check whether our key exist in the map or not, we use count function
    if(ourmap.count("ghi")>0){
        cout<<"key exists"<<endl;
    }

    // Size of the hashmap
    cout<<ourmap.size()<<endl;

    //erase a key value pair
    ourmap.erase("abc");
}
