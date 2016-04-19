#!/bin/bash
#Script to install cryptojka by JKA Network
#Define variables
name=cryptojka
version=0.4.12
dep=0
#Check dependences
echo "Check make dependences"
if [ -x /usr/bin/tar ];then
	echo "tar is installed"
else
	echo "tar is not installed"
	dep=1
fi
if [ -x /usr/bin/make ];then
	echo "make is installed"
else
	echo "make is not installed"
	dep=1
fi
if [ -x /usr/bin/wget ];then
	echo "wget is installed"
else
	echo "wget is not installed"
	dep=1
fi
if [ $dep -eq 1 ];then
	echo "Some make dependences are not installed, exiting"
	exit
fi
#Download and unzip the package
if [ -f $name-$version.tbz2 ];then
	tar xjf $name-$version.tbz2
else
	wget https://gitlab.com/JKANetwork/cryptoJKA/raw/master/last-version/$name-$version.tbz2
	if [ $? -ne 0 ];then
		wget https://github.com/JoseluCross/cryptoJKA/raw/master/last-version/cryptojka-0.4.12.tbz2
		if [ $? -ne 0 ];then
			wget http://mirror.jkanetwork.com/Software/cryptoJKA/last-version/cryptojka-0.4.12.tbz2
		else
			echo "The mirrors can't download the package, exiting"
			exit
		fi
	fi
	tar xjf $name-$version.tbz2
fi
#Create directories
mkdir -p package
mkdir -p package/usr/{bin,share,}
mkdir -p package/usr/share/$name/i18n/es/LC_MESSAGES
#Compiling
cd $name-$version
make
#Languajes
cp $name ../package/usr/bin/
cp i18n/es.mo ../package/usr/share/$name/i18n/es/LC_MESSAGES/$name.mo
cd ..
#Instalation
echo "The package will be put in /usr directory, its need root privileges"
sudo cp -r package/* /
rm -r package $name-$version
