#
# This is an example Makefile for a countwords program.  This
# program uses both the scanner module and a counter module.
# Typing 'make' or 'make count' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = gcc
CFLAGS  = -g -Wall

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: wadsworth

# To create the executable file count we need the object files
# countwords.o, counter.o, and scanner.o:
#
wadsworth:  command.o main.o
	$(CC) $(CFLAGS) -o wadsworth command.o main.o

# To create the object file command.o, we need the source
# files command.c, command.h:
#
command.o:  command.c command.h 
	$(CC) $(CFLAGS) -c command.c

# To create the object file main.o, we need the source files
# main.c and main.h:
#
main.o:  main.c 
	$(CC) $(CFLAGS) -c main.c

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) wadsworth log.txt output.txt *.o *~

# To run valgrind in interactive mode, type 'make val-interactive'
# To run valgrind in file mode, type 'make val-file'
# Valgrind will run a leak check and store the
# results in log.txt
val-interactive: wadsworth
	valgrind --leak-check=full --tool=memcheck ./wadsworth > log.txt 2>&1

val-file: wadsworth
	valgrind --leak-check=full --tool=memcheck ./wadsworth -f input.txt > log.txt 2>&1
