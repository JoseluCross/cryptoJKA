CryptoJKA Version 0.4.2 29/03/2016
----------------------------------
GENERAL USSAGE NOTES
--------------------
--------------------
* Encrypt and decrypt raw text. 
* In this version the text must be of maximum 1 MB of caracter 
* The pass must be of maximum 64 characters. 

* cryptoJKA from JKA Network - Version: 0.4.2

	*The text must be between ASCII 32 and ASCII 125

	*Options:
	 *-f [file_name],	input file
	 *-o [file_name],	output file (default : crypt.out)
	 *-p [text],		password (default: pass)
	 *-t [text],		text (default: text)
					If you put -f and -t, text have preference
	 *-e,			encrypt mode
	 *-d,			decrypt mode
	 *-r [number],		with random generation [number of character]
	 *-h,			show this box
	 *-v, --version,		show version

	 *Examples:

	*	cryptojka -e -t "Example text" -p password -o file_name -r 600
	*	cryptojka -d -f file_name -p password



Contact
-------
* Web Site: www.jkanetwork.com
* E-mail:	  contacto@jkanetwork.com

Licence
-------
* GPLv3
* READ LICENCE.txt
