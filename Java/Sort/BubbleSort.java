
public class BubbleSort {

    public static void main(String[] args) {
        int[] arrInt = {3, 2, 1, 5, 6, 4};

        for (int i = 1; i < arrInt.length; i++) {
            for (int j = arrInt.length - 1; j >= i; j--) {
                if (arrInt[j] < arrInt[j - 1]) {
                    int temp = arrInt[j];
                    arrInt[j] = arrInt[j - 1];
                    arrInt[j - 1] = temp;
                }
            }
        }

        for (int i : arrInt) {
            System.out.printf(i + " ");
        }
    }
}
