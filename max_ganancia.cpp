#include <iostream>
using namespace std;
#define N 10

void max_ganancia (int precio[])
{
    int ganancia[N];
    for (int i=0;i<N;i++)
        ganancia[i] = 0;
    int valor_max = precio[N-1];
    int resultado;
    for (int i=N-2;i>=0;i--)
    {
        if(precio[i]>valor_max)
            valor_max = precio[i];
        ganancia[i] = max(ganancia[i+1], valor_max - precio[i]);
        resultado = ganancia[i];
        cout << ganancia[i] << endl;
    }
    cout << "La maxima ganancia es:" << resultado << endl;
}

int main()
{
    int precios[N] = {1,1,1,1,1,1,1,1,1,1};
    max_ganancia(precios);
    return 0;
}
