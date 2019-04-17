/* 
 *File:   generate_lbp.c
 *Author: shashank areguli
 *
 *Created on October 11, 2015, 6:50 PM
 * 
 */

#include "header.h"



    

int* gen_lbp(int *img, int HEIGHT, int WIDTH,char *fn)
{
    
    
    int i, temp, c, k;
    int *lbp=malloc((HEIGHT*WIDTH)*sizeof(int));
    
   
    
 for(i=0;i<HEIGHT*WIDTH;i++)
 {
     temp=0;
     c=img[i];
      if(i<WIDTH||i>=(WIDTH*(HEIGHT-1))||i%(WIDTH+1)==0||(i%(WIDTH+1)==WIDTH))
      {
          lbp[i]=0;
          continue;
          
      }  
      
     k=i-WIDTH-2;
    if(img[k]>=c)
    	temp+=128;
    
    if(img[i-(WIDTH-1)] >= c)
    		temp+=64;
    
    if(img[i-WIDTH] >= c)
       		temp+=32;
    
    if(img[i-1] >= c)
        temp+=16;

    if(img[i+1] >= c)
        temp+=8;
    if(img[i+WIDTH] >= c)
        temp+=4;
    if(img[i+(WIDTH+1)] >= c)
         	temp+=2;
     if(img[i+(WIDTH+2)] >= c)
        temp+=1;
     lbp[i]=temp;
    
 }
  
    getFrequency(lbp,fn, HEIGHT, WIDTH);
    
    
    return lbp;
}

