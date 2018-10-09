CC = clang++
CFLAGS = -Wall -Wextra -std=c++11 -c
LFLAGS = -Wall -Wextra 
HEAD = map.h  initializations.h system.h planet.h  starship_temp.h weapon.h
OS = simulation.o map.o initializations.o system.o planet.o starship_temp.o weapon.o

%.o: %.cpp $(HEAD)
	$(CC) -o $@ $< $(CFLAGS)

gsws: $(OS)
	$(CC) -o gsws $(OS) $(LFLAGS)

clean:
	rm -f *.o core* *~ gsws
