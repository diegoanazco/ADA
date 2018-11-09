#include <iostream>
#include <conio.h> 
#include <stdio.h> 
#include <string.h> 

using namespace std;

char A[] = "ABCBDAB";
char B[] = "BDCABA";

void LCS(int m, int n)
{
	int T[m+1][n+1]; 
	for (int i=0; i<=m; i++) 
	{ 
 		for (int j=0; j<=n; j++) 
		{ 
   			if (i == 0 || j == 0) 
     			T[i][j] = 0; 
		    else if (A[i-1] == B[j-1]) 
     			T[i][j] = T[i-1][j-1] + 1; 
		    else
     			T[i][j] = max(T[i-1][j], T[i][j-1]); 
 		} 
	} 
	
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout << T[i][j] << ","; 
		}
		cout << endl;
	}
	
	int index = T[m][n];
	char value[index+1]; 
    value[index] = '\0'; 
	int i = m;
	int j = n;
	while (i > 0 && j > 0)
	{
		if (A[i-1] == B[j-1])
		{
			value[index-1] = A[i-1];
			i--;
			j--;
			index--;
		}
		else if(T[i-1][j] > T[i][j-1]) i--;
		else j--;
	}
	cout << "Tamano: " << T[m][n] << endl;
	cout << "Cadena: " << value << endl;
}

int main() 
{ 
	int m = strlen(A); 
	int n = strlen(B); 
	LCS( m, n ) ; 
	return 0; 
} 
