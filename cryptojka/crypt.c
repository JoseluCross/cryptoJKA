#include "data.h"
/*
 *Title: crypt
 *Description: It de/encrypt strings
 *@param pass[]: string which we use like password
 *@param text[]: string which we will encrypt
 *@param x: false = encrypt, true = decrypt
 *@param name[]: name of output
 */
void crypt(char pass[], char *text, bool x, char name[]) {
  int     pass_length;
  int     text_length;
  int     passPosition = 0;	//Relative position in pass[]
  int     textPosition = 0;	//Relative position in text[]
  pass_length=strlen(pass);
  text_length=strlen(text);
  int     sol;			//output character

  FILE   *nom;

  nom = fopen(name, "w");

  for(textPosition = 0; textPosition < text_length; textPosition++) {
    if(passPosition == pass_length) {
      passPosition = 0;
    }
    if(x == false) {
      sol = *text + pass[passPosition];
      while(sol > 126) {
	sol -= 94;
      }
    } else {
      sol = *text - pass[passPosition];
      while(sol < 32) {
	sol += 94;
      }
    }
    passPosition++;
    text++;
    if(sol!=0)
    fputc(sol, nom);
  }
  fclose(nom);
}
