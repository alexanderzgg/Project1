#makefile for lab 2 pass off cases
NUM?=2
numbers_80=0 1 2 3 4 5 6 7 8
numbers_100=0 1 2
tests=Lab$(NUM)PassOffCases

.SILENT:run

run:
	(echo "BUCKET 80") ; \
	for number in $(numbers_80) ; \
	do \
		echo "Running input$$number" ; \
		./lab$(NUM) $(tests)/$(NUM)-80/input$$number.txt > $(tests)/out.txt ; \
		diff -w $(tests)/$(NUM)-80/answer$$number.txt $(tests)/out.txt || (echo "diff failed on test $$number \n") ; \
	done \

	(echo "BUCKET 100") ; \
	for number in $(numbers_100) ; \
	do \
		echo "Running input$$number" ; \
		./lab$(NUM) $(tests)/$(NUM)-100/input$$number.txt > $(tests)/out.txt ; \
		diff -w $(tests)/$(NUM)-100/answer$$number.txt $(tests)/out.txt || (echo "diff failed on test $$number \n") ; \
	done \

	rm $(tests)/out.txt

compile:
	g++ -Wall -Werror -std=c++17 -g *.cpp -o lab$(NUM)
