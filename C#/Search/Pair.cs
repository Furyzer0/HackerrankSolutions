using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Solution {

    static int pairs(int k, int[] arr) {
        int count = 0; 
        Array.Sort(arr);
        int max = arr.Length - 1;

        for(int i = 0; i < arr.Length; i++)
        {
            int min = i;
            while(min <= max)
            {
                int mid = (min + max) / 2;

                if(arr[i] + k == arr[mid])
                {
                    count++;
                    break;
                }
                else if(arr[i] + k < arr[mid])
                    max = mid - 1;
                else
                    min = mid + 1;
            }
        }

        return count;
    }

    static void Main(String[] args) {
        string[] tokens_n = Console.ReadLine().Split(' ');
        int n = Convert.ToInt32(tokens_n[0]);
        int k = Convert.ToInt32(tokens_n[1]);
        string[] arr_temp = Console.ReadLine().Split(' ');
        int[] arr = Array.ConvertAll(arr_temp,Int32.Parse);
        int result = pairs(k, arr);
        Console.WriteLine(result);
    }
}
