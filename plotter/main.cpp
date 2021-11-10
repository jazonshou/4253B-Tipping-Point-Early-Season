#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// fstream *file;
ofstream file;


// vector<vector<double>> pathLeft = {
//         {0,0},
//         {0.0384,3.75},
//         {0.0768,3.75},
//         {0.128,5.0002},
//         {0.1776,5.1684},
//         {0.2262,4.9355},
//         {0.2757,4.9679},
//         {0.3258,4.9821},
//         {0.3761,4.9892},
//         {0.4259,5.0668},
//         {0.4753,4.9809},
//         {0.5255,4.9286},
//         {0.5759,5.0548},
//         {0.6259,4.9922},
//         {0.6755,5.0414},
//         {0.7253,4.9465},
//         {0.7756,4.9975},
//         {0.8256,5.0368},
//         {0.8753,4.9947},
//         {0.9254,4.9622},
//         {0.9755,5.0329},
//         {1.0254,4.9977},
//         {1.0753,4.9984},
//         {1.1252,4.999},
//         {1.1751,4.9996},
//         {1.2251,5.0001},
//         {1.2753,4.976},
//         {1.3254,5.0266},
//         {1.3753,5.0011},
//         {1.4252,5.0014},
//         {1.4752,4.9805},
//         {1.5252,5.0241},
//         {1.5751,4.9823},
//         {1.6252,5.0037},
//         {1.6752,5.0038},
//         {1.7251,5.0039},
//         {1.7751,4.9865},
//         {1.8252,5.0051},
//         {1.8752,5.0051},
//         {1.9251,5.0051},
//         {1.9751,4.9895},
//         {2.0251,5.006},
//         {2.0751,4.9912},
//         {2.1252,5.0068},
//         {2.1752,4.9927},
//         {2.2253,5.0074},
//         {2.2752,5.0073},
//         {2.325,4.9942},
//         {2.375,4.9951},
//         {2.4251,4.9959},
//         {2.4752,5.0088},
//         {2.5252,4.9968},
//         {2.5752,4.9975},
//         {2.6252,5.0095},
//         {2.6751,4.9982},
//         {2.7251,4.988},
//         {2.7751,5.0105},
//         {2.8251,4.9999},
//         {2.875,5.0004},
//         {2.9251,4.9909},
//         {2.9751,5.0115},
//         {3.025,4.9921},
//         {3.0751,5.0025},
//         {3.1251,4.9936},
//         {3.1751,5.0126},
//         {3.225,4.9946},
//         {3.2751,4.9954},
//         {3.3251,5.0047},
//         {3.3751,4.9966},
//         {3.4251,5.0055},
//         {3.4751,4.9976},
//         {3.5251,4.9983},
//         {3.5751,4.9989},
//         {3.6251,5.0071},
//         {3.6751,4.9922},
//         {3.7251,5.0005},
//         {3.7751,5.0082},
//         {3.825,4.9941},
//         {3.8751,4.9949},
//         {3.9251,5.0094},
//         {3.975,4.996},
//         {4,2.4918},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,0},
//         {4,-0.0003},
//         {3.9745,-2.5572},
//         {3.9245,-4.9999},
//         {3.8745,-4.9929},
//         {3.8245,-5.0084},
//         {3.7745,-4.9938},
//         {3.7244,-5.002},
//         {3.6745,-5.0026},
//         {3.6244,-4.9951},
//         {3.5744,-5.0037},
//         {3.5245,-5.0045},
//         {3.4744,-4.9878},
//         {3.4244,-5.0144},
//         {3.3744,-4.9885},
//         {3.3244,-5.0068},
//         {3.2744,-4.9983},
//         {3.2244,-4.9988},
//         {3.1744,-4.9992},
//         {3.1244,-4.9997},
//         {3.0744,-5.0104},
//         {3.0245,-4.9908},
//         {2.9745,-5.0013},
//         {2.9245,-5.0019},
//         {2.8744,-4.9915},
//         {2.8244,-5.0141},
//         {2.7745,-4.9924},
//         {2.7244,-4.9924},
//         {2.6744,-5.0165},
//         {2.6244,-4.9812},
//         {2.5743,-5.0182},
//         {2.5244,-4.9941},
//         {2.4744,-4.9942},
//         {2.4244,-5.0078},
//         {2.3744,-4.995},
//         {2.3244,-5.0093},
//         {2.2744,-4.9815},
//         {2.2242,-5.0102},
//         {2.1743,-5.0116},
//         {2.1243,-4.9816},
//         {2.0743,-5.0127},
//         {2.0243,-4.9977},
//         {1.9743,-4.998},
//         {1.9243,-4.9983},
//         {1.8743,-4.9986},
//         {1.8244,-5.0176},
//         {1.7744,-4.9814},
//         {1.7243,-4.9997},
//         {1.6742,-5.0002},
//         {1.6243,-5.0218},
//         {1.5745,-4.9809},
//         {1.5244,-5.0018},
//         {1.4744,-5.0025},
//         {1.4242,-4.9792},
//         {1.3741,-5.0274},
//         {1.3243,-5.005},
//         {1.2743,-4.9788},
//         {1.2242,-5.0049},
//         {1.1742,-5.006},
//         {1.1243,-5.0073},
//         {1.0742,-4.9764},
//         {1.024,-5.0073},
//         {0.9739,-5.0089},
//         {0.924,-5.011},
//         {0.874,-4.973},
//         {0.8238,-5.0112},
//         {0.7738,-5.014},
//         {0.7237,-4.9684},
//         {0.6739,-5.0686},
//         {0.624,-4.9135},
//         {0.5739,-5.078},
//         {0.5242,-4.9623},
//         {0.4736,-4.951},
//         {0.4235,-5.1073},
//         {0.3741,-4.9524},
//         {0.3234,-4.9308},
//         {0.2723,-5.0252},
//         {0.2219,-5.0461},
//         {0.1729,-5.0969},
//         {0.1237,-4.884},
//         {0.0679,-4.5571}
//     }
// ;

