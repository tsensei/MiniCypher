#include "../include/asciiToBase64.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdint.h>
char *base64Encoder(const unsigned char *input, int length)
{
    const char base64chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    int output_length = 4 * ((length + 2) / 3);
    char *encoded_data = (char *)malloc(output_length + 1);
    if (encoded_data == NULL)
    {
        fprintf(stderr, "Memory allocation failed.");
        exit(1);
    }

    for (int i = 0, j = 0; i < length;)
    {
        uint32_t octet_a = i < length ? (unsigned char)input[i++] : 0;
        uint32_t octet_b = i < length ? (unsigned char)input[i++] : 0;
        uint32_t octet_c = i < length ? (unsigned char)input[i++] : 0;

        uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

        encoded_data[j++] = base64chars[(triple >> 3 * 6) & 0x3F];
        encoded_data[j++] = base64chars[(triple >> 2 * 6) & 0x3F];
        encoded_data[j++] = base64chars[(triple >> 1 * 6) & 0x3F];
        encoded_data[j++] = base64chars[(triple >> 0 * 6) & 0x3F];
    }

    for (int i = 0; i < (3 - length % 3) % 3; i++)
    {
        encoded_data[output_length - 1 - i] = '=';
    }
    encoded_data[output_length] = '\0';

    return encoded_data;
}
char *asciiToBase64(const char *input_str)
{
    char *encoded_str = base64Encoder((const unsigned char *)input_str, strlen(input_str));
    return encoded_str;
}