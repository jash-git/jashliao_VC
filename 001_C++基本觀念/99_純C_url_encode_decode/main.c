#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char *url_decode(const char *input)
{
	int input_length = strlen(input);

	size_t output_length = (input_length + 1) * sizeof(char);
	char *working = malloc(output_length), *output = working;

	while(*input)
	{
		if(*input == '%')
		{
			char buffer[3] = { input[1], input[2], 0 };
			*working++ = strtol(buffer, NULL, 16);
			input += 3;
		}
		else
		{
			*working++ = *input++;
		}
	}

	*working = 0; //null terminate
	return output;
}
//note unicode support should happen upstream of this.
bool is_non_symbol(char c)
{
    if(c == '\0') return 1; //we want to write null regardless
    int c_int = (int)c;
    return (c_int >= 48 && c_int <= 57) || (c_int >= 65 && c_int <= 90) || (c_int >= 97 && c_int <= 122);
}

char *url_encode(const char *input)
{
    int end = strlen(input);
    size_t final_size = (end * 3) + 1;
    char *working = malloc(final_size * sizeof(char)), *output = working;

    while(*input)
    {
        const char c = *input;
        if(c < 0)
        {
            input++;
        }
        else if(is_non_symbol(c))
        {
            *working++ = *input++;
        }
        else
        {
            char encoded[4] = {0};
            snprintf(encoded, 4, "%%%02x", c);

            *working++ = encoded[0];
            *working++ = encoded[1];
            *working++ = encoded[2];
            input++;
        }
    }

    *working = 0; //null term
    return output;
}
int main(int argc, char **argv)
{
    if(argc > 1)
    {
        char *input = argv[1];
        char *encoded = url_encode(input);
        printf("%s\n", encoded);
        char *decoded = url_decode(encoded);
        printf("%s\n",decoded);
        free(encoded);
        free(decoded);
        free(input);
    }
    else
    {
        char *line = "http://www.google.com";
        char *encoded = url_encode(line);
        char *decoded = url_decode(encoded);
        printf("%s\n", encoded);
        printf("%s\n",decoded);
        free(encoded);
        free(decoded);
        free(line);
    }
    return 0;
}
