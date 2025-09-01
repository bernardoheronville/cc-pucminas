import java.util.Scanner;

class Ex03 {
    private int array[];
    private int n;
    private int M;

    public Ex03(int array[], int N, int M) {
        this.array = array;
        this.n = N;
        this.M = M;
    }

    public boolean compare(int a, int b) {
        int modA = (a % M);
        int modB = (b % M);

        if(modA > modB) return false;
        else if (modA < modB) return true;
        else {
            int parA = a % 2;
            int parB = b % 2;
            if(parA == 1 && parB == 0) return true;
            if(parA == 0 && parB == 1) return false;
            if(parA == 1 && parB == 1) {
                if(a > b) return true;
                else return false;
            }
            if(parA == 0 && parB == 0) {
                if(a < b) return true;
                else return false;
            }
        }
        return false;
    } 

    public void sort() {
		for (int i = 0; i < (n - 1); i++) {
			int menor = i;
			for (int j = (i + 1); j < n; j++){
				if (!(compare(array[menor], array[j]))){
					menor = j;
				}
			}
			swap(menor, i);
		}
	}

    public void swap(int i, int j) {
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}

    public void exibe() {
        for(int i = 0; i < n; i++) {
            System.out.println(array[i]);
        }
    }
}

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        while(N != 0 && M != 0) {
            int array[] = new int[N];
            for(int i = 0; i < N; i++) {
                array[i] = sc.nextInt();
            }
            Ex03 ex03 = new Ex03(array, N, M);
            ex03.sort();
            System.out.println(N + " " + M);
            ex03.exibe();
            N = sc.nextInt();
            M = sc.nextInt();
        }
        System.out.println("0 0");
        sc.close();
    }
}