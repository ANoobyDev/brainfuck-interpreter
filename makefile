COMPILER=gcc
CONF=-o brainfuck
COMPILE=$(COMPILER) $(CONF)

compile:
	$(COMPILE) src/brainfuck.c

test: compile
	./brainfuck src/thanks.bf
