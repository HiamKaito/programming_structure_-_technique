
public class InsertionSort {

    public static void main(String[] args) {
        int[] arrInt = {3, 2, 1, 5, 6, 4};

        for (int i = 0; i < arrInt.length; i++) {
            int key = arrInt[i];
            int j = i - 1;
            while (j >= 0 && key < arrInt[j]) {
                arrInt[j + 1] = arrInt[j];
                j -= 1;
            }
            arrInt[j + 1] = key;
        }

        for (int i : arrInt) {
            System.out.printf(i + " ");
        }
    }
}
