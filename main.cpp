#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;

void Bossreact(int attaccoNemico)
{
    int numeroCasuale = rand() % 4;
    switch (numeroCasuale)
    {
    case 0:
        cout << "\033[3;31mIl Boss ti contrattacca e ti ferisce per " << attaccoNemico << " danni...\033[0m" << endl;
        break;
    case 1:
        cout << "\033[3;31mIl Boss ringhia e ti colpisce con violenza: -" << attaccoNemico << " HP!\033[0m" << endl;
        break;
    case 2:
        cout << "\033[3;31mIl Boss reagisce con furia e ti infligge " << attaccoNemico << " danni...\033[0m" << endl;
        break;
    case 3:
        cout << "\033[3;31mUn colpo improvviso! Il Boss ti ferisce per " << attaccoNemico << " danni!\033[0m" << endl;
        break;
    }
}

void Logo()
{
    cout << "\033[38;2;255;255;255m" << endl;
    cout << "███████╗██╗███╗   ██╗ █████╗ ██╗          ██████╗ ███████╗ ██████╗  ██╗   ██╗██╗███████╗███╗   ███╗" << endl;
    cout << "██╔════╝██║████╗  ██║██╔══██╗██║          ██╔══██╗██╔════╝██╔═══██╗ ██║   ██║██║██╔════╝████╗ ████║" << endl;
    cout << "█████╗  ██║██╔██╗ ██║███████║██║          ██████╔╝█████╗  ██║   ██║ ██║   ██║██║█████╗  ██╔████╔██║" << endl;
    cout << "██╔══╝  ██║██║╚██╗██║██╔══██║██║          ██╔══██╗██╔══╝  ██║   ██║ ██║   ██║██║██╔══╝  ██║╚██╔╝██║" << endl;
    cout << "██║     ██║██║ ╚████║██║  ██║███████╗     ██║  ██║███████╗╚████████╗╚██████╔╝██║███████╗██║ ╚═╝ ██║" << endl;
    cout << "╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚══════╝     ╚═╝  ╚═╝╚══════╝ ╚════████ ╚═════╝ ╚═╝╚══════╝╚═╝     ╚═╝" << endl;
    cout << "======================================================================================================" << endl;
    cout << "                                      BENVENUTO IN FINAL REQUIEM                                      " << endl;
    cout << "======================================================================================================\033[0m" << endl;
}

void Zona(int &scelta, int supl[], string &boss, bool partenza)
{
    string arr[5] = {
        "\033[3;31mLe Montagne di Fuoco\033[0m",
        "\033[3;33mIl Deserto degli Echi Perduti\033[0m",
        "\033[3;36mLe Isole Fluttuanti di Aetheris\033[0m",
        "\033[3;35mLa Foresta di Ombre\033[0m",
        "\033[3;32mLa Valle dei Giganti Dormienti\033[0m"};

    while (true)
    {
        if (partenza)
        {
            cout << "\033[1mDecidi da che area vuoi partire:\033[0m" << endl;
        }
        else
        {
            cout << "\033[1mDecidi l'area:\033[0m" << endl;
        }
        // Mostra solo le zone non ancora visitate
        for (int i = 0; i < 5; ++i)
        {                                                 // sintassi: find(inizio_puntr, fine_puntr, valore_da_trovare)
            if (find(supl, supl + 5, i) == supl + 5)      // supl(array) è nel find un puntatore al primo elemento (equivale a supl[0])
            {                                             // supl + 5 punta al 5 elemento (equivale a supl[5])
                cout << i + 1 << " - " << arr[i] << endl; // == supl + 5 perche il find restituisce il valore finale se non trova niente
            }
        }
        cout << "\033[3m> \033[0m";
        cin >> scelta;
        scelta = clamp(scelta, 1, 5) - 1;
        switch (scelta)
        {
        case 0:
            boss = "PYRAETHROS";
            break;
        case 1:
            boss = "ZARH'ETH";
            break;
        case 2:
            boss = "AELYRIA";
            break;
        case 3:
            boss = "XELTHARIS";
            break;
        case 4:
            boss = "THALGRAM";
            break;
        }

        // Controlla se la zona è già stata visitata
        if (find(supl, supl + 5, scelta) != supl + 5)
        {
            cout << "Sei gia' stato qua! Scegli un'altra zona." << endl;
        }
        else
        {
            break;
        }
    }

    supl[scelta] = scelta; // Marca la zona come visitata
    cout << "\033[1mHai scelto: \033[0m" << arr[scelta] << endl;
    cout << "\033[1mBella scelta! Premi un pulsante per andare avanti...\033[0m" << endl;
    cin.ignore();
    cin.get();
    cout << "\033[2J\033[H";
}

void Hud(int hp, int hp1, string player, int count, int hpmax, string boss, int nboss, int penalita)
{
    int saluteVisualizzata, hp1max = 0, salute, saluteMassima;
    hp1max = 120 + count;
    if (nboss == 5)
    {
        hp1max = 300 + penalita;
    }
    cout << "\033[1;37m+==============HUD==============+\033[0m" << endl;
    for (int i = 0; i < 2; ++i)
    {
        switch (i)
        {
        case 0:
            cout << "\033[1;31m" << player << "\033[0m" << endl;
            saluteVisualizzata = (hp * 20) / hpmax;
            salute = hp;
            saluteMassima = hpmax;
            break;
        case 1:
            cout << "\033[1;31m" << boss << "\033[0m" << endl;
            saluteVisualizzata = (hp1 * 20) / hp1max;
            salute = hp1;
            saluteMassima = hp1max;
            break;
        }
        cout << "[";
        for (int i = 0; i < 20; i++)
        {
            if (i < saluteVisualizzata)
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }
        }
        cout << "] " << salute << "/" << saluteMassima << " HP" << endl;
        if (i == 0)
        {
            cout << endl;
        }
    }
    cout << "\033[1;37m+===============================+\033[0m" << endl;
    cout << endl;
}

void Attacco1(int &hp1, int rangeAttacco, int incremento)
{
    int attacco1 = rand() % (15 - rangeAttacco + incremento) + (5 + rangeAttacco);
    hp1 -= attacco1;
    cout << "\033[3;37mInfliggi un colpo potente! Il Boss subisce " << attacco1 << " danni!\033[0m" << endl;
}

bool Debufff()
{
    bool debuffer;
    int randomNum = rand() % 101;
    if (randomNum < 25)
    {
        debuffer = true;
    }
    else
    {
        debuffer = false;
    }
    return debuffer;
}

void Attacco2(int &hp1, bool &check, int rangeAttacco, int incremento)
{
    int attacco2 = rand() % (8 - rangeAttacco + incremento - 2) + (5 + rangeAttacco);
    hp1 -= attacco2;
    bool a = Debufff();
    if (a)
    {
        cout << "\033[3;38;2;255;229;0mIl debuff si e' attivato e ha addormentato il nemico per tutto il prossimo turno!\033[0m" << endl;
        check = false;
    }
    else
    {
        cout << "\033[3;38;2;171;171;171mIl debuff non e' avvenuto\033[0m" << endl;
        check = true;
    }
    cout << "\033[3;37mHai inflitto " << attacco2 << " danni\033[0m" << endl;
}

bool Critico()
{
    bool critico = false;
    int randomNum = rand() % 101;
    if (randomNum > 82)
    {
        critico = true;
    }
    return critico;
}

void Attacco3(int &hp1, bool &veleno, int &turniVeleno, int rangeAttacco, int incremento)
{
    int attacco3 = rand() % (7 - rangeAttacco + incremento - 4) + (3 + rangeAttacco);
    hp1 -= attacco3;
    if (Critico())
    {
        hp1 -= 50;
        cout << "\033[3;38;2;255;229;0mIl colpo critico si e' attivato e stai per infliggere 50 danni\033[0m" << endl;
    }
    else
    {
        cout << "\033[3;38;2;171;171;171mil colpo critico non e' avvenuto\033[0m" << endl;
        veleno = true;
        turniVeleno = 0;
    }
    cout << "\033[3;37mUn fendente preciso! Il Boss subisce " << attacco3 << " danni!\033[0m" << endl;
}

