#include "garaj.h"
#include "exceptii.h"

void garaj :: upgrade_masina(masina* &masina_jucator, int& bani){
    int opt;
    bool stop = false;

    while(!stop){
        cout<<"1. Upgrade motor V6 (300cp) | 500$\n";
        cout<<"2. Upgrade motor V10 (600cp) | 800$\n";
        cout<<"3. Cumpara diferential (masina Off Road) | 450$\n";
        cout<<"4. Iesire\n\n";
        cout<<"Introd opt: " ;

        cin>>opt;
        try{
            switch(opt){
                case 1:
                    if(bani < 500){
                        throw ExceptieBaniInsuficienti();
                    }
                    else if(masina_jucator->getMotor()->getCaiPutere() > 300)
                        throw ExceptieMotor();
                    else{
                        masina_jucator->upgrade(300);
                        cout<<"Felicitari! Acum motorul tau are "<<masina_jucator->getMotor()->getCaiPutere()<<" CP.";
                        bani-=500;
                    }
                    break;
                case 2:
                    if(bani < 800){
                        throw ExceptieBaniInsuficienti();
                    }
                    else if(masina_jucator->getMotor()->getCaiPutere() > 600)
                        throw ExceptieMotor();
                    else{
                        masina_jucator->upgrade(600);
                        cout<<"Felicitari! Acum motorul tau are "<<masina_jucator->getMotor()->getCaiPutere()<<" CP.";
                        bani-=800;
                    }
                    break;
                case 3:
                {
                    if(bani < 450){
                        throw ExceptieBaniInsuficienti();
                    }
                    masinaOffRoad* p = dynamic_cast<masinaOffRoad*>(masina_jucator);
                    if(p == NULL)
                        throw ExceptieMasinaOffRoad();
                    else{
                        if(p->getDiferential() == 1)
                            cout<<"Ai deja un diferential pe masina!\n";
                        else{
                            p->setDiferential(1);
                            cout<<"Felicitari! Acum masina ta are un diferential montat!\n";
                            bani-=450;
                        }
                    }
                    break;
                }
                case 4:
                    stop = true;
                    break;
                default:
                    cout<<"Optiune invalida!\n";
                    break;
            }
        }
        catch(const exception& e){
            cout<<e.what();
        }
        system("pause");
    	system("cls");
    }
}


void garaj::update_masina(masina* &masina_jucator, pilot& jucator, masina* m){
    masina* masina_veche = masina_jucator;
    delete masina_veche;
    masina_jucator = m;
    masina_jucator->setPilot(&jucator);
}
void garaj::cumpara_masina(masina* &masina_jucator, pilot& jucator, int& bani){
    int opt;
    bool stop = false;
    while(!stop){
        cout<<"1. Cumpara masina Off Road (170cp, 270nm) | 1500$\n";
        cout<<"2. Cumpara masina Electrica (220cp, 340nm) | 2500$\n";
        cout<<"3. Cumpara masina F1 (400cp, 450nm) | 5000$\n";
        cout<<"4. Iesire\n\n";
        cout<<"Introd opt: ";

        cin>>opt;
        switch(opt){
            case 1:
                if(bani < 1500){
                    cout<<"Nu ai suficienti bani!\n";
                    break;
                }
                else{
                    update_masina(masina_jucator, jucator ,new masinaOffRoad("Opel Astra G", new motorCombustibil(170, 270, "diesel", 100), 75, 0));
                    bani-=1500;
                    cout<<"Felicitari! Acum masina ta este una de Off Road!\n";
                }
                break;
            case 2:
                if(bani < 2500){
                    cout<<"Nu ai suficienti bani!\n";
                    break;
                }
                else{
                    update_masina(masina_jucator, jucator, new masinaElectrica("Opel Astra G", new motorElectric(220, 340, 100), 100));
                    bani-=2500;
                    cout<<"Felicitari! Acum masina ta este una Electrica!\n";
                }
                break;
            case 3:
                if(bani < 5000){
                    cout<<"Nu ai suficienti bani!\n";
                    break;
                }
                else{
                    update_masina(masina_jucator, jucator, new masinaF1("Opel Astra G", new motorHibrid(400, 450, "benzina", 100, 100), 100));
                    bani-=5000;
                    cout<<"Felicitari! Acum masina ta este una de F1!\n";
                }
                break;
            case 4:
                stop = true;
                break;
            default:
                cout<<"Optiune invalida!\n";
                break;
        }
        system("pause");
    	system("cls");
    }
}

void garaj::meniu_garaj(masina* &masina_jucator, pilot& jucator, int& bani){
    int optiune;
    bool stop = false;

    while(!stop) {
        cout<<"Bine ai venit in garaj!\n\n";
        cout<<"1. Informatii masina\n";
        cout<<"2. Upgrade\n";
        cout<<"3. Cumpara masina\n";
        cout<<"4. Iesire\n";

        cout<<"Introdu opt: ";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
            masina_jucator->afisare_jucator();
            cout<<"\n\n";
            break;
        case 2:
            upgrade_masina(masina_jucator, bani);
            break;
        case 3:
            cumpara_masina(masina_jucator, jucator, bani);
            break;
        case 4:
            stop = true;
            break;
        default:
            cout<<"Optiune invalida!\n";
            break;
        }
        system("pause");
    	system("cls");
    }
}