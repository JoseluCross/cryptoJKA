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
