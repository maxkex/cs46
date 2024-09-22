#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>

// Function prototypes. Don't change these.
uint8_t *read_card(char *fname, int *size);
void save_jpeg(uint8_t *data, int size, char *filename);
void recover(uint8_t *data, int size);

#define RAW_FILE "card.raw"

int main()
{
    // Read the card.raw file into an array of bytes (uint8_t)
    int card_length;
    uint8_t *card_data = read_card(RAW_FILE, &card_length);
    
    // Recover the images
    recover(card_data, card_length);
}

uint8_t *read_card(char *filename, int *size)
{
    struct stat st;
    if (stat(filename, &st) == -1)
    {
        fprintf(stderr, "Can't get info about %s\n", filename);
        exit(1);
    }
    int len = st.st_size;
    uint8_t *raw = malloc(len * sizeof(uint8_t));
    
    FILE *fp = fopen(filename, "rb");
    if (!fp)
    {
        fprintf(stderr, "Can't open %s for reading\n", filename);
        exit(1);
    }
    
    fread(raw, 1, len, fp);
    fclose(fp);
    
    *size = len;
    return raw;
}

void save_jpeg(uint8_t *data, int size, char *filename)
{
    static int file_count = 0;

    file_count++;
    if (file_count >= 100)
    {
        fprintf(stderr, "Warning: Your program was terminated.\n");
        fprintf(stderr, "  To prevent a large number of files from being created,\n");
        fprintf(stderr, "  program execution was stopped after save_jpeg was called\n");
        fprintf(stderr, "  100 times. You likely have a bug in your program.\n");
        exit(1);
    }

    FILE *fp = fopen(filename, "wb");
    if (!fp)
    {
        fprintf(stderr, "Can't write to %s\n", filename);
        exit(1);
    }
    
    fwrite(data, 1, size, fp);
    fclose(fp);   
}

void recover(uint8_t *data, int size){
    int i = 0;
    int file_count = 0; // need count for image naming
    int start = -1; //starting index of jpeg
    while (i < size - 512) { // 512 is the size of a block, prevents buffer overflow
        //program loops through the data, if it finds the start of a new jpeg, it saves the previous jpeg
        if (data[i] == 255 && data[i + 1] == 216 && data[i + 2] == 255 && (data[i + 3] == 224 || data[i + 3] == 225)) {
            if (start != -1) {
                // Check for the end marker of the current JPEG
                for (int j = start; j < i - 1; j++) {
                    if (data[j] == 255 && data[j + 1] == 217) {
                        char filename[8]; // number + .jpg extension, 8 characters should suffice
                        sprintf(filename, "%d.jpg", file_count++);
                        save_jpeg(&data[start], j - start + 2, filename);
                        break;
                    }
                }
            }
            start = i; //update the start for next looparound
        }
        i += 512; // go to the next block
    }

    // Check for the end marker of the last JPEG
    for (int j = start; j < size - 1; j++) {
        if (data[j] == 255 && data[j + 1] == 217) {
            char filename[8];
            sprintf(filename, "%d.jpg", file_count++);
            save_jpeg(&data[start], j - start + 2, filename);
            break;
        }
    }
    
}