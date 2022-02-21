CXX = g++
CXXFLAGS = -Wall -g

proj5: MediaPlayer.o Media.o proj5.cpp Tqueue.cpp
	$(CXX) $(CXXFLAGS) MediaPlayer.o Media.o Tqueue.cpp proj5.cpp -o proj5

MediaPlayer.o: MediaPlayer.cpp  MediaPlayer.h Media.o Tqueue.cpp
	$(CXX) $(CXXFLAGS) -c MediaPlayer.cpp

Media.o: Media.cpp Media.h
	$(CXX) $(CXXFLAGS) -c Media.cpp

Tqueue.o: Tqueue.cpp
	$(CXX) $(CXXFLAGS) -c Tqueue.cpp

run:
	./proj5

run1:
	./proj5 proj5_media.txt

val1:
	valgrind ./proj5 proj5_media.txt
