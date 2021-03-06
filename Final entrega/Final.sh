flex ./lexico/Lexico.l
bison -dyv ./sintactico/Sintactico.y
gcc lex.yy.c y.tab.c expression.c Primitivas.c assembler.c -o Final.exe
./Final.exe ./sintactico/prueba_sintactica.txt
dot -Tpng:cairo:cairo tree.dot -o intermedia.png
code intermedia.png
code Final.asm

rm lex.yy.c
rm y.tab.c
rm y.output
rm y.tab.h