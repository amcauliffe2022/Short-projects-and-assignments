import java.util.ArrayList;

public class Partition {
    public static void main(String args[]) {
        int[] Set = new int[100];
        for (int x = 0; x < Set.length; x++) {
            Set[x] = (int) (Math.random() * 100000);
        }
        long timestart = System.nanoTime();
        int T = partitionSet(Set);
        long timestop = System.nanoTime() - timestart;
        System.out.println("Minimum difference in the subsets: " + T);
        System.out.println("Time to run in nano seconds: " + timestop);
    }
    public static int partitionSet(int[] Set){
        int sum = 0;
        //Gets the sum of the Set
        for(int x = 0; x <= Set.length-1; x++){
            sum += Set[x];
        }
        //Memorization to find the best
        boolean[][] memo = new boolean[Set.length+1][sum +1];
        //The index of the main set inorder to check every entry
        for(int a = 0; a < Set.length; a++) {
            memo[a][0] = true;
        }

        //Index of the set to get the test
        for(int index = 0; index <= Set.length; index++){
           /*
           setsum is the sum of subset 1.
           The loop is will continue until the next subset sum is equal to of less than half the total sum
           If one subset sum is equal to half total sum the other subset will be main up of the remaining and equal half.
           It the best subset 1 is not equal to half, the other half should still equal half.
            */
            for(int setsum = 0; setsum <= sum/2 && index != 0; setsum++){

                //If the previous number of the set is less than or equal to the subset sum then it will be include
                if(Set[index-1] <= setsum){
                    //If the previous subset and/or the possibility of replacing the last entry in the subset are include
                    if (memo[index][setsum] || memo[index - 1][setsum - Set[index - 1]]){
                        memo[index][setsum] = true;
                    }
                    else{
                        memo[index][setsum] = false;
                    }
                }
                else{
                    //If the entry is excluded from the subset
                    memo[index][setsum] = memo[index-1][setsum];
                }

            }
        }
        /*
        This process is to find the difference by finding best subset that has sorted the entire main set and
         */
        int diff = sum/2;
        while (diff >= 0 && !memo[Set.length][diff]) {
            diff--;
        }
        return sum - 2*diff;
    }


}
