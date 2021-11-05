
#include "Individual.h"
#include "stdlib.h"
#include "cmath"

Individual::Individual(int genesQuantity, vector<Vec3b> colorsList) {
    this->colorsList = colorsList;
    this->genesQuantity = genesQuantity;
    this->fitness = 0;
    for(int i = 0;  i < this->colorsList.size(); i++){
        this->quantityOfEachGen.insert(quantityOfEachGen.cend(),0);
    }

    int flag;
    for (int p = 0; p < genesQuantity; p++) {
        flag = rand() % colorsList.size();
        Vec3b color = colorsList[flag];
        this->genes.insert(genes.cend(), color );
        }

    this->quantities();
    this->pixelsPercentage();
    }
Individual::Individual(int genesQuantity, vector<Vec3b> colorsList, vector<double> crossoverIndPercentajes){
    this->fitness = 0;
    this->colorsList = colorsList;
    this->genesQuantity = genesQuantity;


    for(int i = 0;  i < this->colorsList.size(); i++){
        double quantity = (double)genesQuantity*(crossoverIndPercentajes[i]/(double)100);
        this->quantityOfEachGen.insert(quantityOfEachGen.cend(),(int)round(quantity));
    }

    Vec3b white;
    white[0]=255;
    white[1]=255;
    white[2]=255;


    for (int i = 0; i < genesQuantity; i++) {
        this->genes.insert(genes.cend(),white);
    }

    for (int i = 0; i < colorsList.size()  ; i++) {
        int running = this->quantityOfEachGen[i];
        int pos;
        Vec3b  color = colorsList[i];
        while(running != 0){
            pos = rand() % genesQuantity;
            if(this->genes[pos][0]==255 & this->genes[pos][1]==255 & this->genes[pos][2]==255){
                this->genes[pos] = color;
                running--;
            }
        }
    }
    this->pixelsPercentage();
}


void Individual::quantities(){
    for (int i = 0; i < this->genesQuantity; i++) {
        for(int j = 0; j < this->colorsList.size(); j++){
            Vec3b color = this->colorsList[j];
            if (this->genes[i][0] == color[0] & genes[i][1] == color[1]  & genes[i][2] == color[2]  ){
                this->quantityOfEachGen[j] += 1;
                break;
            }
        }
    }
}

void Individual::pixelsPercentage(){
    double percentage;
    for (int i = 0; i < this->quantityOfEachGen.size() ; i++) {
        percentage = ((double)this->quantityOfEachGen[i]/(double)this->genes.size())*100;
        this->IndividualPercentages.insert(IndividualPercentages.cend(),percentage);
    }
}

    void Individual::calculateIndFitness(vector<double> percentages){
    double fitnessCase = 10 * this->IndividualPercentages.size();
    double difference;
    double sumDifferences = 0;

    for (int i = 0; i < percentages.size() ; ++i) {
        difference = abs(this->IndividualPercentages[i]-percentages[i]);
        sumDifferences += difference;
    }
    this->fitness = (int)sumDifferences;
}

vector<Vec3b> Individual::getGenes() {
    return this->genes;
}

int Individual::getFitness() {
    return this->fitness;
}

int Individual::getGenesQuantity() {
    return this->genesQuantity;
}
vector<int> Individual::getQuantityOfEachGen() {
    return this->quantityOfEachGen;
}
vector<double> Individual::getRectanglePercentages() {
    return this->IndividualPercentages;
}
vector <Vec3b> Individual::getColors() {
    return this->colorsList;
}