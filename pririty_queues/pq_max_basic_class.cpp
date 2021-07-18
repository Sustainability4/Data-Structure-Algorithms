#include <iostream>
using namespace std;
#include<vector>
class PriorityQueue {
    // Declare the data members here
    vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int currentIndex = pq.size()-1;
        int rootIndex = (currentIndex-1)/2;
        
        while(rootIndex >= 0){
            if(pq[rootIndex]<pq[currentIndex]){
                int a = pq[rootIndex];
                pq[rootIndex] = pq[currentIndex];
                pq[currentIndex] = a; 
            }else{
                break;
            }
            
            currentIndex = rootIndex;
            rootIndex = (currentIndex-1)/2;
        }
        
    }

    int getMax() {
        // Implement the getMax() function here
        if(pq.size()==0){
            return -9999999;
        }
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(pq.size()==0){
            return -9999999;
        }
        int a = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        
        int root = 0;
        int lci = 2*root+1;
        int rci = 2*root +2;
        
        while(lci<pq.size()){
            if(lci == pq.size()-1){
                if(pq[root]<pq[lci]){
                    int a = pq[root];
                    pq[root] = pq[lci];
                    pq[lci] = a;
                    root = lci;
                    lci = 2*root+1;
                    rci = 2*root+2;
                }else{
                    break;
                }
            }else{
                if(pq[rci]<pq[lci]){
                    if(pq[root]<pq[lci]){
                        int a = pq[root];
                    	pq[root] = pq[lci];
                    	pq[lci] = a;
                    	root = lci;
                    	lci = 2*root+1;
                        rci = 2*root+2;
                    }else{
                        break;
                    }
                }else{
                    if(pq[root]<pq[rci]){
                        int a = pq[root];
                    	pq[root] = pq[rci];
                    	pq[rci] = a;
                    	root = lci;
                    	rci = 2*root+1;
                        rci = 2*root+2;
                    }else{
                        break;
                    } 
                }
            }
        }
        
        return a;
        
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}
