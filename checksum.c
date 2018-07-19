// Checksum Program
// Aashish Madamanchi

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Helper functions

int checksum8(char *file)
{
  int c;
  unsigned int letter = 0;
  unsigned int finalresult;

  // Open the file and read it here
  FILE *inputFile = NULL;
  inputFile = fopen(file, "r");

  // Loop through file
  while((c = fgetc(inputFile)) != EOF)
  {
    letter = c + letter;
    printf("%u\n", letter);
  }

  finalresult = letter % (2^8);

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



// Main Program
int main(int argc, char const *argv[])
{
  char *inputFile;
  const char *checksumVal;
  int charCount = 0;

  // Capture input arguments
  inputFile = malloc(sizeof(char) * strlen(argv[1]));
  checksumVal = malloc(sizeof(int) * strlen(argv[2]));

  inputFile = argv[1];
  checksumVal = argv[2];

  printf("File Name: %s\n", inputFile);
  printf("Checksum Number: %s\n", checksumVal);

  // Check if the argument value passed in is either 8, 16, 32 bits
  if(checksumVal[0] == '8')
  {
    printf("ENTERED 8 BIT CHECKSUM\n");
    unsigned int result;
    charCount = characterCounter(inputFile);
    result = checksum8(inputFile);
    printf("8 bit checksum is %x for all %d characters\n", result, charCount);
  }
  else if (checksumVal[0] == '1' && checksumVal[1] == '6')
  {
    //
  }
  else if (checksumVal[0] == '3' && checksumVal[1] == '2')
  {
    // Run the checksum 32 function
  }
  else {
    printf("Valid checksum sizes are 8, 16, or 32\n");
  }

  return 0;
}
