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