COMPILER=cc
CONF=-o brainfuck
COMPILE=$(COMPILER) $(CONF)

compile:
	$(COMPILE) main.c

test: compile
	./brainfuck src/thanks.bf
