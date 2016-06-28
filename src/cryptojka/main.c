/*Title: cryptojka
*Descripton: cryptation character by character
*Autor: José Luis Garrido Labrador (JoseluCross) and Kevin Puertas Ruiz (Kprkpr)
*Version: 0.5.1 - june/16
*/
#include "data.h"
//Files
#include "crypt.c"
#include "methods.c"
#include "functions.c"
//Prototypes
void interactive(char[],char[],char[]);

int main(int argc, char *argv[]) {
  bool    state;		//false when encrypt, true when decrypt
  bool    ran = false;		//false: not random generation, true: random generation
  bool    fil;			//false: not file, true, with file
  bool    cond = false;		//If false = not argument
  bool    v = false;		//If true use the cryptation before version 0.4.5
  int     cant = 0;		//number of characters in random generation
  char    text[MAX_TEXT];	//imput character
  char    pass[MAX_PASS];	//Imput pass
  FILE   *in;			//Input file
  char    out[35];	//output file
  srand(time(NULL));

  strcpy(text, "text");
  strcpy(pass, "pass");
  strcpy(out, "crypt.out");

  //Set locales
  bind_textdomain_codeset("cryptojka", "UTF-8");
  setlocale(LC_ALL, "");
  textdomain("cryptojka");
  bindtextdomain("cryptojka", "/usr/share/cryptojka/i18n");

  //Flags options
  int     i;
  for(i = 0; i < argc; i++) {
    if(strcmp(argv[i], "-e") == 0) { //encrypt mode
      state = false;
      cond = true;
    }else if(strcmp(argv[i], "-i") == 0){
      interactive(text,pass,out);
      exit(0);
    } else if(strcmp(argv[i], "-d") == 0) { //decrypt mode
      state = true;
      cond = true;
    } else if(strcmp(argv[i], "-f") == 0) { //file mode
      in = fopen(argv[i + 1], "r");
      if(in == NULL) {
        printf(gettext("File could't be open, aborting\n"));
        exit(0);
      }
      fil = true;
      cond = true;
    } else if(strcmp(argv[i], "-o") == 0) { //Output file
      strcpy(out, argv[i + 1]);
      cond = true;
    } else if(strcmp(argv[i], "-p") == 0) { //Password
      strcpy(pass, argv[i + 1]);
      cond = true;
    } else if(strcmp(argv[i], "-t") == 0) { // Input Text
      if(!fil) {
        //if(strcmp(argv[i + 1], '\0') != 0) {
          strcpy(text, argv[i + 1]);
          fil = false;
          cond = true;
      /*  } else {
          exit(0);
        }*/
      }
    } else if(strcmp(argv[i], "-r") == 0) { //Random Generation
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
  if(state == false) { //encrypt
    if(fil == false) { //Without file
      for(i = 0; text[i] != '\0'; i++) {
        if(text[i] == ' ') {
          text[i] = ranSpace();	//In functions.c
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
      fclose(in);
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
  showFile(out,MAX_TEXT);

  return 0;
}

/*
 *Title: interactive
 *Description: capture the information interactively
 *@param text[]: text
 *@param pass[]: pass
 *@param out[]: output file name
 */
void interactive (char text[],char pass[],char out[]){
  bool mode;
  printf(gettext("Write the text: "));
  inputText(text,MAX_TEXT);
  printf(gettext("Write the pass: "));
  inputText(pass,MAX_PASS);
  printf(gettext("Write the output file name: "));
  inputText(out,35);
  do {
    printf(gettext("Select mode, 0 = crypt, 1 = decrypt: "));
    scanf("%u",&mode);
  } while(mode != 0 && mode != 1);
  crypt(pass,text,mode,out,false);
}
