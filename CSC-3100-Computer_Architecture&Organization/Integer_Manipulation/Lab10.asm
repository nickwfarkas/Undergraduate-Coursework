.data
  nl:  .asciiz "\n"
  input: .asciiz "Enter a three-digit number: " 
  output: .asciiz "Your input was: " 
.text       
  la $a0, input
  li $v0, 4
  syscall
  li $v0, 5
  syscall
  move $t0, $v0
  la $a0, output
  li $v0, 4
  syscall
  li $v0, 1
  move $a0, $t0
  syscall  
  la $a0, nl
  addi $v0, $0, 4
  syscall   
  addi $t1, $zero, 100
  div $t0, $t1        
  mfhi $t0
  mflo $t2
  li $v0, 1
  move $a0, $t2
  syscall   
  la $a0, nl
  addi $v0, $0, 4
  syscall   
  addi $t1, $0, 10
  div $t0, $t1        
  mfhi $t0
  mflo $t2
  li $v0, 1
  move $a0, $t2
  syscall     
  la $a0, nl
  addi $v0, $0, 4
  syscall
  li $v0, 1
  move $a0, $t0
  syscall
  li $v0, 10
  syscall