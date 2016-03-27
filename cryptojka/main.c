/*Title: cryptojka
 *Descripton: cryptation character by character
 *Autor: José Luis Garrido Labrador (JoseluCross) and Kevin Puertas Ruiz (Kprkpr)
 *Version: 0.2.1 - mar/16
 */
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <strings.h>

#include "rangen.c"

#define MAX_TEXT 1024
#define MAX_PASS 32

int     clean_stdin(void);
int     crypt(char[], char[], bool);
int     length(char[]);

int main() {
  int     mode = 2;
  bool    state;		//false when encrypt, true when desencrypt
  bool    ran;			//false: not random generation, true: random generation
  char    c;			//control character 
  char    text[MAX_TEXT];	//imput character
  char    pass[MAX_PASS];	//Imput pass

  //Mode menu
  do {
    printf("Choose, 0 = encrypt, 1 = decrypt: ");
    if(scanf("%d%c", &mode, &c) != 2 || c != '\n') {
      printf("Incorrect value\n");
      clean_stdin();
      mode = 2;
    }
  } while(mode != 0 && mode != 1);
  state = mode;
  //Random generation menu
  if(state == false) {
    mode = 2;
    do {
      printf
	  ("If you want generation of random text type 1, else type 0: ");
      if(scanf("%d%c", &mode, &c) != 2 || c != '\n') {
	printf("Incorrect option\n");
	clean_stdin();
	mode = 2;
      }
    } while(mode != 0 && mode != 1);
    ran = mode;
  }

  printf("Input text (only ASCII): ");
  fgets(text, MAX_TEXT, stdin);
  if(text[strlen(text)] == '\n') ;
  text[strlen(text)] = '\0';
  clean_stdin();

  printf("Input password: ");
  fgets(pass, MAX_PASS, stdin);
  if(pass[strlen(pass)] == '\n') ;
  pass[strlen(pass)] = '\0';
  clean_stdin();

  if(state == false && ran == true) {
    printf("The encrypt text is: ");
    random(MAX_TEXT - crypt(pass, text, false));
  } else if(state == false && ran == false) {
    printf("The encrypt text is: ");
    crypt(pass, text, false);
  } else {
    printf("The decrypt text is: ");
    crypt(pass, text, true);
  }
  printf("\n");
  return 0;
}

//Clean keyboard's buffer
int clean_stdin() {
  while(getchar() != '\n') ;
  return 1;
}

/*
 *Title: crypt
 *Description: It de/encrypt strings
 *@param pass[]: string which we use like password
 *@param text[]: string which we will encrypt
 *@param x: false = encrypt, true = decrypt
 *@return text_length: text length
 */
int crypt(char pass[], char text[], bool x) {
  int     pass_length;
  int     text_length;
  int     passPosition = 0;	//Relative position in pass[]
  int     textPosition = 0;	//Relative position in text[]
  pass_length = length(pass);
  text_length = length(text);
  int     sol[text_length];

  for(textPosition = 0; textPosition < text_length; textPosition++) {
    if(passPosition == pass_length) {
      passPosition = 0;
    }
    if(x == false) {
      sol[textPosition] = text[textPosition] + pass[passPosition];
      while(sol[textPosition] > 126) {
	sol[textPosition] -= 94;
      }
    } else {
      sol[textPosition] = text[textPosition] - pass[passPosition];
      while(sol[textPosition] < 32) {
	sol[textPosition] += 94;
      }
    }
    passPosition++;
    printf("%c", sol[textPosition]);
  }
  return text_length;
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
