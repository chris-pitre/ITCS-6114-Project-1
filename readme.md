# ITCS-6114 Project 1
C-based program to compare Insertion sort, Merge sort, Heapsort, In-place Quicksort, and a Modified quicksort.

The program runs 20 trials for a randomly generated array, pre-sorted array, and reverse sorted array on input sizes 1000, 2000, 3000, 5000, 10,000, 20,000, 30,000, 40,000, 50,000, 60,000. Afterwards it returns a file data.txt with the minimum, average, and maximum size for each method and input size.

## Getting Started

### Dependencies

* C Compilier of choice

### Running

1. Compile the program with your C compiler of choice. We used gcc to compile, but you should be able to use your prefered compiler.
    ```sh
    For Unix/MacOS:
    gcc -o project1 project1.c
    For Windows:
    gcc -o project1.exe project1.c
    ```
2. Run the program (Warning: The program is designed to iterate through multiple different arrays multiple different times so the runtime of the entire program may be long!)
    ```sh
    For Unix/MacOS:
    chmod a+x project1
    ./project1
    For Windows:
    project1
    ```

### Alternatives

If you are unable to compile or run the program on your system for some reason, you can use an online IDE such as [Replit](https://replit.com/) to run our project, as we have tested it on that platform and it is able to run our program.
    
