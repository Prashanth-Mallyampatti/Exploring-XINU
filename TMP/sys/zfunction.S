.globl zfunction
zfunction:
	push %ebp 
	mov %esp, %ebp 
	mov 8(%esp), %eax

        and $0xfffc01ff,%eax
	shr $8, %eax  
	or  $0xff000000,%eax				
	
	mov %ebp,%esp
	pop %ebp
	
	ret
