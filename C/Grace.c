// todo insert something funny
#include <stdio.h>
#define CONTENT "// todo insert something funny%c#include <stdio.h>%c#define CONTENT %c%s%c%c#define WRITE(file) fprintf(file, CONTENT, 10, 10, 34, CONTENT, 34, 10, 10, 34, 34, 34, 34, 10, 10)%c#define MAIN() int main(void) { FILE *file = fopen(%cGrace_kid.s%c, %cw%c); if (!file) return 1; WRITE(file); fclose(file); return 0; }%cMAIN()%c"
#define WRITE(file) fprintf(file, CONTENT, 10, 10, 34, CONTENT, 34, 10, 10, 34, 34, 34, 34, 10, 10)
#define MAIN() int main(void) { FILE *file = fopen("Grace_kid.s", "w"); if (!file) return 1; WRITE(file); fclose(file); return 0; }
MAIN()
