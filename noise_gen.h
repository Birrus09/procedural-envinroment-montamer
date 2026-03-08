//noise generation and processing
#include <vector>
#include <fstream>
#include "randomcust.h"

using namespace std;



//generate noisemap
vector<float> PureNoise(int width, int height, int seed){
    vector<float> ret;
    float temp = 0;
    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            temp = randomnum(seed);
            ret.push_back(temp);
        }
    }
    return ret;
}


//biggify
vector<float> Biggify(int width, int height, int scale_factor, vector<float> origin){
    vector<float> biggified;
        // create temporary biggified line
        for (int i = 0; i < height; i++){
            vector<float> temp;
            for (int j = 0; j < width; j++)
            {
                for (int k = 0; k < scale_factor; k++){
                    temp.push_back(origin[j + width * i]);
                }
            }
            //and paste x times
            for (int k = 0; k < scale_factor; k++){
                biggified.insert(biggified.end(), temp.begin(), temp.end());
            }
        }
        return biggified;
}

//convolution
void Convolution(int width, int height, vector<float> &origin){
    vector<float> temp;

    // do stuff

    origin = temp;
}


//clip/gate
void ClipGate(float treshold, vector<float> &origin, int mode = 0){
    if (mode==0){
        //clip
        for (int i = 0; i < origin.size(); i++){
            if (origin[i] >= treshold){
                origin[i] = treshold;
            }                
        }
    }
    else{
        //gate
        for (int i = 0; i < origin.size(); i++){
            if (origin[i] <= treshold){
                origin[i] = 0;
            }
        }
    }
}



//compress(steepify)

//perlin?



//files stuff


void CreateNoiseFile(string filename, vector<float> noisemap, int seed){
    ofstream noisefile(filename);
    noisefile << seed << endl;
    for (int i = 0; i < noisemap.size(); i++){
        noisefile << noisemap[i] << " ";
    }
    noisefile.close();
}
