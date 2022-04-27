

all:
	clang++ -pthread -o input src/main.cpp src/window/window.cpp src/event/event.cpp -Isrc -lglfw -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl -Wall
