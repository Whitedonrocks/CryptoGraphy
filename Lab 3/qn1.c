// WAP to generate 16 round key in DES.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int PC1[56] = {
	57,49,41,33,25,17,9,
	1,58,50,42,34,26,18,
	10,2,59,51,43,35,27,
	19,11,3,60,52,44,36,
	63,55,47,39,31,23,15,
	7,62,54,46,38,30,22,
	14,6,61,53,45,37,29,
	21,13,5,28,20,12,4
};

int PC2[48] = {
	14,17,11,24,1,5,
	3,28,15,6,21,10,
	23,19,12,4,26,8,
	16,7,27,20,13,2,
	41,52,31,37,47,55,
	30,40,51,45,33,48,
	44,49,39,56,34,53,
	46,42,50,36,29,32
};

// Number of left shifts per round
int shifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

// Function to print a key in binary, grouped by 8 bits
void print_key(unsigned char *key, int nbits) {
	for (int i = 0; i < nbits; i++) {
		int byte = i / 8;
		int bit = 7 - (i % 8);
		printf("%d", (key[byte] >> bit) & 1);
		if ((i+1) % 8 == 0 && i != nbits-1) printf(" ");
	}
	printf("\n");
}

// Function to apply a permutation table
void permute(unsigned char *in, unsigned char *out, int *table, int nbits) {
	for (int i = 0; i < nbits; i++) {
		int pos = table[i] - 1;
		int byte = pos / 8;
		int bit = 7 - (pos % 8);
		int val = (in[byte] >> bit) & 1;
		out[i/8] |= val << (7 - (i % 8));
	}
}

// Left shift a 28-bit half by n positions
void left_shift(unsigned char *half, int n) {
	unsigned int val = 0;
	// Convert 28 bits to int
	for (int i = 0; i < 4; i++) val = (val << 8) | half[i];
	val = val & 0x0FFFFFFF;
	val = ((val << n) | (val >> (28 - n))) & 0x0FFFFFFF;
	// Store back
	for (int i = 3; i >= 0; i--) {
		half[i] = val & 0xFF;
		val >>= 8;
	}
}

int main() {

	// Default 64-bit binary key (example: "0001001100110100010101110111100110011011101111001101111111110001")
	char key_str[65] = "0001001100110100010101110111100110011011101111001101111111110001";
	unsigned char key[8] = {0};
	for (int i = 0; i < 64; i++) {
		int byte = i / 8;
		int bit = 7 - (i % 8);
		if (key_str[i] == '1') {
			key[byte] |= (1 << bit);
		}
	}

	printf("Original Key:        ");
	print_key(key, 64);

	// Apply PC-1
	unsigned char permuted[7] = {0};
	memset(permuted, 0, 7);
	permute(key, permuted, PC1, 56);
	printf("PC-1 Key:            ");
	print_key(permuted, 56);

	// Split into C and D (28 bits each)
	unsigned char C[4] = {0}, D[4] = {0};
	memset(C, 0, 4);
	memset(D, 0, 4);
	for (int i = 0; i < 28; i++) {
		int byte = i / 8, bit = 7 - (i % 8);
		int val = (permuted[byte] >> bit) & 1;
		C[i/8] |= val << (7 - (i % 8));
	}
	for (int i = 28; i < 56; i++) {
		int j = i - 28;
		int byte = i / 8, bit = 7 - (i % 8);
		int val = (permuted[byte] >> bit) & 1;
		D[j/8] |= val << (7 - (j % 8));
	}
	printf("Left  (C0):          ");
	print_key(C, 28);
	printf("Right (D0):          ");
	print_key(D, 28);

	printf("\n16 Round Keys and Combined Keys:\n");
	for (int round = 0; round < 16; round++) {
		left_shift(C, shifts[round]);
		left_shift(D, shifts[round]);
		// Combine C and D
		unsigned char CD[7] = {0};
		memset(CD, 0, 7);
		for (int i = 0; i < 28; i++) {
			int val = (C[i/8] >> (7 - (i % 8))) & 1;
			CD[i/8] |= val << (7 - (i % 8));
		}
		for (int i = 0; i < 28; i++) {
			int val = (D[i/8] >> (7 - (i % 8))) & 1;
			CD[(i+28)/8] |= val << (7 - ((i+28) % 8));
		}
		printf("Combined Key (C%-2dD%-2d): ", round+1, round+1);
		print_key(CD, 56);
		// Apply PC-2
		unsigned char round_key[6] = {0};
		memset(round_key, 0, 6);
		permute(CD, round_key, PC2, 48);
		printf("Round %2d Key:         ", round+1);
		print_key(round_key, 48);
		printf("\n");
	}
	return 0;
}