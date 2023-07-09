import java.util.Scanner; 
 
public class Main { 
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); 
        int size = sc.nextInt(); 
        int[] arr = new int[size]; 
        for (int i = 0; i < size; i++) { 
            arr[i] = sc.nextInt(); 
        } 
        int k = sc.nextInt(); 
 
        KthSmallestElement kthSmallest = new KthSmallestElement(); 
        int kth = kthSmallest.findKthSmallest(arr, size, k); 
 
        System.out.println(kth); 
    } 
}

class KthSmallestElement { 
    public int findKthSmallest(int[] arr, int size, int k) { 
        int temp=0;
        for(int i=0; i<size-1; i++){
            for(int j=0; j <size-i-1; j++){
                if(arr[j]>arr[j+1]){
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
     //lines 33 to 37 not required   
     for(int i=0;i<size;i++){
            
            System.out.println(arr[i]);
            
        }
        return arr[k-1];
    } 
}
