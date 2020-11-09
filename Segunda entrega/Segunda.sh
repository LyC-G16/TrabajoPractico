flex ./lexico/Lexico.l
bison -dyv ./sintactico/Sintactico.y
gcc lex.yy.c y.tab.c expression.c Primitivas.c -o Segunda.exe
./Segunda.exe ./sintactico/prueba_sintactica.txt
dot -Tpng:cairo:cairo tree.dot -o intermedia.png

rm lex.yy.c
rm y.tab.c
rm y.output
rm y.tab.h