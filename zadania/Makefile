# In particular, the macro CC is the C compiler to use, 
# and CFLAGS is the list of flags to pass to the compilation command.

CC=g++
CFLAGS=-I.
OBJ = zadanie1 zadanie2 zadanie3 zadanie4 zadanie5 zadanie6

# the special macros $@ and $^ are the left and right sides of the :
zadanie: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean: 
	rm zadanie1 zadanie2 zadanie3 zadanie4 zadanie5 zadanie6
