//
// Created by ariana on 10/05/19.
//

#include "Arena.h"

void Arena::Run(Fight &fight) {
    int scoreA=fight.A->defense()-fight.B->attack();
    int scoreB=fight.B->defense()-fight.A->attack();
    if(scoreA>scoreB){
        fight.winner=fight.A;
        fight.score=scoreA;
    }else if(scoreA<scoreB){
        fight.winner=fight.B;
        fight.score=scoreB;
    }
}

void ReadFighter(std::ifstream* rfile,std::string line, Fighter* &A){
    getline(*rfile, line);
    line.pop_back();
    if(line=="BL") {
        A = new BruceLee();
    }
    else if(line=="CN")
        A=new ChuckNorris();
    else if(line=="JS")
        A=new JasonStatham();
    getline(*rfile,line);
    line.pop_back();
    for(int i=0; i<line.size();i+=3){
        A->add_defense(line[i]);
    }
    getline(*rfile,line);
    for(int i=0; i<line.size();i+=3){
        A->add_attack(line[i]);
    }
}

void Arena::load_fights(std::string filename) {
    std::ifstream rfile(filename);
    std::vector<Fight> fights1;
    if(rfile.is_open()){
        std::string line,part;
        while(!rfile.eof()) {
            Fight* f=new Fight();
            Fighter* A= nullptr;
            Fighter* B= nullptr;
            ReadFighter(&rfile,line,A);
            ReadFighter(&rfile,line,B);
            f->A=A;
            f->B=B;
            fights.push_back(f);
        }
    }
    rfile.close();
}

void Arena::Run_all() {
    for(int i=0;i<fights.size();i++){
        Run(*fights[i]);
    }
}