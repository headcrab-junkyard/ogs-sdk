#include <cstdlib>
#include <cstdio>

#include <iostream>

#include "IRegistry.hpp"

int main(int argc, char **argv)
{
	printf("ENGINE REGISTRY TEST\n");
	
	auto pRegistry{GetRegistry()};
	
	printf("READING\n");
	
	auto nScrWidth{pRegistry->GetInt("ScreenWidth")};
	auto nScrHeight{pRegistry->GetInt("ScreenHeight")};
	
	printf("Screen size: %d x %d\n", nScrWidth, nScrHeight);
	
	std::cin.get();
	printf("WRITING\n");
	
	pRegistry->SetInt("ScreenWidth", nScrWidth * 0.5);
	pRegistry->SetInt("ScreenHeight", nScrHeight * 0.5);
	
	printf("DONE\n");
	std::cin.get();
	
	return EXIT_SUCCESS;
};