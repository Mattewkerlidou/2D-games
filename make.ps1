New-Item bin -ItemType Directory -ea 0
New-Item bin/Release -ItemType Directory -ea 0
New-Item bin/Debug -ItemType Directory -ea 0
New-Item obj -ItemType Directory -ea 0
New-Item build -ItemType Directory -ea 0
Copy-Item -Path "SDL2/bin/*" -Destination "bin/Release" -ea 0
Copy-Item -Path "SDL2/bin/*" -Destination "bin/Debug" -ea 0

g++.exe -Wall -fexceptions -Iinclude -ISDL2/include/SDL2 -g  -c src\Image.cpp -o obj\Debug\src\Image.o
g++.exe -Wall -fexceptions -Iinclude -ISDL2/include/SDL2 -g  -c src\main.cpp -o obj\Debug\src\main.o
g++.exe -Wall -fexceptions -Iinclude -ISDL2/include/SDL2 -g  -c src\Moteur.cpp -o obj\Debug\src\Moteur.o
g++.exe -Wall -fexceptions -Iinclude -ISDL2/include/SDL2 -g  -c src\Personnage.cpp -o obj\Debug\src\Personnage.o
g++.exe -Wall -fexceptions -Iinclude -ISDL2/include/SDL2 -g  -c src\Item.cpp -o obj\Debug\src\Item.o


g++.exe  -o bin\Debug\s102.exe obj\Debug\src\Image.o obj\Debug\src\main.o obj\Debug\src\Moteur.o obj\Debug\src\Personnage.o obj\Debug\src\Item.o -lmingw32 -LSDL2/lib -lSDL2main -lSDL2 -lSDL2_image