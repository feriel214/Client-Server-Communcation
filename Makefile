SRC:=$(wildcard ./*.c)
EXE :=$(SRC:.c=)

name := ""

app: $(SRC)
	gcc $(SRC) -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic -o app

run:
	./app $(name)

clean:
	rm *.o app











	






	