vector<vector<double>> pathLeft = {
        {0,0},
        {0.0279,2.6923},
        {0.0761,4.9508},
        {0.1255,4.9322},
        {0.1755,5.0075},
        {0.2254,5.002},
        {0.2753,4.9999},
        {0.3252,4.9988},
        {0.3751,4.9981},
        {0.4251,4.9976},
        {0.4751,4.9971},
        {0.5251,5.0062},
        {0.5751,4.9948},
        {0.6251,5.0029},
        {0.6751,5.0012},
        {0.7251,4.9928},
        {0.7751,5.0062},
        {0.8251,4.9979},
        {0.8751,5.0031},
        {0.9251,4.9961},
        {0.9751,5.0063},
        {1.025,4.9944},
        {1.0751,4.9991},
        {1.1251,5.003},
        {1.1751,4.9974},
        {1.2251,5.0013},
        {1.2751,5.0004},
        {1.3251,4.9997},
        {1.375,5.003},
        {1.425,4.9946},
        {1.475,5.0056},
        {1.525,4.9939},
        {1.575,5.0044},
        {1.625,4.9969},
        {1.6751,5.0033},
        {1.725,4.9996},
        {1.775,4.9962},
        {1.825,5.0055},
        {1.875,4.996},
        {1.925,5.002},
        {1.975,4.9989},
        {2.025,4.999},
        {2.075,5.0018},
        {2.125,4.9991},
        {2.175,5.0019},
        {2.225,4.9969},
        {2.275,5.0023},
        {2.325,5},
        {2.375,5.0003},
        {2.425,4.9984},
        {2.475,5.0012},
        {2.525,4.9994},
        {2.575,5},
        {2.625,4.9985},
        {2.675,5.0014},
        {2.725,5},
        {2.775,5.0009},
        {2.825,4.9997},
        {2.875,4.9988},
        {2.925,5},
        {2.975,5.0012},
        {3.025,5.0005},
        {3.075,4.9982},
        {3.125,5.0016},
        {3.1465,2.1428},
        {3.0994,-4.7028},
        {3.0494,-4.9996},
        {2.9994,-4.9983},
        {2.9494,-5.0027},
        {2.8994,-4.9976},
        {2.8494,-5.002},
        {2.7994,-4.9986},
        {2.7494,-5.001},
        {2.6994,-4.9994},
        {2.6494,-4.9998},
        {2.5994,-5.0001},
        {2.5494,-5.0004},
        {2.4994,-4.9985},
        {2.4494,-5.0008},
        {2.3994,-5.001},
        {2.3494,-4.999},
        {2.2994,-5.0012},
        {2.2494,-4.9969},
        {2.1994,-5.0034},
        {2.1494,-4.9989},
        {2.0994,-4.9988},
        {2.0494,-5.0008},
        {1.9994,-5.0006},
        {1.9494,-4.9979},
        {1.8994,-5.0022},
        {1.8495,-4.9994},
        {1.7995,-4.9988},
        {1.7494,-5.0006},
        {1.6994,-4.9999},
        {1.6494,-4.9991},
        {1.5994,-5.0007},
        {1.5494,-4.9996},
        {1.4994,-5.0011},
        {1.4495,-4.9997},
        {1.3995,-4.9982},
        {1.3495,-5.002},
        {1.2994,-4.9974},
        {1.2494,-5.001},
        {1.1994,-5.0017},
        {1.1495,-4.9992},
        {1.0995,-4.9994},
        {1.0495,-4.9994},
        {0.9995,-4.9991},
        {0.9495,-5.0021},
        {0.8995,-4.9979},
        {0.8495,-5.0004},
        {0.7994,-4.9991},
        {0.7494,-5.0014},
        {0.6995,-4.9996},
        {0.6494,-4.9971},
        {0.5994,-5.0037},
        {0.5494,-4.996},
        {0.4994,-5.0034},
        {0.4494,-5.0007},
        {0.3994,-4.9972},
        {0.3494,-5.0006},
        {0.2994,-4.9974},
        {0.2494,-5.0048},
        {0.1994,-4.9925},
        {0.1494,-5.007},
        {0.0994,-4.9966},
        {0.0486,-4.9258}
    }
;

int main()
{
    cout << "hi";
    // file.open("leftOriginal.txt", ios::trunc);
    file.open("leftRaw.txt", ios::trunc);
    for(int i = 0; i < pathLeft.size(); i++) {
        file << pathLeft[i][0] << endl;
    }
    file.close();
}