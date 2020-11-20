.MODEL LARGE
.386
.STACK 200h

.DATA

a                             	dd	?
_5                            	dd	5
_1                            	dd	1


;MENOR
FLD _5
FCOMP _a
FSTSW ax
SAHF
JNA	;MIENTRAS
bloque_falso
mientras_inicio:
;MENOR
FLD _5
FCOMP _a
FSTSW ax
SAHF
JNA	bloque_falso
;SUMA
FLD _a
FLD _1
FADD 
FSTP @aux0
ffree
;ASIGNACION
FLD _@aux0
FSTP _a
ffree
bloque_falso
jmp mientras_inicio
bloque_falso:


FINAL:
	mov ah, 1 ; pausa, espera que oprima una tecla:
	int 21h ; AH=1 es el servicio de lectura
	MOV AX, 4C00h ; Sale del Dos
	INT 21h ; Enviamos la interripcion 21h
END ; final del archivo.
