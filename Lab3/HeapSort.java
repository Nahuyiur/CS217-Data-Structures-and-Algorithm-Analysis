package Lab3;

import java.util.Scanner;

public class HeapSort {
    // 从1开始计算，调整最大堆性质
    public static void maxHeapify(int[] a, int i, int heap_size) {
        int l = 2 * i;
        int r = l + 1;
        int largest = i;

        if (l <= heap_size && a[l] > a[i]) {
            largest = l;
        }

        if (r <= heap_size && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            int temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;

            maxHeapify(a, largest, heap_size);
        }
    }

    public static void buildMaxHeap(int[] a, int n) {
        for (int i = n / 2; i >= 1; i--) {
            maxHeapify(a, i, n);
        }
    }

    public static void heapSort(int[] a) {
        int length = a.length - 1;

        buildMaxHeap(a, length);

        for (int i = length; i >= 2; i--) {
            int temp = a[1];
            a[1] = a[i];
            a[i] = temp;
            maxHeapify(a, 1, i - 1);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            arr[i] = in.nextInt();
        }

        heapSort(arr);

        for (int i = 1; i <= n; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
