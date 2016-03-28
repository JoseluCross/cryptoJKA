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

void helpbox(){
	printf("Options:\n -f [file_name]\tinput file\n -o [file_name]\toutput file\n -p [text]\tpassword\n");
	printf("-t [text]\ttext (not compatible with -f)\n");
	 printf("-e\tencrypt mode\n -d\tdecrypt mode\n -r [number]\twith random generation [number of character]\n -h\tshow this box\n");
}
