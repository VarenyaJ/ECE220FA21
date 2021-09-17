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

PRINT_R7 .BLKW #1 ; save R7 in 1 block of memory
ZERO .FILL x30
A .FILL #65 ; the ASCII value for 'A'
ASCII .FILL x37 ; the ASCII value for 7
STORE_R7 .BLKW #1
	
;R0 - keyboard character i/o
;R1- temp register
;R2- second temp register
;R3- hexadecimal output
;R4- hold value last popped
;R5- output from push/pop subroutine
;R6 - last displayed number

EVALUATE
;your code goes here
	ST R7, STORE_R7

KEYBOARD_INPUT
	GETC                        ; scan input
	OUT                         ; print value
	LD R2, EQUALSIGN_INPUT      ; load R2 with equal sign
	ADD R2, R2, R0              ; add keyboard character value value to the second temp register
	BRz PRODUCT                 ; loop PRODUCT

	LD R2, SPACECHARACTER       ; the character is a space, load the value into R2
	ADD R2, R0, R2              ; add keyboard character value value to the second temp register
	BRz KEYBOARD_INPUT          ; loop KEYBOARD_INPUT




;************************** PART 2 ABOVE THIS LINE**************************

;IN:R0, OUT:R5 (0-success, 1-fail/overflow)
;R3: STACK_END R4: STACK_TOP
;
PUSH	
	ST R3, PUSH_SaveR3	;save R3
	ST R4, PUSH_SaveR4	;save R4
	AND R5, R5, #0		;
	LD R3, STACK_END	;
	LD R4, STACk_TOP	;
	ADD R3, R3, #-1		;
	NOT R3, R3		;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz OVERFLOW		;stack is full
	STR R0, R4, #0		;no overflow, store value in the stack
	ADD R4, R4, #-1		;move top of the stack
	ST R4, STACK_TOP	;store top of stack pointer
	BRnzp DONE_PUSH		;
OVERFLOW
	ADD R5, R5, #1		;
DONE_PUSH
	LD R3, PUSH_SaveR3	;
	LD R4, PUSH_SaveR4	;
	RET


PUSH_SaveR3	.BLKW #1	;
PUSH_SaveR4	.BLKW #1	;


;OUT: R0, OUT R5 (0-success, 1-fail/underflow)
;R3 STACK_START R4 STACK_TOP
;
POP	
	ST R3, POP_SaveR3	;save R3
	ST R4, POP_SaveR4	;save R3
	AND R5, R5, #0		;clear R5
	LD R3, STACK_START	;
	LD R4, STACK_TOP	;
	NOT R3, R3		;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz UNDERFLOW		;
	ADD R4, R4, #1		;
	LDR R0, R4, #0		;
	ST R4, STACK_TOP	;
	BRnzp DONE_POP		;
UNDERFLOW
	ADD R5, R5, #1		;
DONE_POP
	LD R3, POP_SaveR3	;
	LD R4, POP_SaveR4	;
	RET


POP_SaveR3	.BLKW #1	;
POP_SaveR4	.BLKW #1	;
STACK_END	.FILL x3FF0	;
STACK_START	.FILL x4000	;
STACK_TOP	.FILL x4000	;


.END
