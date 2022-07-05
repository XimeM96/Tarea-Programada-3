FLAGS = -g -c --std=c++17


all:
	mkdir -p obj
	mkdir -p bin
	
	g++ $(FLAGS) src/biblioteca.cpp -o obj/biblioteca.o
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o
	

	g++ -shared -o bin/libreria.so obj/biblioteca.o
	mkdir -p bin/include
	cp src/biblioteca.h src/producto.h src/tienda.h ./bin/include

compile:
	mkdir -p bin
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ $(FLAGS) src/producto.cpp -o bin/producto.o
	g++ $(FLAGS) src/tienda.cpp -o bin/tienda.o
	g++ -o bin/tarea3 bin/main.o bin/producto.o bin/tienda.o

test:
	mkdir -p obj
	mkdir -p bin

	g++ $(FLAGS) src/biblioteca.cpp -o obj/biblioteca.o
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o
	g++ $(FLAGS) tests/biblioteca_test.cpp -o obj/biblioteca_test.o
	g++ $(FLAGS) tests/producto_test.cpp -o obj/producto_test.o

	g++ -g -o bin/tests obj/biblioteca.o obj/biblioteca_test.o obj/producto_test.o obj/producto.o obj/tienda.o -lgtest -lgtest_main -lpthread

clean:
	rm -Rf bin
	rm *.dat