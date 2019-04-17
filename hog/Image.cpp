/* 
 * File:   Image.cpp
 * Author: shashank
 *
 * Created on 31 August, 2016, 10:30 PM
 */
#include "Image.h"

/*
 * 
 */
   
   
   

Image::Image(char filename[50])
    {
        ifstream input;
        input.open(filename);
        
        input>>l1;
        input>>l2;
        
        
        input>>width;  
        input>>height;
            
        input>>maxv;
        
        cout<<filename<<endl;
        cout<<l1<<endl<<l2<<endl<<height<<"x"<<width<<endl<<"maxv "<<maxv<<endl;
        
        cout<<"Reading pixels"<<endl;
        
        img.resize(height, vector<int>(width, 0));
        
        for(int i=0; i<height; i++)
        {
            for(int j=0;j<width;j++)
            {
                
                input>>img[i][j];
            }
            
        }
        
        cout<<"Done.."<<endl;
        char cmd[100]="eog ";
        strcat(cmd, filename);
        cout<<cmd;
       
        system(cmd);
    }
    
  Image:: Image(){
        cout<<"Error specify name of file";
                exit(0);
    }
    
    void Image::writeImage()
{
    ofstream output;
    output.open("output.pgm");
    output<<l1<<endl;
    output<<l2<<endl;
    output<<width<<" "<<height<<endl;
    output<<maxv<<endl;
    
    for(int i=0;i<height;i++)
    {
        
        for(int j=0; j<width; j++)
        {
            output<<img[i][j]<<endl;
            
        }
    }
    
    system("eog output.pgm");
    
    
}
    
    void Image::writeImage(vector<vector<int> > IMG)
    {
    
        ofstream output;
        output.open("output.pgm");
        output<<l1<<endl;
        output<<l2<<endl;
        output<<width<<" "<<height<<endl;
        output<<maxv<<endl;
        
         for(int i=0;i<height;i++)
        {
        
            for(int j=0; j<width; j++)
            {
                output<<IMG[i][j]<<endl;
                 cout<<"Writing Image...."<<"\r";
            
            }
        }   
    
        system("eog output.pgm");
        
    }
    
    void Image::findEdge()
    {
        int dy, dx, grad;
         vector< vector<int> > temp;
         temp.resize(height, vector<int>(width, 0));
        
        for(int i=1; i< height- 1; i++)
        {
            
            for(int j=1;j< width -1; j++)
            {
                dy = img[i-1][j] - img[i+1][j];
                dx = img[i][j+1] - img[i][j-1];
                
                grad = sqrt((dy*dy)+(dx*dx));
                if(grad < 0)
                    grad = 0;
              
                cout<<"Working...."<<"\r";
                
                temp[i][j] = grad;
                
                
            }
        }
         cout<<"Done"<<endl;
        writeImage(temp);
        
        
    }





    
    void Image::hog()
    {
        vector<double> histograms;
        double dy, dx, mag, arr[9]={0}, angle;
        int i, j,k,l;
    
        
        
        for( i=0; i< height-4;i=i+4)
        {
            for( j=0; j< width-4;j= j+4)
            {
                //cell
                for( k=i; k<i+8;k++)
                {
                    for( l=j;l<j+8;l++)
                    {
                        if(!(i==0||j==0|| k==height-1|| k>=height||l==width ))
                        { 
                               
                            dy = img[k+1][l]-img[k-1][l];
                            dx = img[k][l+1]-img[k][l-1];
                        
                            mag = sqrt((dy*dy)+(dx*dx));
                         
                            if(mag<=0){ mag=1;}
                            // dy = dy/mag;
                            //dx = dx/mag;
                        
                            //mag = sqrt((dy*dy)+(dx*dx));
                         
                            if(dx <= 0)
                                 dx=1;
                            angle = dy/dx*(180/PI);
                         
                         
                        
                          if(angle<0)
                                 angle*=-1;
                         
                      
                         
                        
                            if( angle > 0 && angle < 20)
                                 arr[0] += mag;
                            if( angle > 20 && angle < 40)
                                 arr[1] += mag;
                            if( angle > 40 && angle < 60)
                                 arr[2] += mag;
                            if( angle > 60 && angle < 80)
                                 arr[3] += mag;
                            if( angle > 80 && angle < 100)
                                 arr[4] += mag;
                            if( angle > 100 && angle < 120)
                                 arr[5] += mag;
                            if( angle > 120 && angle < 140)
                                 arr[6] += mag;
                            if( angle > 140 && angle < 160)
                                 arr[7] += mag;
                            if( angle > 160 && angle < 180)
                                 arr[8] += mag;
                         
                        }
                       
                             
                               
                              
                        
                    }
                     
                 
                  
                    
                    //cell normalization
                    int mag1=0;
                    for(int i=0; i< 8;i++)
                    mag1+=arr[i]*arr[i];
                    if(mag1<=0)
                    {
                        mag1=1;
                    }
                    mag1=sqrt(mag1);
                    for(int i=0;i< 8;i++)
                        arr[i]=arr[i]/mag1;
                    
                   
                    
                    for(int i=0;i<8;i++)
                        histograms.push_back(arr[i]);
                    
                }
          
                
            }
            
        }
     
        int count=0;
        ofstream out;
        out.open("result");
        
         for(int i=0;i<histograms.size();i++)
         {
                        cout<<histograms[i];
                        out<<histograms[i];
                        if(count>36)
                        {
                            
                            count=0;
                            out<<endl;cout<<endl;
                        }
                        count++;
         }
        out.close();
        cout<<i<<" "<<j<<endl;
        
        system("eog test.pgm");
    }
    
    
    void Image::visualize()
    {
        
        ofstream oi;
        int dy, dx, mag, angle;
       
     
       vector<vector<int> > IMG;
       IMG.resize(height, vector<int>(width, 0));
       
        for(int i=0;i<height-1;i++)
        {
            for(int j=0; j<width-1;j++)
            {
                 
                   
                if(i%8==0||i%j==0)
                {
                    IMG[i][j]=0;
                }
               // IMG[i][j]=255;
                if(!(i==0||i==height||j==0||j==width))
                {
                    dy = img[i-1][j] - img[i+1][j];
                    dx = img[i][j+1] - img[i][j-1];
                
                    mag = sqrt((dy*dy)+(dx*dx));
                         
                       if(mag<=0){ mag=1;}
                          
                         
                            if(dx <= 0)
                                 dx=1;
                            angle = dy/dx*(180/PI);
                         
                         
                        
                          if(angle<0)
                                 angle*=-1;                        
                            if( angle > 0 && angle < 45)
                                IMG[i][j+1]=0;
                            if( angle > 45 && angle < 90)
                                IMG[i-1][j+1]=0;
                            if( angle > 46 && angle <=90)
                                 IMG[i-1][j]=0;
                            if( angle > 90 && angle < 140)
                                IMG[i-1][j-1]=0;
                            if( angle > 80 && angle < 100)
                                IMG[i][j-1]=0;
                          
                                
                
                }
            
                   
                
            }       
        }
      
       writeImage(IMG);

  }