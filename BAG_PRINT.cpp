#include <iostream>
using namespace std;

#define N 4
#define W 7

void bag(int wt[],int val[])
{
	int w;
	int K[N+1][W+1];
	for(int i=0;i<=N;i++)
	{
		for(w = 0; w<= W;w++)
		{
			if(i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i-1] <= w)
				K[i][w] = max(val[i-1]+K[i-1][w-wt[i-1]], K[i-1][w]);
			else
				K[i][w] = K[i-1][w];
		}
	}
		for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=W;j++)
		{
			cout << K[i][j] << ","; 
		}
		cout << endl;
	}
	
	//Guardamos el resultado de la mochila
	int res = K[N][W];
	cout << "Max ganancia:" << res <<endl;
	w = W;
	int array[N];
	for(int i=0;i<N;i++)
	{
		array[i] = 0;
	}
	for(int i=N; i>0 && res > 0;i--)
	{
		if(res == K[i-1][w]) continue;
		else
		{
			//cout << wt[i-1] << endl;
			array [i-1] = 1;
			res = res - val[i-1];
			w = w - wt[i-1];
		}
	}
	for(int i=0;i<N;i++)
	{
		cout << array[i] << "-";
	}
}

int main()
{
	int wt[] = {1,3,4,5};
	int val[]={1,4,5,7};
	bag(wt,val);
	return 0;
}


/*Dado que, este valor proviene de la parte superior , el elemento en esta fila no está incluido. 
Vaya verticalmente hacia arriba en la tabla sin incluir esto en la mochila. Ahora, este valor K [n-1] [W] que es 9 no proviene de la parte superior,
 lo que significa que el elemento en esta fila se incluye y sube verticalmente y luego se deja por el peso del elemento incluido (mostrado en negro flecha).
  Continuando con este proceso, incluya los pesos 3 y 4 con un valor total de 9 en la mochila.*/

