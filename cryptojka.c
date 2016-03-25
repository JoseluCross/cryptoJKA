/*Title: 
 *Descripton: 
 *Autor: José Luis Garrido Labrador (JoseluCross) and Kevin Puertas Ruiz (Kprkpr)
 *Version: 0.1.0 - mar/16
 */
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <strings.h>

int     clean_stdin(void);
void    crypt(char[], char[], bool);
int     length(char[]);

int main() {
  unsigned char mode = 2;
  bool    state;		//false when encrypt, true when desencrypt
  char    text[101];		//imput character
  char    c;			//control character
  char    pass[17];		//Imput pass

  do {
    printf("Choose, 0 = encrypt, 1 = desencrypt: ");
    if(scanf("%u%c", &mode, &c) != 2 || c != '\n') {
      printf("Incorrect value\n");
      clean_stdin();
      mode = 2;
    }
  } while(mode != 0 && mode != 1);
  state = mode;
  printf("Input text (only ANSI): ");
  fgets(text, 101, stdin);
  if(text[strlen(text) - 1] == '\n') ;
  text[strlen(text) - 1] = '\0';
  clean_stdin();
  printf("Input password: ");
  fgets(pass, 17, stdin);
  if(pass[strlen(pass) - 1] == '\n') ;
  pass[strlen(pass) - 1] = '\0';;
  clean_stdin();
  if(state == false) {
    printf("The encrypt text is: ");
    crypt(pass, text, false);
  } else {
    printf("The desencrypt text is: ");
    crypt(pass, text, true);
  }

  return 0;
}

//Clean keyboard's buffer
int clean_stdin() {
  while(getchar() != '\n') ;
  return 1;
}

/*
 *Title: crypt
 *Description: des/encrypt string
 *@param pass[]: string which we use like password
 *@param text[]: string which we will encrypt
 *@param x: false = encrypt, true = desencrypt
 */
void crypt(char pass[], char text[], bool x) {
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
  printf("\n");
}

/*
 *Title: length
 *Description: count string length
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
