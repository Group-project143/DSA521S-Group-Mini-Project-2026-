import java.util.Arrays;

public class TaskB2 {

    public static void insertionSort(int[] arr) {

        int comparisons = 0;
        int shifts = 0;

        // Start from the second element
        for (int i = 1; i < arr.length; i++) {

            int key = arr[i];
            int j = i - 1;

            // Move elements greater than key one position to the right
            while (j >= 0 && arr[j] > key) {

                comparisons++;
                arr[j + 1] = arr[j];
                shifts++;
                j--;
            }

            // Count the comparison that stops the loop
            if (j >= 0) {
                comparisons++;
            }

            // Insert key into its correct position
            arr[j + 1] = key;

            // Display the array after each pass
            System.out.println("Pass " + i + ": " + Arrays.toString(arr));
        }

        System.out.println();
        System.out.println("Total Comparisons: " + comparisons);
        System.out.println("Total Shifts: " + shifts);
    }

    public static void main(String[] args) {

        // Given array from Task B2
        int[] serviceTimes = {17, 5, 23, 8, 14, 3, 11, 20, 6, 9};

        System.out.println("Original Array:");
        System.out.println(Arrays.toString(serviceTimes));

        System.out.println();
        System.out.println("Insertion Sort:");

        insertionSort(serviceTimes);

        System.out.println();
        System.out.println("Final Sorted Array:");
        System.out.println(Arrays.toString(serviceTimes));
    }
}