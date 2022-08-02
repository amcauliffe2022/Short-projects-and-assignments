import java.util.Arrays;

public class merge_sort {
    static int comparisons;
    public static void main(String args[]) {


        int[] test = new int[50000];
        for(int x =0; x < test.length; x++){
            test[x] = (int)(Math.random()*100)*(int)(Math.random()*100);
        }
        long starttime = System.currentTimeMillis();
        System.out.println("Before sorting : " + Arrays.toString(test));
        sort(test,0,test.length-1); // sort the integer array using quick sort algorithm
        long endtime = System.currentTimeMillis();
        System.out.println("After sorting : " + Arrays.toString(test));
        System.out.println("Time to sort in milliseconds "+(endtime-starttime));
        System.out.println("Number of Comparisons: "+ comparisons);

    }
    /*
    The comparison is O(1).
    Then the arrays get subdivided into n/2 recursively. Leading to O(log n)
    This means that O(log n + 1)
     */
        public static void sort(int[] arr, int start, int end) {
            if (start < end) {
                comparisons++;
                int mid = (start + end) / 2;
                //log n for both of these
                sort(arr, start, mid);
                sort(arr, mid + 1, end);
                merge(arr, start, mid, end);
            }
        }
    /*
    There are 2 loops that are n time complexity.
    This makes this O(n) time complexity
    Leading to the whole program being O(n logn)
     */
        public static void merge(int[] arr, int start,int mid, int end){
            int L = mid - start +1;
            int R = end -mid;
            int[] Larr = new int[L];
            int[] Rarr = new int[R];

            //O(n/2)
            for(int a = 0;a < L; a++){
                Larr[a] = arr[a +start];
            }
            //O(n/2)
            for(int b = 0;b < R; b++){
                Rarr[b] = arr[mid + b +1];
            }
            int a = 0;
            int b = 0;
            int temp = start;
            //O(n)
            while(a < L && b < R){
                if(Larr[a] <= Rarr[b]){
                    arr[temp] = Larr[a];
                    a++;
                    comparisons++;
                }
                else{
                    arr[temp] = Rarr[b];
                b++;
                }
                temp++;
            }
            //O(n/2 - x) x<=n
            while(a<L){
                arr[temp] = Larr[a];
                a++;
                temp++;
            }
            //O(n/2 - x) x<=n
            while(b<R){
                arr[temp] = Rarr[b];
                b++;
                temp++;
            }
        }
}
