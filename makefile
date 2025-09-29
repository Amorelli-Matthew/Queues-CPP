program:driver.o event.o
	g++ -o program driver.o event.o -g

driver.o: driver.cpp queue.h arraypriorityqueue.h event.h arrayqueue.h
	g++ -c driver.cpp -g

event.o: event.cpp event.h 
	g++ -c  event.cpp -g

clean:
	rm *.o program