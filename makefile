compile runme: fork.o
	@gcc -o fork fork.o -lm
fork.o: fork.c
	@gcc -c fork.c -lm
run: fork
	@./fork
clean:
	@rm -f *.o
	@rm -f fork
