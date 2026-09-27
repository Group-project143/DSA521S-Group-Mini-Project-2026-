public class SelectionSort {

    public static void main(String[]args){
        int[] Array = {17 , 5, 23, 8, 14, 3, 11, 20, 6, 9};
        int comparisons = 0;
        int swaps = 0;

        for (int i = 0; i < Array.length - 1; i++){
            int smallestNo= i;
            for(int j = i + 1; j < Array.length; j++){
                comparisons++;
                if(Array[j] < Array[smallestNo]){
                    smallestNo = j;
                }
            }
            if(smallestNo != i){
                int temp =Array[i];
                Array[i] =Array[smallestNo];
                Array[smallestNo] = temp;
                swaps++;
            }
                System.out.print("Pass" +( i + 1) + ": ");
                            for (int number : Array){
                System.out.print(number + "");
                    }
            System.out.println();
        }
        System.out.println("comparisons: " + comparisons);
            System.out.println("swaps: " + swaps);
    }
}
    
    