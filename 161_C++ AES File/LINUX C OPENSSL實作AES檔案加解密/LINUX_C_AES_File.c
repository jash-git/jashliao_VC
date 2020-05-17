//http://stackoverflow.com/questions/24856303/openssl-aes-256-cbc-via-evp-api-in-c
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <openssl/evp.h>
#include <openssl/aes.h>

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif


/**
 * Encrypt or decrypt, depending on flag 'should_encrypt'
 */
void en_de_crypt(int should_encrypt, FILE *ifp, FILE *ofp, unsigned char *ckey, unsigned char *ivec) {

    const unsigned BUFSIZE=4096;
    unsigned char *read_buf = malloc(BUFSIZE);
    unsigned char *cipher_buf;
    unsigned blocksize;
    int out_len;
    EVP_CIPHER_CTX ctx;

    EVP_CipherInit(&ctx, EVP_aes_256_cbc(), ckey, ivec, should_encrypt);
    blocksize = EVP_CIPHER_CTX_block_size(&ctx);
    cipher_buf = malloc(BUFSIZE + blocksize);

    while (1) {

        // Read in data in blocks until EOF. Update the ciphering with each read.

        int numRead = fread(read_buf, sizeof(unsigned char), BUFSIZE, ifp);
        EVP_CipherUpdate(&ctx, cipher_buf, &out_len, read_buf, numRead);
        fwrite(cipher_buf, sizeof(unsigned char), out_len, ofp);
        if (numRead < BUFSIZE) { // EOF
            break;
        }
    }

    // Now cipher the final block and write it out.

    EVP_CipherFinal(&ctx, cipher_buf, &out_len);
    fwrite(cipher_buf, sizeof(unsigned char), out_len, ofp);

    // Free memory

    free(cipher_buf);
    free(read_buf);
}

int main(int argc, char *argv[]) {

    unsigned char ckey[] = "thiskeyisverybad";
    unsigned char ivec[] = "dontusethisinput";
    FILE *fIN, *fOUT;

    if (argc != 2) {
        printf("Usage: <executable> /path/to/file/exe");
        return -1;
    }

    // First encrypt the file

    fIN = fopen("plain.txt", "rb"); //File to be encrypted; plain text
    fOUT = fopen("cyphertext.txt", "wb"); //File to be written; cipher text

    en_de_crypt(TRUE, fIN, fOUT, ckey, ivec);

    fclose(fIN);
    fclose(fOUT);

    //Decrypt file now

    fIN = fopen("cyphertext.txt", "rb"); //File to be read; cipher text
    fOUT = fopen("decrypted.txt", "wb"); //File to be written; cipher text

    en_de_crypt(FALSE, fIN, fOUT, ckey, ivec);

    fclose(fIN);
    fclose(fOUT);

    return 0;
}