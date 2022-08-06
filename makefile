FLAGS = -g -fPIC -c --std=c++17


all:
	mkdir -p obj
	mkdir -p bin
	
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o
	
	g++ -shared -o bin/libreria.so obj/producto.o obj/tienda.o
	mkdir -p bin/include
	cp src/producto.h ./bin/include
	cp src/tienda.h ./bin/include
	cp src/excepcionesProducto.h ./bin/include
	cp src/excepcionesTienda.h ./bin/include

compile:

	mkdir -p bin

	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ $(FLAGS) src/producto.cpp -o bin/producto.o
	g++ $(FLAGS) src/tienda.cpp -o bin/tienda.o
	g++ -o bin/tarea3 bin/main.o bin/producto.o bin/tienda.o

test:

	mkdir -p obj
	mkdir -p bin

	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o
	g++ $(FLAGS) tests/tienda_test.cpp -o obj/tienda_test.o
	g++ $(FLAGS) tests/producto_test.cpp -o obj/producto_test.o

	g++ -g -o bin/tests obj/producto.o obj/producto_test.o obj/tienda.o obj/tienda_test.o -lgtest -lgtest_main -lpthread 

clean:
	rm -Rf bin
	rm -Rf obj
	rm *.dat