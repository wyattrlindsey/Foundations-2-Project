CC=gcc
LD=ld
WARNS=-Wall -pedantic -Wextra
CFLAGS=-g3 -std=gnu11 ${WARNS}
LIBS=-lpthread -lrt 


all: tags project 


tags: 
	ctags -R .

project: test.o insert.o search.o tree.o
	${CC} -g -o $@ $^ ${LIBS}

test.o: test.c
	${CC} -g -c $<

insert.o: insert.c
	${CC} -g -c $<

search.o: search.c
	${CC} -g -c $<

tree.o: tree.c
	${CC} -g -c $<

# This is our master compiler rule to generate .o files.
#It needs all 4 warnings (see WARNS variable defined above)
%.o:%.c *.h
	${CC} ${CFLAGS} -c $< -o $@