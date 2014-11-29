#!/usr/bin
echo "THis is another URL extractor C library by Cooler_"
echo "---------------------------------------------------------"
echo "libParseURL - https://github.com/CoolerVoid/libParseURL "
mkdir pack; cd pack
cmake ../; make; cd .. ; cp libParseURL.h pack; cp test.c pack; cd pack
cp liblibParseURL.so /lib
echo "================================================"
echo "Test programm at pack/test\n "
echo " $ gcc -o test test.c -llibParseURL"
echo "------------------------------------------------"
gcc -o test test.c -llibParseURL
./test
echo "look the file \"test.c\" to you know how to use this library..."
