CUFLAGS= --optimize 2 \
	--compiler-options "-O2 -Wall" \
	-gencode arch=compute_30,code=sm_30 \
	-gencode arch=compute_35,code=sm_35 \
	-D_FORCE_INLINES

IEEE_COMPLIANCE=-ftz=false -prec-div=true -prec-sqrt=true

NVCC_FLAGS=$(CUFLAGS) $(IEEE_COMPLIANCE)
	
EXE=satisfy.exe 

all : satisfy.exe

satisfy.exe: src/satisfy.o src/cpu_timer.o 
	nvcc  $^ -o $@ -lglut -lGL  $(NVCC_FLAGS) -DUSE_FLOAT

src/satisfy.o: src/satisfy.cpp
	g++ -std=c++11 -o src/satisfy.o -c src/satisfy.cpp
	
src/cpu_timer.o: src/cpu_timer.cpp
	g++ -std=c++11 -o src/cpu_timer.o -c src/cpu_timer.cpp


clean:
	rm -rf *.exe src/*.o