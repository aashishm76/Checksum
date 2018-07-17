// Checksum Program
// Aashish Madamanchi

#include<stdio.h>
#include<stdlib.h>

// Main Program
int main(int argc, char const *argv[])
{
  char *inputfile, *checksumVal;

  // Capture the name of the input args
  inputfile = malloc(sizeof(char) * strlen(argv[1]));
  checksumVal = malloc(sizeof(int) * strlen(argv[2]));

  // Check if the argument value passed in is either 8, 16, 32 bits
  if(checksumVal[1] == 8)
  {
    // Run the checksum 8 function
  }
  else if (checksumVal[1] == 16)
  {
    // Run the checksum 16 function
  }
  else if (checksumVal[1] == 32)
  {
    // Run the checksum 32 function
  }
  else {
    printf("Valid checksum sizes are 8, 16, or 32\n");
  }

  return 0;
}

int checksum8()
