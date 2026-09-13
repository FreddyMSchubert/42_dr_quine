#include <stdio.h>

/*
	comment outside of main
*/

void another_function_in_addition_to_main(void)
{
	char *content = "#include <stdio.h>%1$c%1$c/*%1$c%2$ccomment outside of main%1$c*/%1$c%1$cvoid another_function_in_addition_to_main(void)%1$c{%1$c%2$cchar *content = %3$c%4$s%3$c;%1$c%2$cprintf(content, 10, 9, 34, content);%1$c}%1$c%1$cint main(void)%1$c{%1$c%2$c/*%1$c%2$c%2$cWie heisst der Bürgermeister von Wesel? (Esel)%1$c%2$c*/%1$c%2$canother_function_in_addition_to_main();%1$c%2$creturn (0);%1$c}%1$c";
	printf(content, 10, 9, 34, content);
}

int main(void)
{
	/*
		Wie heisst der Bürgermeister von Wesel? (Esel)
	*/
	another_function_in_addition_to_main();
	return (0);
}
