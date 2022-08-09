all: shell run

shell: parse.c history.c shellFormatting.c shell.c
		gcc parse.c history.c shellFormatting.c shell.c -g -o shell

run: shell
		./shell

clean:
		rm shell
