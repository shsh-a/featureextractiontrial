/*
 * histogram.c
 *
 *  Created on: Nov 2, 2015
 *      Author: shashank
 */


#include "header.h"



void getFrequency(int *img, char *fn, int HEIGHT, int WIDTH)
{
	int i, j, k=0, range[18];
	FILE *out_file;
         int freq[256]={0};
	
        
         
         out_file=fopen("lbp","a");
	for(i=0;i<HEIGHT*WIDTH;i++)
	{
            fprintf(out_file,"%d\n",img[i]);
            k=img[i];
            freq[k]=freq[k]+1;
           
	}
         fclose(out_file); 
         out_file=fopen("rangecount","w");

	j=0;
	for(i=0;i<15;i++)
	{
		for(k=0; k<17; ++k)
		{
			range[i]= range[i] + freq[j];
					j++;
		}

	}
	fprintf(out_file, "\n\n%s\n",fn);
	printf("Processed %s\n",fn);
	j=0; k=17;
	for(i=0;i<15;i++)
	{

		fprintf(out_file, "%d-%d\t%d\n", j, k, range[i]);
		j=j+17;
		k=k+17;
	}
        fclose(out_file);
      
        
       



}




