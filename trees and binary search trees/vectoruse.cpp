#include <iostream>
#include <vector>
using namespace std;
int main() {
    // actually vector is a template and hence we can put in any type of datatypes
    //statically creating a vector 
    vector<int> v;
    // dynamically creating a vector 
    //vector<int> * vp = new vector<int> ();

    // we have added one element in the vector
    v.push_back(10);
    // we have pushed 20 after 10 and also 30 after 20
    v.push_back(20);
    v.push_back(30);

    // If we want to print the elements at different indexes, we can simply treat
    // it as an array 

    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;

    // We can also change the element at a particular index

    v[1] = 100;
    cout<<v[1]<<endl;

    // Now we can also change the elements like this 
    // Why do i need a push back
    v[3] = 1000; 

    // This is a very wrong practice as push back function also perform other 
    // essential checks, whether the array is full, we need to double the size
    // etc. 

    // Now if i do the push back then 1000 will get replaced with the new number

    v.push_back(40);

    // We will only use [] for updating values and printing values but will not
    // use it to insert elements

    // Also if we try to access an element that we haven't pushed in the vector 
    // we will get a garbage value 

    cout<<v[6]<<endl;

    // an alternative to square brackets is v.at() function 
    cout<<v.at(2)<<endl;
    // if you try to access the element at 6, it will give an error out of range
    cout<<v.at(6)<<endl;

    // We can also check the size of our vector with a simple size function 

    cout << v.size()<<endl;

    // One more interesting function is capacity which tell us the underlying 
    // capacity of an array

    cout<<v.capacity()<<endl;

    // capacity of vector increase in a fashion like 0,1,2,4,8,16...

}
