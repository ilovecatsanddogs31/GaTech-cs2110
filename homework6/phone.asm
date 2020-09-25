;;=============================================================
;;CS 2110 - Spring 2019
;;Homework 6 - Phone Number
;;=============================================================
;;Name: Jared Raiola
;;=============================================================

.orig x3000
		AND R0, R0, 0 ;; I IS SET TO 0
		AND R1, R1, 0 ;; J IS SET TO 0
		AND R2, R2, 0 ;; SET PLACEHOLDER REGISTER TO 0
		LD R3, STRING
		LD R5, ASCII

WHILE
		AND R1, R1, 0
		LD R1, TEMPSTRING
		ADD R0, R0, 0 ;; ALLOW THE VALUE OF I TO BE IN THE CC
		BRz EL1 ;; IF I IS 0, GO INSIDE FIRST IF

		ADD R2, R0, -4 ;; SEE IF I IS 4
		BRz EL1 ;; IF I IS 4 GO INSIDE FIRST IF

		AND R2, R2, 0 ;; SET R2 BACK TO 0
		ADD R2, R0, -5 ;; SEE IF I IS 5
		BRz EL1 ;; IF I IS 5 GO INSIDE FIRST IF

		AND R2, R2, 0 ;; SET R2 BACK TO 0
		ADD R2, R0, -9 ;; SEE IF I IS 9
		BRz EL1 ;; IF I IS 9 GO INSIDE FIRST IF

		AND R2, R2, 0 ;; SET R2 BACK TO 0
		ADD R2, R0, -14 ;; SEE IF I IS 14
		BRz EL1 ;; IF I IS 14 GO INSIDE FIRST IF

		;; THIS IS WHERE THE ELSE GOES
		;; YOU HAVE AN IF STATEMENT IN HERE
		LD R3, STRING
		ADD R3, R3, R0
		LDR R4, R3, 0 ;; LOADS STRING AT CURRENT INDEX
		ADD R4, R4, R5
		BRn EL2 ;; JUMPS TO BREAK CASE BECAUSE IT'S LESS THAN 0
		LD R3, STRING
		ADD R3, R3, R0
		LDR R4, R3, 0 ;; LOADS STRING AT CURRENT INDEX
		ADD R4, R4, R5
		ADD R4, R4, -9
		BRp EL2 ;; JUMPS TO BREAK CASE BECAUSE IT'S BIGGER THAN 9
		BRnzp ENDOFWHILE ;; JUMPS TO ENDOFWHILE


EL1 ;; INSIDE FIRST IF STATEMENT
		;; WRITE IF STATEMENT IN HERE
		LD R3, STRING
		ADD R3, R3, R0
		LDR R4, R3, 0 ;; LOADS STRING AT CURRENT INDEX
		ADD R1, R1, R0 
		LDR R1, R1, 0;; LOADS TEMPLATE AT CURR INDEX
		ADD R4, R4, R5
		ADD R1, R1, R5
		NOT R4, R4
		ADD R4, R4, 1
		ADD R1, R1, R4
		BRnp EL2
		BRnzp ENDOFWHILE ;; JUMPS TO END OF WHILE

EL2
		;; THIS IS WHERE THE CODE GOES TO IF IF HITS EITHER OF THE BREAK STATEMENTS
		AND R4, R4, 0
		ST R4, ANSWER
		HALT


ENDOFWHILE
		AND R1, R1, 0
		ADD R1, R1, 15
		ADD R0, R0, 1 ;; INCREMENT I BY 1
		NOT R4, R1 ;; FLIP J
		ADD R4, R4, 1 ;; 2'S COMP J
		ADD R4, R0, R4 ;; I-J
		BRn WHILE ;; IF NEGATIVE THAT MEANS THAT I IS < J
		BRnzp END ;; JUMP TO THE END
	
END
		AND R1, R1, 0
		ADD R1, R1, 1
		ST R1, ANSWER
		HALT

STRING .fill x4000
TEMPSTRING .fill x5000
ANSWER .blkw 1
ASCII .fill -48
.end

.orig x4000
.stringz "(704) 555-2110"
.end

.orig x5000
.stringz "(000) 000-0000"
.end