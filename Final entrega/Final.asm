.MODEL LARGE
.386
.STACK 200h

.DATA

a                             	dd	?
_20                           	dd	20
_10                           	dd	10
_cad0                         	dd	"LyC"


;MAYOR
FLD _a
FCOMP _20
FSTSW ax
SAHF
JNA	;MIENTRAS
bloque_falso
mientras_inicio:
;MAYOR
FLD _a
FCOMP _20
FSTSW ax
SAHF
JNA	bloque_falso
;RESTA
FLD _a
FLD _10
FSUB 
FSTP @aux0
ffree
;ASIGNACION
FLD _@aux0
FSTP _a
ffree
;ESCRIBIR
displayString cadena
bloque_falso
jmp mientras_inicio
bloque_falso:


FINAL:
	mov ah, 1 ; pausa, espera que oprima una tecla:
	int 21h ; AH=1 es el servicio de lectura
	MOV AX, 4C00h ; Sale del Dos
	INT 21h ; Enviamos la interripcion 21h
END ; final del archivo.
