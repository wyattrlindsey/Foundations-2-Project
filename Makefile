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

final.zip: makefile *.h *.c *.s *.o peformance_analysis_insert.txt peformance_analysis.txt README
	# zips all required files
	zip $@ $^ 

	# self-test is required: first remove old install folder
	rm -rf install
	# create the install folder
	mkdir install
	# unzip the install folder
	unzip final.zip -d install

	# make all the other things that get graded too (never the zip!) examples below

	# LOOK FOR ERRORS BELOW here
	make -C install -r tags
	make -C install -r project

	# LOOK FOR BUILD ERRORS ABOVE HERE
	install/tags
	install/project

	# Finally: remove install folder so we don't accidently use it
	rm -rf install