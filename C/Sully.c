#include <stdio.h>
#include <stdlib.h>

#define CONTENT "#include <stdio.h>%c#include <stdlib.h>%c%c#define CONTENT %c%s%c%c%cint is_root(void) {%c%cint len = 0;%c%cwhile (__FILE__[len] != '%c0')%c%c%clen++;%c%c%cwhile (len >= 0) {%c%c%cif (__FILE__[len] == '/') return 0;%c%c%cif (__FILE__[len] == '_') return 1;%c%c%clen--;%c%c}%c%c%creturn 0;%c}%c%cvoid write_child(int nbr) {%c%cchar buffer[10];%c%csnprintf(buffer, 10, %cSully_%%d.c%c, nbr);%c%c%cFILE *file = fopen(buffer, %cw%c);%c%cif (!file) exit(1);%c%cfprintf(file, CONTENT, 10, 10, 10, 34, CONTENT, 34, 10, 10, 10, 9, 10, 9, 92, 10, 9, 9, 10, 10, 9, 10, 9, 9, 10, 9, 9, 10, 9, 9, 10, 9, 10, 10, 9, 10, 10, 10, 10, 9, 10, 9, 34, 34, 10, 10, 9, 34, 34, 10, 9, 10, 9, 10, 9, 10, 10, 10, 10, 9, 10, 10, 9, 10, 9, 9, 10, 9, 10, 9, 34, 34, 10, 9, 10, 9, 9, 10, 10, 9, 10, 9, 9, 10, 10, 9, 10, 9, 9, 10, 9, 10, 9, 34, 34, 10, 9, 10, 9, 9, 10, 10, 10, 10, 9, nbr, 10, 10, 9, 10, 9, 9, 10, 10, 9, 10, 9, 9, 10, 10, 9, 10, 9, 10, 10, 9, 10, 10);%c%cfclose(file);%c}%c%cvoid compile_run_child(int nbr) {%c%cchar buffer[24];%c%c%c/*%c%c%ccompile%c%c*/%c%csnprintf(buffer, 24, %ccc Sully_%%d.c -o Sully_%%d%c, nbr, nbr);%c%cif (system(buffer) != 0)%c%c%cexit(1);%c%c%cif (nbr <= 0)%c%c%creturn;%c%c%c/*%c%c%crun%c%c*/%c%csnprintf(buffer, 24, %c./Sully_%%d%c, nbr);%c%cif (system(buffer) != 0)%c%c%cexit(1);%c}%c%cint main(void) {%c%cint nbr = %d;%c%c%cif (nbr < 0)%c%c%creturn 0;%c%c%cif (is_root() == 1)%c%c%cnbr--;%c%c%cwrite_child(nbr);%c%ccompile_run_child(nbr);%c%c%creturn (0);%c}%c"

int is_root(void) {
	int len = 0;
	while (__FILE__[len] != '\0')
		len++;

	while (len >= 0) {
		if (__FILE__[len] == '/') return 0;
		if (__FILE__[len] == '_') return 1;
		len--;
	}

	return 0;
}

void write_child(int nbr) {
	char buffer[10];
	snprintf(buffer, 10, "Sully_%d.c", nbr);

	FILE *file = fopen(buffer, "w");
	if (!file) exit(1);
	fprintf(file, CONTENT, 10, 10, 10, 34, CONTENT, 34, 10, 10, 10, 9, 10, 9, 92, 10, 9, 9, 10, 10, 9, 10, 9, 9, 10, 9, 9, 10, 9, 9, 10, 9, 10, 10, 9, 10, 10, 10, 10, 9, 10, 9, 34, 34, 10, 10, 9, 34, 34, 10, 9, 10, 9, 10, 9, 10, 10, 10, 10, 9, 10, 10, 9, 10, 9, 9, 10, 9, 10, 9, 34, 34, 10, 9, 10, 9, 9, 10, 10, 9, 10, 9, 9, 10, 10, 9, 10, 9, 9, 10, 9, 10, 9, 34, 34, 10, 9, 10, 9, 9, 10, 10, 10, 10, 9, nbr, 10, 10, 9, 10, 9, 9, 10, 10, 9, 10, 9, 9, 10, 10, 9, 10, 9, 10, 10, 9, 10, 10);
	fclose(file);
}

void compile_run_child(int nbr) {
	char buffer[24];

	/*
		compile
	*/
	snprintf(buffer, 24, "cc Sully_%d.c -o Sully_%d", nbr, nbr);
	if (system(buffer) != 0)
		exit(1);

	if (nbr <= 0)
		return;

	/*
		run
	*/
	snprintf(buffer, 24, "./Sully_%d", nbr);
	if (system(buffer) != 0)
		exit(1);
}

int main(void) {
	int nbr = 5;

	if (nbr < 0)
		return 0;

	if (is_root() == 1)
		nbr--;

	write_child(nbr);
	compile_run_child(nbr);

	return (0);
}
