#
# Este eh o Makefile para compilar o trabalho, tanto
# os testes quanto o programa em si.
#
# Digite 'make' para criar o executável com o programa
# e 'make testes' para criar o executavel dos testes. 

# Definindo o compilador como sendo o g++, e criando macros para
# gerar o executavel do programa ou o executavel dos testes
#
# -lm math.h
# -g debugging
# -Wall warnings
#
# As outras flags sao flags para o gtest
CC = g++
CFLAGS = -lm -g -Wall
TESTFLAGS = -lgtest -lgtest_main -lpthread -ftest-coverage -fprofile-arcs -g -Wall

# Definindo o 'make' como a compilacao do trabalho e nao dos testes
default: trabalho

# Para criar os .o, precisamos dos .c e .h
app/obj/Adaptadores.o: ./app/src/Adaptadores.c ./app/header/Adaptadores.h 
	$(CC) $(CFLAGS) -c ./app/src/Adaptadores.c

app/obj/Cidades.o: ./app/src/Cidades.c ./app/header/Cidades.h 
	$(CC) $(CFLAGS) -c ./app/src/Cidades.c

app/obj/Geradores.o: ./app/src/Geradores.c ./app/header/Geradores.h 
	$(CC) $(CFLAGS) -c ./app/src/Geradores.c

app/obj/Interconexoes.o: ./app/src/Interconexoes.c ./app/header/Interconexoes.h 
	$(CC) $(CFLAGS) -c ./app/src/Interconexoes.c

app/obj/Principal.o: ./app/src/Principal.c ./app/header/Principal.h 
	$(CC) $(CFLAGS) -c ./app/src/Principal.c

# Para criar o executável, precisamos dos .o
trabalho: ./app/obj/Adaptadores.o ./app/obj/Cidades.o ./app/obj/Geradores.o ./app/obj/Interconexoes.o ./app/obj/Principal.o 
	$(CC) $(CFLAGS) -o ./app/obj/Adaptadores.o ./app/obj/Cidades.o ./app/obj/Geradores.o ./app/obj/Interconexoes.o ./app/obj/Principal.o 

# Make para os testes
#testes: /app/obj/Adaptadores.o /app/src/Cidades.o /app/obj/Geradores.o /app/obj/Interconexoes.o /app/obj/Principal.o 
# $(CC) $(TESTFLAGS) -o /app/obj/Adaptadores.o /app/src/Cidades.o /app/obj/Geradores.o /app/obj/Interconexoes.o /app/obj/Principal.o 

# To start over from scratch, type 'make clean'. This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) count *.o *~