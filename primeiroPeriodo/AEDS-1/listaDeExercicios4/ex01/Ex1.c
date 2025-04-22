#include <stdlib.h>

int contador(int n)
{
  if(n==0) return 0;
  else if(n<10) return 1;
  else return (1+contador(n/10));
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",contador(n));
    return 0;
}
