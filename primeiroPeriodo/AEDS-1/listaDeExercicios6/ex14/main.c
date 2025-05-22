#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *vetor;
    int N;
    scanf("%d",&N);
    vetor = (char*)malloc(N*sizeof(char));
    scanf("%s",vetor);
    for(int i=N-1;i>=0;i--)
    {
        printf("%c",*(vetor+i));
    }
    free(vetor);
    return 0;
}
