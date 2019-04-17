/* 
 * File:   main.cpp
 * Author: shashank
 *
 * Created on 31 August, 2016, 10:25 AM
 */



#include "Image.h"


using namespace std;

/*
 * 
 * 
 * 
 * 
 * 
 * 
 */

int main(int argc, char** argv) {

    Image test("1.pgm");
    //test.writeImage();
   
    test.findEdge();
    return 0;
}

