import java.util.*;

public class Main {

    // ---------- QUICKSORTS ----------
    public static void QuickSortFirstPivot(int array[], int left, int right) {
        int i = left, j = right;
        int pivo = array[left];
        while(i <= j) {
            while(array[i] < pivo) i++;
            while(array[j] > pivo) j--;
            if(i <= j) {
                swap(array, i, j);
                i++;
                j--;
            }
        }
        if(left < j) QuickSortFirstPivot(array, left, j);
        if(i < right) QuickSortFirstPivot(array, i, right);
    }

    public static void QuickSortLastPivot(int array[], int left, int right) {
        int i = left, j = right;
        int pivo = array[right];
        while(i <= j) {
            while(array[i] < pivo) i++;
            while(array[j] > pivo) j--;
            if(i <= j) {
                swap(array, i, j);
                i++;
                j--;
            }
        }
        if(left < j) QuickSortLastPivot(array, left, j);
        if(i < right) QuickSortLastPivot(array, i, right);
    }

    public static void QuickSortRandomPivot(int array[], int left, int right) {
        int i = left, j = right;
        Random gerador = new Random();
        int pivoIndex = left + gerador.nextInt(right - left + 1);
        int pivo = array[pivoIndex];
        while(i <= j) {
            while(array[i] < pivo) i++;
            while(array[j] > pivo) j--;
            if(i <= j) {
                swap(array, i, j);
                i++;
                j--;
            }
        }
        if(left < j) QuickSortRandomPivot(array, left, j);
        if(i < right) QuickSortRandomPivot(array, i, right);
    }

    public static void QuickSortMedianOfThree(int array[], int left, int right) {
        int i = left, j = right;
        int a = array[left], b = array[(left + right) / 2], c = array[right];
        int pivo;
        if ((a >= b && a <= c) || (a <= b && a >= c)) pivo = a;
        else if ((b >= a && b <= c) || (b <= a && b >= c)) pivo = b;
        else pivo = c;

        while(i <= j) {
            while(array[i] < pivo) i++;
            while(array[j] > pivo) j--;
            if(i <= j) {
                swap(array, i, j);
                i++;
                j--;
            }
        }
        if(left < j) QuickSortMedianOfThree(array, left, j);
        if(i < right) QuickSortMedianOfThree(array, i, right);
    }

    // ---------- UTILITÁRIOS ----------
    public static void swap(int array[], int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void ordenado(int array[], int n) {
        for (int i = 0; i < n; i++) {
            array[i] = i;
        }
    }

    public static void random(int array[], int n) {
        Random rand = new Random();
        ordenado(array, n);
        for (int i = 0; i < n; i++) {
            swap(array, i, rand.nextInt(n));
        }
    }

    public static void meioOrdenado(int array[], int n) {
        Random rand = new Random();
        ordenado(array, n);
        for (int i = 0; i < n / 2; i++) {
            swap(array, i, rand.nextInt(n));
        }
    }

    public static long now() {
        return System.nanoTime();
    }

    // ---------- MAIN ----------
    public static void main(String args[]) {
        // Tamanhos que queremos testar
        int[] tamanhos = {100, 1000, 10000};

        for (int n : tamanhos) {
            
            int[] arrayOrdenado = new int[n];
            ordenado(arrayOrdenado, n);

            int[] arrayMeioOrdenado = new int[n];
            meioOrdenado(arrayMeioOrdenado, n);

            int[] arrayAleatorio = new int[n];
            random(arrayAleatorio, n);
            
            int[][] cenarios = {arrayOrdenado, arrayMeioOrdenado, arrayAleatorio};
            String[] nomesCenarios = {"Array Ordenado", "Array Meio Ordenado", "Array Aleatório"};

            System.out.println("\n#####################################################");
            System.out.println("   INICIANDO TESTES PARA N = " + n);
            System.out.println("#####################################################");

            for (int i = 0; i < cenarios.length; i++) {
                System.out.println("-----------------------------------------------------");
                System.out.println("CENÁRIO: " + nomesCenarios[i]);
                System.out.println("-----------------------------------------------------");

                int[] original = cenarios[i];
                long inicio, fim;

                // Pivô Primeiro
                int[] copia1 = Arrays.copyOf(original, n);
                inicio = now();
                QuickSortFirstPivot(copia1, 0, n - 1);
                fim = now();
                System.out.printf("Pivô Primeiro:   %.3f ms.\n", (fim - inicio) / 1_000_000.0);

                // Pivô Último
                int[] copia2 = Arrays.copyOf(original, n);
                inicio = now();
                QuickSortLastPivot(copia2, 0, n - 1);
                fim = now();
                System.out.printf("Pivô Último:     %.3f ms.\n", (fim - inicio) / 1_000_000.0);

                // Pivô Aleatório
                int[] copia3 = Arrays.copyOf(original, n);
                inicio = now();
                QuickSortRandomPivot(copia3, 0, n - 1);
                fim = now();
                System.out.printf("Pivô Aleatório:  %.3f ms.\n", (fim - inicio) / 1_000_000.0);

                // Mediana de Três
                int[] copia4 = Arrays.copyOf(original, n);
                inicio = now();
                QuickSortMedianOfThree(copia4, 0, n - 1);
                fim = now();
                System.out.printf("Mediana de Três: %.3f ms.\n", (fim - inicio) / 1_000_000.0);
            }
        }
    }
}