void Heal(int &hp, int &volte, bool &curato, int hpmax, int difficulty)
{
    int heal;
    if (volte == 3)
    {
        cout << "Non puoi curarti piu' di 3 volte!" << endl;
        curato = true;
        return;
    }
    volte++;
    int percentuale = hp * 100 / hpmax;

    if (difficulty == 3)
    {
        if (percentuale < 20)
        {
            heal = rand() % 11 + 15; // Cura: 15-25 HP
        }
        else if (percentuale < 40)
        {
            heal = rand() % 9 + 10; // Cura: 10-18 HP
        }
        else if (percentuale < 60)
        {
            heal = rand() % 6 + 7; // Cura: 7-12 HP
        }
        else
        {
            heal = rand() % 5 + 3; // Cura: 3-7 HP
        }
    }
    // Logica per Medio (75 HP)
    else if (difficulty == 2)
    {
        if (percentuale < 20)
        {
            heal = rand() % 16 + 22; // Cura: 22-37 HP
        }
        else if (percentuale < 40)
        {
            heal = rand() % 13 + 15; // Cura: 15-27 HP
        }
        else if (percentuale < 60)
        {
            heal = rand() % 9 + 10; // Cura: 10-18 HP
        }
        else
        {
            heal = rand() % 7 + 4; // Cura: 4-10 HP
        }
    }
    // Logica per Facile (100 HP) e default
    else if (difficulty == 1)
    {
        if (percentuale < 20)
        {
            heal = rand() % 21 + 30; // Cura: 30-50 HP
        }
        else if (percentuale < 40)
        {
            heal = rand() % 17 + 20; // Cura: 20-36 HP
        }
        else if (percentuale < 60)
        {
            heal = rand() % 11 + 14; // Cura: 14-24 HP
        }
        else
        {
            heal = rand() % 9 + 6; // Cura: 6-14 HP
        }
    }
    else
    {
        cout << "Hai troppa vita per curarti!" << endl;
        volte--;
        curato = true;
        return;
    }
    curato = true;
    hp += heal;
    if (hp > hpmax)
    {
        heal = heal - (hp - hpmax); // calcola la cura in eccesso e modifica il valore di heal rendendolo valido
        hp = hpmax;
    }
    cout << "Hai curato " << heal << " punti vita!" << endl;
}

void attaccoBoss(int &hp, int difficulty, int &nboss)
{
    int attaccoNemico;
    /*if (difficulty == 1)
    {
        if (nboss == 5)
        {
            attaccoNemico = rand() % 27 + 10;
        }
        else
        {
            attaccoNemico = rand() % 17 + 10;
        }
    }
    else if (difficulty == 2)
    {
        if (nboss == 5)
        {
            attaccoNemico = rand() % 20 + 8;
        }
        else
        {
            attaccoNemico = rand() % 10 + 8;
        }
    }
    else if (difficulty == 3)
    {
        if (nboss == 5)
        {
            attaccoNemico = rand() % 17 + 3;
        }
        else
        {
            attaccoNemico = rand() % 7 + 3;
        }
    }*/

    if (difficulty == 1) // FACILE (100 HP Giocatore)
    {
        if (nboss == 5) // Boss
        {
            attaccoNemico = rand() % 7 + 10; // Danno: 10-16 HP
        }
        else // Nemico Normale
        {
            attaccoNemico = rand() % 5 + 7; // Danno: 7-11 HP
        }
    }
    else if (difficulty == 2) // MEDIO (75 HP Giocatore)
    {
        if (nboss == 5) // Boss
        {
            attaccoNemico = rand() % 7 + 12; // Danno: 12-18 HP
        }
        else // Nemico Normale
        {
            attaccoNemico = rand() % 6 + 8; // Danno: 8-13 HP
        }
    }
    else if (difficulty == 3) // DIFFICILE (50 HP Giocatore)
    {
        if (nboss == 5) // Boss
        {
            attaccoNemico = rand() % 7 + 10; // Danno: 10-16 HP
        }
        else // Nemico Normale
        {
            attaccoNemico = rand() % 6 + 7; // Danno: 7-12 HP
        }
    }
    hp -= attaccoNemico;
    Bossreact(attaccoNemico);
}

void MosseFinali(int &hp, int difficulty, int nboss, bool &deboss, string boss, int &hp1)
{
    int randomnum = rand() % 4;
    switch (randomnum)
    {
    case 0:
    {
        attaccoBoss(hp, difficulty, nboss);
        break;
    }
    case 1:
    {
        int attacco2 = rand() % 8 + 5;
        hp -= attacco2;
        bool a = Debufff();
        if (a)
        {
            cout << "\033[1;38;2;255;165;0mIl debuff si e' attivato e ha addormentato il nemico per tutto il prossimo turno!\033[0m" << endl;
            deboss = true;
        }
        else
        {
            deboss = false;
        }
        cout << "\033[1;38;2;255;165;0m" << boss << " ti ha inflitto " << attacco2 << " danni\033[0m" << endl;
        break;
    }
    case 2:
    {
        int attacco3 = rand() % 4 + 3;
        if (Critico())
        {
            hp -= 40;
            cout << "\033[1;38;2;255;165;0mIl colpo critico si e' attivato e" << boss << " sta per infliggerti 40 danni\033[0m" << endl;
        }
        cout << "\033[1;38;2;255;165;0m" << boss << " ti ha inflitto " << attacco3 << " danni\033[0m" << endl;
        hp -= attacco3;
        break;
    }
    case 3:
    {
        int curaBoss = rand() % 20 + 10;
        hp1 += curaBoss;
        if (hp1 > 300)
        {
            curaBoss = curaBoss - (hp1 - 300); // calcola la cura in eccesso e modifica il valore di curaBoss rendendolo valido
            hp1 = 300;
        }
        cout << "\033[1;38;2;255;165;0mIl boss si e' curato di " << curaBoss << " HP\033[0m" << endl;
        break;
    }
    }
}

void Fine(bool perso)
{
    cout << "\033[2J\033[H";
    if (perso)
    {
        cout << "\033[38;2;255;255;255m" << endl;
        cout << " ██████╗  █████╗ ███╗   ███╗███████╗      ██████╗ ██╗   ██╗███████╗██████╗ " << endl;
        cout << "██╔════╝ ██╔══██╗████╗ ████║██╔════╝     ██╔═══██╗██║   ██║██╔════╝██╔══██╗" << endl;
        cout << "██║ ████╗███████║██╔████╔██║█████╗       ██║   ██║██║   ██║█████╗  ██████╔╝" << endl;
        cout << "██║   ██║██╔══██║██║╚██╔╝██║██╔══╝       ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗" << endl;
        cout << "╚██████═╝██║  ██║██║ ╚═╝ ██║███████╗     ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║" << endl;
        cout << " ╚════╝  ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝      ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝\033[0m" << endl;
    }
    else
    {
        cout << "\033[38;2;69;128;209m" << endl;
        cout << "██╗   ██╗ █████╗ ██╗     ██╗███████╗████████╗██╗  ██╗███████╗ █████╗      ██╗     ██╗██████╗ ███████╗██████╗  █████╗ ████████╗ █████╗ " << endl;
        cout << "██║   ██║██╔══██╗██║     ██║██╔════╝╚══██╔══╝██║  ██║██╔════╝██╔══██╗     ██║     ██║██╔══██╗██╔════╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗" << endl;
        cout << "██║   ██║███████║██║     ██║███████╗   ██║   ███████║█████╗  ███████║     ██║     ██║██████╔╝█████╗  ██████╔╝███████║   ██║   ███████║" << endl;
        cout << "╚██╗ ██╔╝██╔══██║██║     ██║╚════██║   ██║   ██╔══██║██╔══╝  ██╔══██║     ██║     ██║██╔══██╗██╔══╝  ██╔══██╗██╔══██║   ██║   ██╔══██║" << endl;
        cout << " ╚████╔╝ ██║  ██║███████╗██║███████║   ██║   ██║  ██║███████╗██║  ██║     ███████╗██║██████╔╝███████╗██║  ██║██║  ██║   ██║   ██║  ██║" << endl;
        cout << "  ╚═══╝  ╚═╝  ╚═╝╚══════╝╚═╝╚══════╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝     ╚══════╝╚═╝╚═════╝ ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝\033[0m" << endl;
    }
    cin.get();
    cout << "PROGRAMMATORI:" << endl;
    cout << "Tommaso Maniero" << endl
         << "Andrea Lapo Tolosi" << endl;
    cin.get();
    cout << "RINGRAZIAMENTI SPECIALI:" << endl;
    cout << "ThommyG (Controllo BUG)" << endl;
    cin.get();
    cout << "GRAZIE PER AVER GIOCATO";
    cin.get();
    exit(0); // Termina il programma
}

