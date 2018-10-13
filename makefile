files = main.c calcFun.c

main: $(files)
	gcc -o $@ $^

testmain: $(files)
	gcc -g $^ -o $@
