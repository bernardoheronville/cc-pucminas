public static int[] vetorOrdenado(int vetA[], int vetB[]) {
    int tamA = vetA.length;
    int tamB = vetB.length;
    int tamC = tamA + tamB;
    int vetC[] = new int[tamC];

    int i = tamA - 1;
    int j = tamB - 1;
    int k = 0;
    
    while (i >= 0 && j >= 0) {
        if (vetA[i] < vetB[j]) {
            vetC[k] = vetA[i];
            i--; 
        } 
        else {
            vetC[k] = vetB[j];
            j--; 
        }
        k++; 
    }
    while (i >= 0) {
        vetC[k] = vetA[i];
        i--;
        k++;
    }
    while (j >= 0) {
        vetC[k] = vetB[j];
        j--;
        k++;
    }
    return vetC;
}