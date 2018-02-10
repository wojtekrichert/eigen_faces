//
//  main.cpp
//  eigen_faces
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
// dimensions of pictures:
const int m = 1000;
const int n= 1000;


int main(int argc, const char * argv[]) {
    // average face:
    double * avg = new double[m*n];
    for(int i =0; i< m*n; ++i){
        avg[i]= 0;
    }
    //********************************************
    double** tablica = new double*[m*n];
    for(int i = 0; i < m*n; ++i){
        tablica[i] = new double[liczbazdjec];
    }
    
    double **array = new double*[m];
    for (int i=0; i<n; ++i)
        array[i] = new double[m];
    // loading all images to tall matrix [m*n][1] and then transfer them to matrix 'tablica':
    for(int img_number= 0; img_number<liczbazdjec; ++img_number){
        string aaa = "/Users/wojtek/Desktop/eigen_faces/eigen_faces/" +to_string(img_number+1)+".png" ;
        Mat img = imread(aaa, 0);
        cout<< "\n";
        img.convertTo(img, CV_64F, 1, 0);
        for (int i=0; i<img.rows; ++i)
            array[i] = img.ptr<double>(i);
        int x =0;
        for(int i = 0 ;i < img.rows; ++i){
            for(int j = 0; j < img.cols; ++j){
                //cout << array[i][j];
                tablica[x][img_number]= array[i][j];
                avg[x]= avg[x]+array[i][j];
                ++x;
            }
            cout<< "\n";
        }
    }
/*
    // displaying all elements in tablica:
    for(int i = 0; i <m*n; ++i){
        for(int j= 0; j<liczbazdjec; ++j){
            cout << " "<< tablica[i][j];
        }
        cout << "\n";
    }
 */
    for(int i = 0; i <m*n; ++i){
        avg[i]= int(avg[i]/liczbazdjec);
        cout << avg[i] << "\n";
        
    }
    delete [] array;
    delete [] tablica;
}

