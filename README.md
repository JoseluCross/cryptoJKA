### CryptoJKA Version 0.4.8 16/04/2016

GENERAL USAGE NOTES
--------------------
--------------------
* Encrypt and decrypt raw text using expand Vigenere (with ASCII)
*	The password change during the execution for each set of characters in input text
* In this version the text must be of maximum 1 MB of character
* The pass must be of maximum 64 characters.

* cryptoJKA from JKA Network - Version: 0.4.8

	* The text must be between ASCII 32 and ASCII 126

	* Options:
	 * -f [file_name]		    input file
	 * -o [file_name]		    output file (default : crypt.out)
	 * -p [text]				    password (default: pass)
	 * -t [text]				    text (default: text)
	 												    If you put -f and -t, text have preference<br>
	 * -e								    encrypt mode
	 * -d								    decrypt mode
	 * -b								    use encryptation algorithm before 0.4.5
	 * -r [number]			    with random generation [number of character]
	 * -h, --help				    show this box
	 * -v, --version		    show version

	 * Examples:

	*	cryptojka -e -t "Example text" -p password -o file_name -r 600
	*	cryptojka -d -f file_name -p password

Known bugs
----------
If -f, -o, -p, -t or -r don't have argument it will print the error *Segmentation fault (core dumped)*

If input text (like -t [text] or -p [text]) have bash special characters (&, $, !...) bash will print the error *bash: [part of text]: event not found* or *bash: [part of text]: command not found*

If you find new bugs report it us. Thanks.

Contact
-------
* Web Site: www.jkanetwork.com
* E-mail:	  contacto@jkanetwork.com

License
-------
* GPLv3
* READ LICENSE.txt
