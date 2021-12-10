CC=gcc											
FLAGS= -Wall `pkg-config --libs --cflags glib-2.0`	-I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include						
LIBS= ../lib/libgraphique.c -lm -lSDL -lSDL_ttf	-L/usr/lib -lm -lglib-2.0 
EXEC= versionstatique versiondynamique fonctiongraphique fonctiontexte 			 

%.o: %.c
	$(CC) $(FLAGS) -c $<						

all: $(EXEC)									
		
versiondynamique: versiondynamique.o fonctiontexte.o fonctiongraphique.o 			
	$(CC) $(LIBS) $(FLAGS) -o $@ $^	

fonctiongraphique: fonctiongraphique.o libgraphique.o fonctiontexte.o
	$(CC) $(LIBS) $(FLAGS) -o $@ $^	
					
clean:						
	rm *.o					
