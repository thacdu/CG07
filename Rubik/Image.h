#ifndef _IMAGE_H_
#define _IMAGE_H_

/**
 * This class represents for an image.
 * An image is specified by an array of pixels values,
 * image width and image height 
 **/

class Image {
public:
	Image(char* ps, int w, int h);
    ~Image();
    char* pixels;
    int width;
    int height;
};

/* This function describe how to load and image from storage and assign it 
to a pointer of Image */
Image* loadBMP(const char* filename);

#endif

