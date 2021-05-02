#include<iostream>
using namespace std;

bool checksequenece(char large[] , char*small) {
    if(small[0]=='\0'&&large[0]!='\0')
                return true;
    else if(small[0]!='\0'&&large[0]=='\0')
        return false;


          else if(large[0]=='\0'&&small[0]=='\0')
            return true;


        int i=0;
        for(;large[i]!='\0';i++)
        {
            if(large[i]==small[0])
            {
                break;
            }
        }
        if(large[i]=='\0')
            return false;

    return checksequenece(large+i+1,small+1);

}

int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}

