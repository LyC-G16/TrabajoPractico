flex ./lexico/Lexico.l
bison -dyv ./sintactico/Sintactico.y
gcc lex.yy.c y.tab.c -o Primera.exe
./Primera.exe ./sintactico/prueba_sintactica.txt

rm lex.yy.c
rm y.tab.c
rm y.output
rm y.tab.h