void Bossfight(int &hp, int difficulty, int &hp1, string player, int &count, int hpmax, string boss, int rangeAttacco, int &incremento, int &penalita, int &pietre, int nboss, bool &maledetto, int &turniMaledetto)
{
    int turniVeleno = 0, volte = 0, abilita;
    bool check = true, check1 = false, veleno = false, curato = false, deboss = false;
    while (hp > 0 && hp1 > 0)
    {
        Hud(hp, hp1, player, count, hpmax, boss, nboss, penalita);
        if (!deboss)
        {
            cout << "Scegli un'azione: " << endl;
            cout << "1 - Attacco Rapido \033[1m|\033[0m 2 - Taglio del Caos \033[1m|\033[0m 3 - Fendente Velenoso \033[1m|\033[0m 4 - Cura Cristallina" << endl;
            cout << "\033[3m> \033[0m";
            cin >> abilita;
            abilita = clamp(abilita, 1, 4);
            cout << endl;
            cout << "--------------------------------------" << endl;
            switch (abilita)
            {
            case 1:
                Attacco1(hp1, rangeAttacco, incremento);
                break;
            case 2:
                Attacco2(hp1, check, rangeAttacco, incremento);
                break;
            case 3:
                Attacco3(hp1, veleno, turniVeleno, rangeAttacco, incremento);
                break;
            case 4:
                Heal(hp, volte, curato, hpmax, difficulty);
                break;
            }
            if (turniVeleno <= 3 && veleno == true)
            {
                hp1 -= 7;
                cout << "\033[3;38;2;0;111;0mil veleno ha eliminato 7 hp al nemico\033[0m" << endl;
                turniVeleno++;
            }
            else
            {
                turniVeleno = 0;
                veleno = false;
            }

            if (maledetto && turniMaledetto > 0)
            {
                hp -= 1;
                turniMaledetto--;
            }
            else
            {
                maledetto = false;
            }

            if (check && !check1)
            {
                if (curato)
                {
                    curato = false;
                }
                else
                {
                    if (nboss == 5)
                    {
                        MosseFinali(hp, difficulty, nboss, deboss, boss, hp1);
                    }
                    else
                    {
                        attaccoBoss(hp, difficulty, nboss);
                    }
                }
            }
            else if (!check && !check1)
            {
                if (nboss == 5)
                {
                    MosseFinali(hp, difficulty, nboss, deboss, boss, hp1);
                }
                else
                {
                    attaccoBoss(hp, difficulty, nboss);
                }
                check1 = true;
            }
            else
            {
                cout << "\033[3;38;2;171;171;171mIl il boss non puo' attaccare perche' e stato addormentato dal debuff\033[0m" << endl;
                check1 = false;
            }
            cout << "--------------------------------------" << endl;
            check = true;
            cin.ignore();
            cin.get();
            cout << "\033[2J\033[H";
        }
        else
        {
            cout << "--------------------------------------" << endl;
            cout << "Non puoi attaccare per questo turno perche il boss ti ha stordito!" << endl;
            attaccoBoss(hp, difficulty, nboss);
            deboss = false;
            cout << "--------------------------------------" << endl;
            cin.get();
            cout << "\033[2J\033[H";
        }
    }
    if (hp <= 0 && hp1 > 0)
    {
        cout << "\033[2J\033[H";
        cout << "\033[1;38;2;119;34;40m" << endl;
        cout << "███████╗███████╗██╗     ███╗   ███╗ ██████╗ ██████╗ ████████╗ ██████╗ " << endl;
        cout << "██╔════╝██╔════╝██║     ████╗ ████║██╔═══██╗██╔══██╗╚══██╔══╝██╔═══██╗" << endl;
        cout << "███████╗█████╗  ██║     ██╔████╔██║██║   ██║██████╔╝   ██║   ██║   ██║" << endl;
        cout << "╚════██║██╔══╝  ██║     ██║╚██╔╝██║██║   ██║██╔══██╗   ██║   ██║   ██║" << endl;
        cout << "███████║███████╗██║     ██║ ╚═╝ ██║╚██████╔╝██║  ██║   ██║   ╚██████╔╝" << endl;
        cout << "╚══════╝╚══════╝╚═╝     ╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝    ╚═════╝ \033[0m" << endl;
        cout << endl;
        if (pietre > 0)
        {
            cout << "\033[1;37mHai la possibilita di usare una Pietra Elementare per la rianimazione!\033[0m" << endl;
            cout << "\033[1;37mVuoi usarla?\033[0m" << endl;
            cout << "1 - \033[3;37mSi\033[0m   2 - \033[3;37mNo\033[0m" << endl;
            cout << "\033[3m> \033[0m";
            cin >> abilita;
            abilita = clamp(abilita, 1, 2);
            cout << endl;
            cin.ignore();
            switch (abilita)
            {
            case 1:
                cout << "\033[1;32mHai usato una Pietra Elementare per la rianimazione!\033[0m" << endl;
                cout << "\033[1;37mLa battaglia e pronta a ricominciare, Premi un pulsante per continuare...\033[0m" << endl;
                cin.get();
                pietre--;
                break;
            case 2:
                cout << "\033[1;31mHai deciso di non usare la Pietra Elementare!\033[0m" << endl;
                cout << "\033[1;37mVerrai rianimato lo stesso ma ti verra assegnata una penalita' di 20HP in piu' al Boss Finale! Premi un pulsante per continuare...\033[0m" << endl;
                cin.get();
                penalita = penalita + 20;
                break;
            }
            hp = hpmax;
            hp1 = hp1;
            cout << "\033[2J\033[H";
            Bossfight(hp, difficulty, hp1, player, count, hpmax, boss, rangeAttacco, incremento, penalita, pietre, nboss, maledetto, turniMaledetto);
        }
        else
        {
            cout << "\033[1;31mNon possiedi Pietre Elementari\033[0m" << endl;
            cout << "\033[1;37mHai pero' due possibilita!\033[0m" << endl;
            cout << "1 - \033[3;37mRianimazione con penalita'\033[0m   2 - \033[3;37mGame Over\033[0m" << endl;
            cout << "\033[3m> \033[0m";
            cin >> abilita;
            abilita = clamp(abilita, 1, 2);
            cout << endl;
            cin.ignore();
            switch (abilita)
            {
            case 1:
                cout << "\033[1;32mHai deciso di rianimarti con penalita'!\033[0m" << endl;
                cout << "\033[1;37mVerranno assegnati 20HP in piu' al Boss Finale! Premi un pulsante per continuare...\033[0m" << endl;
                cin.get();
                penalita = penalita + 20;
                hp = hpmax;
                cout << "\033[2J\033[H";
                Bossfight(hp, difficulty, hp1, player, count, hpmax, boss, rangeAttacco, incremento, penalita, pietre, nboss, maledetto, turniMaledetto);
                break;
            case 2:
                Fine(true);
                // game over
            }
        }
    }
    else
    {
        cout << "\033[38;2;246;209;47m" << endl;
        cout << "██████╗  ██████╗ ███████╗███████╗     ███████╗ ██████╗ ██████╗ ███╗   ██╗███████╗██╗████████╗████████╗ ██████╗" << endl;
        cout << "██╔══██╗██╔═══██╗██╔════╝██╔════╝     ██╔════╝██╔════╝██╔═══██╗████╗  ██║██╔════╝██║╚══██╔══╝╚══██╔══╝██╔═══██╗" << endl;
        cout << "██████╔╝██║   ██║███████╗███████╗     ███████╗██║     ██║   ██║██╔██╗ ██║█████╗  ██║   ██║      ██║   ██║   ██║" << endl;
        cout << "██╔══██╗██║   ██║╚════██║╚════██║     ╚════██║██║     ██║   ██║██║╚██╗██║██╔══╝  ██║   ██║      ██║   ██║   ██║" << endl;
        cout << "██████╔╝╚██████╔╝███████║███████║     ███████║╚██████╗╚██████╔╝██║ ╚████║██║     ██║   ██║      ██║   ╚██████╔╝" << endl;
        cout << "╚═════╝  ╚═════╝ ╚══════╝╚══════╝     ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝     ╚═╝   ╚═╝      ╚═╝    ╚═════╝\033[0m" << endl;
        cout << "\033[38;2;255;255;255m===============================================================================================================\033[0m" << endl;
        cout << "                                            \033[1;37mHAI SCONFITTO \033[0m" << "\033[1;38;2;200;17;1m" << boss << "\033[0m" << endl;
        cout << "\033[38;2;255;255;255m===============================================================================================================\033[0m" << endl;
        count = count + 25;
        incremento = incremento + 8;
        hp1 = 120 + count;
        hp = hpmax;
    }
}

