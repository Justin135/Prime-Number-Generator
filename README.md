# Prime-Number-Generator

This repository contains different implementations of finding prime numbers up to an upper limit. Below are the different approaches explained.

## 1. Basic factor looping

This implementation is usually the go-to algorithm for finding if a number is prime or composite. The code will loop through the numbers 2 to `num - 1` and check if each value is a factor of the original number. If so, it outputs false and exits the function. If not, then it skips to the next iteration.

The above algorithm is illustrated in *simplestMethods.py* as the `worst(num)` function. This is because this implementation is inefficient.

It is easy to make it more efficient by skipping all even numbers (except for 2) and only iterating up to `sqrt(num) + 1`. The reason we can do this is because of this:

- If 2 is a factor of `num`, then `num / 2` is a factor of `num`.
- Similarly, if 3 is a factor of `num`, then `num / 3` is a factor of `num`.
- Thus, there is no point in checking `num / 2` or `num / 3`.
- Note: For some large value of `num`, 2 < `num / 2` and 3 < `num / 3`. This saves iterations.
- However, if `num` is a perfect square, then we can say this factor (let's label it `factor`) is equal to `num / factor`.
- Thus, we can simply loop up to `sqrt(num) + 1)`.
- Note: It must include `sqrt(num)`, which is why it loops up to `sqrt(num) + 1`.

This implementation is illustrated in both *simplestMethods.py* and *listOfPrimes.py*. The file *simplestMethods.py* illustrates the time difference of the two algorithms, while the file *listOfPrimes.py* actually implements the efficient method to find and output the list of all prime numbers up to a million in a text file.

## 2. Sieve of Eratosthenes

This implementation uses a process of elimination to determine a list of prime numbers up to an upper limit. Here's how:

- Create an array of booleans that is the size of the upper limit called `primes`. True means the corresponding index is a prime number, while `false` means composite.
- Initialize the array so that all values are true (except for index 0 and 1).
- Take all known prime numbers `p` where p<sup>2</sup> <= the upper limit.
- Take the multiples of these prime numbers and set each corresponding index in `primes` to false.
- All remaining true values of `primes` will be prime numbers.

The time complexity of the Sieve of Eratosthenes is O(N log (log N)), which is incredibly efficient.

**Note:** this implementation is mainly dependent on RAM, so finding a list with a large upper limit will use an incredible amount of RAM. Python booleans use 24 bytes for some reason. That is why for this implementation, I use the C language since each bool is only one byte (as it should be).
