import java.util.Random;

public class Main {

    public static void QuickSortFirstPivot(int array[], int left, int right) {
        if (left >= right) return;
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
        QuickSortFirstPivot(array, left, j);
        QuickSortFirstPivot(array, i, right);
    }

    public static void QuickSortLastPivot(int array[], int left, int right) {
        if (left >= right) return;
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
        QuickSortLastPivot(array, left, j);
        QuickSortLastPivot(array, i, right);
    }

    public static void QuickSortRandomPivot(int array[], int left, int right) {
        if (left >= right) return;
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
        QuickSortRandomPivot(array, left, j);
        QuickSortRandomPivot(array, i, right);
    }

    public static void QuickSortMedianOfThree(int array[], int left, int right) {
        if (left >= right) return;
        int i = left, j = right;
        int mid = (left + right) / 2;
        int a = array[left], b = array[mid], c = array[right];
        int pivo;

        // Lógica corrigida para encontrar a mediana corretamente
        if ((a >= b && a <= c) || (a <= b && a >= c)) {
            pivo = a;
        } else if ((b >= a && b <= c) || (b <= a && b >= c)) {
            pivo = b;
        } else {
            pivo = c;
        }

        while(i <= j) {
            while(array[i] < pivo) i++;
            while(array[j] > pivo) j--;
            if(i <= j) {
                swap(array, i, j);
                i++;
                j--;
            }
        }
        QuickSortMedianOfThree(array, left, j);
        QuickSortMedianOfThree(array, i, right);
    }

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
        // Desordena 25% do array para um resultado "meio ordenado" mais realista
        for (int i = 0; i < n / 4; i++) {
            swap(array, rand.nextInt(n), rand.nextInt(n));
        }
    }

    public static long now() {
        return System.nanoTime();
    }

    public static void main(String args[]) {
        int tamanhos[] = {100, 1000, 10000};
        String nomesCenarios[] = {"Ordenado", "Meio Ordenado", "Aleatório"};

        for (int n : tamanhos) {
            System.out.println("\n#####################################################");
            System.out.println("   INICIANDO TESTES PARA N = " + n);
            System.out.println("#####################################################");

            for (String cenario : nomesCenarios) {
                System.out.println("-----------------------------------------------------");
                System.out.println("CENÁRIO: " + cenario);
                System.out.println("-----------------------------------------------------");

                long inicio, fim;
                int arrayTeste[];

                arrayTeste = new int[n];
                if (cenario.equals("Ordenado")) ordenado(arrayTeste, n);
                else if (cenario.equals("Meio Ordenado")) meioOrdenado(arrayTeste, n);
                else random(arrayTeste, n);
                
                inicio = now();
                QuickSortFirstPivot(arrayTeste, 0, n - 1);
                fim = now();
                System.out.printf("Pivô Primeiro: %.3f ms.\n", (fim - inicio) / 1_000_000.0);

                arrayTeste = new int[n]; 
                if (cenario.equals("Ordenado")) ordenado(arrayTeste, n);
                else if (cenario.equals("Meio Ordenado")) meioOrdenado(arrayTeste, n);
                else random(arrayTeste, n);
                
                inicio = now();
                QuickSortLastPivot(arrayTeste, 0, n - 1);
                fim = now();
                System.out.printf("Pivô Último: %.3f ms.\n", (fim - inicio) / 1_000_000.0);

                arrayTeste = new int[n]; 
                if (cenario.equals("Ordenado")) ordenado(arrayTeste, n);
                else if (cenario.equals("Meio Ordenado")) meioOrdenado(arrayTeste, n);
                else random(arrayTeste, n);

                inicio = now();
                QuickSortRandomPivot(arrayTeste, 0, n - 1);
                fim = now();
                System.out.printf("Pivô Aleatório:  %.3f ms.\n", (fim - inicio) / 1_000_000.0);

                arrayTeste = new int[n]; 
                if (cenario.equals("Ordenado")) ordenado(arrayTeste, n);
                else if (cenario.equals("Meio Ordenado")) meioOrdenado(arrayTeste, n);
                else random(arrayTeste, n);

                inicio = now();
                QuickSortMedianOfThree(arrayTeste, 0, n - 1);
                fim = now();
                System.out.printf("Mediana de Três: %.3f ms.\n", (fim - inicio) / 1_000_000.0);
            }
        }
    }
}