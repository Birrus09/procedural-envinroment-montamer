#include <string>
#include <fstream>

struct node{
    int x;
    int y;
    int amplitude;
    int temperature;
};


struct region{
    //bottom left
    int xorigin;
    int yorigin;
    vector<vector<float>> rows;
    string name;
};

struct world{
    vector<vector<region>> rows;
    int width;
    int height;
};

void CreateWorldFile(string filename, vector<float> noisemap, int seed, int xworld, int yworld){
    ofstream noisefile(filename);
    noisefile << seed << ", " << xworld << ", " << yworld << endl;
    for (int i = 0; i < xworld; i++){
        for (int k = 0; k < yworld; k++)
            noisefile << i << ", " << k << ", " << noisemap[i] << endl;
    }
    noisefile.close();
}

void UpdateWorldFile();

void GenerateTerrain();

void AssignBiome();
