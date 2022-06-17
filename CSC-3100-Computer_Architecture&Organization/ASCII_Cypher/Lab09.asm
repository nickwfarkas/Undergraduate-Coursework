.data

  msg: .asciiz "UGETGV UQWR KU DGUV"
  space: .asciiz " "

.text

  la $t4, space
  la $t1, msg
  li $t2, 0
  li $t3, 18
  

loop:
  bgt $t2, $t3, exitProgram
  lb $a0, 0($t1)
  lb $a1, 0($t4)

  bne  $a0,$a1,l1
  beq  $a0,$a1,l2
  
  l1: addi $a0, $a0, -2
  l2:
  li $v0, 11
  syscall
  
  addi $t1,$t1,1
  addi $t2, $t2, 1
  b loop
  
exitProgram:
  li $v0, 10
  syscall
  
  
