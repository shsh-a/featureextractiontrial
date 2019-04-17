#include<time.h>
#include "header.h"



int main()
{
   

    FILE *in_image,*writedata;
    int i, k,  *lbp, H, W, *img;
    clock_t start,end;
    double total;
    char fn[100],ch;
    

    start=clock();
    writedata=fopen("imgdb","a");
     
    for(k=1; k<1000; k++)
     {
         sprintf(fn,"faces/%d.pgm",k);
         in_image=fopen(fn, "r");

	if(in_image==NULL)
	{
            printf("Error image %s not found\n",fn);
            exit(0);
	}

        while((ch=getc(in_image)) != '\n');
        fscanf(in_image,"%d",&W);
        fscanf(in_image,"%d",&H); 
        while((ch=getc(in_image)) != '\n');
        while((ch=getc(in_image)) != '\n');
      
        img=malloc((H*W)*sizeof(int));
        
        printf("H=%d, W=%d %s", H,W,fn);
        
	for(i=0;i<H*W;i++)
	{
        
                 fscanf(in_image,"%d",&img[i]);
               
        }
 
   lbp=gen_lbp(img, H, W,fn);
   
 //  getFrequency(lbp, fn, H, W);
  
     }
    end=clock();
    total=((double)end-start)/CLOCKS_PER_SEC;
    printf("Time taken is %f ",total);


    free(img);
    free(lbp);
    fclose(writedata);

    return 0;
}

