/*Title: cryptojka
 *Descripton: cryptation character by character
 *Autor: José Luis Garrido Labrador (JoseluCross) and Kevin Puertas Ruiz (Kprkpr)
 *Version: 0.4.1 - mar/16
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "methods.c"

#define MAX_TEXT 1048576
#define MAX_PASS 64

int     clean_stdin(void);
void    crypt(char[], char[], bool, char[]);
int     length(char[]);

int main(int argc, char *argv[]) {
  bool    state;		//false when encrypt, true when decrypt
  bool    ran = true;		//false: not random generation, true: random generation
  bool    fil;			//false: not file, true, with file
  bool    cond = false;		//If false = not argument
  int     cant = 0;		//number of characters in random generation
  char    text[MAX_TEXT] = "text";	//imput character
  char    pass[MAX_PASS] = "pass";	//Imput pass
  FILE   *in;			//Input file
  char    out[35] = "crypt.out";	//output file

  //Flags options
  int     i;
  for(i = 0; i < argc; i++) {
    if(strcmp(argv[i], "-e") == 0) {
      state = false;
      cond = true;
    } else if(strcmp(argv[i], "-d") == 0) {
      state = true;
      cond = true;
    } else if(strcmp(argv[i], "-f") == 0) {
      in = fopen(argv[i + 1], "r");
      fil = true;
      cond = true;
    } else if(strcmp(argv[i], "-o") == 0) {
      strcpy(out, argv[i + 1]);
      cond = true;
    } else if(strcmp(argv[i], "-p") == 0) {
      strcpy(pass, argv[i + 1]);
      cond = true;
    } else if(strcmp(argv[i], "-t") == 0) {
      strcpy(text, argv[i + 1]);
      fil = false;
      cond = true;
    } else if(strcmp(argv[i], "-r") == 0) {
      ran = true;
      cant = atoi(argv[i + 1]);
      cond = true;
    } else if(strcmp(argv[i], "-h") == 0) {
      helpbox();		//In methods.c
      return 0;
    }
  }

  if(cond == false) {
    printf("No option specified\n");
    helpbox();
    return 0;
  }

  if(state == false) {
    if(fil == false) {
      crypt(pass, text, false, out);
    } else {
      for(i = 0; feof(in) == 0; i++) {
	text[i] = fgetc(in);
      }
      for(i = 0; i < length(text); i++) {
	if(text[i] == '\n') {
	  text[i] = ' ';
	}
      }
      crypt(pass, text, false, out);
    }
    if(ran == true) {
      rangen(cant, out);	//In methods.c
    }
  } else {
    if(fil == false) {
      crypt(pass, text, true, out);
    } else {
      for(i = 0; feof(in) == 0; i++) {
	text[i] = fgetc(in);
      }
      for(i = 0; i < length(text); i++) {
	if(text[i] == '\n') {
	  text[i] = ' ';
	}
      }
      crypt(pass, text, true, out);
    }
  }

  printf("\n");
  showFile(out, MAX_TEXT);

  return 0;
}

/*
 *Title: crypt
 *Description: It de/encrypt strings
 *@param pass[]: string which we use like password
 *@param text[]: string which we will encrypt
 *@param x: false = encrypt, true = decrypt
 *@param name[]: name of output
 *@return text_length: text length
 */
void crypt(char pass[], char text[], bool x, char name[]) {
  int     pass_length;
  int     text_length;
  int     passPosition = 0;	//Relative position in pass[]
  int     textPosition = 0;	//Relative position in text[]
  pass_length = length(pass);
  text_length = length(text);
  int     sol;			//output character

  FILE   *nom;

  nom = fopen(name, "w");

  for(textPosition = 0; textPosition < text_length; textPosition++) {
    if(passPosition == pass_length) {
      passPosition = 0;
    }
    if(x == false) {
      sol = text[textPosition] + pass[passPosition];
      while(sol > 126) {
	sol -= 94;
      }
    } else {
      sol = text[textPosition] - pass[passPosition];
      while(sol < 32) {
	sol += 94;
      }
    }
    passPosition++;
    fputc(sol, nom);
  }
  fclose(nom);
}

/*
 *Title: length
 *Description: It count logic string length
 *@param l[]: string
 *@return m: lenght
 */
int length(char l[]) {
  int     m = 0;
  while(l[m] != '\0') {
    m++;
  }
  return m;
}
