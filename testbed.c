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

char *fileHandler(char *file)
{
  int i = 0;
  char letter;
  char *text;

  FILE *inputFile = NULL;
  inputFile = fopen(file, "r");
  text = malloc(sizeof(char) * 512);

  while(1)
  {
    letter = fgetc(inputFile);
    text[i++] = letter;
    if (feof(inputFile))
      break;
  }

  printf("Text is: %s\n", text);
  fclose(inputFile);
  return text;
}

int main(int argc, char const *argv[])
{
  char *inputFile, *fileHandlerOutput;
  const char *checksumVal;
  int charCount, checksumNum;

  // Capture input arguments
  inputFile = malloc(sizeof(char) * strlen(argv[1]));
  checksumVal = malloc(sizeof(int) * strlen(argv[2]));

  inputFile = argv[1];
  checksumVal = argv[2];

  // Convert the string to a Number
  checksumNum = atoi(checksumVal);
  printf("%d\n", checksumNum);

  if(checksumNum == 8)
  {
    printf("ENTERED 8 BIT CHECKSUM\n");
    fileHandlerOutput = fileHandler(inputFile);
    printf("FileHandlerOutput Function: %s\n", fileHandlerOutput);
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
