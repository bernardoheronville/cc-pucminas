#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    float n;
    int div9e3=0,div2=0,div5=0;
    int intn = (int)n;

    for(int i=0; i<10; i++)
    {
        scanf( "%f",&n);
        int nint = (int)n;

        if(fmod(n,9)==0)
        {
            div9e3++;
        }

        if(fmod(n,2)==0)
        {
            div2++;
        }

        if(fmod(n,5)==0)
        {
            div5++;
        }
        if(fmod(n,5)!=0 && fmod(n,2)!=0 && fmod(n,9)!=0)
        {
            printf("Numero nao e divisivel pelos valores\n");
        }

    }

    printf("%d Numeros sao divisiveis por 3 e por 9\n",div9e3);
    printf("%d Numeros sao divisiveis por 2\n",div2);
    printf("%d Numeros sao divisiveis por 5",div5);

    return 0;
}
