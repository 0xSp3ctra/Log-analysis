CC=gcc											
FLAGS= -Wall `pkg-config --libs --cflags glib-2.0`	-I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include						
LIBS= ../lib/libgraphique.c -lm -lSDL -lSDL_ttf	-L/usr/lib -lm -lglib-2.0 
EXEC= versionstatique versiondynamique fonctiongraphique fonctiontexte fonctionweb 			 

%.o: %.c
	$(CC) $(FLAGS) -c $<						

all: $(EXEC)									
		
versiondynamique: versiondynamique.c fonctiontexte.c fonctiongraphique.c fonctionweb.c			
	$(CC) $(LIBS) $(FLAGS) -o $@ $^	

fonctiongraphique: fonctiongraphique.c libgraphique.c 
	$(CC) $(LIBS) $(FLAGS) -o $@ $^	
					
clean:						
	rm *.o					
