#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    if (input.size() == 0){
        return 1; 
    }
    string smallOutput[1000];
    int smalllength = returnPermutations(input.substr(1), smallOutput);
    int k = 0;
    for(int j = 0 ; j<smalllength;j++){
        for(int i=0; i<= smallOutput[0].size() ; i++ ){
            output[k] = smallOutput[j].substr(0,i)+input[0]+smallOutput[j].substr(i);
            k++;
        }
    }
    return k; 
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
