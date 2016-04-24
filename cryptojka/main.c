/*Title: cryptojka
*Descripton: cryptation character by character
*Autor: José Luis Garrido Labrador (JoseluCross) and Kevin Puertas Ruiz (Kprkpr)
*Version: 0.5.0 - apr/16
*/
#include "data.h"

#include "crypt.c"
#include "methods.c"
#include "functions.c"

int main(int argc, char *argv[]) {
  bool    state;		//false when encrypt, true when decrypt
  bool    ran = false;		//false: not random generation, true: random generation
  bool    fil;			//false: not file, true, with file
  bool    cond = false;		//If false = not argument
  bool    v = false;		//If true use the cryptation before version 0.4.5
  int     cant = 0;		//number of characters in random generation
  char    text[MAX_TEXT] = "text";	//imput character
  char    pass[MAX_PASS] = "pass";	//Imput pass
  FILE   *in;			//Input file
  char    out[35] = "crypt.out";	//output file
  srand((unsigned int)time(NULL));

  //Set locales
  bind_textdomain_codeset("cryptojka", "UTF-8");
  setlocale(LC_ALL, "");
  textdomain("cryptojka");
  bindtextdomain("cryptojka", "/usr/share/cryptojka/i18n");

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
      in = fopen(argv[i + 1], "rw");
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
    } else if(strcmp(argv[i], "--version") == 0
	      || strcmp(argv[i], "-v") == 0) {
      printf(gettext("cryptoJKA, version: %s\n\n"), VERSION);
      return 0;
    } else if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
      helpbox();		//In methods.c
      return 0;
    } else if(strcmp(argv[i], "-b") == 0) {
      v = true;
    }
  }

  if(cond == false) {
    printf(gettext("No option specified\n"));
    printf(gettext("Use cryptojka --help\n\n"));
    return 0;
  }
  //crypt methods is in crypt.c
  if(state == false) {
    if(fil == false) {
      for(i = 0; text[i] != '\0'; i++) {
	if(text[i] == ' ') {
	  text[i] = ranSpace();
	}
      }
      crypt(pass, text, state, out, v);
    } else {
      for(i = 0; feof(in) == 0; i++) {
	text[i] = fgetc(in);
	if(text[i] == ' ') {
	  text[i] = ranSpace();	//In functions.c
	}
	if(text[i] == '\n') {
	  text[i] = ' ';
	}
      }

      crypt(pass, text, false, out, v);
    }
    if(ran == true) {
      rangen(cant, out);	//In methods.c
    }

  } else {
    if(fil == false) {
      crypt(pass, text, true, out, v);
    } else {
      for(i = 0; feof(in) == 0; i++) {
	text[i] = fgetc(in);
      }
      crypt(pass, text, true, out, v);
    }
  }

  printf("\n");
  showFile(out, MAX_TEXT);

  return 0;
}