void EventoIndovinello(int &pietre, int &hp)
{
    string risposta = " ";
    int scelta;
    cout << "\033[2J\033[H";
    cout << "\033[3mNel mezzo del tuo cammino per arrivare al prossimo cristallo incontri un vecchio\033[0m" << endl;
    cout << "\033[1m                                                                         <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mTi propone un indovinello...\033[0m" << endl;
    cout << "\033[1;37mVuoi sottoporti al suo indovinello?\033[0m" << endl;
    cout << "1 - \033[3;37mSi\033[0m   2 - \033[3;37mNo\033[0m" << endl;
    cout << "\033[3m> \033[0m";
    cin >> scelta;
    scelta = clamp(scelta, 1, 2);
    cout << endl;
    switch (scelta)
    {
    case 1:
        cout << "\033[3mDistruggo la pietra ma un'onda mi spegne,\033[0m" << endl;
        cout << "\033[3mdo vita al deserto, ma la sete mi assorbe.\033[0m" << endl;
        cout << "\033[3mMi porti nel vento, ma il fuoco mi vince:\033[0m" << endl;
        cout << "\033[3mchiude il cerchio eterno...\033[0m" << endl;
        cout << endl;
        cout << "\033[1;37mMetti in ordine i seguenti elementi: Vento, Acqua, Terra, Fuoco\033[0m" << endl;
        cout << "\033[3mPer rispondere correttamente scrivi una virgola e salta uno spazio dopo ogni elemento (tranne l'ultimo), ricordati che tutto deve essere scritto in minuscolo.\033[0m" << endl
             << "Ex: \033[3melemento1, elemento2, elemento3, elemento4\033[0m" << endl;
        cout << "\033[1mRisposta: \033[0m";
        cin.ignore();
        getline(cin, risposta); // Legge l'intera riga di input, inclusi gli spazi (al contrario di: cin >> risposta)
        cout << endl;
        cout << "\033[2J\033[H";
        if (risposta == "fuoco, acqua, terra, vento")
        {
            cout << "\033[1;32mHai indovinato!\033[0m" << endl;
            cout << "\033[1;32mHai ottenuto una Pietra Elementale per la rianimazione\033[0m" << endl;
            pietre++;
        }
        else
        {
            cout << "\033[1;31mHai sbagliato!\033[0m" << endl;
            cout << "\033[1;31mPer punirti il vecchio ti infligge 20 danni!\033[0m" << endl;
            hp -= 20;
        }
        cout << "\033[1mPremi per continuare la tua avventura...\033[0m" << endl;
        cin.get();
        cout << "\033[2J\033[H";
        return;
    case 2:
        cout << "\033[1;31mHai rifiutato l'indovinello!\033[0m" << endl;
        cout << "\033[1;37mPorta avanti la tua avventura! Premi un pulsante per andare avanti...\033[0m" << endl;
        cout << "\033[1mPremi per continuare la tua avventura...\033[0m" << endl;
        cin.ignore();
        cin.get();
        cout << "\033[2J\033[H";
        return;
    }
}

void EventoViandante(int &rangeAttacco, int &hp)
{
    int scelta;
    cout << "\033[2J\033[H";
    cout << "\033[3mMentre ti stavi riposando in un avamposto incontri un viandante in difficolta che ti chiede di seguirlo e aiutarlo...\033[0m" << endl;
    cout << "\033[1m                                                                                                              <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mTuttavia sembra molto pericoloso e armato\033[0m" << endl;
    cout << "\033[1m                                  <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[1;37mVuoi aiutarlo?\033[0m" << endl;
    cout << "1 - \033[3;37mSi\033[0m   2 - \033[3;37mNo\033[0m" << endl;
    cout << "\033[3m> \033[0m";
    cin >> scelta;
    scelta = clamp(scelta, 1, 2);
    cout << endl;
    switch (scelta)
    {
    case 1:
        cout << "\033[1;32mHai deciso di salvare il viandante\033[0m" << endl;
        cin.get();
        cout << "\033[1;32mIl viandante si propone, quindi, di migliorarti la spada, alzando il danno minimo che questa puo fare!\033[0m" << endl;
        rangeAttacco += 5;
        cin.get();
        cout << "\033[3;31mTuttavia hai subito 15 danni a causa di un'esplosione imprevista durante il potenziamento\033[0m" << endl;
        hp -= 15;
        break;
    case 2:
        cout << "\033[1;31mHai deciso di non salvare il viandante\033[0m" << endl;
        cin.get();
        cout << "\033[1;31mIl viandante e' morto\033[0m" << endl;
        break;
    }
    cout << "\033[1mPremi per continuare la tua avventura...\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    return;
}

void EventoDroga(int &hpmax, int &hp)
{
    int scelta, boost = 0;
    cout << "\033[2J\033[H";
    cout << "\033[3mMentre cammini per arrivare al cristallo successivo, nel mezzo di un villaggio incontri un uomo che ti offre una sostanza...\033[0m" << endl;
    cout << "\033[1m                                                                                                                     <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mTi dice che e miracolosa e ti fara' diventare piu' forte\033[0m" << endl;
    cout << "\033[1;37mVuoi assumerla?\033[0m" << endl;
    cout << "1 - \033[3;37mSi\033[0m   2 - \033[3;37mNo\033[0m" << endl;
    cout << "\033[3m> \033[0m";
    cin >> scelta;
    scelta = clamp(scelta, 1, 2);
    cout << endl;
    switch (scelta)
    {
    case 1:
        cout << "\033[1;37mHai deciso di assumere la sostanza che si rivela essere droga!\033[0m" << endl;
        cin.get();
        boost = rand() % 10 - 5;
        if (boost > 0)
        {
            cout << "\033[1;32mTuttavia, non tutto il male vien per nuocere e la tua vita massima incrementa di " << boost << " HP\033[0m" << endl;
        }
        else if (boost == 0)
        {
            cout << "\033[1mTuttavia, sei fortunato e non ti succede niente\033[0m" << endl;
        }
        else
        {
            cout << "\033[1;31mL'assunzione di questa sostanza ti decrementa la vita massima di " << boost << " HP\033[0m" << endl;
        }
        cin.get();
        cout << "\033[1;37mAdesso e l'ora di riprendere il viaggio! Premi un pulsante per continuare...\033[0m" << endl;
        cin.get();
        cout << "\033[2J\033[H";
        hpmax += boost;
        hp = hpmax;
        return;
    case 2:
        cout << "\033[1;32mHai deciso di non assumere la sostanza!\033[0m" << endl;
        cin.get();
        cout << "\033[1;37mHai fatto una buona scelta continua con la tua avventura! Premi un pulsante per continuare...\033[0m" << endl;
        cin.get();
        cout << "\033[2J\033[H";
        return;
    }
}

