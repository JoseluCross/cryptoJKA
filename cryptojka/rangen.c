/*
 *Title: random
 *Description: It generates random text between ASCII 32 and 126
 *@param tam: max length of string
 */
void random(int tam){
	int p;//Generated num
	int m;//Relative position
	char    name[] = "crypt.out";
	
	FILE   *out;
    out = fopen(name, "a");
	
	for(m=0;m<tam;m++){
		p=(rand() % 95)+32; //p is between 32 and 126
		fputc(p,out);;
	}
	fclose(out);
}