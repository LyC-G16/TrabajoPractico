.MODEL LARGE
.386
.STACK 200h

.DATA

suma                          	dd	?
actual                        	dd	?
promedio                      	dd	?
contador                      	dd	?
_cad0                         	dd	"Prueba.txt LyC Tema 2!"
_cad1                         	dd	"Ingrese un valor entero:"
_0                            	dd	0.0
_02.5                         	dd	02.5
_0xA2B0                       	dd	41648.0
_9                            	dd	9.0
_1                            	dd	1.0
_0.342                        	dd	0.342
_2                            	dd	2.0
_4                            	dd	4.0
_0x00A8                       	dd	168.0
@max1                         	dd	?
@max0                         	dd	?
_cad2                         	dd	"La suma es: "
_0b10                         	dd	2.0
_cad3                         	dd	"es mayor que 2 y dist de 0"
_0b111010                     	dd	58.0
_cad4                         	dd	"no es mayor que 2"


; ESCRIBIR
displayString _cad0
; ESCRIBIR
displayString _cad1
; LEER
getString actual
; ASIGNACION
FLD _0
FSTP _contador
ffree
; SUMA
FLD _02.5
FLD _0xA2B0
FADD 
FSTP @aux0
ffree
; ASIGNACION
FLD _@aux0
FSTP _suma
ffree
condicion0:
; MENORIGUAL
FLD _9
FCOMP _contador
FSTSW ax
SAHF
JNAE	endwhile0
; SUMA
FLD _contador
FLD _1
FADD 
FSTP @aux1
ffree
; ASIGNACION
FLD _@aux1
FSTP _contador
ffree
; DIVISION
FLD _contador
FLD _0.342
FDIV 
FSTP @aux2
ffree
; MULTIPLICACION
FLD _contador
FLD _
FMUL 
FSTP @aux3
ffree
; SUMA
FLD _@aux2
FLD _@aux3
FADD 
FSTP @aux4
ffree
; ASIGNACION
FLD _@aux4
FSTP _actual
ffree
; SUMA
FLD _suma
FLD _actual
FADD 
FSTP @aux5
ffree
; ASIGNACION
FLD _@aux5
FSTP _suma
ffree
jmp condicion0
endwhile0:
; ESCRIBIR
displayString _cad2
; ESCRIBIR
displayString suma
; MAYOR
condicion1:
FLD _actual
FCOMP _0b10
FSTSW ax
SAHF
JNA	bloque_falso1
; ESCRIBIR
displayString _cad3
; DECISIONCUERPO
jmp endif1
bloque_falso1:
; MENOR
condicion2:
FLD _0b111010
FCOMP _actual
FSTSW ax
SAHF
JNA	endif2
; ESCRIBIR
displayString _cad4
endif2:
endif1:


FINAL:
	mov ah, 1 ; pausa, espera que oprima una tecla:
	int 21h ; AH=1 es el servicio de lectura
	MOV AX, 4C00h ; Sale del Dos
	INT 21h ; Enviamos la interripcion 21h
END ; final del archivo.
