rm main.exe main.o
g++ -Wall -c "main.cpp"
g++ -Wall -o "main.exe" "main.o" "sqlite3.dll"
./main.exe
