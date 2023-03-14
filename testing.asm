.data #directive

.text
main:
li $t0,4  #int x=4
li $t1,9  #int y=5
beq $t0,$t1,check  #if(x==y) then go to check label
bne $t0,$t1,cc  #if(x!=y) then go to cc label
check:
add $s0,$t0,$t1
move $a0,$s0 #move data of s0 into a0(a0=s0) because it is address register 
li $v0,1 #integer protocol for printing
syscall
li $v0 ,10 #protocol for exiting the program
cc:
sub $s0,$t0,$t1 
move $a0,$s0 
li $v0,1 
syscall 
li $v0 ,10 
#---------------------------------------------------------------------------------------------------------------------------------

.text
main:
la $a0,prompt #load Address (address for string to be printed)
li $v0,4 #v is return register
syscall

la $a0,input #provde area of 20 characters (address register)
li $a1,20  #provde storage of 20 characters
li $v0,8
syscall

la $a1,prompt2
li $v0, 4
syscall

move $a0, $a1
li $v0, 4
syscall
li $v0, 10
syscall
