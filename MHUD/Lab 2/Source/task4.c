/* length_ext.c for Task 4 */
#include <stdio.h>
#include <arpa/inet.h>
#include <openssl/sha.h>
int main(int argc, const char *argv[])
{
	int i;
	unsigned char buffer[SHA256_DIGEST_LENGTH];
	SHA256_CTX c;
	SHA256_Init(&c);
	for(i=0; i<64; i++)
	SHA256_Update(&c, "*", 1);
	// MAC of the original message M (padded)
	c.h[0] = htole32(0x5a252fae);
	c.h[1] = htole32(0xd80b35ab);
	c.h[2] = htole32(0x0ba0a084);
	c.h[3] = htole32(0xe32c535b);
	c.h[4] = htole32(0x474f747a);
	c.h[5] = htole32(0xecbb2fcf);
	c.h[6] = htole32(0xcc8866a9);
	c.h[7] = htole32(0x628aa769);
	// Append additional message
	SHA256_Update(&c, "&download=secret.txt", 20);
	SHA256_Final(buffer, &c);
	for(i = 0; i < 32; i++) {
		printf("%02x", buffer[i]);
	}
	printf("\n");
	return 0;
}