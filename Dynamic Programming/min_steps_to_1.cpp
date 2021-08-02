// Brute Force Code
int countMinStepsToOne(int n)
{
	//Write your code here
    if(n == 1){
        return 0; 
    }
    int count_1 = 999999;
    int count_2 = 999999;
    int count_3 = 999999;
    
    if(n%2 == 0){
        count_1 = countMinStepsToOne(n/2);
    }
    
    if(n%3 == 0){
        count_2 = countMinStepsToOne(n/3);
    }
    
    count_3 = countMinStepsToOne(n-1);
    
    return min(min(count_1,count_2),count_3)+1;
}

// Memoization using Recursion
int countMinStepsToOneHelper(int n, int*ans)
{
	//Write your code here
    if(ans[n] != -1){
        return ans[n];
    }
    if(n == 1){
        ans[n] = 0;
        return 0; 
    }
    int count_1 = 999999;
    int count_2 = 999999;
    int count_3 = 999999;
    
    if(n%2 == 0){
        count_1 = countMinStepsToOneHelper(n/2, ans);
    }
    
    if(n%3 == 0){
        count_2 = countMinStepsToOneHelper(n/3, ans);
    }
    
    count_3 = countMinStepsToOneHelper(n-1, ans);
    
    int b = min(min(count_1,count_2),count_3)+1;
    ans[n] = b;
    
    return ans[n];
}

int countMinStepsToOne_1(int n ){
    int * ans = new int[n+1];
    for(int i = 0; i<n+1; i++){
        ans[i] = -1;
    }
    return countMinStepsToOneHelper(n, ans);
}

// Dynamic Programming : Memoization using iteration 

// Dynamic Programming: Memoization Using Iteration
int countStepsToOne(int n)
{
    
    int table[n+1];
    table[1]=0;
    
    for (int i=2; i<=n; i++)
    {
    	if (!(i%2) && (i%3))
        	table[i] = 1+min(table[i-1], table[i/2]);
    	else if (!(i%3) && (i%2))
        	table[i] = 1+min(table[i-1], table[i/3]);
    	else if(!(i%2) && !(i%3))
        	table[i] = 1+min(table[i-1],min(table[i/2],table[i/3]));
    	else
        	table[i] =1+table[i-1];
    }
    
    return table[n];
    
	
    /*//Write your code here
    int * ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 0; 

    for(int i = 2; i<n+1; i++){
        int count_1 = 99999;
    	int count_2 = 99999;
    	int count_3 = 99999;
        
        if(i%2 == 0){
            count_1 = ans[n/2];
        }
        if(i%3 == 0){
            count_2 = ans[n/3];
        }
        
        count_3 = ans[n-1];
        //cout<<count_1<<" "<<count_2<<" "<<count_3<<" ";
        int a = min(count_1, min(count_2,count_3));
        int b = a+1;
        ans[n] = b;
        //out<<ans[n]<<endl;
    }

    return ans[n];
    */
}

