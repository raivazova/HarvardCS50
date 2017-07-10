/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Resize a BMP.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize int infile outfile\n");
        return 1;
    }

    // remember filenames
    int factor = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];
    
    if(factor == 0 || factor > 100)
    {
        printf("int must be positive and <= 100\n");
        return 2;
    }
    
    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    // saving the curent values 
    LONG width = bi.biWidth;
    LONG height = abs(bi.biHeight);
    
    
    // updating bi fot the outfile
    bi.biWidth = bi.biWidth * factor;
    bi.biHeight = bi.biHeight * factor;
    
    // determine padding for original file 
    int padding =  (4 - (width * sizeof(RGBTRIPLE) % 4) ) % 4;
    
    // determine padding for output scanlines 
    int outPadding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE) % 4) ) % 4;
    
    // updating bi fot the outfile
    bi.biSizeImage = abs(bi.biHeight) * (bi.biWidth * sizeof(RGBTRIPLE)+ outPadding);
    
    // updating bf for the outfile
    bf.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi.biSizeImage;
    
    

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    
 
    

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    
    // temporary storage
    RGBTRIPLE triple;
    
    // the width + padding in bytes
    int line = (width * 3 + padding);
    
    // iterate over infile's scanlines
    for (int i = 0; i < height; i++)
    {
    
        // write to outfile n lines for each infile line
        for(int q = 0; q < factor; q++)
        {
            
            // iterate over pixels in scanline
            for (int j = 0; j < width; j++)
            {
            

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
              
                // write to the oufile n pixels for each infile pixel
                for(int r = 0; r < factor; r++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
                
                
                
            }
            
            //skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);
            
            // add the padding if any to the outfile
            for (int k = 0; k < outPadding; k++)
            {
                fputc(0x00, outptr);
            }
            // if less then n lines writen to outfile for curent infile line
            if (q < factor - 1)
            {
                // return to the begining of the curent line
                fseek(inptr, - line, SEEK_CUR);
            }
        }
        
        
    }
    
   
    
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
