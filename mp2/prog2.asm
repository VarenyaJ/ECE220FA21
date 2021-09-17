;Pieces of Historgram



;R0- data input register - input operands and operators
;R1- temp register
;R2- temp register ???
;R3- hexadecimal output
;R4- hold value last popped
;R5- output from push/pop subroutine
;R6- load ASCII and I/O
; *********************- maybe used as stack pointer???
;R7- store PC

PRINT_HEX
	ST R7, PRINT_R7       ; stores the label value into R7
	AND R6, R6, #0        ; clear R6
	ADD R6, R5, #0        ; move output from push/pop into i/o

LOOP_SHIFT              
	AND R1, R1, #0        ; clear R1
	ADD R1, R1, #4        ; add decimal 4 to temp register

INITIAL_SHIFT
    AND R2, R2, #0        ; clear R2
    AND R0, R0, #0        ; clear R2
    ADD R0, R0, #4        ; add #4 to register with last value popped

TAKE_OUT	
	ADD R2, R2, R2        ; shift R2 left -> double its value
	ADD R6, R6, #0        ; clear R6
	BRzp SHIFT            ; loop the SHIFT label until negative
	ADD R2, R2, #1        ; update R2 by incrementing the second temp register

SHIFT
	ADD R6, R6, R6         ; left shift R6 -> double R6
	ADD R0, R0, #-1        ; decrement the data input register
	BRp TAKE_OUT           ; loops the TAKE_OUT

TWO_PRINTS
	ADD R0, R2, #-9       ; decrease temp register by 9 and store in i/o
	BRnz PRINT_IO_NUM     ; loop PRINT_IO_NUM
	LD R0, #65            ; store A in i/o register
	ADD R0, R0, R2        ; R0 is then added with R2, updating R0 register
	ADD R0, R0, #-10      ; decrement i/o register by 10
	BRnzp OUT_LOOP        ; loop OUT_LOOP

PRINT_IO_NUM
	LD R0, ZERO           ; load i/o register with value #0
	ADD R0, R0, R2        ; add temp register value to i/o

OUT_LOOP
	OUT                   ; output value
	ADD R1, R1, #-1       ; move temp register back 1
	BRp INITIAL_SHIFT       ; loop INITIAL_SHIFT LABEL
	BRnzp RESULT          ; start the RESULT loop

RESULT
	LD R7, PRINT_R7       ; loads value from PRINT_R7 to R7 PC
	RET                   ; return calling routine


;************************** PART 1 ABOVE THIS LINE**************************
