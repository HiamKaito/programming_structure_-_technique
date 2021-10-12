
public class SelectionSort {

    public static void main(String[] args) {
        int[] arrInt = {3, 2, 1, 5, 6, 4};

        int jmin;
        for (int i = 0; i < arrInt.length - 1; i++) {
            jmin = i;
            for (int j = i + 1; j < arrInt.length; j++) {
                if (arrInt[j] < arrInt[jmin]) {
                    jmin = j;
                }
            }
            if (jmin != i) {
                int temp = arrInt[jmin];
                arrInt[jmin] = arrInt[i];
                arrInt[i] = temp;
            }
        }

        for (int i : arrInt) {
            System.out.printf(i + " ");
        }
    }
}
