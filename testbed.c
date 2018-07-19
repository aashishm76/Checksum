// Testbed for your code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checksum8(char *file)
{
  int c, counter = 0;
  unsigned int letter = 0;
  int finalresult;

  // Open the file and read it here
  FILE *inputFile = NULL;
  inputFile = fopen(file, "r");

  // Loop through file
  while((c = fgetc(inputFile)) != EOF)
  {
    letter = c + letter;
    counter++;
  }

  printf("There's %d characters in the file", counter);
  printf("letter value: %d\n", letter);
  finalresult = letter % 256;

  // Close file and return out of function
  fclose(inputFile);

  return finalresult;
}

int characterCounter(char *file)
{
  int c, counter = 0;

  FILE *inputFile = NULL;
  inputFile = fopen(file, "r");

  while((c = fgetc(inputFile)) != EOF)
  {
    counter++;
  }

  return counter;
}


int main(int argc, char const *argv[])
{
  char *inputFile;
  const char *checksumVal;
  int charCount;

  // Capture input arguments
  inputFile = malloc(sizeof(char) * strlen(argv[1]));
  checksumVal = malloc(sizeof(int) * strlen(argv[2]));

  inputFile = argv[1];
  checksumVal = argv[2];

  if(checksumVal[0] == '8')
  {
    printf("ENTERED 8 BIT CHECKSUM\n");
    unsigned int result;
    charCount = characterCounter(inputFile);
    result = checksum8(inputFile);
    printf("Result: %x with %d characters\n", result, charCount);
  }
  else{
    return 0;
  }

  return 0;
}
