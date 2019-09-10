# CSC 415 - Project 4 - Thread Racing

## Student Name: Lidiya Jebessa

## Student ID :  917267252

## Build Instructions:  gcc -I -Wall pthread_race.c -o threadracer -pthread

## Run Instructions:  ./threadracer
## Sample output:
#### (base) lidiyas-MacBook-Pro:Desktop lidiyajebessa$ cd csc415-p4-ljebessa
#### (base) lidiyas-MacBook-Pro:csc415-p4-ljebessa lidiyajebessa$ ls
#### 415_HW4.pdf		Makefile		pthread_race.c
#### CMakeLists.txt		README.md		threadracer
#### LICENSE			cmake-build-debug
#### (base) lidiyas-MacBook-Pro:csc415-p4-ljebessa lidiyajebessa$ make
#### gcc -I -Wall pthread_race.c -o threadracer -pthread
#### (base) lidiyas-MacBook-Pro:csc415-p4-ljebessa lidiyajebessa$ ./threadracer
#### Current Value written to Global Variables by thread : 4 is 10
#### Current Value written to Global Variables by thread : 10 is -10
#### Current Value written to Global Variables by thread : 6 is 10
#### Current Value written to Global Variables by thread : 6 is 10

# Description:
The goal of the assignment is to create a group of threads and then try to coax them into
producing as many race conditions as possible.

# Implementation:
A single global variable was declared with initial value zero. Next thread
was spawned off the number of threads specified in the source file using the MAX_THREADS
defined constant in the pre-processor directives. Loop was used to create these threads.
The thread with even numbered iterations were designated as ADDER threads and the threads
on odd iterations as SUBTRACTOR threads.

# Adder Threads:
Adder threads execute following steps:
1. Read global shared value and store it into temporary variable
2. ADD 10 to the Temp_V value
3. Store Temp_V value into global variable
4. Print to the terminal:
    "Current Value written to Glboal Variables by ADDER thread"


# Subtractor Threads:
Subtractor threads execute following steps:
1. Read global shared value and store it into temporary variable
2. SUBTRACT 10 to the temp_V value
3. Store temp value into global variable
4. Print to the terminal:
    "Current Value written to Glboal Variables by SUBTRACTOR thread"

## Explain why your program produces the wrong output
