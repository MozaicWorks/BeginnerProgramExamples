all: animateSquare.cpp run

animateSquare.cpp: .PHONY
	g++ animateSquare.cpp  -o animateSquare -lGL -lglut

run:
	./animateSquare

dev-setup:
	sudo apt-install -y freeglut3-dev mesa-common-dev libglew-dev libglm-dev

.PHONY:
