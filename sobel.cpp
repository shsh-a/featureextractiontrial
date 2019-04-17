/*
//Convolution sobel operator
//argv[1] input
//argv[2] output
//argv[3] Channel
*/

#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>



    using namespace std;


int main(int argc, char *argv[])
{

    ////////////////////////////////reading



    int channel = atoi(argv[3]);

    ifstream img;
    img.open(argv[1]);

    if(!img){
        cout<<"Error";
        exit(0);
    }
    string l1, l2;
    cout<<"Reading image"<<endl;
    getline(img, l1);

    getline(img, l2);

    cout<<l1<<"\n"<<l2<<endl;

  int height, width, maxv, t, total, htotal, vtotal;

    img>>width;
    img>>height;
    img>>maxv;


     cout<< height << "x"<<width<<endl<<maxv<<endl;

     int image[height][width * channel];



    for( int i = 0; i < height ; i++)
    {
        for(int j=0; j < width*channel; j++)
        {
                img >> t;
                image[i][j]=t;
        }
    }


////////////////////////////Apply convolution
    ofstream outimg;
    outimg.open(argv[2]);

    outimg<<"P2"<<endl;
    outimg<<"#shshnk"<<endl;
    outimg<<width<<" "<<height<<endl;
    outimg<<maxv<<endl;


 int mask[3][3] = {
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}
    };

     int vmask[3][3] = {
    {-1, -2, -1},
    {0, 0, 0},
    {1, 2, 1}
    };


    //Horizontal gx

    for( int i = 0; i < height; i++)
    {

        for(int j=0; j< width * channel;j++)
        {

            if( !(i > 1 && j> 1 && i < height && j<width * channel))
                {
                    outimg<<image[i][j]<<endl;
                    continue;
            }


            htotal = ( (image[i-1][j-1] * mask[0][0]) + (image[i-1][j] * mask[0][1]) + (image[i-1][j+1] * mask[0][2]) +
                        (image[i][j-1] * mask[1][0]) + (image[i][j] * mask[1][1] ) +  (image[i][j+1] * mask[1][2]) +
                        (image[i+1][j-1] * mask [2][0]) + (image[i+1][j] * mask[2][1]) + (image[i+1][j+1] * mask[2][2]) );

                         htotal = htotal/1;


     cout<<"H processing pixel"<<i<<"\r";
                fflush(stdout);

                    vtotal = ( (image[i-1][j-1] * vmask[0][0]) + (image[i-1][j] * vmask[0][1]) + (image[i-1][j+1] * vmask[0][2]) +
                        (image[i][j-1] * vmask[1][0]) + (image[i][j] * vmask[1][1] ) +  (image[i][j+1] * vmask[1][2]) +
                        (image[i+1][j-1] * vmask [2][0]) + (image[i+1][j] * vmask[2][1]) + (image[i+1][j+1] * vmask[2][2]) );

                         vtotal = vtotal/1;



     cout<<"V processing pixel"<<i<<"\r";
                fflush(stdout);

        // magnitude = sqrt of gx^2+gy squared
        total = sqrt((vtotal*vtotal)+(htotal*htotal));
        if(total > 256 || total < 0)
            {
                outimg<<255<<endl;
                continue;
            }
            //total=atan(total);
     outimg<<total<<endl;
    }


        }




    outimg.close();

    return  0;
}
