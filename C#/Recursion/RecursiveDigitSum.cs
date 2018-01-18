using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Solution {

    static int digitSum(string text) {
        if(text.Length == 1)
            return Int32.Parse(text);
        int result = 0;
        for(int i = 0; i < text.Length; i++)
        {
            result += text[i] - 48;
        }   
        return digitSum(Convert.ToString(result));
    }

    static void Main(String[] args) {
        string[] tokens_n = Console.ReadLine().Split(' ');
        string n = tokens_n[0];
        int k = Convert.ToInt32(tokens_n[1]);
        long num = 0;
        for(int i = 0; i < n.Length; i++)
            num += n[i] - 48;
        num *= k;
        string text = Convert.ToString(num);
        int result = digitSum(text);
        Console.WriteLine(result);
    }
}
