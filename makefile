COMPILER=cc
CONF=-o brainfuck

compile:
	$(COMPILER) $(CONF) main.c

test: compile
	./brainfuck src/thanks.bf
