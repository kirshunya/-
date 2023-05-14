#pragma pack(push, 1)
typedef struct {
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;
} BMPFileHeader;

typedef struct {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bit_count;
    unsigned int compression;
    unsigned int size_image;
    int x_pels_per_meter;
    int y_pels_per_meter;
    unsigned int clr_used;
    unsigned int clr_important;
} BMPInfoHeader;

typedef struct {
    BMPFileHeader file_header;
    BMPInfoHeader info_header;
} BMPHeader;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Pixel;

#pragma pack(pop)
void input_size(int* size);
Pixel median(Pixel* arr, int n);