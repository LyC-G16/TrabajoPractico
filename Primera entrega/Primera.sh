flex ./lexico/Lexico.l
bison -dyv ./sintactico/Sintactico.y
gcc lex.yy.c -o programa
./programa prueba.txt
rm lex.yy.c
rm y.tab.c
rm y.output
rm y.tab.h
rm programa