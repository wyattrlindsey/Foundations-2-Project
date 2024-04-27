CFLAGS= -std=c99 -pedantic -Wformat -Wreturn-type 
all:  tags project

tags: *.c *.o *.h
	ctags -R .

#####################################################################

project: search.o insert.o test.o tree.o
	gcc -g -m64 -o $@ $^

#####################################################################

# this is our master compiler rule to generate .o files.
# It needs all 4 warnings

%.o:%.c *.h
	gcc $(CFLAGS) -g -c $< -o $@