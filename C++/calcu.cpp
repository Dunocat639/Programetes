#include <iostream>
#include <thread>
#include <chrono>

    double calcular(char operador, double x, double y){

        switch(operador){
            case '+':
                return x + y;
            
            case '-':
                return x - y;
            
            case '/':
                return x / y;
            
            case '*':
                return x * y;

            default:
                return 0;

        }
    }

    void puntets(int temps){
        for (int i = 0; i < 3; i++)
        {
            std::cout << ".";
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(temps));
        }
        std::cout << '\n';
        
    }

int main(){

    std::string calcu = true;

    while (calcu == true){

        char operador;
        double x;
        double y;
        char continuar;

        std::cout << "****************** Calculadora premium 3000 ******************" << '\n' << '\n';

        std::cout << "Escriu el primer número: ";
        std::cin >> x;
        std::cout << '\n';

        std::cout << "Molt bé. Ara el segon número: ";
        std::cin >> y;
        std::cout << '\n';

        std::cout << "Que vols fer amb aquestos dos numerets? (+ - * /): ";
        std::cin >> operador;
        std::cout << '\n' << '\n';

        std::cout << "Perfecte!" << '\n'  << '\n';

        std::cout << "Netejant bufLfer de dades";
        puntets(500);

        std::cout << "Calculant variables abstractes";
        puntets(500);

        std::cout << "Descarregant resultats quàntics";
        puntets(500);



        std::cout << '\n';
        std::cout << '\n';

        std::cout << "Ja està!" << '\n' << '\n'<< "El resultat d'aqusta complicadíssima operació és: " << calcular(operador, x, y) << '\n' << '\n';
        std::cout << "Gràcies per usar el nostre servei!" << '\n';

        std::cout << "Vol tornar a repetir? (s/n): ";
        std::cin >> continuar;

        if(continuar == 's' || continuar == 'S'){
            std::cout << "Doncs tornem :)" << '\n' << '\n';
            calcu = true;
        }
        else if(continuar == 'n' || continuar == 'N'){
            std::cout << "Pos vale :(" << '\n';
            puntets(1000);
            calcu = false;
        }
        else{
            std::cout << "No sé que coi has dit però m'ho prendré com un no";
            puntets(1000);
            calcu = false;
        }

        
        

    }

    return 0;

}