//
// Created by ariana on 10/05/19.
//

#include "Arena.h"

void Arena::add_fight(Fight f) {
    fights.push_back(f);
}

void Arena::load_fights(std::string filename) {
    std::ifstream rfile(filename);
    std::string iden1, iden2;
    std::vector<int> d1,d2,a1,a2;
    if(rfile.is_open()){
        std::string line;
        getline(rfile,line);
        iden1=line;
        getline(rfile,line);
        std::istringstream sub1(line);
        while (getline(sub1,line,',')){
            if(line=="E"){
                Elude e;
                d1.push_back(e.defense());
            }else{
                if(line=="S"){
                    Shield s;
                    d1.push_back(s.defense());
                }else{
                    if(line=="A"){
                        Armor a;
                        d1.push_back(a.defense());
                    }
                }
            }
        }
        getline(rfile,line);
        std::istringstream sub2(line);
        while (getline(sub2,line,',')){
            if(line=="P"){
                Punch p;
                d1.push_back(p.attack());
            }else{
                if(line=="S"){
                    Saber s;
                    d1.push_back(s.attack());
                }else{
                    if(line=="F"){
                        Firearm f;
                        d1.push_back(f.attack());
                    }
                }
            }
        }
        getline(rfile,line);
        iden2=line;
        getline(rfile,line);
        std::istringstream sub3(line);
        while (getline(sub3,line,',')){
            if(line=="E"){
                Elude e;
                d1.push_back(e.defense());
            }else{
                if(line=="S"){
                    Shield s;
                    d1.push_back(s.defense());
                }else{
                    if(line=="A"){
                        Armor a;
                        d1.push_back(a.defense());
                    }
                }
            }
        }
        getline(rfile,line);
        std::istringstream sub4(line);
        while (getline(sub4,line,',')){
            if(line=="P"){
                Punch p;
                d1.push_back(p.attack());
            }else{
                if(line=="S"){
                    Saber s;
                    d1.push_back(s.attack());
                }else{
                    if(line=="F"){
                        Firearm f;
                        d1.push_back(f.attack());
                    }
                }
            }
        }
    }
    rfile.close();
}

void Arena::run(Fighter A, Fighter B) {
    Fight f(&A,&B);
    int scorea=A.defense()-B.attack();
    int scoreb=B.defense()-A.attack();
    if(scorea>scoreb) {
        f.SetScore(scorea);
        f.SetWinner(&A);
    }else{
        if(scorea>scoreb){
            f.SetScore(scoreb);
            f.SetWinner(&B);
        }
    }
}

void Arena::run_all() {
    for(int i=0; i<fights.size();i++){
        run()
    }
}