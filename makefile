COMPILER=cc
CONF=-Os
NAME=-o brainfuck

compile:
	$(COMPILER) $(CONF) $(NAME) main.c

test: compile
	./brainfuck src/thanks.bf
