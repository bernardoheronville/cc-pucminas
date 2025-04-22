#include <stdlib.h>

int somardigitos(int n)
{
  if(n==0) return 0;
  else return (n % 10) + somardigitos(n / 10);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",somardigitos(n));
    return 0;
}
