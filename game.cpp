#include "game.h"

game* game::instance = NULL;

void game::uiMeniu() {
	cout << "\n==== Joc curse POO ====\n";
    cout << "Bani actuali: " << bani  << "$\n";
    cout << "1. Adauga adversari\n";
    cout << "2. Garaj \n";
    cout << "3. Start Cursa\n";
    cout << "4. Statistici personale\n";
    cout << "5. Afisare adversari("<<masina_jucator->getContor() - 1<<")\n";
    cout << "6. Top victorii\n";
    cout << "0. Iesire\n";
    cout << "=========================\n";
}


game::~game(){
    delete masina_jucator;
    for (masina* m : adversari){
        delete m;
    }
}


void game::meniu(){
    int dif;
    cout<<"Alege dificultatea (0: EASY, 1: MEDIUM, 2: HARD)\n";
    cin>>dif;
    switch(dif){
        case 0:
            this->dificultate = EASY;
            break;
        case 1:
            this->dificultate = MEDIUM;
            break;
        case 2:
            this->dificultate = HARD;
            break;
        default:
            cout<<"Optiune invalida! Dificultatea va fi implicit MEDIUM\n";
            this->dificultate = MEDIUM;
            break;
    }
    adversari_impliciti();
    string nume;
    cout<<"Cum vrei sa te numesti?\n";
    cin>>nume;
    this->jucator = pilot(nume, 10); 
    masina_jucator->setPilot(&(this->jucator));
    cout<<"Jocul este setat cu 3 adversari default\n";
    bool stop = false;
	int opt;
	while(stop == false) {
    	uiMeniu();
    	cout<<"Introd opt: ";
    	cin>>opt;

    	switch (opt) {
        	case 1:
                citire_adversari();
            	break;
        	case 2:{
                garaj gar;
                gar.meniu_garaj(masina_jucator, jucator, bani);
             	break;
            }
        	case 3:
                start_cursa();
            	break;
        	case 4:
                statistici_personale();
            	break;
            case 5:
                afisare_adversari();
                break;
            case 6:
                victorii();
                break;
        	case 0:
            	stop = true;
            	break;
        	default:
            	cout << "Optiune invalida! Incearca din nou.\n";
    	}

    	system("pause");
    	system("cls");

	}
}

void game::citire_adversari(){
    int n;
    cout<<"Cati adversari vrei sa adaugi?\n";
    cin>>n;

    for(int i = 1; i<=n; i++){
        pilot pilot_temporar;
        masina* masina_temporara;

        cout<<"Introdu numele pentru oponentul "<<i<<": \n";
        string nume;
        cin>>nume;
        pilot_temporar.setNume(nume);
        pilot_temporar.genereaza_skill();
        piloti.push_back(pilot_temporar);

        cout<<"Ce tip de masina vrei sa citesti?\n1 - Masina Standard\n2 - Masina Electrica\n3 - Masina Off Road\n4 - Masina F1";
        int opt;
        cin>>opt;
        if(opt == 1){
            masina_temporara = new masinaStandard();
            cin>>*masina_temporara;
        }
        else if(opt == 2){
            masina_temporara = new masinaElectrica();
            cin>>*masina_temporara;
        }
        else if(opt == 3){
            masina_temporara = new masinaOffRoad();
            cin>>*masina_temporara;
        }
        else if(opt == 4){
            masina_temporara = new masinaF1();
            cin>>*masina_temporara;
        }
        else
            cout<<"Optiune invalida.";


        masina_temporara->setPilot(&piloti.back());
        adversari.push_back(masina_temporara);
    }
}

void game :: adversari_impliciti(){
    if (dificultate == EASY){
        masina* p = new masinaStandard();
        p->generare_masina();
        adversari.push_back(p);
        masina* q = new masinaStandard();
        q->generare_masina();
        adversari.push_back(q);
        masina* t = new masinaOffRoad();
        t->generare_masina();
        adversari.push_back(t);
    }
    else if (dificultate == MEDIUM){
        masina* p = new masinaOffRoad();
        p->generare_masina();
        adversari.push_back(p);
        masina* q = new masinaOffRoad();
        q->generare_masina();
        adversari.push_back(q);
        masina* t = new masinaElectrica();
        t->generare_masina();
        adversari.push_back(t);
    }
    else{
        masina* p = new masinaF1();
        p->generare_masina();
        adversari.push_back(p);
        masina* q = new masinaF1();
        q->generare_masina();
        adversari.push_back(q);
        masina* t = new masinaElectrica();
        t->generare_masina();
        adversari.push_back(t);
    }
}


void game::afisare_adversari(){
    for(masina* m : adversari){
        cout<<*m<<"\n";
    }
}

void game::statistici_personale(){
    jucator.afisare_jucator();
    masina_jucator->afisare_jucator();
}

void game::start_cursa(){
    cout<<"\n\n";
    masina_jucator->reseteaza();
    for(masina* m : adversari){
        m->reseteaza();
    }
    int laps = 5;
    int cnt = 1;
    int opt;
    bool stop = false;
    while(!stop){
        if(cnt > laps){
            stop = true;
            clasament<masina*> c;
            c.adauga(masina_jucator);
            for(masina* m : adversari)
                c.adauga(m);
            c.sortare([](masina* a, masina* b) {return *b < *a;});
            vector<masina*> v = c.getElemente();
            int contor = 0;
            int castig;
            for(masina* m : v){
                contor++;
                if(*masina_jucator == *m){
                    castig = (v.size() - contor + 1) *100;
                    break;
                }
            }
            
            bani+=castig;
            jucator.setSkill(jucator.getSkill() + (v.size() - contor + 1));
            c.afisare();
            v[0]->getPilot()->adauga_cursa_castigata();
            if(contor == 1){
                cout<<"Felicitari! ai castigat cursa, primind o suma de "<<castig<<"$\n";
            }
            else{
                cout<<"Din pacate, ai luat doar locul "<<contor<<"! Totusi ai primit o suma de "<<castig<<"$\n";
            }
            break;
        }
        cout<<"1. Start lap "<<cnt<<"\n";
        cout<<"2. Afiseaza clasament\n";
        cout<<"3. Iesire\n";
        cout<<"=================";
        cout<<"Introd opt: ";
        cin>>opt;
        switch(opt){
            case 1:
                masina_jucator->calculeaza_distanta(5);
                for(masina* m : adversari){
                    m->calculeaza_distanta(5);
                }
                cout<<"Lapul "<<cnt<<" s-a terminat\n";
                cnt++;
                break;
            case 2:{
                clasament<masina*> c;
                c.adauga(masina_jucator);
                for(masina* m : adversari)
                    c.adauga(m);
                c.sortare([](masina* a, masina* b) {return *b < *a;});
                c.afisare();
                break;
            }
            case 3:
                stop = true;
                break;
            default:
                cout<<"optiune invalida";
                break;
        }
        system("pause");
    	system("cls");
    }
}

void game :: victorii() const{
    clasament<pilot> p;
    p.adauga(jucator);
    for(pilot pil : piloti)
        p.adauga(pil);
    p.sortare([](pilot a, pilot b){return b < a;});
    p.afisare();
}