//Edit Distance
#include <iostream>

using namespace std;

//REcursive Solution
int editDist(string str1 , string str2 , int m ,int n) 
{ 
	// If first string is empty, the only option is to 
	// insert all characters of second string into first 
	if (m == 0) return n; 

	// If second string is empty, the only option is to 
	// remove all characters of first string 
	if (n == 0) return m; 

	// If last characters of two strings are same, nothing 
	// much to do. Ignore last characters and get count for 
	// remaining strings. 
	if (str1[m-1] == str2[n-1]) 
		return editDist(str1, str2, m-1, n-1); 

	// If last characters are not same, consider all three 
	// operations on last character of first string, recursively 
	// compute minimum cost for all three operations and take 
	// minimum of three values. 
	return 1 + min ( editDist(str1, str2, m, n-1),min(editDist(str1, str2, m-1, n), // Remove 
					editDist(str1, str2, m-1, n-1)) // Insert 
					 // Replace 
				); 
}

//Bottom Up Approach
int editDistance(string s1,string s2)
{
    int dp[100][100] = {};
    
    int m = s1.length();
    int n = s2.length();
    
    dp[0][0] = 0;
    for(int i=1;i<=m;i++) dp[i][0] = dp[i-1][0] + 1;
    for(int i=1;i<=n;i++) dp[0][i] = dp[0][i-1] + 1;
    
    for(int i=1; i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int q1 = dp[i-1][j-1];
            int q2 = dp[i-1][j];
            int q3 = dp[i][j-1];
            dp[i][j] = min(q1,min(q2,q3)) + ( s1[i-1] != s2[j-1] );
        }
    }
    
    return dp[m][n];
}

int main()
{
    string s1 = "sunday";
    string s2 = "saturday";
    
    
    cout<<editDist(s1,s2,s1.length()-1,s2.length()-1)<<endl;
    cout<<editDistance(s1,s2)<<endl;

    return 0;
}
