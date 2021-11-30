COMPILER=gcc
CONF=-o brainfuck.out
COMPILE=$(COMPILER) $(CONF)

compile:
	$(COMPILE) src/brainfuck.c

test: compile
	./brainfuck.out src/thanks.bf
