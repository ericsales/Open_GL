all:
	g++ main.cpp -o main -lglut -lGLU -lGL -lm -lglfw -lGLEW
	g++ vectors.cpp -o vectors -lglut -lGLU -lGL -lm -lglfw -lGLEW

run:
	./main

clear:
	rm main

