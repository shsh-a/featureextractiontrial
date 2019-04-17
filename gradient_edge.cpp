
/*
//Gradient edge
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

  int height, width, maxv, t, total, dy, dx;

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



    ofstream outimg;
    outimg.open(argv[2]);

    outimg<<"P2"<<endl;
    outimg<<"#shshnk"<<endl;
    outimg<<width<<" "<<height<<endl;
    outimg<<maxv<<endl;




    for( int i = 0; i < height; i++)
    {

        for(int j=0; j< width * channel;j++)
        {

            if( !(i > 1 && j> 1 && i < height && j<width * channel))
                {
                    outimg<<image[i][j]<<endl;
                    continue;
            }

            dy = image[i-1][j] - image[i+1][j];
            dx = image[i][j-1] - image[i][j+1];


            if(dx==0) dx = 1;

            total = sqrt((dy*dy)+(dx*dx));
            if(total> 256) total = 255;
            if(total < 0) total = 0;

            total =(int)(atan(dy/dx)*(180/M_PI));
            //if(total < 0)  total=0;

            outimg<<total<<endl;



    }


        }




    outimg.close();

    return  0;
}
