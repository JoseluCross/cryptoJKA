#include "data.h"


/*
 *Title: showFile
 *Description: Print in screen a file
 *@param n[]:filename
 *@param tam: length of file
 */
void showFile(char n[],int tam){
	char f[tam];//output string

	FILE *show;
	show = fopen(n, "r");
	fgets(f,tam,show);
	printf("%s\n",f);
}

/*
 *Title: helpbox
 *Description: Show the help menu
 */
void helpbox(){
	printf("\n");
	printf(gettext("\tcryptoJKA from JKA Network - Version: %s\n"), VERSION);
	printf("\n");
	printf(gettext("\tThe text must be between ASCII 32 and ASCII 126\n\n"));
	printf(gettext("\tOptions:\n"));
	printf(gettext("\t -f [file_name]\tinput file\n"));
	printf(gettext("\t -o [file_name]\toutput file (default : crypt.out)\n"));
	printf(gettext("\t -p [text]\t\tpassword (default: pass)\n"));
	printf(gettext("\t -t [text]\t\ttext (default: text)\n\t\t\t\t\tIf you put -f and -t, text have preference\n"));
	printf(gettext("\t -e\t\t\tencrypt mode\n"));
	printf(gettext("\t -d\t\t\tdecrypt mode\n"));
	printf(gettext("\t -r [number]\t\twith random generation [number of character]\n"));
	printf(gettext("\t -b\t\t\tcyption mode whith before algorithm (before version 0.4.5)\n"));
	printf(gettext("\t -h, --help\t\tshow this box\n"));
	printf(gettext("\t -v, --version\t\tshow version\n\n"));
	printf(gettext("\t Examples:\n\n"));
	printf(gettext("\t\tcryptojka -e -t \"Example text\" -p password -o file_name -r 600\n"));
	printf(gettext("\t\tcryptojka -d -f file_name -p password\n\n"));
}

/*
 *Title: random
 *Description: It generates random text between ASCII 32 and 126
 *@param tam: max length of string
 *@param name[]: output name
 */
void rangen(int tam, char name[]){
  FILE *out_text;

	out_text = fopen(name, "a");
	int p;//Generated num
	int m;//Relative position
	for(m=0;m<tam;m++){
		p=(rand() % 95)+32; //p is between 32 and 126
		fputc(p, out_text);
	}
	fclose(out_text);
}
