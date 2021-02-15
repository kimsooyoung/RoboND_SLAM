#include <iostream>
#include <math.h>
#include <Eigen/LU>
#include <Eigen/Core>

using namespace std;

const int mapWidth =  2;
const int mapHeight = 2;

float DeMorgan(double m1, double m2){
    float result = 0.0;

    result = 1 - (1 - m1) * (1 - m2);

    return result;
}

void sensorFusion(double m1[][mapWidth], double m2[][mapWidth])
{
    //*#############TODO: Code the Sensor Fusion Function############*//
    // Fuse the measurments of the two maps and print the resulting 
    //map in a matrix form:
    //a  b
    //c  d
    Eigen::MatrixXf result(2, 2);

    result(0, 0) = DeMorgan(m1[0][0], m2[0][0]);
    result(0, 1) = DeMorgan(m1[0][1], m2[0][1]);
    result(1, 0) = DeMorgan(m1[1][0], m2[1][0]);
    result(1, 1) = DeMorgan(m1[1][1], m2[1][1]);

    std::cout << result << std::endl;

}

int main()
{

    double m1[mapHeight][mapWidth] = { { 0.9, 0.6 }, { 0.1, 0.5 } };
    double m2[mapHeight][mapWidth] = { { 0.3, 0.4 }, { 0.4, 0.3 } };
    sensorFusion(m1, m2);

    return 0;
}
