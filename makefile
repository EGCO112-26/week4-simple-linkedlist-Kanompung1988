compile: main.c 
	 gcc main.c -o Kanompung

run: Kanompung
	 ./Kanompung

clean: Kanompung
	 rm Kanompung
