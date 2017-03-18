

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <dirent.h>

#include "Rijndael-EK.h"

//Testing Resources:
// http://csrc.nist.gov/groups/STM/cavp/documents/aes/AESAVS.pdf

int main(int argc, char **argv)
{

	unsigned int totalTests, testsPassed, testsFailed;
	bool testPassed;
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
			testPassed = false;
			++totalTests;
			printf("Running Test: %s..", testsDirEntry->d_name);

			// x/key  x/plaintext  x/ciphertext

			if (testPassed) {
				printf(". Passed.\n");
				++testsPassed;
			} else {
				printf(". FAILED!\n");
				++testsFailed;
			}
		}
	}

	closedir(testsDirPtr);

	printf("Test Summary:\n\tTotal Tests:%i\n\tPassed: %i\n\tFailed: %i\n", totalTests, testsPassed, testsFailed);

	return 0;
}

