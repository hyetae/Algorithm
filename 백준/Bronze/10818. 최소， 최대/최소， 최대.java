import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> arr = new ArrayList<>();
        
        int n = sc.nextInt();
        for (int i = 0; i < n; i++)
            arr.add(sc.nextInt());
        
        Collections.sort(arr);
        
        System.out.print(arr.get(0) + " " + arr.get(n - 1));
        sc.close();
    }
}