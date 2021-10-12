public class ShellSort {
    public static void main(String[] args) {
        int[] arrInt = {3, 2, 1, 5, 6, 4};

        for (int h = arrInt.length/ 2 ; h > 0 ; h = h/2) {
            for (int i = h; i < arrInt.length ; i++) {
                int temp = arrInt[i];
                int j = i;
                
                while (j >= h && arrInt[j - h] > temp ) {
                    arrInt[j] = arrInt[j - h];
                    j -= h;
                }
                
                arrInt[j] = temp;
            }
        }
        

        for (int i : arrInt) {
            System.out.printf(i + " ");
        }
    }
}
