/*
 *Title: random
 *Description: It generates random text between ASCII 32 and 126
 *@param tam: max length of string
 *@return nothing: string in ASCII
 */
void random(int tam){
	int p;//Generated num
	int m;//Relative position
	for(m=0;m<tam;m++){
		p=(rand() % 95)+32; //p is between 32 and 126
		printf("%c",p);
	}
}