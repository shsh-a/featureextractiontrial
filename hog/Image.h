/* 
 * File:   Image.h
 * Author: shashank
 *
 * Created on 31 August, 2016, 10:45 PM
 */

#ifndef IMAGE_H
#define	IMAGE_H

#include <cstdlib>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<math.h>
#include<cstring>

#define PI 3.142
   
using namespace std;
class Image
{
    int height, width, maxv;
    string l1, l2;
    
 vector <vector<int> > img;
   
    
public:
    Image(char filename[50]);
    
    Image();
    void writeImage();
    void writeImage(vector <vector<int> > IMG);
    
    void findEdge();
    
    void hog();
    void visualize();
    
    
};


#endif	/* IMAGE_H */

