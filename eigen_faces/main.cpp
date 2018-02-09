//
//  main.cpp
//  aaaa
//
//  Created by Wojciech Richert on 20.01.2018.
//  Copyright © 2018 Wojciech Richert. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/core.hpp"
using namespace cv;
using namespace std;
const int liczbazdjec = 10;
const int m = 1000;
const int n= 1000;

int main(int argc, const char * argv[]) {
    double** tablica = new double*[m*n];
    for(int i = 0; i < m*n; ++i){
        tablica[i] = new double[liczbazdjec];
    }
    
    Mat img = imread("/Users/wojtek/Desktop/aaaa/aaaa/1.png", 0);
    cout << img;
    cout<< "\n";
    img.convertTo(img, CV_64F, 1, 0);
    double **array = new double*[img.rows];
    for (int i=0; i<img.rows; ++i)
        array[i] = new double[img.cols];
    
    for (int i=0; i<img.rows; ++i)
        array[i] = img.ptr<double>(i);
    int k =0;
    
    for(int i = 0 ;i < img.rows; ++i){
        for(int j = 0; j < img.cols; ++j){
            cout << array[i][j];
            ++k;
            
        }
        cout<< "\n";
    }
    cout << " "<< k;
    delete [] array;
}

