NAME: 	    Kevin Terceros
STUDENT ID: 5078969
COURSE:     CS3790
PROJECT:    Lab 5

# Banker's Algorithm

## Contents of this file

  - Introduction
  - Project Creation
  - Program Execution
    - Constraints
  - User Input
  - Expected Output
  - Program Termination

## Introduction

This project is a somewhat bare-bones, hard-coded, minimalistic implementation the Banker's Algorithm - a testing
method for ensuring the safety of the system during the running of processes.

## Project Creation

The user shall create their project by entering "make" in the command line. This creates an executable under the
name "banker". To remove this file, the user shall enter "make clean" in the command line, which will then request
confirmation. Entering 'y' (upper- or lower- case) at this stage will cause the file to be deleted. Entering any
other key will cancel the deletion process and leave the file intact.

## Program Execution

The user shall execute this program through the command line by entering four arguments in the format
"./banker <num_processes> <num_rsrc_types>" in the command line.

- The value <num_processes> will be the number of processes that the user will run.

- The value <num_rsrc_types> will be the number of resource types that will run in each process.

The program was intended to process a file that would contain the above two arguments, as well as a MAX matrix and
an AVAILABLE vector. Unfortunately, the program does not have this functionality at this time.

### Constraints

- The user must enter exactly three arguments. If the user enters any other number of arguments, they will be met
  with a "Malformed request" error.

- The integer values entered as the second and thrid arguments must be values greater than 0. If the user enters a
  negative integer, they will be met with a "Malformed request" error.

- There is theoretically no upper limit as to the integer value that can be entered.

- While the program accepts any sort of input is as values for arguments 2 and 3 (provided it is not a negative
  integer), it is strongly recommended that the user enters integer values in those places. The developer cannot
  guarantee the outcome if the user enters a non-integer value.

## User Input

After entering these arguments, the user will be prompted to enter a process to run. This process must be a value
within the range of the total number of processes (minimum of 0, maximum of range minus 1).

- If the user enters a value of -1, the program will terminate early

- If the user enters a value outside of this range, they will be met with a "Invalid request" message.

- If the user enters a value for a process that has already been completed, they will be notified that the process
  has already been complete.

The program was intended to allow the user to enter their own Request vector. Unfortunately, this feature has not
been implemented, and this value is currently hard-coded. This value also remains unused in the program.

## Expected Output

Upon entering a value for process, the user will see the following in this order:

- Request vector, seeming to ask for input, but with input already built-in.

- Work vector prior to running the program

- Request acceptance - this message states if a request was accepted or denied, depending on the state in which
  running this request would leave the system.

- If request was accepted, the value of the work matrix after running the process.

- Max matrix

- Allocation matrix

- Need matrix

- Available matrix

- A boolean matrix indicating what processes have been completed.

## Program Termination

The program terminates when all processes have been complete, OR the user enters a process value of -1.