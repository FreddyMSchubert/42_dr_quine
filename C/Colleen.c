#include <stdio.h>

// comment outside of main

void another_function_in_addition_to_main(void)
{
	char *content = "#include <stdio.h>%c%c// comment outside of main%c%cvoid another_function_in_addition_to_main(void)%c{%c%cchar *content = %c%s%c;%c%cprintf(content, 10, 10, 10, 10, 10, 10, 9, 34, content, 34, 10, 9, 10, 10, 10, 10, 10, 9, 10, 9, 10, 10);%c}%c%cint main(void)%c{%c%c// Wie heisst der Bürgermeister von Wesel? (Esel)%c%canother_function_in_addition_to_main();%c}%c";
	printf(content, 10, 10, 10, 10, 10, 10, 9, 34, content, 34, 10, 9, 10, 10, 10, 10, 10, 9, 10, 9, 10, 10);
}

int main(void)
{
	// Wie heisst der Bürgermeister von Wesel? (Esel)
	another_function_in_addition_to_main();
}
