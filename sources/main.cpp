#include <iostream>
#include "../headers/clases.h"
#include "../headers/tools.h"
#include "../headers/math_tools.h"
#include "../headers/sel.h"

using namespace std;

int main(int argc, char const *argv[])
{
    vector<Matrix> localKs;
    vector<Vector> localbs;
.
    Matrix K;
    Vector b;
    Vector T;

    cout << "IMPLEMENTACI" << char(224) << "N DEL M" << char(144) << "TODO DE LOS ELEMENTOS FINITOS\n"
            << "\t- TRANSFERENCIA DE CALOR\n"
            << "\t- 1 DIMENSI" << char(224) << "N\n"
            << "\t- FUNCIONES DE FORMA LINEALES\n"
            << "\t- PESOS DE GALERKIN\n"
            << "*********************************************************************************\n\n";

    mesh m;
    leerMallayCondiciones(m);

    crearSistemasLocales(m, localKs, localbs);
    //showKs(localKs); showbs(localbs);

    zeroes(K, m.getSize(NODES));
    zeroes(b, m.getSize(NODES));
    ensamblaje(m, localKs, localbs, K, b);
    //showMatrix(K); showVector(b);

    applyNeumann(m, b);
    //showVector(b);

    applyDirichlet(m, K, b);
    //showMatrix(K); showVector(b);

    zeroes(T, b.size());
    calculate(K, b, T);

    cout << "La respuesta es: \n";
    showVector(T);
    return 0;
}
