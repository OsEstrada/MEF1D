#pragma once
#include "clases.h"
#include <fstream>
using namespace std;

void obtenerDatos(ifstream& file, int nlines, int n, int mode, item* item_list){
    string line;
    file >> line;
    if(nlines == DOUBLELINE) file >> line;
    for(int i = 0; i<n; i++){
        switch(mode){
            case INT_FLOAT:
                int e; float r;
                file >> e >> r;
                item_list[i].setIntFloat(e,r);
                break;
            case INT_INT_INT:
                int e1,e2,e3;
                file >> e1 >> e2 >> e3;
                item_list[i].setIntIntInt(e1,e2,e3);
                break;
        }
    }

}

void leerMallayCondiciones(mesh &m){
    string filename;
    ifstream file;
    float l,k,Q;
    int nnodes,neltos,ndirich,nneu;
    do{
        cout << "Ingrese el nombre del archivo que contiene los datos de la malla: ";
        cin >> filename;
        file.open(filename);
    }while(!file);
    file >> l >> k >> Q; 
    file >> nnodes >> neltos >> ndirich >> nneu;

    m.setParameters(l,k,Q);
    m.setSizes(nnodes, neltos, ndirich, nneu);
    m.crateData();

    obtenerDatos(file, SINGLELINE, nnodes, INT_FLOAT, m.getNodes());
    obtenerDatos(file, DOUBLELINE, neltos, INT_INT_INT, m.getElements());
    obtenerDatos(file, DOUBLELINE, ndirich, INT_FLOAT, m.getDirichlet());
    obtenerDatos(file, DOUBLELINE, nneu, INT_FLOAT, m.getNeumann());

    file.close();

}