// LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
// FUNCIONES

// Funcion de Insertion Sort
void insertion_sort(int A[], int n)
{
   int i, j, k; // k de key
   for (i = 1; i < n; i++)
   {
       k = A[i];
       j = i-1;

       while (j >= 0 && A[j] > k)
       {
           A[j+1] = A[j];
           j = j-1;
       }
       A[j+1] = k;
   }
}
 
// Funcion para imprimir arreglo
void imprimir_arreglo(int A[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", A[i]);
   printf("\n");
}

///////////////////////////////////////////////////////////////////////////
int ordenar(int lista[],int arr_tam,int ord)
{
  int c1,c2,aux;
  for(c1=0;c1<arr_tam;c1++)
  {
    for(c2=0;c2<arr_tam;c2++)
    {
      if(ord==1)
      {
        if(lista[c2]>lista[c2+1])
        {
          aux=lista[c2];
          lista[c2]=lista[c2+1];
          lista[c2+1]=aux;
        }
      }
      else
      {
        if(lista[c2]<lista[c2+1])
        {
          aux=lista[c2];
          lista[c2]=lista[c2+1];
          lista[c2+1]=aux;
        }
      }
    }
  }
  return 0;
}
///////////////////////////////////////////////////////////////////////////
 
//MAIN
int main()
{
    clock_t t_ini, t_fin;
    double secs;

    printf("Insertion sort\n");
    
    int tamanio = 5000;    
    int ii;
    for(ii = 1; ii<11; ii++)
    {
    int A[tamanio];
    
    int i;
    for(i = 0; i < tamanio; i++)
    {
        A[i] = rand();
    }

    int arr_tam = sizeof(A)/sizeof(A[0]);

    ordenar(A,arr_tam,2);    

    t_ini = clock();
    insertion_sort(A, arr_tam);
    t_fin = clock();

    secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
    printf("\nIteracion %d, datos %d",ii,tamanio);
    //printf("\nTiempo: %.16g milisegundos", secs * 1000.0);
    printf("\nTiempo segundos: %.10f\n", secs);
    tamanio += 5000;
    }

    return 0;
}