void Eventoscelte(int &hp, int &pietre, int hpmax, bool &maledetto, int &turniMaledetto)
{
    int scelta;
    cout << "\033[2J\033[H";
    cout << "\033[3mMentre ti fai strada tra le radici contorte della Foresta dei Maestri, una figura oscura emerge dalle ombre...\033[0m" << endl;
    cout << "\033[1m                                                                                                       <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mCon voce roca e minacciosa, l'ombra ti intima di consegnarle tutte le tue pietre elementali di rianimazione.\033[0m" << endl;
    cout << "\033[1m                                                                                                     <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[1;37mCome reagisci alla richiesta?\033[0m" << endl;
    cout << "1 - \033[3;37mObbedisci e gliele consegni\033[0m   2 - \033[3;37mRifiuti e tieni ciò che è tuo\033[0m" << endl;
    cout << "\033[3m> \033[0m";
    cin >> scelta;
    scelta = clamp(scelta, 1, 2);
    if (pietre == 0 && scelta == 1)
    {
        cout << endl;
        cout << "\033[1;32mCerchi nelle tue tasche...\033[0m" << endl;
        cin.ignore();
        cin.get();
        cout << "\033[1;31mTi rendi conto di non avere alcuna pietra da offrire.\033[0m" << endl;
        cout << "\033[1;31mL'ombra, furiosa, non ti lascia altra scelta che negargliele!\033[0m" << endl;
        scelta = 2;
        cin.get();
        cout << "\033[2J\033[H";
    }
    switch (scelta)
    {
    case 1:
        cout << "\033[1;32mCon riluttanza, cedi le pietre. L'ombra annuisce e svanisce senza ferirti.\033[0m" << endl;
        cin.get();
        cout << "\033[1;37mUn sospiro di sollievo. È tempo di rimettersi in cammino...\033[0m" << endl;
        cin.get();
        cout << "\033[2J\033[H";
        return;
    case 2:
        cout << "\033[1;31mTi opponi con fermezza: non cederai nulla!\033[0m" << endl;
        cin.get();
        cout << "\033[2J\033[H";
        cout << "\033[1;31mCon un ringhio rabbioso, l'ombra si lancia al tuo inseguimento nella foresta!\033[0m" << endl;
        cout << "\033[1;37mPreparati a scappare! Premi Invio per iniziare la fuga...\033[0m" << endl;
        cin.get();
        cout << "\033[2J\033[H";
        cout << "\033[1;37mDurante la fuga, scorgi una profonda insenatura nel terreno!\033[0m" << endl;
        cin.get();
        cout << "\033[1;37mCosa fai?\033[0m" << endl;
        cout << "1 - \033[3;37mSaltala\033[0m   2 - \033[3;37mAggirala\033[0m" << endl;
        cout << "\033[3m> \033[0m";
        cin >> scelta;
        scelta = clamp(scelta, 1, 2);
        cout << "\033[2J\033[H";
        switch (scelta)
        {
        case 1:
            cout << "\033[1;31mProvi a saltare, ma l'insenatura è troppo larga. Cadi e subisci 10 danni!\033[0m" << endl;
            hp -= 10;
            break;
        case 2:
            cout << "\033[1;32mAggiri l'ostacolo abilmente, ma l'ombra ti è ancora alle calcagna!\033[0m" << endl;
            break;
        }
        cin.ignore();
        cin.get();
        cout << "\033[2J\033[H";
        cout << "\033[3mDevi aumentare la velocità o verrai raggiunto!\033[0m" << endl;
        cout << "\033[1m                                       <Premi>\033[0m" << endl;
        cin.get();
        cout << "\033[2J\033[H";
        cout << "\033[1;37mTi trovi ora ad un bivio nel sentiero.\033[0m" << endl;
        cin.get();
        cout << "\033[1;37mQuale strada scegli?\033[0m" << endl;
        cout << "1 - \033[3;37mDestra: lunga ma sicura\033[0m   2 - \033[3;37mSinistra: breve ma pericolosa\033[0m" << endl
             << endl;
        cout << "\033[3;37mLa strada a destra si snoda dolcemente tra gli alberi, illuminata da qualche raggio di sole. Sembra più sicura, ma si perde in lontananza: potresti impiegare molto tempo.\033[0m" << endl;
        cout << "\033[3;37mLa strada a sinistra, invece, è stretta e tortuosa. Rocce appuntite e radici sporgenti ostacolano il cammino, ma potrebbe farti guadagnare tempo prezioso...\033[0m" << endl
             << endl;
        cout << "\033[3m> \033[0m";
        cin >> scelta;
        scelta = clamp(scelta, 1, 2);
        cout << "\033[2J\033[H";
        switch (scelta)
        {
        case 1:
            cout << "\033[1;37mPrendi la strada lunga. Il nemico ti colpisce di striscio: perdi 5 HP.\033[0m" << endl;
            hp -= 5;
            break;
        case 2:
            cout << "\033[1;37mAffronti la strada breve e pericolosa...\033[0m" << endl;
            cout << "\033[1;31mCadi in una trappola e subisci 15 danni!\033[0m" << endl;
            cout << "\033[1;32mMa tra le rocce, trovi una pietra della rianimazione!\033[0m" << endl;
            pietre++;
            hp -= 15;
            break;
        }
        cin.ignore();
        cin.get();
        cout << "\033[2J\033[H";
        cout << "\033[3mAncora un ultimo sforzo... La salvezza è vicina!\033[0m" << endl;
        cout << "\033[1m                                         <Premi>\033[0m" << endl;
        cin.get();
        cout << "\033[2J\033[H";
        cout << "\033[1;32mVedi la luce: stai per uscire dalla foresta!\033[0m" << endl;
        cin.get();
        cout << "\033[1;37mDavanti a te, uno sconosciuto ti tende la mano, offrendoti protezione.\033[0m" << endl;
        cout << "1 - \033[3;37mAccetta l'aiuto\033[0m   2 - \033[3;37mContinua da solo\033[0m" << endl;
        cout << "\033[3m> \033[0m";
        cin >> scelta;
        scelta = clamp(scelta, 1, 2);
        cout << "\033[2J\033[H";
        switch (scelta)
        {
        case 1:
            cout << "\033[1;37mLo sconosciuto affronta il tuo inseguitore e lo sconfigge.\033[0m" << endl;
            cout << "\033[1;32mPoi si prende cura delle tue ferite. Ti senti rinato.\033[0m" << endl;
            hp = hpmax;
            break;
        case 2:
            cout << "\033[1;37mIgnori lo sconosciuto e continui da solo...\033[0m" << endl;
            cout << "\033[1;31mMa l'inseguitore ti trova e ti sussurra parole in una lingua dimenticata.\033[0m" << endl
                 << endl;
            cout << "\033[1;35mUna strana energia oscura ti avvolge... Sei stato maledetto!\033[0m" << endl;

            maledetto = true;
            turniMaledetto = 10;

            cout << "\033[1;90m[Fino a quando la maledizione è attiva, perdi 1 HP a turno.]\033[0m" << endl;
            break;
        }
    }
    cin.ignore();
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mChi o cosa ti attende ora? Il viaggio è tutt'altro che finito.\033[0m" << endl;
    cout << "\033[1m                                                       <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mPreparati: il destino ha ancora molte prove in serbo per te!\033[0m" << endl;
    cout << "\033[1m                                                     <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    // return;
}

void quickTimeEventRandom(int &pietre, int &hp, int &hpmax)
{
    int conta = 0;
    cout << "\033[2J\033[H";
    cout << "\033[3mUn'antica presenza si manifesta davanti a te, avvolta da una luce tremolante...\033[0m" << endl;
    cout << "\033[1m                                                                        <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mStraniero... solo chi dimostra prontezza e riflessi potrà ricevere il mio dono.\033[0m" << endl;
    cout << "\033[1m                                                                        <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[1mPreparati: dovrai premere il tasto giusto entro pochi istanti.\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[1mTi verrà chiesto di premere una lettera casuale. Hai solo 2 secondi per farlo!\033[0m" << endl;
    cout << "\033[1mSei pronto! Premi per iniziare...\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    for (int i = 0; i < 10; ++i)
    {
        char lettera = 'A' + rand() % 26; // Lettera casuale A-Z
        cout << "? PREMERE [" << lettera << "] entro 2 secondi!\n";
        clock_t start = clock();
        bool riuscito = false;
        while (((clock() - start) / CLOCKS_PER_SEC) < 2)
        {
            if (_kbhit())
            {
                char input = _getch();
                input = toupper(input); // Rende tutto maiuscolo per confronto
                if (input == lettera)
                {
                    riuscito = true;
                    break;
                }
            }
        }
        if (riuscito)
        {
            conta += 1;
        }
        cout << "\033[2J\033[H";
    }

    if (conta < 6)
    {
        cout << "\033[31mHai fallito la prova...\033[0m" << endl;
        cout << "\033[2mUna forza oscura ti colpisce. Il tuo corpo si piega sotto il peso dell’errore.\033[0m" << endl;
        cout << "\033[1;31m-40 HP\033[0m" << endl;
        hp -= 40;
    }
    else if (conta >= 6 && conta < 8)
    {
        cout << "\033[33mProva superata... ma a caro prezzo.\033[0m" << endl;
        cout << "\033[3mHai esitato, ma sei riuscito a resistere. Una scintilla di magia si unisce al tuo spirito.\033[0m" << endl;
        cout << "\033[1;31m-10 HP\033[0m \033[1;35m+1 Pietra Magica\033[0m" << endl;
        hp -= 10;
        pietre++;
    }
    else
    {
        cout << "\033[1;32mPERFECT SCORE!\033[0m" << endl;
        cout << "\033[3;36mHai dominato la prova con maestria. L’essenza dei Cristalli risponde al tuo coraggio.\033[0m" << endl;
        cout << "\033[1;35m+1 Pietra Elementale\033[0m \033[1;32mHP Massimi aumentati!\033[0m" << endl;
        pietre++;
        hpmax += 10;
        hp = hpmax;
    }
    cout << "Adesso è l'ora di riprendere il cammino, Premi per continuare..." << endl;
    cin.get();
    cout << "\033[2J\033[H";
}

