#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

unsigned fact(unsigned);
unsigned fib(unsigned);
unsigned mult(unsigned, unsigned);
unsigned power(unsigned, unsigned);
unsigned product(unsigned, unsigned);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls various recursive functions that can be
 * optimized using tail recursion.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

unsigned factWorker(unsigned n, unsigned acc);
unsigned fibWorker(unsigned n, unsigned a, unsigned b);
unsigned multWorker(unsigned x, unsigned y, unsigned acc);
unsigned powerWorker(unsigned x, unsigned y, unsigned acc);
unsigned productWorker(unsigned x, unsigned y, unsigned res);
int main() {
    // try a ridiculous case that won't work without tail recursion
    cout << "6 * 123000 = " << mult(6, 123000) << endl;
    
    // these functions can't demonstrate the usefulness of tail recursion
    // due to data type overflow, but still, good practice
    cout << "3 ^ 10 = " << power(3, 10) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15) << endl;
    cout << "10! = " << fact(10) << endl;

    // without tail recursion, this next call is going to take a while
    cout << "50th Fibonacci number is " << fib(50) << endl;

    // terminate
    return 0;
}

/*******************************************************************************
 * Function definitions below are NOT tail recursive!
 * TODO: make them tail recursive :)
*******************************************************************************/

unsigned factWorker(unsigned n, unsigned res) {
    // base cases (combined)
    if (n <= 1) {
        return res;
    }
        return factWorker(n - 1, res* n);
    }
    unsigned fact (unsigned n) {
        return factWorker(n, 1);
}  

unsigned fibWorker(unsigned n, unsigned a, unsigned b) {
    // base case 1
    if (n == 0) {
        return a;
    }

    // base case 2
    else if (n == 1) {
        return b;
    }
        return fibWorker(n -1, b, a + b);
    }
    unsigned fib(unsigned n) {
        return fibWorker(n, 0, 1);
}

unsigned multWorker(unsigned x, unsigned y, unsigned res) {
    // base case
    if (y == 0) {
        return res;
    }
        return multWorker(x, y - 1, res + x);
    }
    unsigned mult(unsigned x, unsigned y) {
        if (y < x){
            return multWorker(x, y, 0);
        } else {
            return multWorker(y, x, 0);
    }
}

unsigned powerWorker(unsigned x, unsigned y, unsigned res) {
    // base case
    if (y == 0) {
        return res;
    }
        return powerWorker(x, y - 1, res* x);
    }
    unsigned power(unsigned x, unsigned y) {
    return powerWorker(x, y, 1);
}

unsigned productWorker(unsigned x, unsigned y, unsigned res) {
    // base case
    if (x > y) {
        return res;
    }
    return productWorker(x + 1, y, res* x);
    }
    unsigned product(unsigned x, unsigned y) {
        return productWorker(x, y, 1);
}
