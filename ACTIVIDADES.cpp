#include <iostream>
using namespace std;
#define N 11

void actividades(int s[],int f[])
{
	int i;
	//La primera actividad siempre entra
	i = 0;
	cout << i << "-";
	for(int j = 1; j< N; j++)
	{
		if(s[j]>= f[i])
		{
			// Si esta actividad tiene una hora de inicio mayor o igual que la hora 
			//de finalización de la actividad que seleecionamos antes, 
			//entonces la seleccionamos
			cout << j << "-";
			i = j;
		}
	}
}

int main()
{
	int s[] = {1,3,0,5,3,5,6,8,8,2,12};
	int f[] = {4,5,6,7,9,9,10,11,12,14,16};
	actividades(s,f);
	return 0;
}
