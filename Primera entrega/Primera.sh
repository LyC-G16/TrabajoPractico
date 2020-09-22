flex ./Lexico.l
gcc lex.yy.c -o programa
./programa datos2.txt
rm lex.yy.c
rm programa