#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        // Write your code here
        if(pq.size()==0){
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        
        int i = 0;
        int lci = 2*i+1;
        int rci = 2*i+2;
        
        while(lci <= pq.size()-1 || rci<=pq.size()-1){
            

            if(lci == pq.size()-1){
                if(pq[i]>pq[lci]){
                    int a = pq[i];
                    pq[i] = pq[lci];
                    pq[lci] = a;
                    i = lci;
                }else{
                    break;
                }
            }else if(lci < pq.size()-1){
                if(pq[lci]<pq[rci]){
                   if(pq[i]>pq[lci]){
                    	int a = pq[i];
                    	pq[i] = pq[lci];
                    	pq[lci] = a;
                    	i = lci;
                	}else{
                    	break;
                   } 
                }else{
                    if(pq[i]>pq[rci]){
                    	int a = pq[i];
                    	pq[i] = pq[rci];
                    	pq[rci] = a;
                    	i = rci;
                	}else{
                    	break;
                    }
                }
            }
            
            lci = 2*i+1;
        	rci = 2*i+2;
        }
        return ans;
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
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
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
