TARGET = sub6
OBJS = asm_io.o main6.o $(TARGET).o 
$(TARGET) : $(OBJS)
	gcc -m32  $(OBJS) -o $(TARGET)

%.o : %.asm
	nasm -f elf32  -D ELF_TYPE $< -o $@ 

%.o: %.c
	gcc -m32 -c $<

clean: 
	rm -f *.o $(OBJS) $(TARGET)
