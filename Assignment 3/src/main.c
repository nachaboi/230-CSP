#include <stdlib.h>
#include "count-strings.h"

int main (int argc, char * argv[]) {
  if (argc < 2) {
    printf("Usage: %s file s1 s2 s3 ...\n", argv[0]);
    printf("  Reads text from file and counts how many times\n");
    printf("  each string s1, s2, etc., occurs in that file.\n");
    printf("  The program will consider up to 50 strings to search for;\n");
    printf("  any more than that wll be ignored.  Matches must be exact,\n");
    printf("  including upper/lower case. Lines read from the input\n");
    printf("  are expected to be no more than %d characters long.\n", LINE_MAX_CHARS);
    printf("Example output:\n");
    printf("  If the invocation is \"%s my friend flicka\"\n", argv[0]);
    printf("  the output may look like:\n");
    printf("my: 17\n");
    printf("friend: 0\n");
    printf("flicka: 4\n");
    return 1;
  }

  char *filename = argv[1];

  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Could not open file %s\n.", filename);
    exit(1);
  }

  int n = argc - 2;
  if (n > MAX_STRINGS) {
    n = MAX_STRINGS;
  }

  Entry entries[MAX_STRINGS];
  char **strings = argv+2;
  prepare_table(n, strings, entries);
  count_occurrences(n, file, entries);
  print_occurrences(n, entries);
}
