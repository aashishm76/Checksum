// Checksum Program
// Aashish Madamanchi

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_CHARACTERS 512

// Helper functions
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

  fclose(inputFile);
  return text;
}



// Main Functions
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
  }

  // Checksum calculation
  finalresult = letter % (256);

  // Close file and return out of function
  fclose(inputFile);
  return finalresult;
}

int checksum16(char *inputArray, int numChars)
{
  int i = 0, numLetters;
  unsigned int let1, let2;
  unsigned int finalresult;

  // Padding check
  numLetters = numChars;
  if (numLetters % 2 != 0)
  {
    while(inputArray[i] != '\0')
      i++;

    // Pad with capital X
    inputArray[i] = 'X';
    numLetters++;
  }

  // Print out to screen the original array (w/ padding if necessary)
  printf("\n%s\n", inputArray);

  // Checksum Algo
  for(i = 0; i < numLetters; i+=2)
  {
    finalresult += ((inputArray[i] << 8) + inputArray[i+1]);
  }

  finalresult = finalresult % 65536;
  return finalresult;
}

int checksum32(char *inputArray, int numChars)
{
  unsigned int finalResult = 0;
  int numLetters = numChars;

  for(int i = 0; i < numLetters; i += 4)
  {
    if(i + 3 == numLetters){
      finalResult += (inputArray[i] << 24) + (inputArray[i + 1] << 16) + (inputArray[i + 2] << 8) + 'X';
      numLetters++;
      printf("X");
    } // end if
    else if(i + 2 == numLetters){
      finalResult += (inputArray[i] << 24) + (inputArray[i + 1] << 16) + ('X' << 8) + 'X';
      numLetters += 2;
      printf("XX");
    } // end else if
    else if(i + 1 == numLetters){
      finalResult += (inputArray[i] << 24) + ('X' << 16) + ('X' << 8) + 'X';
      numLetters += 3;
      printf("XXX");
    }
    else{
      finalResult += (inputArray[i] << 24) + (inputArray[i + 1] << 16) + (inputArray[i + 2] << 8) + inputArray[i + 3];
    }
  }

  finalResult = finalResult % 4294967296;
  return finalResult;
}


// Main Program
int main(int argc, char const *argv[])
{
  char *inputFile, *fileHandlerOutput;
  const char *checksumVal;
  int charCount = 0, checksumNum;

  // Capture input arguments
  inputFile = malloc(sizeof(char) * strlen(argv[1]));
  checksumVal = malloc(sizeof(int) * strlen(argv[2]));

  inputFile = argv[1];
  checksumVal = argv[2];

  // Convert the string to a number
  checksumNum = atoi(checksumVal);

  fileHandlerOutput = malloc(sizeof(char) * MAX_CHARACTERS);

  // Check if the argument value passed in is either 8, 16, 32 bits
  if(checksumNum == 8)
  {
    unsigned int result;
    charCount = characterCounter(inputFile);
    result = checksum8(inputFile);
    fileHandlerOutput = fileHandler(inputFile);
    printf("%s\n", fileHandlerOutput);
    printf("\n8 bit checksum is %x for all %4d characters\n", result, charCount);
  }
  else if (checksumNum == 16)
  {
    unsigned int result16;
    charCount = characterCounter(inputFile);
    fileHandlerOutput = fileHandler(inputFile);
    result16 = checksum16(fileHandlerOutput, charCount);
    printf("\n16 bit checksum is %x for all %4d characters\n", result16, charCount);
  }
  else if (checksumNum = 32)
  {
    unsigned int result32;
    charCount = characterCounter(inputFile);
    fileHandlerOutput = fileHandler(inputFile);
    result32 = checksum32(fileHandlerOutput, charCount);
    printf("\n32 bit checksum is %x of all %4d characters\n", result32, charCount);
  }
  else {
    printf("Valid checksum sizes are 8, 16, or 32\n");
  }

  return 0;
}
