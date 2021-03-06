#include <stdio.h>
#include <iostream>

#include "PCD.h"
#include "File.h"
#include "DDS.h"

void PrintToolInfo();
void PrintToolUsage();

int main(int argc, char* argv[])
{
	//Print the tool info on-screen.
	PrintToolInfo();

	//If there are args to process.
	if (argc == 2)
	{
		unsigned int fileMagic = getFileMagic(argv[1]);

#if PS3
		fileMagic = ReverseUInt(fileMagic);
#endif
		switch (fileMagic)
		{
		case SECTION_MAGIC:
			ConvertPCDToDDS(argv[1]);
			break;
		case DDS_MAGIC:
			ConvertDDSToPCD(argv[1]);
			break;
		default:
			std::cout << "Failed to detect file type!" << std::endl;
			break;
		}
	}
	else
	{
		std::cout << "Fatal Error: Insufficient amount of args!" << std::endl;
		PrintToolUsage();
	}

	return 0;
}

const char* GAME_NAME = "Tomb Raider: Legend";
const char* PLATFORM_FULL_NAME = "PC";

void PrintToolInfo()
{
#if DEBUG
	std::cout << "PCD2DDS v1.0 (DEBUG) for " << GAME_NAME << std::endl;
#else
	std::cout << "PCD2DDS v1.0 for " << GAME_NAME << std::endl;
#endif
	//std::cout << "Platform: " << PLATFORM_FULL_NAME << " (" << PLATFORM_CONFIG_NAME << ")" << std::endl;
	std::cout << "Built: " << (__DATE__ ", " __TIME__) << std::endl;
	std::cout << "By Gh0stBlade" << std::endl;
}

void PrintToolUsage()
{
	std::cout << "PCD2DDS.exe [input.pcd/.dds]" << std::endl;
	system("pause");
}