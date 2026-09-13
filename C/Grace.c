/*
	todo insert something funny
*/
#include <stdio.h>
#define CONTENT "/*%1$c%2$ctodo insert something funny%1$c*/%1$c#include <stdio.h>%1$c#define CONTENT %3$c%4$s%3$c%1$c#define WRITE(file) fprintf(file, CONTENT, 10, 9, 34, CONTENT)%1$c#define MAIN() int main(void) { FILE *file = fopen(%3$cGrace_kid.c%3$c, %3$cw%3$c); if (!file) return 1; WRITE(file); fclose(file); return 0; }%1$cMAIN()%1$c"
#define WRITE(file) fprintf(file, CONTENT, 10, 9, 34, CONTENT)
#define MAIN() int main(void) { FILE *file = fopen("Grace_kid.c", "w"); if (!file) return 1; WRITE(file); fclose(file); return 0; }
MAIN()
