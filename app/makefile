
kompilator=g++
standard=-std=c++14
optymalizacja=-O3
debug=
exec=exec
#src=app
src=.
memory=./nvwa


__ : $(exec)/main 
	$(exec)/main 
	$(exec)/main -h 
	$(exec)/main  -i ../dat/input.dat  -d ../dat/output.dat
	$(exec)/main  -i ../dat/input.dat  -q ../dat/output.dat
	$(exec)/main  -i ../dat/input.dat  -d 
	
	



	   	   
$(exec)/main : $(exec)/main.o               \
               $(exec)/algorytm.o                 \
               $(exec)/funkcje_odczytu.o          \
               $(exec)/obsluga_list.o    
                     
	$(kompilator) $(standard) $(debug) $(optymalizacja) -pedantic-errors -o $@ $^ 
	            
$(exec)/main.o : $(src)/main.cpp 
	if [ ! -d $(exec) ]; then mkdir $(exec) ; fi 
	$(kompilator) $(standard) $(debug) $(optymalizacja) -pedantic-errors -c -o $@ $^ 
	
$(exec)/algorytm.o : $(src)/algorytm.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) -pedantic-errors -c -o $@ $^

$(exec)/funkcje_odczytu.o : $(src)/funkcje_odczytu.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) -pedantic-errors -c -o $@ $^

$(exec)/obsluga_list.o : $(src)/obsluga_list.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) -pedantic-errors -c -o $@ $^		


# kompilacja biblioteki wykrywajacej wycieki pamieci		
$(exec)/debug_new.o : $(memory)/debug_new.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) -pedantic-errors  -c -o $@ $^ 
	
$(exec)/static_mem_pool.o : $(memory)/static_mem_pool.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) -pedantic-errors  -c -o $@ $^ 		

$(exec)/mem_pool_base.o : $(memory)/mem_pool_base.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) -pedantic-errors  -c -o $@ $^ 		

$(exec)/bool_array.o : $(memory)/bool_array.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) -pedantic-errors  -c -o $@ $^ 

	# doxygen
doxygen : 
	doxygen Doxyfile	

		
