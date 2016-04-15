CC = gcc
LIBS = -lfl	# Flex library
#LIBS = -ll	# 
LEX = flex	# -l turns on maximum compatibility with the original 
                # AT&T lex implementation. Note that this does not 
                # mean full compatibility. Use of this option costs
                # a considerable amount of performance,

CFLAGS = -g -std=gnu99
RPATH = -Wl,-rpath=/usr/local/lib
YACC = byacc -d -v -t # byacc for cygwin

project: project.tab.o project.yy.o 
	${CC} -o project project.tab.o project.yy.o ${LIBS} $(CFLAGS) ${RPATH}

project.tab.o: project.tab.h
project.yy.o: project.tab.h ast.h

project.tab.c project.tab.h: project.y
	${YACC} -o project.tab.c project.y

project.yy.c: project.l ast.h
	${LEX} -o project.yy.c project.l

.PHONY: clean
clean: 
	rm -f *.yy.c *.tab.c
	rm -f *.tab.h
	rm -f *.o
	rm -f project
