stringy: stringy.c
	gcc stringy.c -o stringy

clean:
	rm *~

run: stringy
		./stringy