void eventoRandom(int &pietre, int &hp, int &hpmax, int &rangeAttacco, bool &avv1, bool &avv2, bool &avv3, bool &avv4, bool &avv5, bool maledetto, int turniMaledetto)
{
    int evento;
    bool bigge = false;
    while (!bigge)
    {
        evento = rand() % 5 + 1;
        if (evento == 1 && avv1)
        {
            EventoIndovinello(pietre, hp);
            avv1 = false;
            bigge = true;
        }
        else if (evento == 2 && avv2)
        {
            EventoViandante(rangeAttacco, hp);
            avv2 = false;
            bigge = true;
        }
        else if (evento == 3 && avv3)
        {
            EventoDroga(hpmax, hp);
            avv3 = false;
            bigge = true;
        }
        else if (evento == 4 && avv4)
        {
            quickTimeEventRandom(pietre, hp, hpmax);
            avv4 = false;
            bigge = true;
        }
        else if (evento == 5 && avv5)
        {
            Eventoscelte(hp, pietre, hpmax, maledetto, turniMaledetto);
            avv5 = false;
            bigge = true;
        }
    }
}

int main()
{
    srand(time(0));
    int difficulty, hp, hp1, scelta, hpmax, pietre = 0, rangeAttacco = 0;
    string player, boss;
    Logo();
    cout << "\033[1mScegliere il nome del proprio personaggio\033[0m" << endl;
    cout << "\033[3m> \033[0m";
    getline(cin, player);
    cout << endl;
    cout << "\033[1mScegliere la difficolta:\033[0m" << endl;
    cout << "\033[3m1 - \033[3;32mFacile\033[0m   2 - \033[3;38;2;255;98;0mMedio\033[0m   3 - \033[3;31mDifficile\033[0m" << endl;
    cout << "\033[3m> \033[0m";
    cin >> difficulty;
    difficulty = clamp(difficulty, 1, 3); // Limito il valore di difficulty
    cout << endl;
    cin.ignore();            // Svuota il buffer di input (per evitare problemi con cin.get)
    cout << "\033[2J\033[H"; // Pulisce il terminale
    cout << "\033[1mOk adesso vediamo le tue statistiche, premi un pulsante per continuare...\033[0m" << endl;
    cin.get(); // Aspetta che l'utente prema un tasto

    switch (difficulty)
    {
    case 1:
        cout << "\033[1;37m=== STATUS PERSONAGGIO ===\033[0m" << endl;
        cout << "\033[1mPlayer: \033[0m\033[3m" << player << "\033[0m" << endl;
        cout << "\033[1mVita: \033[0m" << "\033[3m[########100HP########]\033[0m" << endl;
        cout << "\033[1mMosse disponibili:\033[0m" << endl;
        cout << "\033[1m1.\033[0m \033[3mAttacco Rapido\033[0m" << endl;
        cout << "\033[1m2.\033[0m \033[3mTaglio del Caos\033[0m" << endl;
        cout << "\033[1m3.\033[0m \033[3mFendente Velenoso\033[0m" << endl;
        cout << "\033[1m4.\033[0m \033[3mCura Cristallina\033[0m" << endl;
        cout << "\033[1;37m==========================\033[0m" << endl;
        hp = 100;
        hpmax = 100;
        hp1 = 120;
        break;

    case 2:
        cout << "\033[1;37m=== STATUS PERSONAGGIO ===\033[0m" << endl;
        cout << "\033[1mPlayer: \033[0m\033[3m" << player << "\033[0m" << endl;
        cout << "\033[1mVita: \033[0m" << "\033[3m[########75HP########]\033[0m" << endl;
        cout << "\033[1mMosse disponibili:\033[0m" << endl;
        cout << "\033[1m1.\033[0m \033[3mAttacco Rapido\033[0m" << endl;
        cout << "\033[1m2.\033[0m \033[3mTaglio del Caos\033[0m" << endl;
        cout << "\033[1m3.\033[0m \033[3mFendente Velenoso\033[0m" << endl;
        cout << "\033[1m4.\033[0m \033[3mCura Cristallina\033[0m" << endl;
        cout << "\033[1;37m==========================\033[0m" << endl;
        hp = 75;
        hpmax = 75;
        hp1 = 120;
        break;

    case 3:
        cout << "\033[1;37m=== STATUS PERSONAGGIO ===\033[0m" << endl;
        cout << "\033[1mPlayer: \033[0m\033[3m" << player << "\033[0m" << endl;
        cout << "\033[1mVita: \033[0m" << "\033[3m[########50HP########]\033[0m" << endl;
        cout << "\033[1mMosse disponibili:\033[0m" << endl;
        cout << "\033[1m1.\033[0m \033[3mAttacco Rapido\033[0m" << endl;
        cout << "\033[1m2.\033[0m \033[3mTaglio del Caos\033[0m" << endl;
        cout << "\033[1m3.\033[0m \033[3mFendente Velenoso\033[0m" << endl;
        cout << "\033[1m4.\033[0m \033[3mCura Cristallina\033[0m" << endl;
        cout << "\033[1;37m==========================\033[0m" << endl;
        hp = 50;
        hpmax = 50;
        hp1 = 120;
        break;
    }
    cout << endl;
    cout << "\033[1mPronto per iniziare? Scegli se iniziare subito l'avventura oppure avviare un mini tutorial\033[0m" << endl;
    cout << "\033[3m1 - \033[3;32mInizia Avventura\033[0m   2 - \033[3;31mInizia Tutorial\033[0m" << endl;
    cout << "\033[3m> \033[0m";
    cin >> scelta;
    scelta = clamp(scelta, 1, 2);
    switch (scelta)
    {
    case 1:
        cout << "\033[1mIniziamo l'avventura! Premi un pulsante per continuare...\033[0m" << endl;
        break;
    case 2:
        cout << "\033[1mIniziamo il tutorial! Premi un pulsante per continuare...\033[0m" << endl;
        cin.ignore();
        cin.get();
        cout << "\033[2J\033[H";

        // Introduzione al gioco
        cout << "\033[1;37m=== BENVENUTO IN FINAL REQUIEM ===\033[0m" << endl;
        cout << "\033[3mIn questo mondo fantasy, dovrai affrontare 5 potenti boss per distruggere i Cristalli che stanno corrompendo Valisthea.\033[0m" << endl;
        cin.get();
        cout << "\033[2J\033[H";

        // Sistema di combattimento
        cout << "\033[1;37m=== SISTEMA DI COMBATTIMENTO ===\033[0m" << endl;
        cout << "\033[3mI combattimenti sono a turni. Ogni turno potrai scegliere una delle quattro abilità disponibili:\033[0m" << endl
             << endl;
        cout << "\033[1m1. Attacco Rapido:\033[0m \033[3mInfligge danni elevati e diretti al nemico.\033[0m" << endl;
        cout << "\033[1m2. Taglio del Caos:\033[0m \033[3mDanni moderati con 25% di probabilità di addormentare il nemico per un turno.\033[0m" << endl;
        cout << "\033[1m3. Fendente Velenoso:\033[0m \033[3mDanni bassi, ma con 18% di probabilità di colpo critico (50 danni) o effetto veleno (7 danni per 3 turni).\033[0m" << endl;
        cout << "\033[1m4. Cura Cristallina:\033[0m \033[3mRipristina HP in base alla tua salute attuale (più efficace quando sei ferito). Usabile solo 3 volte per battaglia.\033[0m" << endl;
        cin.get();
        cout << "\033[2J\033[H";

        // Progressione e meccaniche
        cout << "\033[1;37m=== PROGRESSIONE DEL GIOCO ===\033[0m" << endl;
        cout << "\033[3mDovrai visitare 5 aree diverse e sconfiggere un boss in ciascuna:\033[0m" << endl
             << endl;
        cout << "\033[3m• Ogni vittoria potenzia la tua arma (+8 danni) e aumenta la vita dei nemici successivi (+25 HP)\033[0m" << endl;
        cout << "\033[3m• La tua vita viene ripristinata completamente dopo ogni scontro\033[0m" << endl;
        cout << "\033[3m• L'ultimo boss è più potente (300 HP + eventuali penalità)\033[0m" << endl;
        cin.get();
        cout << "\033[2J\033[H";

        // Eventi e oggetti
        cout << "\033[1;37m=== EVENTI E OGGETTI ===\033[0m" << endl;
        cout << "\033[3mDurante l'avventura incontrerai eventi casuali che possono offrire:\033[0m" << endl
             << endl;
        cout << "\033[3m• Pietre Elementari: ti permettono di rivivere dopo una sconfitta\033[0m" << endl;
        cout << "\033[3m• Potenziamenti: aumento della vita massima o del danno delle armi\033[0m" << endl;
        cout << "\033[3m• Sfide: indovinelli, quick time event e incontri che richiedono scelte\033[0m" << endl;
        cout << "\033[3m• Maledizioni: effetti negativi che possono persistere per più turni\033[0m" << endl
             << endl;
        cout << "\033[3mSe vieni sconfitto senza Pietre Elementari, puoi comunque continuare ma il boss finale guadagnerà +20 HP.\033[0m" << endl;
        cin.get();
        cout << "\033[2J\033[H";

        // Interfaccia e controlli
        cout << "\033[1;37m=== INTERFACCIA E CONTROLLI ===\033[0m" << endl;
        cout << "\033[3m• Durante il combattimento, l'HUD mostra la tua vita e quella del nemico\033[0m" << endl;
        cout << "\033[3m• Seleziona le azioni digitando il numero corrispondente (1-4)\033[0m" << endl;
        cout << "\033[3m• I valori inseriti vengono automaticamente corretti se non validi\033[0m" << endl;
        cout << "\033[3m• Premi Invio per avanzare nei dialoghi e nella storia\033[0m" << endl;
        cin.get();
        cout << "\033[2J\033[H";

        // Conclusione
        cout << "\033[1;37m=== OBIETTIVO FINALE ===\033[0m" << endl;
        cout << "\033[3mIl tuo compito è distruggere tutti i 5 Cristalli per liberare Valisthea dalla corruzione.\033[0m" << endl;
        cout << "\033[3mOgni Cristallo distrutto cambierà il mondo, ma le conseguenze delle tue azioni non saranno sempre chiare...\033[0m" << endl
             << endl;
        cout << "\033[1mOra sei pronto per iniziare la tua avventura! Premi per continuare...\033[0m" << endl;
        break;
    }
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mIn un mondo lontano, Valisthea era un regno di pace e prosperita', governato da potenti Cristalli.\033[0m" << endl;
    cout << "\033[1m                                                                                           <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mQuando i Cristalli brillavano ancora, Valisthea prosperava sotto la loro luce. Ma quella luce... non era gratuita.\033[0m" << endl;
    cout << "\033[1m                                                                                                           <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mCiò che dona... chiede in cambio. E ciò che chiede... è vita.\033[0m" << endl;
    cout << "\033[1m                                                      <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mSotto i Cristalli Madre, le terre si spengono. Le bestie si corrompono. Gli uomini perdono sé stessi. La Brama cresce come un cancro nel cuore di Valisthea.\033[0m" << endl;
    cout << "\033[1m                                                                                                                                                     <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mPer salvare Valisthea, dobbiamo distruggere ciò che l’ha resa grande. Tagliare le radici malate. Spezzare i sigilli. Uccidere gli dèi.\033[0m" << endl;
    cout << "\033[1m                                                                                                                               <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mNon c’è più scelta. O i Cristalli muoiono... o lo faremo noi.\033[0m" << endl;
    cin.get();

    int supl[5] = {-1, -1, -1, -1, -1}, count = 0, incremento = 0, penalita = 0, nboss = 0, turniMaledetto = 0;
    bool avv1 = true, avv2 = true, avv3 = true, avv4 = true, avv5 = true, maledetto = false, partenza = true;

    Zona(scelta, supl, boss, partenza);
    Bossfight(hp, difficulty, hp1, player, count, hpmax, boss, rangeAttacco, incremento, penalita, pietre, nboss, maledetto, turniMaledetto);
    nboss++;
    nboss++;
    partenza = false;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[1mIl primo Cristallo è caduto.\033[0m \033[3mLa terra respira, ma una sensazione di freddo si fa strada nel cuore di Valisthea.\033[0m" << endl;
    cout << "\033[1m                                                                                                        <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mAbbiamo liberato un angolo del mondo, ma non c'è gioia in questa vittoria. La luce che si è accesa lascia solo ombre.\033[0m" << endl;
    cout << "\033[1m                                                                                                              <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mQuesto è solo l'inizio. Ogni passo che facciamo ci avvicina a una fine che non possiamo prevedere.\033[0m" << endl;
    cout << "\033[1m                                                                                           <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mLa terra brucia sotto i nostri piedi, eppure non possiamo fermarci...\033[0m" << endl;
    cout << "\033[1m                                                              <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3;37mDOBBIAMO CONTINUARE!\033[0m" << endl;

    cin.get();
    Zona(scelta, supl, boss, partenza);
    eventoRandom(pietre, hp, hpmax, rangeAttacco, avv1, avv2, avv3, avv4, avv5, maledetto, turniMaledetto);
    Bossfight(hp, difficulty, hp1, player, count, hpmax, boss, rangeAttacco, incremento, penalita, pietre, nboss, maledetto, turniMaledetto);
    nboss++;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[1mIl secondo Cristallo è caduto.\033[0m \033[3mIl cielo, prima carico di luce eterea, ora è solo un velo grigio sopra la terra spenta.\033[0m" << endl;
    cout << "\033[1m                                                                                                               <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mLa luce che credevamo corrotta... era anche vita. La regione ora giace in silenzio. Né Brama, né magia. Solo cenere.\033[0m" << endl;
    cout << "\033[1m                                                                                                             <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mI contadini non ci ringraziano. Ci guardano in silenzio. Le loro lanterne non si accendono più. Le loro acque non scorrono.\033[0m" << endl;
    cout << "\033[1m                                                                                                                    <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mE poi… una voce. Antica. Come se la terra stessa avesse deciso di parlare.\033[0m" << endl;
    cout << "\033[1m                                                                   <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3m\033[2m\"Distruttore... Tu spezzi l’equilibrio. Tu credi di salvare il mondo… ma il mondo non vuole essere salvato.\"\033[0m" << endl;
    cout << "\033[1m                                                                                                     <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mOgni Cristallo che cade, svela ciò che era nascosto. Non luce... ma ombra. Non salvezza... ma giudizio.\033[0m" << endl;
    cout << "\033[1m                                                                                                <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mLa voce si è spenta. Ma l’eco rimane. E con essa… un dubbio.\033[0m" << endl;
    cout << "\033[1m                                                     <Premi>\033[0m" << endl;
    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mDue Cristalli caduti. Tre rimangono. E ora... non siamo più soli in questo cammino.\033[0m" << endl;

    cin.get();
    Zona(scelta, supl, boss, partenza);
    eventoRandom(pietre, hp, hpmax, rangeAttacco, avv1, avv2, avv3, avv4, avv5, maledetto, turniMaledetto);
    Bossfight(hp, difficulty, hp1, player, count, hpmax, boss, rangeAttacco, incremento, penalita, pietre, nboss, maledetto, turniMaledetto);
    nboss++;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[1mIl terzo Cristallo è caduto.\033[0m" << endl;
    cout << "\033[3mL'impatto ha scosso le radici stesse della terra.\033[0m" << endl;
    cout << "\033[1m                                          <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mLe montagne tremano.\033[0m" << endl;
    cout << "\033[3mLe nubi si arrotolano come draghi ciechi sopra le valli.\033[0m" << endl;
    cout << "\033[1m                                                 <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mAbbiamo camminato attraverso la cenere, tra templi spezzati e statue piangenti.\033[0m" << endl;
    cout << "\033[3mLa gente non ci guarda più. Ci teme.\033[0m" << endl;
    cout << "\033[1m                                                                        <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mC'è chi ci chiama liberatori. C'è chi ci chiama assassini.\033[0m" << endl;
    cout << "\033[3mNoi non rispondiamo. Non sappiamo più chi siamo.\033[0m" << endl;
    cout << "\033[1m                                                   <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mUna notte, al confine di una landa spoglia, abbiamo sentito cantare.\033[0m" << endl;
    cout << "\033[3mNon era voce umana. Né animale. Era la terra stessa.\033[0m" << endl;
    cout << "\033[1m                                                             <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3m\033[2m\"Liberatori... ma di cosa? Dalla schiavitù, o dalla speranza?\"\033[0m" << endl;
    cout << "\033[3mLa voce rideva. O piangeva. O entrambe le cose.\033[0m" << endl;
    cout << "\033[1m                                                       <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mOgni passo più profondo nel mondo, eppure più lontano dalla luce.\033[0m" << endl;
    cout << "\033[3mMa non possiamo tornare indietro. E avanti... non c’è più sentiero.\033[0m" << endl;

    cin.get();
    Zona(scelta, supl, boss, partenza);
    eventoRandom(pietre, hp, hpmax, rangeAttacco, avv1, avv2, avv3, avv4, avv5, maledetto, turniMaledetto);
    Bossfight(hp, difficulty, hp1, player, count, hpmax, boss, rangeAttacco, incremento, penalita, pietre, nboss, maledetto, turniMaledetto);
    nboss++;
    hp1 = 300 + penalita;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[1mIl quarto Cristallo è caduto.\033[0m" << endl;
    cout << "\033[3mUn'esplosione silenziosa ha lacerato il cielo stesso.\033[0m" << endl;
    cout << "\033[1m                                              <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mIl mondo non è più come prima.\033[0m" << endl;
    cout << "\033[3mLe stelle sembrano più lontane. Le ombre... più vicine.\033[0m" << endl;
    cout << "\033[1m                                                <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mAbbiamo attraversato campi di cristalli spezzati, che piangono luce liquida.\033[0m" << endl;
    cout << "\033[3mOgni passo risuona come un giudizio, ogni silenzio pesa come una condanna.\033[0m" << endl;
    cout << "\033[1m                                                                     <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mIn un villaggio senza nome, i bambini ci hanno guardato con occhi vuoti.\033[0m" << endl;
    cout << "\033[3mNon ci temevano. Ma avevano già rinunciato a sperare.\033[0m" << endl;
    cout << "\033[1m                                                                 <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mIl loro silenzio pesa più delle urla. Più delle battaglie. Più del sangue.\033[0m" << endl;
    cout << "\033[1m                                                                   <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mPoi, durante la notte, un sogno ci ha trovati.\033[0m" << endl;
    cout << "\033[3mUn sogno... o un ricordo che non ci appartiene.\033[0m" << endl;
    cout << "\033[1m                                        <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3m\033[2m\"Quello che spegni... era stato acceso da mani dimenticate.\"\033[0m" << endl;
    cout << "\033[3m\033[2m\"Il mondo non chiede salvezza. Chiede solo tempo.\"\033[0m" << endl;
    cout << "\033[1m                                                              <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mCi siamo svegliati con la pelle fredda. Le mani tremanti. Il silenzio intorno.\033[0m" << endl;
    cout << "\033[3mMa il cielo... il cielo non è più grigio. È nero.\033[0m" << endl;
    cout << "\033[1m                                                                       <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mUn solo Cristallo rimane. E con esso, il destino di Valisthea.\033[0m" << endl;

    cin.get();
    Zona(scelta, supl, boss, partenza);
    eventoRandom(pietre, hp, hpmax, rangeAttacco, avv1, avv2, avv3, avv4, avv5, maledetto, turniMaledetto);
    Bossfight(hp, difficulty, hp1, player, count, hpmax, boss, rangeAttacco, incremento, penalita, pietre, nboss, maledetto, turniMaledetto);

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[1;37mL'ultimo Cristallo è caduto.\033[0m" << endl;
    cout << "\033[3mNon c'è stato alcun suono. Solo una luce cieca, e poi... nulla.\033[0m" << endl;
    cout << "\033[1m                                                        <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mIl mondo intero si è fermato. Come se trattenesse il respiro.\033[0m" << endl;
    cout << "\033[3mOgni foglia, ogni goccia d'acqua, ogni cuore… ha smesso di battere per un istante eterno.\033[0m" << endl;
    cout << "\033[1m                                                                                  <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mPoi, la tenebra ha cominciato a sciogliersi.\033[0m" << endl;
    cout << "\033[3mUna luce nuova — non quella dei Cristalli — si è fatta largo tra le rovine.\033[0m" << endl;
    cout << "\033[1m                                                                    <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mNon era magia. Non era divina. Era qualcosa di antico. Più antico della stessa Valisthea.\033[0m" << endl;
    cout << "\033[3mQualcosa che i Cristalli avevano nascosto per secoli.\033[0m" << endl;
    cout << "\033[1m                                                                                  <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mUn sussurro ha attraversato le terre spezzate:\033[0m" << endl;
    cout << "\033[3m\033[2m\"Hai distrutto i pilastri del mondo... sei pronto a costruirne uno nuovo?\"\033[0m" << endl;
    cout << "\033[1m                                                                   <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mIl silenzio non è più un vuoto. È attesa.\033[0m" << endl;
    cout << "\033[3mIl cielo non è più scuro. È nudo.\033[0m" << endl;
    cout << "\033[3mValisthea è libera. Ma anche perduta.\033[0m" << endl;
    cout << "\033[1m                                  <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mAbbiamo compiuto l’irreparabile.\033[0m" << endl;
    cout << "\033[3mE adesso… resta solo da decidere chi saremo, in un mondo senza Cristalli.\033[0m" << endl;
    cout << "\033[38;2;246;209;47mPREMI PER CONTINUARE\033[0m" << endl;
    cin.get();

    cout << "\033[2J\033[H";
    cout << "\033[3mIl mondo è cambiato.\033[0m" << endl;
    cout << "\033[3mNiente più Brama, niente più Cristalli. Solo silenzio... e possibilità.\033[0m" << endl;
    cout << "\033[1m                                                                <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mI villaggi spogli guardano l’orizzonte con occhi nuovi. Qualcuno piange. Qualcuno sorride. Nessuno capisce davvero cosa accadrà.\033[0m" << endl;
    cout << "\033[1m                                                                                                                         <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mLe acque tornano a scorrere, ma non hanno più la stessa magia.\033[0m" << endl;
    cout << "\033[3mLe bestie si svegliano, confuse. La terra respira. Non canta, non soffre. Respira, semplicemente.\033[0m" << endl;
    cout << "\033[1m                                                                                          <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mTu cammini da solo. O forse no. Forse dietro di te qualcuno ha scelto di seguire. Forse davanti c’è un futuro.\033[0m" << endl;
    cout << "\033[1m                                                                                                       <Premi>\033[0m" << endl;

    cin.get();
    cout << "\033[2J\033[H";
    cout << "\033[3mIn un mondo senza dèi, senza magie, senza predestinazione... cosa rimane?\033[0m" << endl;
    cin.get();
    cout << "\033[38;2;246;209;47mSolo la volontà.\033[0m" << endl;
    cin.get();
    Fine(false);
    return 0;
}
