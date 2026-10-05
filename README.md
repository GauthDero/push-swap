*This project has been created as part of the 42 curriculum by gdero*

# push_swap

## Description

push_swap is an algorithmic project from the 42 curriculum. The goal is to sort a stack of
random integers using a second, empty stack and a limited set of operations, while minimizing
the total number of moves. The project emphasizes algorithmic thinking, complexity analysis,
and choosing the right data structure for the job.

## How it works

- Numbers are pushed onto stack A in random order.
- Only a restricted set of operations is allowed: swap, push, rotate, and reverse rotate
  (applied to either stack).
- The program outputs a sequence of operations to fully sort stack A using radix sort.
  

## Usage

```bash
make
./push_swap "4 67 3 87 23" | ./checker "4 67 3 87 23"
```
