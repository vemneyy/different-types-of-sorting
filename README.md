# different-types-of-sorting
The program in the C programming language and is an algorithm for comparing the effectiveness of five different sorting methods: bubble, shuffle, gnome, fast and pyramid.

This code is written in the C programming language and is an algorithm for comparing the effectiveness of five different sorting methods: bubble, shuffle, gnome, fast and pyramid.
At the beginning of the code, function prototypes are declared for each of these sorting methods.
The `Sort` structure is defined to store the name of the sorting method and the time of its execution. The `compare` function is used to compare the execution time of two sorting methods.
In the `main()` function, two arrays are created: one for sorting and the other as a backup. Then, for each sorting method, the time is clocked, the sorting takes place, the time stops and the elapsed time is calculated. The name of the sorting method and the time spent are then stored in an array of `Sort` structures.
After all five sorting methods have been applied, the methods are sorted by elapsed time using the `qsort` function.
Finally, the code outputs a sorted list of sorting methods along with the time spent on each method.
Sorting functions (bubbleSort, Cocktails, gnomeSort, quickSort, heapSort) are implemented in a standard way. The `swap` function is used to exchange the values of two variables. The `partition` and `heapify` functions are auxiliary functions for quick and pyramid sorting, respectively.
