# In particular, the macro CC is the C compiler to use, 
# and CFLAGS is the list of flags to pass to the compilation command.

CC=gcc
CFLAGS=-I.
DEPS = functions.h
OBJ = zadanie1.o functions.o

# A rule that applies to all files ending in the .o suffix. 
# The rule says that the .o file depends upon the .c version of the file and the .h files included in the DEPS macro. 
# The rule then says that to generate the .o file, make needs to compile the .c file using the compiler defined in the CC macro. 
# The -c flag says to generate the object file, the -o $@ says to put the output of the compilation in the file named on the left side of the :, the $< is the first item in the dependencies list, and the CFLAGS macro is defined as above.
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# the special macros $@ and $^ are the left and right sides of the :
zadanie1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean: 
	rm zadanie1 *.o
