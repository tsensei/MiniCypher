#ifndef CONVERTER_H
#define CONVERTER_H

typedef struct Converter {
    char  *number;
    char *base;
    char *(*toBinary)(struct Converter *);
    char *(*toDecimal)(struct Converter *);
    char *(*toOctal)(struct Converter *);
    char *(*toHexadecimal)(struct Converter *);
} Converter;

void initConverter(Converter *converter, char *number, char *base);

#endif // CONVERTER_H
