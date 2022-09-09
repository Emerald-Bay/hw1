cxx = g++ -g -Wall

ulliststr: ulliststr.cpp ulliststr_test.cpp ulliststr.h
	$(cxx) $^ -o test