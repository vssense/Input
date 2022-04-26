

all:
	clang++ -pthread -o input src/main.cpp src/window.cpp src/event.cpp -lglfw -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl
