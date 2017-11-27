CUFLAGS= --optimize 2 \
	--compiler-options "-O2 -Wall" \
	-gencode arch=compute_30,code=sm_30 \
	-gencode arch=compute_35,code=sm_35 \
	-D_FORCE_INLINES

IEEE_COMPLIANCE=-ftz=false -prec-div=true -prec-sqrt=true

NVCC_FLAGS=$(CUFLAGS) $(IEEE_COMPLIANCE)
	
EXE=satisfy.exe 

all : satisfy.exe

satisfy.exe: satisfy.o cpu_timer.o 
	nvcc  $^ -o $@ -lglut -lGL  $(NVCC_FLAGS) -DUSE_FLOAT

satisfy.o: satisfy.cpp
	g++ -std=c++11 -o satisfy.o -c satisfy.cpp
	
cpu_timer.o: cpu_timer.cpp
	g++ -std=c++11 -o cpu_timer.o -c cpu_timer.cpp


clean:
	rm -rf *.exe *.o