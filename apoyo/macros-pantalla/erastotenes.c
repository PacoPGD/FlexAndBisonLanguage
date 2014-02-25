#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include "macros.h"
main()
{
 int *primos, n, i, j, linea;

 /* Peticion del valor de n */
do {
    BORRAR;
    LUGAR(5,10);
    printf("Introduce un numero entero positivo para  n --> ");
    scanf("%d",&n); 
    getchar();
  } while (n<1);

 /* Reserva de memoria */
 primos = (int *) malloc (n * sizeof(int));

 /* Inicializacion del vector */
 for (i=0; i<n; i++) *(primos+i) = i+1;

/**********************************************************************
 Criba de Erastotenes 
 Version optimizada: solo se criba con los numeros primos 
                     menores o iguales que la raiz cuadrada de n 
************************************************************************/

 for (i=1; *(primos+i)<=sqrt(n); i++)
   if (*(primos+i) != 0) 
        for (j= 2 * *(primos+i) - 1; j<n; j+= *(primos+i))
             *(primos+j) = 0;

/* Presentacion de los numeros primos menores que n */
 BORRAR;
 LUGAR(1,5);
 printf("Numeros primos menores que %d",n);
 for(i=0,linea=1;i<n;i++)
    { 
     if (*(primos+i)!=0) 
            {
             LUGAR(linea+1,10);
             printf("%d", *(primos+i)); 
             linea++; 
            }
     if (linea%20==0) 
           {
            linea = 1;
            LUGAR(22,30);
            puts("pulse");
            LUGAR(23,30);

	    SUBRAYADO;
  	    puts("ENTER");
	    APAGA;

            LUGAR(24,30);
	    puts("para continuar"); 

            getchar();
            BORRAR; 
            LUGAR(1,5);
            printf("Numeros primos menores que %d (continuacion)",n);
           }
    }
putchar('\n');

INTENSIDAD;

printf("Fin del programa\n");

APAGA;

}

