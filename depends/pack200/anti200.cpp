/*
 * This is trivial. Do what thou wilt with it. Public domain.
 */

#include <stdexcept>
#include <iostream>
#include "unpack200.h"

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cerr << "Simple pack200 unpacker!" << std::endl << "Run like this:" << std::endl
				  << "  " << argv[0] << " input.jar.lzma output.jar" << std::endl;
		return EXIT_FAILURE;
	}

	FILE *input = fopen(argv[1], "rb");
	FILE *output = fopen(argv[2], "wb");
	if (!input)
	{
		std::cerr << "Can't open input file";
		return EXIT_FAILURE;
	}
	if (!output)
	{
		fclose(output);
		std::cerr << "Can't open output file";
		return EXIT_FAILURE;
	}
	try
	{
		unpack_200(input, output);
	}
	catch (std::runtime_error &e)
	{
		std::cerr << "Bad things happened: " << e.what() << std::endl;
		fclose(input);
		fclose(output);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
