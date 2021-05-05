SHELL = /bin/bash
CC = g++
CFLAGS = -g -Wall -fpermissive
SRC = $(wildcard *.c)
EXE = $(patsubst %.c, %, $(SRC))

all: $(EXE)

%: %.c %.h main.c
	${CC} ${CFLAGS} $@.c -o $@

.PHONY: clean

clean: 
	rm ${EXE}

