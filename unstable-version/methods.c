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
	printf("\tOptions:\n\t -f [file_name],\tinput file\n\t -o [file_name],\toutput file\n\t -p [text],\t\tpassword\n\t");
	printf(" -t [text],\t\ttext (not compatible with -f)\n\t");
	 printf(" -e,\t\t\tencrypt mode\n\t -d,\t\t\tdecrypt mode\n\t -r [number],\t\twith random generation [number of character]\n\t -h,\t\t\tshow this box\n");
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
