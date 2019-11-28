del test.exe test.o
g++ -Wall -std=c++11 -c "test.cpp"
g++ -Wall -std=c++11 -o "test.exe" "test.o" "sqlite3.dll"
::g++ -Wall -std=c++11 -I./ IDatabaseHandler.h
test.exe
