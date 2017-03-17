

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

#include "Rijndael-EK.h"

//Testing Resources:
// http://csrc.nist.gov/groups/STM/cavp/documents/aes/AESAVS.pdf

int main(int argc, char **argv)
{

	unsigned int totalTests, testsPassed, testsFailed;
	DIR *testsDirPtr;
	struct dirent *testsDirEntry = NULL;

	totalTests = 0;
	testsPassed = 0;
	testsFailed = 0;

	testsDirPtr = opendir("./tests/");
	if (! testsDirPtr) {
		printf("Could not open tests directory. Failed!\n");
		exit(-1);
	}

	while ((testsDirEntry = readdir(testsDirPtr))) {
		if (testsDirEntry->d_name[0] != '.') {
			printf("Running Test: %s\n", testsDirEntry->d_name);
			// x/key  x/plaintext  x/ciphertext
		}
	}

	closedir(testsDirPtr);

	return 0;
}

