
/*
 * read.c
 *
 *  Created on: Oct 9, 2015
 *  Author: shashank
 */

#include "header.h"

imgArray* read_image(char fn[100])
{
	FILE *in_image;

    imgArray *image;
    image=(imgArray*)malloc(sizeof(imgArray));
	int i,j;
	char ch;
	in_image=fopen(fn, "r");
	if(in_image==NULL)
	{
        printf("Error No image found\n");
        exit(0);

	}

   while((ch=getc(in_image)) != '\n');
   while((ch=getc(in_image)) != '\n');
   while((ch=getc(in_image)) != '\n');
   while((ch=getc(in_image)) != '\n');


	for(i=0;i<92;i++)
	{
        for(j=0;j<112;j++)
        {
             fscanf(in_image,"%d",&image->a[i][j]);
        }
	}
	return image;
    fclose(in_image);

}





