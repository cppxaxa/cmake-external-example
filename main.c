#include <siphon/siphon.h>
#include <stdio.h>

int
main (int argc, char *argv[])
{
	const char p[] = "/some/path/to/file.txt";
	SpRange16 r = { 0, (sizeof p) - 1 };
	sp_path_pop (p, &r, 1);
	printf ("POP: %.*s\n", (int)r.len, p+r.off);
	return 0;
}

