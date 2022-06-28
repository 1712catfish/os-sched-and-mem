#!/bin/bash
echo "Input file:"
cat input.txt
echo "Results"
gcc -Wall -g sched.c queue.c -o sched -lpthread
cat input.txt | ./sched
