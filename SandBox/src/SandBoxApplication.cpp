#include <iostream>

#include "Dwarf.h"

class Sandbox : public Dwarf::Application {
public:
	Sandbox() {
	
	}

	~Sandbox() {
	
	}
};

Dwarf::Application* Dwarf::CreateApplication() {
	return new Sandbox();
}