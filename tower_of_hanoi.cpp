#include <iostream>
using namespace std;
#include <cmath>

// Change in the given string itself. So no need to return or print the changed string.

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Power of Recursion 
    if (n == 0){
        return; 
    }
    towerOfHanoi(n-1, source, destination, auxiliary);
    cout<< source << " " << destination << endl ; 
    towerOfHanoi(n-1, auxiliary, source, destination );

}
int main() {
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
}
