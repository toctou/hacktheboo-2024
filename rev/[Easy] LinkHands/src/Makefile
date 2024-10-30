.PHONY := clean

link: main.c flag.inc
	gcc -O1 -no-pie -s main.c -o link

flag.inc: gen.py
	python3 gen.py > flag.inc

clean:
	rm -f link flag.inc
