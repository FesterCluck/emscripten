#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Reading

  FILE *file = fopen("somefile.binary", "rb");
  assert(file);

  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  rewind (file);
  printf("size: %d\n", size);

  char *buffer = (char*) malloc (sizeof(char)*size);
  assert(buffer);

  size_t read = fread(buffer, 1, size, file);
  assert(read == size);

  printf("data: %d", buffer[0]);
  for (int i = 1; i < size; i++)
    printf(",%d", buffer[i]);
  printf("\n");

  fclose (file);
  free (buffer);

  // Standard streams

  fwrite("texto\n", 1, 6, stdout);
  fwrite("texte\n", 1, 6, stderr);

  // Writing

  char data[5] = { 10, 30, 20, 11, 88 };
  FILE *outf = fopen("go.out", "wb");
  fwrite(data, 1, 5, outf);
  fclose(outf);

  char data2[10];
  FILE *inf = fopen("go.out", "rb");
  int num = fread(data2, 1, 10, inf);
  fclose(inf);
  printf("%d : %d,%d,%d,%d,%d\n", num, data2[0], data2[1], data2[2], data2[3], data2[4]);

  return 0;
}

