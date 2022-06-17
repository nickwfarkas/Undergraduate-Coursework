.data
  msg: .asciiz "Enter a year: "
  t: .asciiz "Leap Year"
  f: .asciiz "Not a Leap Year"

.text
 li $v0, 4
 la $a0, msg
 syscall
 li $v0, 5
 syscall   
 move $t0, $v0      
 rem $t1, $t0, 4
 seq $t1,$t1, 0 
 rem $t2, $t0, 100
 sgt $t2,$t2,0     
 rem $t3, $t0, 400
 seq $t3, $t3, 0 
 or $s1, $t2, $t3   
 and $s2, $t1, $s1 
 beqz $s2, notLeap
 li $v0, 4
 la $a0, t
 syscall     
 b exitProgram
        
exitProgram:
  li $v0, 10
  syscall

notLeap:
 li $v0, 4
 la $a0, f
 syscall
 b exitProgram