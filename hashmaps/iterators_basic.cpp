#include <iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
int main() {
    unordered_map <string,int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc2"] = 2;
    ourmap["abc3"] = 3;
    ourmap["abc4"] = 4;
    ourmap["abc5"] = 5;
    ourmap["abc6"] = 6;
    ourmap["abc7"] = 7;
    ourmap["abc8"] = 8;

    unordered_map<string,int> :: iterator it = ourmap.begin();
    while(it != ourmap.end()){
        cout<<"key : "<< it->first <<"Value : " << it->second << endl;
        it++;
    }
  // Actually .find() function in the map will actually return an iterator. 
  // You can also give erase function in an iterator.
    
  // We can also give starting to ending iterator 
    
    //ourmap.erase(it, it+4)

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    vector<int> :: iterator it1 = v.begin();

    while(it1 != v.end()){
        cout<< *it1 << endl;
        it1++;
    }

}
