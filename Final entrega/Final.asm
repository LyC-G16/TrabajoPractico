.MODEL LARGE
.386
.STACK 200h

.DATA

cont                          	dd	?
suma                          	dd	?
_2                            	dd	2
_4                            	dd	4
_5                            	dd	5
_3                            	dd	3
_2                            	dd	2
_cad0                         	dd	"hola"


;SUMA
FLD _2
FLD _4
FADD 
FSTP @aux0
ffree
;ASIGNACION
FLD _@aux0
FSTP _suma
ffree
;MULTIPLICACION
FLD _3
FLD _2
FMUL 
FSTP @aux1
ffree
;SUMA
FLD _5
FLD _@aux1
FADD 
FSTP @aux2
ffree
;ASIGNACION
FLD _@aux2
FSTP _cont
ffree
;ESCRIBIR
displayString cadena
;LEER
getString cont


FINAL:
	mov ah, 1 ; pausa, espera que oprima una tecla:
	int 21h ; AH=1 es el servicio de lectura
	MOV AX, 4C00h ; Sale del Dos
	INT 21h ; Enviamos la interripcion 21h
END ; final del archivo.
