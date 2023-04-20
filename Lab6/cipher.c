#include <stdio.h>
#include "lcg.h"

#define FILL_M 0  /*when to convert m to number*/
#define FILL_C 1  /*when to convert c to number*/
#define FILL_DATA 2  /*when to work with the data*/
#define ENCRYPT 1  /*when to encrypt*/
#define DECRYPT 2  /*when to decrypt*/

int encryptData(unsigned long m, unsigned long c, int ch, unsigned long x) {
  int out = ch ^ (x % 128);

  if (m == 0 || c == 0) {
    printf("Error");
    return 1;
  }

  if (out < 32) {
    printf("*%c", ('?' + out));
  }
  else if (out == 127) {
    printf("*!");
  }
  else if (out == '*') {
    printf("**");
  }
  else {
    printf("%c", out);
  }

  return 0;
}

int decryptData(unsigned long m, unsigned long c, int ch, unsigned long x) {
  int out = ch ^ (x % 128);

  if (m == 0 || c == 0) {
    printf("Error");
    return 1;
  }

  if (ch == '*') {
    ch = getchar();

    if (ch == '*') {
      out = ch ^ (x % 128);
      printf("%c", out);
    }
    else if (ch == '!') {
      out = 127 ^ (x % 128);
      printf("%c", out);
    }
    else if (ch > 32 && ch < 127) {
      out = (ch - '?') ^ (x % 128);
      printf("%c", out);
    }
    else if (ch == 32) {
      printf("Error");
      return 1;
    }
  }
  else {
    printf("%c", out);
  }

  return 0;
}

int main() {
  int c, currentPos, action, linenum, error;
  unsigned long m, ci, random;
  currentPos = action = error = 0;
  m = ci = random = 0; 
  linenum = 1;

  FILE* infile = fopen("cipherdata.in", "r");
  FILE* outfile = fopen("cipherdata.out", "w");

  while ((c = fgetc(infile)) != EOF) {
    if (currentPos == FILL_M && c == 'e') action = ENCRYPT;
    else if (currentPos == FILL_M && c == 'd') action = DECRYPT;

    if (c != ',' && c != '\n') {
      if (currentPos == FILL_M && c >= '0' && c <= '9') {
        m = 10 * m + (c - '0');
      }
      else if (currentPos == FILL_C && c >= '0' && c <= '9') {
        ci = 10 * ci + (c - '0');
      }
      else if (currentPos == FILL_DATA) {
        if (action == ENCRYPT) {
          struct LinearCongruentialGenerator a;
          a = makeLCG(m, ci);

          
          fprintf(outfile, "%5d) ", linenum);

          linenum++;

          if (a.m == 0) {
            
            fprintf(outfile, "Error");

        while ((c = fgetc(infile)) != '\n');

        continue;
      }
      else {
        random = getNextRandomValue(&a);

        while (c != '\n' && error == 0) {
          error = encryptData(m, ci, c, random);

          c = fgetc(infile);
          random = getNextRandomValue(&a);
        }
      }

      
      fprintf(outfile, "\n");
    }
    else if (action == DECRYPT) {
      struct LinearCongruentialGenerator b;
      b = makeLCG(m, ci);

      
      fprintf(outfile, "%5d) ", linenum);

      linenum++;

      if (b.m == 0) {
        
        fprintf(outfile, "Error");

        while ((c = fgetc(infile)) != '\n');

        continue;
      }
      else {
        random = getNextRandomValue(&b);

        while (c != '\n' && error == 0) {
          error = decryptData(m, ci, c, random);

          c = fgetc(infile);
          random = getNextRandomValue(&b);
        }
      }

    
      fprintf(outfile, "\n");
    }
    else {
      
      fprintf(outfile, "%5d) ", linenum);

      linenum++;

      
      fprintf(outfile, "Error\n");
    }

    m = ci = 0;
    currentPos = FILL_M;
    action = error = 0;
  }
}

if (c == ',') {
  if (currentPos == FILL_M) currentPos = FILL_C;
  else if (currentPos == FILL_C) currentPos = FILL_DATA;
}

if (c == '\n' && currentPos != FILL_M) {
  
  fprintf(outfile, "%5d) ", linenum);

  linenum++;

  
  fprintf(outfile, "Error\n");

  m = ci = 0;
  currentPos = FILL_M;
  action = 0;
}
}

fclose(infile);
fclose(outfile);

return 0;
}